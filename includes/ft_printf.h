/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 20:14:55 by albernar          #+#    #+#             */
/*   Updated: 2024/12/09 17:57:56 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../utils/utils.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *s, ...);
int		ft_putstrr_fd(char *str, int fd);
int		ft_putunbr_fd(unsigned int n, int fd);
size_t	ft_writepointer(void *ptr, int is_rec, char *base);
size_t	ft_strlen(const char *s);

#endif
