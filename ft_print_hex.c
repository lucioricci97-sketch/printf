/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luricci <luricci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 17:24:00 by luricci           #+#    #+#             */
/*   Updated: 2025/12/18 17:52:40 by luricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned long long num, const char format)
{
	int	len;

	len = 0;
	if (num >= 16)
		len += ft_print_hex(num / 16, format);
	if (format == 'x')
		len += ft_printchar("0123456789abcdef"[num % 16]);
	else if (format == 'X')
		len += ft_printchar("0123456789ABCDEF"[num % 16]);
	return (len);
}

int	ft_print_ptr(unsigned long long ptr)
{
	int	len;

	len = 0;
	if (ptr == 0)
		return (ft_printstr("(nil)"));
	len += ft_printstr("0x");
	len += ft_print_hex(ptr, 'x');
	return (len);
}
