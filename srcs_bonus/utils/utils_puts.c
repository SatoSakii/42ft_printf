/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_puts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:29:05 by albernar          #+#    #+#             */
/*   Updated: 2024/12/05 22:34:44 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_putnstr_fd(char *str, int n, int fd)
{
	int	size;

	if (!str)
		return (0);
	size = ft_strlen(str);
	if (size > n)
		size = n;
	write(fd, str, size);
	return (size);
}

int	ft_putnchar_fd(char c, int n, int fd)
{
	int	i;

	i = 0;
	while (i < n)
	{
		write(fd, &c, 1);
		i++;
	}
	return (i);
}
