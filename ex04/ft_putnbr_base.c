/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmassaak <mmassaak@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 12:59:30 by mmassaak          #+#    #+#             */
/*   Updated: 2021/04/13 16:09:41 by mmassaak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int				str_len(char *str)
{
	int			i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void			ft_putchar(char c)
{
	write(1, &c, 1);
}

int				ft_base_has_only_diff_chars(char *base)
{
	int		i;
	int		j;

	i = 0;
	while (base[i] != '\0')
	{
		j = 0;
		while (base[j] != '\0')
		{
			if (i != j && base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int				ft_base_has_signal_symbol(char *base)
{
	int i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (1);
		i++;
	}
	return (0);
}

void			ft_putnbr_base(int nbr, char *base)
{
	unsigned int	base_num;
	int				converted_num;
	unsigned int	num;

	base_num = str_len(base);
	if (base_num <= 1 || !ft_base_has_only_diff_chars(base) ||
		ft_base_has_signal_symbol(base))
		return ;
	if (nbr < 0)
	{
		ft_putchar('-');
		num = nbr * -1;
	}
	else
		num = nbr;
	if (num >= base_num)
		ft_putnbr_base(num / base_num, base);
	converted_num = num % base_num;
	ft_putchar(base[converted_num]);
}
