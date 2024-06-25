/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comando.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmedyns <anmedyns@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:58:35 by anmedyns          #+#    #+#             */
/*   Updated: 2024/06/25 19:01:16 by anmedyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	eseguibile(char *argv, char **envp)
{
	char	**comando;
	char	*cerca_path;
	int		i;

	i = 0;
	comando = ft_split(argv, ' ');
	cerca_path = to_p(comando[0], envp);
	if (!cerca_path)
	{
		while (comando[i])
		{
			free(comando[i]);
			i++;
		}
		free(comando);
		perror("Errore ricerca path");
	}
	if (execve(cerca_path, comando, envp) == -1)
		perror("Errore");
}

char	*to_p(char *comando, char **envp)
{
	char	**total_path;
	char	*path1;
	char	*path2;
	int		i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	total_path = ft_split(envp[i] + 5, ':');
	i = 0;
	while (total_path[i])
	{
		path1 = ft_strjoin(total_path[i], "/");
		path2 = ft_strjoin(path1, comando);
		free(path1);
		if (access(path2, F_OK) == 0)
			return (path2);
		free(path2);
		i++;
	}
	i = 0;
	while (total_path[i++])
		free(total_path[i]);
	free(total_path);
	return (0);
}
