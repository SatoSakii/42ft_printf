/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:44:29 by albernar          #+#    #+#             */
/*   Updated: 2024/12/09 16:49:28 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <stdlib.h>
# include <unistd.h>

int		ft_atoi(const char *str, int *is_overflow);
void	ft_itoa_base(unsigned long nbr, char *str, const char *base);
char	*ft_itoa_b(int n, char *buf);
char	*ft_uitoa_b(unsigned int n, char *buf);
char	*ft_itoa_m(int n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
int		ft_putchar_fd(char c, int fd);
int		ft_putnbr_fd(int n, int fd);
int		ft_putstr_fd(char *s, int fd);
char	*ft_strdup(const char *src);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);

#endif
