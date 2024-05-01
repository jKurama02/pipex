/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmedyns <anmedyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:57:37 by anmedyns          #+#    #+#             */
/*   Updated: 2024/05/01 19:23:41 by anmedyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>
# include <string.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "libft/libft.h"

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnstr(const char *str, const char *to_find, size_t len);
size_t	ft_strlen(const char	*str);
int		q_free(const char *error, char *str, char **mat, int err_t);
char	*to_p(char *comando, char **envp);
void	eseguibile(char *argv, char **envp);
void	child_pro(char **argv, char **envp, int *fd);
void	parent_pro(char **argv, char **envp, int *fd);
char	**ft_split(const char *s, char c);
size_t	get_words(const char *s, char c);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strdup(const char *src);

#endif
