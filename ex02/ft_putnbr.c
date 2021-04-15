/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmassaak <mmassaak@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 10:22:03 by mmassaak          #+#    #+#             */
/*   Updated: 2021/04/13 19:50:23 by mmassaak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void				ft_putnbr(int nb)
{
	unsigned int	num;
	char			num_as_char;

	if (nb < 0)
	{
		write(1, "-", 1);
		num = nb * -1;
	}
	else
		num = nb;
	if (num >= 10)
		ft_putnbr(num / 10);
	num_as_char = num % 10 + '0';
	write(1, &num_as_char, 1);
}
