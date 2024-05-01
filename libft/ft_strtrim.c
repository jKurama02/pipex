/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmedyns <anmedyns@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:26:04 by anmedyns          #+#    #+#             */
/*   Updated: 2024/01/12 17:34:25 by anmedyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_char(char c, const char	*set)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(set))
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char	*s1, const char	*set)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*s2;

	if (s1 == NULL || set == NULL)
		return (NULL);
	i = 0;
	len = ft_strlen(s1);
	while (check_char(s1[i], set) == 1)
		i++;
	while (len > i && check_char(s1[len - 1], set) == 1)
		len--;
	s2 = malloc(sizeof(char) * (len - i + 1));
	if (s2 == NULL)
		return (NULL);
	j = 0;
	while (i < len)
	{
		s2[j] = s1[i];
		j++;
		i++;
	}
	s2[j] = '\0';
	return (s2);
}
