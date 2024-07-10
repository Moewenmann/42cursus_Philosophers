/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmuhlber <jmuhlber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:10:12 by jmuhlber          #+#    #+#             */
/*   Updated: 2024/07/10 13:41:56 by jmuhlber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	phl_check_space(const char *str);

int	phl_atoi(const char *str)
{
	long	res;
	int		prefix;

	res = 0;
	prefix = 1;
	while (phl_check_space(str))
		str += 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			prefix = -1;
		str += 1;
	}
	while (phl_isdigit(*str))
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

int	phl_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	phl_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	const unsigned char	*s1_uns;
	const unsigned char	*s2_uns;

	s1_uns = (const unsigned char *)s1;
	s2_uns = (const unsigned char *)s2;
	i = 0;
	while (*s1_uns && *s1_uns == *s2_uns && i < n)
	{
		s1_uns += 1;
		s2_uns += 1;
		i += 1;
	}
	if (n == i)
		return (0);
	return (*s1_uns - *s2_uns);
}

size_t	phl_strlen(const char *c)
{
	size_t	len;

	len = 0;
	while (c[len] != '\0')
		len += 1;
	return (len);
}

static int	phl_check_space(const char *str)
{
	if (*str == ' ' || *str == '\t'
		|| *str == '\r' || *str == '\n'
		|| *str == '\f' || *str == '\v')
		return (1);
	else
		return (0);
}
