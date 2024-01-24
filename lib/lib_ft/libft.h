/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:07:18 by anboisve          #+#    #+#             */
/*   Updated: 2024/01/24 17:57:53 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>
# include "index.h"
# include "ft_printf.h"

# define HEX_TABLE "0123456789abcdef"
# define DOLAR_LIST "_"
# define RETURN_PTR_MAX 20

//made by @sm222
//char		\verification

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isascii(int c);
int			ft_isalnum(int c);
int			ft_isprint(int c);
int			ft_isprint(int c);
int			ft_isspace(int c);
short		ft_set_mode(char c);

//char				\modify

int			ft_tolower(int c);
int			ft_toupper(int c);

//str												\manipulation

char		*ft_strdup(const char *s1);
char		*get_env(char **en, char *seed);
char		*ft_strdup_c(const char *str, char c);
char		*ft_strncpy(const char *str, size_t i);
char		*ft_strndup(const char *str, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
char		*ft_substr(char const *s, unsigned int start, size_t len);
void		ft_change_dolar(char **old, char **en, short here_doc, int err);

//str															\compare

size_t		ft_strlen(const char *s);
size_t		ft_strlen_double(char **s);
char		*ft_find_char(char *s, int c);
char		*ft_rfind_char(char *s, int c);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strcmp(const char *s1, const char *s2);
short		ft_ban(const char *src, const char *list);
short		ft_find(const char *src, const char *filter);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		**ft_cpy_double_char(char **str);
char		*ft_combine(char *s, va_list arg);

//memory										\manipulation

void		*ft_free(void *p);
void		ft_bzero(void *s, size_t n);
void		**ft_double_sfree(void **ptr);
void		*ft_return_ptr(void *ptr, int i);
void		*ft_calloc(size_t count, size_t size);
void		*ft_memset(void *b, int c, size_t len);
void		*ft_memchr(const void *s, int c, size_t n);
char		**ft_str_split(const char *s, char **list);
void		*ft_memcpy(void *dst, const void *src, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_realloc(void *old, size_t count, size_t size, size_t new_size);

//output								//

int			ft_putchar_fd(char c, int fd);
int			ft_putstr_fd(char *s, int fd);
int			ft_putnbr_fd(int n, int fd);
int			ft_putendl_fd(char *s, int fd);
char		*ft_make_color(short r, short g, short b);

//b_flag								//

void		ft_b_print(int f, int fd);
short		ft_b_flag_read(int flag, int byte);
void		ft_b_toggle_flag(int *flag, int pos);
void		ft_b_set_flag(int *flag, int pos, char tf);

//conversion							//

int			ft_atoi(const char *str);
long long	ft_atoll(const char *s);
char		*ft_itoa(int n);
char		**ft_split(char const *s, char c);

//fd									//

int			ft_close_fds(int **fds, int f_ptr, int size);

//bonus									//

//minishell								//

int			ft_find_doc(char *s, size_t len);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstnew(void *content);
void		ft_lstadd_back(t_list **lst, t_list *neww);
void		ft_lstadd_front(t_list **lst, t_list *neww);
void		ft_lstiter(t_list *lst, void (*f)(void *));
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

//GNL									//

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 10240
# endif

/*
# if __MACH__
#  define PTR_SIZE unsigned long
# else if
#  define PTR_SIZE unsigned long long
# endif
*/

typedef struct s_info
{
	char	*tmp;
	char	*tmp2;
	int		rv;
	size_t	cut;
}	t_info;

char		*get_next_line(int fd);
char		*ft_strfjoin(char *s1, char *s2);

#endif
