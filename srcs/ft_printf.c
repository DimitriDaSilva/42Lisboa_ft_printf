/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 21:47:48 by dda-silv          #+#    #+#             */
/*   Updated: 2021/01/20 15:44:54 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Implementation of printf
** @param:	- [const char *] string inputted with specified formats
**			- [...] variadic arguments that refer to the specifiied formatj
** @return:	[int] number of printed characters
** Line-by-line comments:
** @8		The address of fmt is passed so that subsequent functions can
** 			increment through the fmt string
** @12		When finding a format specifier like %-10d, the subsequent
** 			functions increment through "%-10" while here 'd' is incremented
*/

int	ft_printf(const char *fmt, ...)
{
	int		nb_printed_chars;

	nb_printed_chars = 0;
	va_start(g_arg_list, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
			nb_printed_chars += convert(&fmt);
		else
			nb_printed_chars += ft_putchar(*fmt);
		fmt++;
	}
	va_end(g_arg_list);
	return (nb_printed_chars);
}

/*
** Traverses fmt to get the settings and prints the output
** @param:	- [const char *] string inputted with specified formats
** @return:	[type] return_value
*/

int	convert(const char **fmt)
{
	int			nb_printed_chars;
	t_format	settings;

	(*fmt)++;
	nb_printed_chars = 0;
	get_settings(fmt, &settings);
	nb_printed_chars = print(&settings);
	return (nb_printed_chars);
}
