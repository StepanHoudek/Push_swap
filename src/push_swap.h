/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoudek <shoudek@student.42.cz>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:07:44 by shoudek           #+#    #+#             */
/*   Updated: 2024/02/14 10:33:19 by shoudek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>

int			ft_lstmin(t_struct *head);
int			ft_lstmax(t_struct *head);
int			ft_lstsize(t_struct *head);
int			ft_lstpricer(t_struct *node, t_struct *head);
int			ft_lstpricerr(t_struct *node, t_struct *tail);
t_struct	*ft_lstfindfit(t_struct *node, t_struct *head);

#endif