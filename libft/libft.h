/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jogomes- <leugim3005@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:25:26 by jogomes-          #+#    #+#             */
/*   Updated: 2023/03/28 14:11:51 by jogomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include	<stdlib.h>
# include	<unistd.h>
# include	<stdarg.h>

int				ft_atoi(const char *nptr);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t nmemb, size_t size);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
char			*ft_itoa(int n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memset(void *s, int c, size_t n);
void			ft_putchar_fd(char s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);
char			**ft_split(char const *s, char c);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s);
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strjoin(char *s1, char *s2);
unsigned int	ft_strlcat(char *dest, const char *src, size_t size);
unsigned int	ft_strlcpy(char *dest, const char *src, size_t size);
unsigned int	ft_strlen(const char *s);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(const char *big, const char *little, size_t len);
char			*ft_strrchr(const char *s, int c);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				ft_tolower(int c);
int				ft_toupper(int c);
char			*ft_itoa_pos(long n);
char			*ft_itoa_hex(unsigned long nbr, char *base, char letter);
int				ft_printf(const char *string, ...);
int				ft_alloc_space(char const *s, char c);
void			ft_swap(int *a, int *b);
char			*get_next_line(int fd, int buffer);
char			*ft_strjoin_free(char *s1, char *s2);
#endif