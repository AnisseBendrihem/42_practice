/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 01:31:11 by abendrih          #+#    #+#             */
/*   Updated: 2025/07/10 02:58:08 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

typedef struct s_list
{
	struct s_list	*next;
	void			*data;
}					t_list;

#include "ft_list.h"
#include "stdlib.h"

