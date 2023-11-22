/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamilog <tahasamiloglu@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:25:58 by msamilog          #+#    #+#             */
/*   Updated: 2023/11/22 13:54:11 by msamilog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

void		*ft_memset(void *b, int c, int len);
void		ft_bzero(void *s, int n);
void		*ft_memcpy(void *dest, const void *src, int n);
void		*ft_memccpy(void *dest, const void *src, int c, int n);
void		*ft_memmove(void *dst, const void *src, int len);
void		*ft_memchr(const void *s, int c, int n);
int			ft_memcmp(const void *x1, const void *s2, int n);
int			ft_strlen(const char *x);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, int n);
int			ft_strlcpy(char *dst, const char *src, int dstsize);
int			ft_strlcat(char *dst, const char *src, int dstsize);
char		*ft_strnstr(const char *haystack, const char *needle, int n);
int			ft_atoi(const char *str);
void		*ft_calloc(int count, int size);
char		*ft_strdup(const char *s1);
char		*ft_substr(char const *s, int start, int len);
char		**ft_split(char const *s, char c);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);

#endif
