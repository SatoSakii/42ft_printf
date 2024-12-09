/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 00:01:58 by albernar          #+#    #+#             */
/*   Updated: 2024/12/09 16:45:15 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	size;

	if (!s || !fd)
		return (0);
	size = ft_strlen(s);
	write(fd, s, size);
	return (size);
}
