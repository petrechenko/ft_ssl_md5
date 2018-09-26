/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 13:03:13 by apetrech          #+#    #+#             */
/*   Updated: 2018/09/24 20:48:12 by apetrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <wchar.h>
# include <fcntl.h>

# define BUFF_SIZE 5000
# define LIMIT 4864
# define INT char *tmp;int nl

typedef struct		s_flag
{
	int				minus;
	int				plus;
	int				space;
	int				zero;
	int				hashtag;
}					t_flag;

typedef struct		s_format
{
	char			convert;
	char			*length;
	int				width;
	int				len;
	int				dot;
	int				precision;
	t_flag			flag;
}					t_format;

typedef char		*(*t_fun)(t_format*, va_list*);

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					ft_atoi(const char *str);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strchr(const char *s, int c);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *s1, const char *s2);
char				*ft_strdup(const char *src);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *str);
char				*ft_strncat(char *dest, const char *src, size_t nb);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strstr(const char *str, const char *to_find);
char				*ft_strnstr(const char *str1, const char *str2, size_t len);
char				*ft_strrchr(const char *s, int c);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
int					ft_tolower(int c);
int					ft_toupper(int c);
void				*ft_bzero(void *s, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(long long number);
void				ft_strrev(char *s);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_swap(int *a, int *b);
int					ft_iterative_factorial(int nb);
int					ft_recursive_factorial(int nb);
char				*ft_itoa_base_uns(unsigned long long value,
		int base, char c);
char				*ft_itoa_base_extra(uint32_t n, int base);
char				*ft_itoaf(uintmax_t n);
int					ft_new_line(const int fd, char **line, int r, char **s);
int					get_next_line(const int fd, char **line);

char				*ft_print_char(t_format *format, va_list *arg);
char				*ft_print_str(t_format *format, va_list *arg);
char				*ft_print_nbr(t_format *format, va_list *arg);
char				*ft_print_unbr(t_format *format, va_list *arg);
char				*ft_print_hex(t_format *format, va_list *arg);
char				*ft_print_octal(t_format *format, va_list *arg);
char				*ft_print_point(t_format *format, va_list *arg);
char				*ft_print_wstr(t_format *format, va_list *arg);
char				*ft_print_binary(t_format *format, va_list *arg);
size_t				ft_wstrlen(unsigned *str);
t_flag				ft_firstflags(char *format, size_t *i);
long long			ft_convertflags(t_format *format, va_list *arg);
unsigned long long	ft_uconvertflags(t_format *format, va_list *arg);
int					ft_flag_width(char *format, size_t *i,
					va_list *arg, t_format *star);
char				*ft_length(char *format, size_t *i);
int					ft_precision(char *format, size_t *i,
					va_list *arg, t_format *conv);
t_format			*ft_flags(char *format, va_list *arg, size_t *i);
int					ft_type(t_format *format, va_list *arg);
t_fun				ft_function(char c);
void				ft_delmem(t_format *array);
int					ft_printf(char *format, ...);

#endif
