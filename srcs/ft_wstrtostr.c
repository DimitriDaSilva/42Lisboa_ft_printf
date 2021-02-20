/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrtostr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 17:39:08 by dda-silv          #+#    #+#             */
/*   Updated: 2021/02/20 13:22:28 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Useful resource for wide characters: https://en.wikipedia.org/wiki/UTF-8
*/

/*
** Converts wide char string to single char string
** @param:	- [char *] dest string with wstr_len + 1 char preallocated
**			- [wchar_t *] wide char string to be converted
**			- [size_t] length in chars of a wide char string. Result of
**					   ft_wstrlen(wstr)
** @return:	[v] return_value
** Line-by-line comments:
** @7		Each wide char can have from 1 to 4 bytes. While a single char is
**			1 byte
** @11		wc_len chars will be copied to s so we need to move that many
**			addresses 
*/

void	ft_wstrtostr(char *s, wchar_t *wstr, size_t wstr_len)
{
	size_t	i;
	size_t	wc_len;

	i = 0;
	while (*wstr && i < wstr_len)
	{
		wc_len = ft_wcharlen(*wstr);
		ft_wctostr(s, *wstr++, wc_len);
		i += wc_len;
		s += wc_len;
	}
}
