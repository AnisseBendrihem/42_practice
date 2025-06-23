# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/30 20:38:49 by abendrih          #+#    #+#              #
#    Updated: 2025/05/16 20:00:53 by abendrih         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nom du programme de test
EXEC = main

# Nom de la librairie
NAME = libft.a

# Fichiers source
SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
	ft_strlcat.c ft_tolower.c ft_toupper.c ft_strchr.c ft_strrchr.c \
	ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_strdup.c \
	ft_calloc.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
	ft_strmapi.c ft_striteri.c ft_putnbr_fd.c ft_putchar_fd.c ft_putstr_fd.c \
	ft_putendl_fd.c

# Fichiers source bonus
SRC_BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
			ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c \

# Fichiers objets
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

# Compilateur & flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Couleurs
NEON_GREEN = \033[38;2;57;255;20m
NEON_PINK = \033[38;2;255;20;147m
NEON_CYAN = \033[38;2;0;255;255m
NEON_PURPLE = \033[38;2;180;0;255m
RESET = \033[0m

# Règle par défaut
all: $(NAME)
	@echo "$(NEON_GREEN)💾 [SYSTEM] Compilation de LIBFT... [OK]$(RESET)"

# Création de la librairie
$(NAME): $(OBJ)
	@echo "$(NEON_CYAN)🔧 Forge de la librairie $(NAME)...$(RESET)"
	@ar rcs $(NAME) $(OBJ)

# Compilation avec les bonus
bonus: $(OBJ) $(OBJ_BONUS)
	@echo "$(NEON_CYAN)🔧 Forge de la librairie $(NAME) avec les bonus...$(RESET)"
	@ar rcs $(NAME) $(OBJ) $(OBJ_BONUS)

# Nettoyage des fichiers objets
clean:
	@echo "$(NEON_PURPLE)🧽 Nettoyage des fichiers .o...$(RESET)"
	@rm -f $(OBJ) $(OBJ_BONUS)

# Nettoyage complet
fclean: clean
	@echo "$(NEON_PINK)💣 Destruction totale de LIBFT...$(RESET)"
	@rm -f $(NAME) $(EXEC)

# Recompilation from scratch
re: fclean all

# Exécution de main.c avec la lib
run: all
	@echo "$(NEON_GREEN)⚙️  Compilation de $(EXEC) avec LIBFT...$(RESET)"
	@$(CC) $(CFLAGS) main.c -L. -lft -o $(EXEC)
	@echo "$(NEON_CYAN)👾 Lancement de $(EXEC)...$(RESET)"
	@./$(EXEC)

# .PHONY pour éviter les conflits de noms avec des fichiers
.PHONY: all bonus clean fclean re run
