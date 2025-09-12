/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 22:28:04 by abendrih          #+#    #+#             */
/*   Updated: 2025/07/09 23:16:44 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

#include "stdlib.h"
typedef struct s_list
{
	struct s_list	*next;
	void			*data;
}					t_list;

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(void *, void *));
void	ft_list_foreach(t_list *begin_list, void (*f)(void *));
t_list	*sort_list(t_list *lst, int (*cmp)(int, int));
int	ft_list_size(t_list *begin_list);



#endif