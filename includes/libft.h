/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 15:17:22 by unite             #+#    #+#             */
/*   Updated: 2020/03/15 15:37:00 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdarg.h>

# define MININT		-2147483648
# define MAXINT		2147483647

# define MAXLONGLONG	9223372036854775807LL
# define MINLONGLONG	-9223372036854775807LL

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					ft_abs(int n);
int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
int					ft_chrinstr(char c, const char *str);
int					ft_chrisalnum(char c);
int					ft_chrisalpha(char c);
int					ft_chrisdigit(char c);
int					ft_chrisprint(char c);
int					ft_chrisspace(char c);
char				ft_chrtolower(char c);
char				ft_chrtoupper(char c);
void				ft_exit(char *message, int err_code);
size_t				ft_intlen(int num);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_isspace(int c);
char				*ft_itoa(int n);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstappend(t_list **alst, t_list *new);
t_list				*ft_lstcpy(t_list const *alst, void *(*f)(void *));
t_list				*ft_lstcpy_str(t_list const *alst);
t_list				*ft_lstcpyone(t_list const *alst, void *(*f)(void *));
t_list				*ft_lstcpyone_str(t_list const *alst);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel_str(t_list **alst);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone_str(t_list **alst);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstlast(t_list *head);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstncpy(t_list const *alst, int n, void *(*f)(void *));
t_list				*ft_lstncpy_str(t_list const *alst, int n);
t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstnew_empty(void);
t_list				*ft_lstnew_str(char const *str);
t_list				*ft_lstnew_str_empty(size_t content_size);
void				ft_lstrev(t_list **alst);
void				ft_lstrotate(t_list **head);
int					ft_max(int a, int b);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, const void *src, size_t n);
void				*ft_memset(void *b, int c, size_t len);
int					ft_min(int a, int b);
int					ft_power(int num, unsigned int exponent);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnstr(char *s, size_t n);
void				ft_putnstr_fd(int fd, char *s, size_t n);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
int					*ft_range(int lbound, int ubound);
int					ft_sqrt(int num);
int					ft_sqrtceil(int num);
int					ft_strappend(char **str1, char *str2);
char				*ft_strcapitalize(char *str);
char				*ft_strcat(char *s1, const char *s2);
int					ft_strcchr(char const *str, char c);
size_t				ft_strcdigits(char *str);
char				*ft_strchr(const char *s, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
size_t				ft_strcount(const char *str, int (*f)(char));
char				*ft_strcpy(char *dst, const char *src);
void				ft_strdel(char **as);
char				*ft_strdup(const char *s1);
int					ft_strequ(const char *s1, const char *s2);
int					ft_strintab(const char *str, char *const tab[]);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strjoin_variadic(const char *str, ...);
char				ft_strlast(char const *str);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t				ft_strlcpy(char *dst, const char *src, size_t maxlen);
size_t				ft_strlen(const char *s);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmap_inplace(char *str, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *s1, const char *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strndup(const char *s1, size_t len);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnotchr(const char *s, int c);
char				*ft_strnstr(const char *haystack, const char *needle,
								size_t len);
int					ft_strprepend(char **str1, char *str2);
char				*ft_strpsub(const char *start, const char *end);
char				*ft_strrchr(const char *s, int c);
char				*ft_strrev(const char *s);
char				*ft_strrsrch(const char *s, int (*f)(char));
char				**ft_strsplit(char const *str, char delim);
char				*ft_strsrch(const char *s, int (*f)(char));
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
int					ft_sum(int const *tab, size_t len);
int					ft_tolower(int c);
int					ft_toupper(int c);


/*
**
*/

# define BUFF_SIZE	32
# define EOL		'\n'

typedef struct		s_list
					t_list;

typedef struct		s_fd_cache
{
	int				fd;
	t_list			*cache;
}					t_fd_cache;

int					get_next_line(const int fd, char **line);
int					get_next_line_untrim(const int fd, char **line);

/*
**
*/

# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_dprintf(int fd, const char *format, ...);
int	ft_vprintf(const char *format, va_list ap);
int	ft_vdprintf(int fd, const char *format, va_list ap);

#endif
