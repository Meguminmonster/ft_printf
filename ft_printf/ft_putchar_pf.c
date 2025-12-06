/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedra-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:10:41 by jpedra-v          #+#    #+#             */
/*   Updated: 2025/11/11 15:10:52 by jpedra-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_pf(char c, size_t *counter)
{
	if (*counter == (size_t)-1)
		return ;
	if (write(1, &c, 1) == -1)
	{
		*counter = (size_t) - 1;
		return ;
	}
	(*counter)++;
}
