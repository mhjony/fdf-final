/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhasan <mhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:59:04 by ismelich          #+#    #+#             */
/*   Updated: 2020/02/05 19:24:16 by mhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>

char	*ft_strdup(const char *src);
char	*ft_strncpy(char *dst, const char *src, size_t len);
char	*ft_strncat(char *dest, const char *src, size_t n);
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
char	*ft_strstr(const char *str, const char *search_string);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strnew(size_t size);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strcpy(char *dest, const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s);
char	**ft_strsplit(char const *s, char c);
char	*ft_strndup(const char *str, size_t len);
char	*ft_itoa(int n);
char	*ft_strmap(char const *s, char (*f)(char));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		ft_isspace(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_isprint(int c);
int		ft_isalpha(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_memcmp(const void *str1, const void *str2, size_t n);
int		ft_strequ(char const *s1, char const *s2);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
int		ft_isblank(int c);
int		ft_islower(int c);
int		ft_isupper(int c);
void	ft_putchar(char c);
void	ft_putstr(char const *str);
void	ft_putnbr(int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char const *str, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putendl(char const *str);
void	ft_putendl_fd(char const *str, int fd);
void	*ft_memset(void *str, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *str1, const void *str2, size_t n);
void	*ft_memccpy(void *str1, const void *str2, int c, size_t n);
void	*ft_memmove(void *str1, const void *str2, size_t n);
void	*ft_memchr(const void *str, int c, size_t n);
void	*ft_memalloc(size_t size);
void	ft_memdel(void **ap);
void	ft_strclr(char *s);
void	ft_strdel(char **as);
void	ft_striter(char *s, void (*f)(char *));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
size_t	ft_strlcat(char *dest, const char *src, size_t destsize);
size_t	ft_strlen(const char *str);
int		ft_words_counter(char *str);
int		ft_abs(int n);

#endif
