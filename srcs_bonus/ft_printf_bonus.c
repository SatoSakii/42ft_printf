/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 20:14:43 by albernar          #+#    #+#             */
/*   Updated: 2024/12/06 22:21:00 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	handle_conversion(char percent, va_list args, t_flags flags,
		int *total_len)
{
	if (percent == 'c')
		handle_char((char)va_arg(args, int), flags, total_len);
	else if (percent == 's')
		handle_string(va_arg(args, char *), flags, total_len);
	else if (percent == 'd' || percent == 'i')
		handle_number(va_arg(args, int), percent, flags, total_len);
	else if (percent == 'u')
		handle_number(va_arg(args, unsigned int), percent, flags, total_len);
	else if (percent == 'p')
		handle_ptr(va_arg(args, void *), percent, flags, total_len);
	else if (percent == 'X' || percent == 'x')
		handle_hex(va_arg(args, unsigned int), percent, flags, total_len);
	else if (percent == 'o')
		handle_oct(va_arg(args, unsigned int), percent, flags, total_len);
	else if (percent == '%')
		*total_len += ft_putchar_fd('%', 1);
}

int	ft_dprintf(int fd, const char *format, va_list args)
{
	t_flags	flags;
	int		total_len;

	total_len = 0;
	flags.fd = fd;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			parse_flags(&format, &flags, args);
			handle_conversion(*format, args, flags, &total_len);
		}
		else
			total_len += ft_putchar_fd(*format, 1);
		format++;
	}
	return (total_len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		total_len;

	va_start(args, format);
	total_len = ft_dprintf(1, format, args);
	va_end(args);
	return (total_len);
}
