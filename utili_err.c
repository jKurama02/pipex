/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utili_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmedyns <anmedyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:35:29 by anmedyns          #+#    #+#             */
/*   Updated: 2024/05/01 19:28:38 by anmedyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	q_free(const char *error, char *str, char **mat, int err_t)
{
	int	i;

	if (err_t == 1)
		write(2, error, ft_strlen(error));
	else if (err_t == 2)
	{
		free(str);
		write(2, error, ft_strlen(error));
	}
	else if (err_t == 3)
	{
		i = -1;
		while (mat[++i])
			free(mat[i]);
		free(mat);
		write(2, error, ft_strlen(error));
	}
	exit(1);
}

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	temp;

	i = 0;
	j = 0;
	if (!to_find[0] || to_find == NULL)
		return ((char *)(str));
	while (i < len && str[i])
	{
		temp = i;
		while (str[i] == to_find[j] && temp + j < len)
		{
			if (to_find[j + 1] == '\0')
				return ((char *)(str + temp));
			j++;
			i++;
		}
		i = temp + 1;
		j = 0;
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	i;
	size_t	j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	j = 0;
	s3 = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (s3 == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		s3[j++] = s1[i++];
	}
	i = 0;
	while (s2[i] != '\0')
	{
		s3[j++] = s2[i++];
	}
	s3[j] = '\0';
	return (s3);
}
