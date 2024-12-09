/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:30:36 by albernar          #+#    #+#             */
/*   Updated: 2024/12/06 20:29:07 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	handle_number(long nbr, char spec, t_flags flags, int *total_len)
{
	char	str[21];

	flags.current_flag = spec;
	if (nbr == 0 && flags.has_precision && flags.precision == 0)
		str[0] = 0;
	else
	{
		if (flags.current_flag == 'd' || flags.current_flag == 'i')
			ft_itoa_b(nbr, str);
		else if (flags.current_flag == 'u')
			ft_uitoa_b(nbr, str);
	}
	apply_flags(str, flags, total_len);
}
