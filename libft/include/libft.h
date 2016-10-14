/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 21:55:08 by auverneu          #+#    #+#             */
/*   Updated: 2016/10/12 18:19:28 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <wchar.h>

/*
** Wide char related macros:
** 0x00 = 0b00000000
** 0x80 = 0b10000000
** 0xC0 = 0b11000000
** 0xE0 = 0b11100000
** 0xF0 = 0b11110000
*/
# define FT_WC_BIS		0x80
# define FT_WC_MASK		"\x00\xC0\xE0\xF0"

/*
** Hexadecimals digits:
*/
# define FT_XDIGIT		"0123456789ABCDEFabcdef"

/*
** Buffer size for GNL:
*/
# define FT_GNL_BUFF	32

/*
** Macros stringification:
*/
# define FT_STR(s)		#s
# define FT_XSTR(s)		FT_STR(s)

/*
** Chained list typedef:
*/
typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
** File descriptor used in get next line:
*/
typedef struct		s_fd
{
	char			*strt;
	char			*buff;
	int				fd;
	struct s_fd		*next;
}					t_fd;

/*
** Prototypes
*/
void				*ft_bzero(void *s, size_t n);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memset_int(void *b, int c, size_t len);

void				ft_free_2d_arr(void **arr, size_t n);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_memdel(void **ap);
void				ft_strclr(char *s);
void				ft_strdel(char **as);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));

char				**ft_strsplit(const char *s, char c);

char				*ft_arrjoin(char **arr, size_t size);
char				*ft_itoa_base(unsigned int n, unsigned int base);
char				*ft_itoa(int n);
char				*ft_strcasestr(const char *s1, const char *s2);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strdup(const char *s1);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strmap(const char *s, char (*f)(char));
char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strndup(const char *s1, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnrev(char *s, size_t begin, size_t end);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strrchr(const char *s, int c);
char				*ft_strrev(char *s);
char				*ft_strrot(char *str, ssize_t n);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strsub(const char *s, unsigned int start, size_t len);
char				*ft_strtolower(char *s);
char				*ft_strtoupper(char *s);
char				*ft_strtrim(const char *s);
char				*ft_strxjoin(char *mode, ...);

int					ft_atoi(const char *str);
int					ft_caseeq(char c1, char c2);
int					ft_gnl(const int fd, char **line);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_islower(int c);
int					ft_ispow2(int n);
int					ft_isprint(int c);
int					ft_isspace(int c);
int					ft_isupper(int c);
int					ft_match(char *s1, char *s2);
int					ft_max(int a, int b);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_min(int a, int b);
int					ft_nmatch(char *s1, char *s2);
int					ft_pow(int nb, int pw);
int					ft_putchar_fd(int c, int fd);
int					ft_putchar(int c);
int					ft_replace(char *str, char repl, char sub, size_t len);
int					ft_sqrt(int n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strequ(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strnequ(const char *s1, const char *s2, size_t n);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_wclen(wchar_t wc);
int					ft_wctomb(char *s, wchar_t wchar);

unsigned int		ft_abs(int n);
unsigned int		ft_atoi_base(const char *str, unsigned int base);

size_t				ft_bitlen(unsigned long long nb);
size_t				ft_ilen(int x);
size_t				ft_ilen_base(unsigned int x, unsigned int base);
size_t				ft_putendl_fd(const char *s, int fd);
size_t				ft_putendl(const char *s);
size_t				ft_putnbr_fd(int n, int fd);
size_t				ft_putnbr(int n);
size_t				ft_putstr_fd(const char *s, int fd);
size_t				ft_putstr(const char *s);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *s);
size_t				ft_strnlen(const char *s, size_t maxlen);
size_t				ft_wcslen(const wchar_t *wcs);
size_t				ft_wcsstrlen(const wchar_t *wcs);

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(const void *content, size_t content_size);

#endif
