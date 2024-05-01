/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmedyns <anmedyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:15:43 by anmedyns          #+#    #+#             */
/*   Updated: 2024/05/01 19:22:37 by anmedyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_pro(char **argv, char **envp, int *fd)
{
	int	fd_file_in;

	fd_file_in = open(argv[1], O_RDONLY, 0777);
	if (fd_file_in == -1)
		q_free("Errore apertura file\n", NULL, NULL, 1);
	close(fd[0]);
	dup2(fd_file_in, 0);
	close(fd_file_in);
	dup2(fd[1], 1);
	close(fd[1]);
	eseguibile(argv[2], envp);
}

void	parent_pro(char **argv, char **envp, int *fd)
{
	int	fd_file_out;

	fd_file_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd_file_out == -1)
		q_free("Errore apertura file\n", NULL, NULL, 1);
	close(fd[1]);
	dup2(fd[0], 0);
	close(fd[0]);
	dup2(fd_file_out, 1);
	close(fd_file_out);
	eseguibile(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			q_free("Errore durante fork\n", NULL, NULL, 1);
		pid = fork();
		if (pid == 0)
			child_pro(argv, envp, fd);
		else
		{
			waitpid(pid, NULL, 0);
			parent_pro(argv, envp, fd);
		}
	}
	else
		q_free("Errore\n", NULL, NULL, 1);
}
