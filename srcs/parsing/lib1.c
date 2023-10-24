/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabperei <fabperei@student.42nice.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:32:41 by fabperei          #+#    #+#             */
/*   Updated: 2023/10/21 17:31:47 by fabperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cube.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	if (!ft_strlen(s1) || !ft_strlen(s2))
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	while (i < n)
	{
		if (s1[i] == 0 || s2[i] == 0)
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		if (((unsigned char)s1[i] != (unsigned char)s2[i]))
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int	ft_strchr_count(char *s, int c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			count++;
		i++;
	}
	return (count);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	resultat;
	int	nbsigne;

	nbsigne = 1;
	i = 0;
	resultat = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i + 1] == '-' || str[i + 1] == '+')
			return (0);
		if (str[i] == '-')
			nbsigne = nbsigne * -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		resultat = resultat * 10 + str[i] - '0';
		if (!(str[i] >= 48 && str[i] <= 57))
			return (resultat * nbsigne);
		i++;
	}
	return (resultat * nbsigne);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		d;
	int		lentotal;

	i = 0;
	d = 0;
	if (!s1 || !s2)
		return (0);
	lentotal = ft_strlen(s1) + ft_strlen(s2);
	s3 = malloc(sizeof(char) * (lentotal + 1));
	if (!s3)
		return (0);
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[d])
		s3[i++] = s2[d++];
	s3[i] = '\0';
	return (s3);
}
