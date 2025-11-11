/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedra-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 12:37:49 by jpedra-v          #+#    #+#             */
/*   Updated: 2025/11/10 13:10:33 by jpedra-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_select_format(va_list argument, const char word);

int	ft_print_character(int character)
{
	write(1, &character, 1);
	return (1);
}

int	ft_printf(const char *str, ...)
{
	va_list	argument;
	int		i;
	int		size;

	i = 0;
	size = 0;
	va_start(argument, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			size += ft_select_format(argument, str[i + 1]);
			i++;
		}
		else
		{
			size += ft_print_characters(str[i]);
			i++;
		}
	}
	va_end(argument);
	return (size);
}
// ... means it accepst a variable number of arguments

static int	ft_select_format(va_list argument, const char word)
{
	int	size;

	size = 0;
	if (word == 'c')
		size += ft_print_character(va_arg(argument, int));
	else if (word == 's')
		size += ft_print_string(va_arg(argument, char *));
	else if (word == 'p')
		size += ft_print_pointer(va_arg(argument, unsigned long long));
	else if (word == 'd' || word == 'i')
		size += ft_print_number(va_arg(argument, int));
	else if (word == 'u')
		size += ft_print_unsigned(va_arg(argument, unsigned int), word);
	else
		size += ft_print_character(word);
	return (size);
}
