/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 13:46:12 by abendrih          #+#    #+#             */
/*   Updated: 2025/09/22 22:06:03 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;

	i = 0;
	while (src[i])
		i++;
	dest = malloc(sizeof(char) * i + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*get_next_line(int fd)
{
	static int	j = 0;              // index pour faire avancer la temporaire 
	static int	readed = 0;         // le nombre de bytes lue avec read
	static char	recip[BUFFER_SIZE];  // la variable temporaire pour chaque relecture de read
	char		line[10000]; 		 // la string final quon va rendre avant le \n 
	int			i;					// notre index pour naviguer dans line et la remplire  

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)  // verifier si le fichier 
		return (NULL);				 //est bon ou si on est pas arriver en fin de fichier 
	while (1)						  //boucle infinie
	{
		if (j >= readed)                 // premiere entrre de la joucle pour remplir recip
		{
			readed = read(fd, recip, BUFFER_SIZE);  // remplir recip
			j = 0;								// set j a 0 pour ne plus renter de la condition 
			if (readed == 0)                    // checker si reader esta 0 pour quitter la boucle 
				break ;
		}
		line[i++] = recip[j++];                 // remplir  line jusuq quelle trouve un \n
		if (line[i -1] == '\n')					// quitter la boucle quand on trouve un \n
			break ;
	}
	if (i == 0)                                 // cas ou on rentre jamais dans la boucle 
		return (NULL);
	line[i] = '\0';					      	// on met le \0 avant de return avace strdup 
	return (ft_strdup(line));
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = 0;
	fd = open("file.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
