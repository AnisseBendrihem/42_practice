#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>

int extract_message(char **buf, char **msg)
{
	char	*newbuf;
	int	i;

	*msg = 0;
	if (*buf == 0)
		return (0);
	i = 0;
	while ((*buf)[i])
	{
		if ((*buf)[i] == '\n')
		{
			newbuf = calloc(1, sizeof(*newbuf) * (strlen(*buf + i + 1) + 1));
			if (newbuf == 0)
				return (-1);
			strcpy(newbuf, *buf + i + 1);
			*msg = *buf;
			(*msg)[i + 1] = 0;
			*buf = newbuf;
			return (1);
		}
		i++;
	}
	return (0);
}
char *str_join(char *buf, char *add)
{
	char	*newbuf;
	int		len;

	if (buf == 0)
		len = 0;
	else
		len = strlen(buf);
	newbuf = malloc(sizeof(*newbuf) * (len + strlen(add) + 1));
	if (newbuf == 0)
		return (0);
	newbuf[0] = 0;
	if (buf != 0)
		strcat(newbuf, buf);
	free(buf);
	strcat(newbuf, add);
	return (newbuf);
}

//---------------------------------------------------------------------
int count = 0;
int max_fd = 0;
int ids[65563];
char* msgs[65563];

fd_set afds, wfds, rfds;
char buf_read[1001];
char buf_write[42];
//---------------------------------------------------------------------
void fatal_error()
{
    write (2, "Fatal error\n", 12);
    exit (1);
}
void notify(int autor, char *str)
{
    for(int fd = 0; fd <= max_fd; fd++)
        if (FD_ISSET(fd, &wfds) && fd != autor)
            send(fd, str, strlen(str), 0);
    
}
void add_client(int fd)
{
    if (max_fd < fd)
        max_fd = fd;
    msgs[fd]= NULL;
    ids[fd] = count ++;
    FD_SET(fd, &afds);
    sprintf(buf_write, "server: client %d just arrived\n", ids[fd]);
    notify(fd, buf_write);
}
void rm_client(int fd)
{
    sprintf(buf_write, "server: client %d just left\n", ids[fd]);
    notify(fd, buf_write);
    free(msgs[fd]);
    FD_CLR(fd, &afds);
    close(fd);
}
void send_msg(int fd)
{
    char *str;
    while (extract_message(&msgs[fd], &str))
    {
        sprintf(buf_write, "client %d: ", ids[fd]);
        notify(fd, buf_write);    
        notify(fd, str);
        free(str);
    }
}

int main(int ac, char** av) 
{
    if (ac != 2)
    {
        write (2, "Wrong number of arguments\n", 26);
        exit (1);
    }
	int sockfd;
	struct sockaddr_in servaddr; 

	// socket create and verification 
	sockfd = socket(AF_INET, SOCK_STREAM, 0); 
	if (sockfd < 0)
        fatal_error();
	bzero(&servaddr, sizeof(servaddr)); 

	// assign IP, PORT 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(atoi(av[1])); 
  
	// Binding newly created socket to given IP and verification 
	if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0)
        fatal_error();
	if (listen(sockfd, SOMAXCONN) != 0)
        fatal_error();

    max_fd = sockfd;    
    FD_ZERO(&afds);
    FD_SET(sockfd, &afds);

    while (1)
    {
        rfds = wfds = afds;
        if (select(max_fd + 1, &rfds, &wfds, NULL, NULL) < 0)
            fatal_error();

        for (int fd = 0; fd <= max_fd; fd++)
        {
            if (!FD_ISSET(fd, &rfds))
                continue;
                
            if (fd == sockfd)
            {
                socklen_t len = sizeof(servaddr);
                int client = accept(sockfd, (struct sockaddr *)&servaddr, &len);  
                if (client >= 0)
                    add_client(client);
                break;         
            }
            int n = recv(fd, buf_read, 1000, 0);
            if (n <=0)
            {
                rm_client(fd);
                break;
            }
            buf_read[n] = '\0';
            msgs[fd] = str_join(msgs[fd], buf_read);
            send_msg(fd);
        }

    }
}
