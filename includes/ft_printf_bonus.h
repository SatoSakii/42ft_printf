/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 22:05:43 by albernar          #+#    #+#             */
/*   Updated: 2024/12/06 22:23:41 by albernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H
# include "../utils/utils.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_flags
{
	char	current_flag;
	int		fd;
	int		left_align;
	int		zero_pad;
	int		width;
	int		precision;
	int		has_precision;
	int		hash;
	int		space;
	int		plus;
}			t_flags;

int			ft_dprintf(int fd, const char *format, va_list args);
int			ft_printf(const char *format, ...);

// Utils
int			ft_putnchar_fd(char c, int n, int fd);
int			ft_putnstr_fd(char *str, int n, int fd);

// Flags
void		apply_flags(char *str, t_flags flags, int *total_len);
void		parse_flags(const char **format, t_flags *flags, va_list args);
int			handle_output(char *str, t_flags flags);
int			calculate_precision_zeros(t_flags flags, int size);
int			handle_sign_and_prefix(char **str, t_flags flags, int *total_len);
int			calculate_padding_size(t_flags flags, int size, char *str);

// Conversions
void		handle_char(char c, t_flags flags, int *total_len);
void		handle_string(char *str, t_flags flags, int *total_len);
void		handle_number(long nbr, char spec, t_flags flags, int *total_len);
void		handle_ptr(void *ptr, char spec, t_flags flags, int *total_len);
void		handle_hex(unsigned int nbr, char spec, t_flags flags,
				int *total_len);
void		handle_oct(unsigned int nbr, char spec, t_flags flags,
				int *total_len);

#endif
