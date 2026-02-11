#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

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
//-------------------------------------------------------------------------------

int count = 0;  // compteur de client
int max_fd = 0;  //le plus gros fd 
int ids[65536]; //id du client pour chaque fd 
char* msgs[65536]; // message 
fd_set afds, wfds, rfds; //
char buf_read[1001];  // buffer pour recv
char buf_write[42];    // buffer pour sprintf

void fatal_error()
{
    write (2, "Fatal error\n", 12);
    exit(1);
}

void notify_all(int autor, char*str)
{
    for (int fd = 0; fd <= max_fd; fd++) // boucle pour parcourir tout les fd 
    {
        if (FD_ISSET(fd, &wfds) && fd != autor) // chercher les fd qui sont dans le set et aussi que cest pas lui meme 
            send(fd, str, strlen(str), 0); // envoyer le message au fd
    }
}
void add_client(int fd)
{
    if (fd > max_fd) //verif si le fd nest pas plus grand que le max 
        max_fd = fd; //sinon mettre a jour le max
    ids[fd] = count ++; //donner un son id au fd
    msgs[fd] = NULL; // mettre le message a null
    FD_SET(fd, &afds); //ajouter le nouveau clien au tableau
    sprintf(buf_write, "server: client %d just arrived\n", ids[fd]); //stocker la phrase de la venue 
    notify_all(fd, buf_write); // sannonce a tout les autres 
}
void rm_client(int fd)
{
    sprintf(buf_write, "server: client %d just left\n", ids[fd]); //stocker la phrase de la venue 
    notify_all(fd, buf_write); // sannonce a tout les autres 
    free(msgs[fd]); // free ses messages 
    FD_CLR(fd , &afds); // le degager du set 
    close(fd); //le fermer
}
void send_msg(int fd)
{
    char *msg;
    while (extract_message(&msgs[fd], &msg))
    {
        sprintf(buf_write, "client %d: ", ids[fd]); //stocker la phrase de son id 
        notify_all(fd, buf_write); //affiche son nom :
        notify_all(fd, msg); //print sa phrase 
        free(msg); //free le msg
    }
}

int main(int ac, char **av) 
{
    if (ac != 2) // verif des arument 
    {
        write (2, "Wrong number of arguments\n", 26); // print message derreur 
        exit(1); // exit le programme
    }
	int sockfd;
	struct sockaddr_in servaddr; 

	sockfd = socket(AF_INET, SOCK_STREAM, 0); 
	if (sockfd < 0) 
        fatal_error();
	bzero(&servaddr, sizeof(servaddr)); 

	// assign IP, PORT 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(atoi(av[1])); 

	if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0)
            fatal_error();
	if (listen(sockfd, 10) != 0)
            fatal_error();
    max_fd = sockfd; // mettre max_fd a la valeur du serv
    FD_ZERO(&afds); // sassurer que  afds est vide 
    FD_SET(sockfd, &afds);// inserer le serv dans asdf

    while(1)
    {
        rfds = wfds = afds; // reinitialise les set de lecture et decriture 
        if (select(max_fd + 1, &rfds, &wfds, NULL, NULL) < 0) //select va retireer ceux qui sont pas pret et modifier rfds et wfds
            fatal_error(); // protection en cas dechec de select
        
        for (int fd = 0; fd <= max_fd; fd++) // on parcour tout les fd jusqua atteindre max_fd
        {
            if (!FD_ISSET(fd, &rfds)) // on check si le fd est dans rfds 
                continue;            //sinon on passe au suivant 

            // nouvelle connection
            if (fd == sockfd) // si cest le serveur qui a ete select 
            {
                socklen_t len = sizeof(servaddr);// size du serv pour utilise accpet
                int client = accept(sockfd, (struct sockaddr *)&servaddr, &len); //stocker le fd du clien qui essey de se connecter au serveur 
                if (client >=0) // si accept na pa eu derrur 
                    add_client(client); // ajouter le fd a afds
                break; // puis on sort quelque sois et on repart a select
            }

            //message ou deco
            int n = recv(fd, buf_read, 1000, 0); //on regarde si on a ecrit dans ce fd et on stock dans bufread
            if (n <= 0) // si recv nous return 0 = le client s'est déconnecté. Négatif = erreur.
            {
                rm_client(fd); // deconection 
                break;
            }
            buf_read[n] = '\0'; // on finit notre message 
            msgs[fd] = str_join(msgs[fd], buf_read); //on le concatene et le stocke dans msgs
            send_msg(fd); //on envoie le msg a tout le monde 
        }
    }
}