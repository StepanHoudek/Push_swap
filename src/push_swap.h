/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoudek <shoudek@student.42.cz>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:07:44 by shoudek           #+#    #+#             */
/*   Updated: 2024/02/14 13:55:29 by shoudek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>

int			ft_lstmin(t_str *head);
int			ft_lstmax(t_str *head);
int			ft_lstsize(t_str *head);
int			ft_lstpricer(t_str *node, t_str *head);
int			ft_lstpricerr(t_str *node, t_str *tail);
t_str	*ft_lstfindfit(t_str *node, t_str *head);

#endif