/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoudek <shoudek@student.42.cz>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:14:50 by shoudek           #+#    #+#             */
/*   Updated: 2024/02/14 11:26:59 by shoudek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_struct
{
	int				x;
	struct s_struct	*next;
	struct s_struct	*prev;
	int				r_price;
	int				rr_price;
	struct s_struct	*node_b;
	int				push_price;
}					t_struct;

void				ft_bzero(void *s, size_t n);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memset(void *s, int c, size_t n);
size_t				ft_strlen(const char *s);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strncmp(char *s1, char *s2, unsigned int n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);
int					ft_atoi(const char *s);
void				*ft_calloc(size_t nmemb, size_t size);
char				*ft_strdup(const char *src);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(const char *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putchar_c(char c, int *ptr_sum);
void				ft_puthex(uintptr_t num, const char *format, int *ptr_sum);
void				ft_putnbr_c(int n, int *ptr_sum);
void				ft_putstr_c(char *s, int *ptr_sum);
void				ft_putunsnbr(unsigned int n, int *ptr_sum);
const char			*ft_format(const char *format, int *ptr_sum, va_list args);
void				ft_handleptr(uintptr_t num, const char *format,
						int *ptr_sum);
int					ft_printf(const char *format, ...);
void				ft_to_binary(unsigned int num);
void				ft_lstadd_after(t_struct *node, int value);
void				ft_lstadd_end(t_struct **root, int value);
void				ft_lstadd_start(t_struct **root, int value);
void				ft_lstdeallocate(t_struct **root);
void				ft_dublstinit(t_struct **tail, t_struct **head, int value);
void				ft_dublstadd_end(t_struct **head, int value);
void				ft_dublstadd_start(t_struct **tail, int value);
void				ft_dublstdeallocate(t_struct **tail, t_struct **head);
#endif
