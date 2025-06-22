# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/30 20:38:49 by abendrih          #+#    #+#              #
#    Updated: 2025/05/27 17:03:20 by abendrih         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nom du programme de test
EXEC = main

# Nom de la librairie
NAME = libftprintf.a 

# Fichiers source
SRC = ft_printf.c ft_convertf.c ft_put_unsigned_nbrf.c ft_putnbrf.c ft_putstrf.c \
	 ft_puthexaf.c ft_putcharf.c

# Fichiers objets
OBJ = $(SRC:.c=.o)

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
	@echo "$(NEON_GREEN)💾 [SYSTEM] Compilation de Printf... [OK]$(RESET)"

# Création de la librairie
$(NAME): $(OBJ)
	@echo "$(NEON_CYAN)🔧 Forge de la librairie $(NAME)...$(RESET)"
	@ar rcs $(NAME) $(OBJ)

# Nettoyage des fichiers objets
clean:
	@echo "$(NEON_PURPLE)🧽 Nettoyage des fichiers .o...$(RESET)"
	@rm -f $(OBJ)

# Nettoyage complet
fclean: clean
	@echo "$(NEON_PINK)💣 Destruction totale de Print_f...$(RESET)"
	@rm -f $(NAME) $(EXEC)

# Recompilation from scratch
re: fclean all

# Exécution de main.c avec la lib
run: all
	@echo "$(NEON_GREEN)⚙️  Compilation de $(EXEC) avec Print_f...$(RESET)"
	@$(CC) $(CFLAGS) main.c -L. -lftprintf -o $(EXEC)
	@echo "$(NEON_CYAN)👾 Lancement de $(EXEC)...$(RESET)"
	@./$(EXEC)

# .PHONY pour éviter les conflits de noms avec des fichiers
.PHONY: all clean fclean re run
