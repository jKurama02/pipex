/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmedyns <anmedyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:03:41 by anmedyns          #+#    #+#             */
/*   Updated: 2024/01/29 20:03:22 by anmedyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char	*str, int c)
{
	const char	*ptr;

	ptr = NULL;
	while (*str != '\0')
	{
		if (*str == (char)c)
			ptr = str;
		str++;
	}
	if (*str == (char)c)
		return ((char *)str);
	return ((char *)ptr);
}
