/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmassaak <mmassaak@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 10:36:06 by mmassaak          #+#    #+#             */
/*   Updated: 2021/04/13 16:15:45 by mmassaak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ‘ ’ Space character.
** \f Form feed.
** \n New-line.
** \r Carriage return.
** \t Horizontal tab.
** \v And vertical tab.
*/

int	ft_atoi(char *str)
{
	int i;
	int signal;
	int result;

	signal = 1;
	result = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\t' || str[i] == '\v')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signal = signal * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = ((result * 10) + str[i] - '0');
		i++;
	}
	return (result * signal);
}
