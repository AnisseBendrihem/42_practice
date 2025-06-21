/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 20:58:14 by abendrih          #+#    #+#             */
/*   Updated: 2025/05/27 16:47:23 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_convertf(char mod, va_list args);
int	ft_put_unsigned_nbrf(int n);
int	ft_puthexaf(unsigned long nb, int is_mod);
int	ft_putnbrf(int n);
int	ft_putstrf(char *str);
int	ft_putcharf(char c);

#endif