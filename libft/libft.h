/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohamdan <sohamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:20:19 by sohamdan          #+#    #+#             */
/*   Updated: 2025/02/17 14:35:54 by sohamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <fcntl.h>  //get_next_line
# include <stdarg.h> //ft_printf
# include <stdlib.h>
# include <string.h> //get_next_line
# include <unistd.h>

//***********************LIBFT***********************************//

/***********************MANDATORY*************************/
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

int					ft_atoi(const char *nptr);

int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);

char				*ft_itoa(int n);
char				*ft_strdup(const char *s);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

char				**ft_split(char const *s, char c);

void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memset(void *s, int c, size_t n);

void				*ft_calloc(size_t nmemb, size_t size);

void				ft_bzero(void *s, size_t n);

void				ft_striteri(char *s, void (*f)(unsigned int, char *));

void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

size_t				ft_strlen(const char *s);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);

/***********************BONUS*************************/

typedef struct s_list
{
	int				index;
	int				content;
	int				cost;
	int				above_half;
	int				cheap;
	struct s_list	*target;
	struct s_list	*next;
	struct s_list	*previous;
}					t_list;

t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

t_list				*ft_lstnew(int content);
t_list				*ft_lstlast(t_list *lst);

int					ft_lstsize(t_list *lst);

void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);

void				ft_lstclear(t_list **lst);
// void	ft_lstiter(t_list *lst, void (*f)(void *));
// void	ft_lstdelone(t_list *lst, void (*del)(void*));

/*********************************************************/

/***********************FT_PRINTF***********************************/

int					ft_printf(const char *s, ...);

/*********************************************************/

/***********************GET_NEXT_LINE***********************************/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef FDS
#  define FDS 1024
# endif

# if BUFFER_SIZE < 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

char				*ft_strndup(const char *s, size_t len);
char				*ft_custom_strchr(const char *s, int c);
char				*get_next_line(int fd);

/*********************************************************/

#endif
