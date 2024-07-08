/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmuhlber <jmuhlber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:10:12 by jmuhlber          #+#    #+#             */
/*   Updated: 2024/07/08 16:30:27 by jmuhlber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_check_space(const char *str);

int	ft_atoi(const char *str)
{
	long	res;
	int		prefix;

	res = 0;
	prefix = 1;
	while (ft_check_space(str))
		str += 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			prefix = -1;
		str += 1;
	}
	while (ft_isdigit(*str))
	{
		if (res > (LONG_MAX - (*str - '0')))
		{
			if (prefix == 1)
				return (INT_MAX);
			return (INT_MIN);
		}
		res = (res * 10) + (*str - '0');
		str += 1;
	}
	return ((int)(res * prefix));
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

static int	ft_check_space(const char *str)
{
	if (*str == ' ' || *str == '\t'
		|| *str == '\r' || *str == '\n'
		|| *str == '\f' || *str == '\v')
		return (1);
	else
		return (0);
}
