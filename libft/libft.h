#ifndef libft_h
 #define libft_h

#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(const void *src, int c, unsigned int num);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, unsigned int n);
void	*ft_memmove(void *dst, void const *src, size_t num);
size_t	ft_strlcpy(char *dtn, const char *src, size_t len_dtn);
size_t	ft_strlcat(char *dst, char const *src, unsigned int dstsize);
int		ft_tolower(int c);
int		ft_toupper(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *str, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *str, int c, size_t n);
int		ft_memcmp(const void *str1, const void *str2, size_t n);
char	*ft_strnstr(const char *haystack, const char *neddle, size_t len);
int		ft_atoi(const char	*number);
void 	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s);
char 	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char 	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

#endif