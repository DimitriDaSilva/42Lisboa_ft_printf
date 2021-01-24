/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 15:39:35 by dda-silv          #+#    #+#             */
/*   Updated: 2021/01/24 09:19:38 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_UTILS_H
# define FT_PRINTF_UTILS_H

# include "ft_printf.h"

void	add_padding(char **nb, int precision);
void	add_sign(char **nb, char *flags);
void	add_hex_prefix(char **nb, char type, char *flags);
int		is_all_zeros(char *nb);
void	add_point(char **nb, t_format *settings);
void	get_exponent(double *nb, char **exponent);
void	add_exponent(char **nb, char **exponent);
void	adjust_rounding(char *nb);
void	increment(char *nb, char sign);

#endif
