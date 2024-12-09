/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:26:06 by albernar          #+#    #+#             */
/*   Updated: 2024/12/06 20:16:05 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	get_nbr_len(long long n)
{
	int	l;

	l = 0;
	if (n < 0)
		n *= -1;
	if (n == 0 || n < 9)
		return (1);
	while (n)
	{
		n /= 10;
		l++;
	}
	return (l);
}

void	ft_itoa_base(unsigned long nbr, char *str, const char *base)
{
	unsigned long	base_len;
	char			buffer[21];
	int				i;

	base_len = ft_strlen(base);
	i = 0;
	if (nbr == 0)
		buffer[i++] = base[0];
	while (nbr > 0)
	{
		buffer[i++] = base[nbr % base_len];
		nbr /= base_len;
	}
	buffer[i] = 0;
	while (--i >= 0)
		*str++ = buffer[i];
	*str = '\0';
}

char	*ft_itoa_b(int n, char *buf)
{
	int	total_len;

	if (n == -2147483648)
		return (ft_memcpy(buf, "-2147483648", 12));
	total_len = get_nbr_len(n) + (n < 0) + 1;
	if (n < 0)
	{
		n = -n;
		*buf = '-';
	}
	if (n == 0)
		*buf = '0';
	*(buf + --total_len) = 0;
	while (n > 0)
	{
		*(buf + --total_len) = n % 10 + '0';
		n /= 10;
	}
	return (buf);
}

char	*ft_uitoa_b(unsigned int n, char *buf)
{
	unsigned int	total_len;

	total_len = get_nbr_len(n) + 1;
	if (n == 0)
		*buf = '0';
	*(buf + --total_len) = 0;
	while (n > 0)
	{
		*(buf + --total_len) = n % 10 + '0';
		n /= 10;
	}
	return (buf);
}

char	*ft_itoa_m(int n)
{
	char	*dest;
	char	*tmp_dest;
	int		total_len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	total_len = get_nbr_len(n) + (n < 0) + 1;
	dest = malloc(sizeof(char) * total_len);
	if (!dest)
		return (NULL);
	tmp_dest = dest;
	if (n < 0)
	{
		n = -n;
		*tmp_dest = '-';
	}
	if (n == 0)
		*tmp_dest = '0';
	*(tmp_dest + --total_len) = 0;
	while (n > 0)
	{
		*(tmp_dest + --total_len) = n % 10 + '0';
		n /= 10;
	}
	return (dest);
}
