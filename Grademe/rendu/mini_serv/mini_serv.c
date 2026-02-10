#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>

/*  ========== COPIE-COLLE DU MAIN DONNE ==========  */
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
//---------------------------------------------------------------------------

int		count = 0;       // compteur d'id client
int		max_fd = 0;      // plus grand fd actif
int		ids[65536];      // id du client pour chaque fd
char	*msgs[65536];    // buffer de message partiel par fd

fd_set	afds, rfds, wfds;        // all / read / write
char	buf_read[1001];          // buffer recv
char	buf_write[42];           // buffer sprintf

void fatal_error(void)
{
	write(2, "Fatal error\n", 12);
	exit(1);
}
void notify_all(int author, char *str)
{
	for (int fd = 0; fd <= max_fd; fd++)
		if (FD_ISSET(fd, &wfds) && fd != author)
			send(fd, str, strlen(str), 0);
}
void add_client(int fd)
{
	if (fd > max_fd)
		max_fd = fd;
	ids[fd] = count++;
	msgs[fd] = NULL;
	FD_SET(fd, &afds);
	sprintf(buf_write, "server: client %d just arrived\n", ids[fd]);
	notify_all(fd, buf_write);
}
void rm_client(int fd)
{
	sprintf(buf_write, "server: client %d just left\n", ids[fd]);
	notify_all(fd, buf_write);
	free(msgs[fd]);
	FD_CLR(fd, &afds);
	close(fd);
}
void send_msg(int fd)
{
	char *msg;

	while (extract_message(&msgs[fd], &msg))
	{
		sprintf(buf_write, "client %d: ", ids[fd]);
		notify_all(fd, buf_write);
		notify_all(fd, msg);
		free(msg);
	}
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		write(2, "Wrong number of arguments\n", 26);
		exit(1);
	}

	// --- copie-colle du main donne (adapte) ---
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
		fatal_error();

	struct sockaddr_in servaddr;
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(2130706433); // 127.0.0.1
	servaddr.sin_port = htons(atoi(av[1]));

	if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)))
		fatal_error();
	if (listen(sockfd, SOMAXCONN))
		fatal_error();
	// --- fin copie-colle ---

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

			// Nouvelle connexion
			if (fd == sockfd)
			{
				socklen_t len = sizeof(servaddr);
				int client = accept(sockfd, (struct sockaddr *)&servaddr, &len);
				if (client >= 0)
					add_client(client);
				break;
			}

			// Message ou deconnexion
			int n = recv(fd, buf_read, 1000, 0);
			if (n <= 0)
			{
				rm_client(fd);
				break;
			}
			buf_read[n] = '\0';
			msgs[fd] = str_join(msgs[fd], buf_read);
			send_msg(fd);
		}
	}
	return 0;
}
