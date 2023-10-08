/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptungbun <ptungbun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:55:20 by nkietwee          #+#    #+#             */
/*   Updated: 2023/10/08 20:41:08 by ptungbun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

typedef struct s_dict t_dict;
typedef struct s_dict_value t_dict_value;

// typedef struct s_data t_data;
#include <stdlib.h>

// void	ft_putstr_fd(char *str, int fd);
// char	**ft_split(char const *s, char c);
// char	*ft_strdup(char *str);
// char	*ft_strjoinextra(char *str1, char *str2, int nbr_free);
// int		ft_strlen(char *str);
// int		ft_strcmp(char *s1, char *s2);
// int     ft_isalpha(int c);

// /*link list*/
// t_dict	*ft_lstnew(void *content);
// void	ft_lstadd_front(t_dict **lst, t_dict *new);
// void	ft_lstadd_back(t_dict **lst, t_dict *new);
// t_dict	*ft_lstlast(t_dict *lst);

// int		ft_lstsize(t_dict *lst);
// // int	ft_lstsize(void *lst);

// typedef struct s_list
// {
// 	void			*data;
// 	struct s_list	*next;
// }					t_list;

int					ft_issign(int c);
int					ft_isspace(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isascii(int c);
int					ft_isalnum(int c);
int					ft_isprint(int c);
char				*ft_itoa(int n);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);

int					ft_lstsize(t_list *lst);
int					ft_lstsize_dict(t_dict *lst);

int				ft_strlen(const char *str);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);

void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_bzero(void *b, size_t len);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_calloc(size_t nmemb, size_t size);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_striteri(char *s, void (*f)(unsigned int, char*));
void				ft_freesplite(char **split);

char				*ft_strdup(const char *s);
char				*ft_substr(char *s, unsigned int start, size_t len);
char				**ft_split(char const *s, char c);
char				**ft_split_allsp(char const *s);

t_list				*ft_lstnew(void *content);
t_dict				*ft_lstnew_dict(void *content);

t_list				*ft_lstlast(t_list *lst);


t_list				*ft_lstmap(t_list *lst, void *(*f)(void *), \
					void (*del)(void *));
t_list				*ft_lstpop_top(t_list **lst);
t_list				*ft_lstpop_bot(t_list *lst);

void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_front_dict(t_dict **lst, t_dict *new);

void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstadd_back_dict(t_dict **lst, t_dict *new);

void				ft_lstdelone(t_list *lst, void (*del)(void*));
void				ft_lstclear(t_list **lst, void (*del)(void*));
void				ft_lstiter(t_list *lst, void (*f)(void *));

long				ft_atol(const char *str);
int					ft_strcmp(char *s1, char *s2);
char	*ft_strjoinextra(char *str1, char *str2, int nbr_free);
char	*ft_strjoin(char const *s1, char const *s2);

#endif