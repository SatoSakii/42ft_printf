/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 22:04:25 by albernar          #+#    #+#             */
/*   Updated: 2024/12/09 17:58:40 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_writepointer(void *ptr, int is_rec, char *base)
{
	size_t	tmp_ptr;
	size_t	result;

	if (ptr == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	result = 0;
	if (!is_rec)
	{
		ft_putstr_fd("0x", 1);
		result += 2;
	}
	tmp_ptr = (size_t)ptr;
	if (tmp_ptr > 15)
		result += ft_writepointer((void *)(tmp_ptr / 16), 1, base);
	result += 1;
	ft_putchar_fd(base[tmp_ptr % 16], 1);
	return (result);
}

int	ft_putstrr_fd(char *str, int fd)
{
	int	size;

	if (!str)
		str = "(null)";
	size = ft_strlen(str);
	write(fd, str, size);
	return (size);
}

int	ft_putunbr_fd(unsigned int n, int fd)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count += ft_putchar_fd('-', fd);
		count += ft_putunbr_fd(-n, fd);
	}
	else
	{
		if (n > 9)
			count += ft_putunbr_fd(n / 10, fd);
		count += ft_putchar_fd(n % 10 + '0', fd);
	}
	return (count);
}
