/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_tool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:45:43 by pruenrua          #+#    #+#             */
/*   Updated: 2023/05/25 23:35:07 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	find_slash(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == '/')
			return (1);
		str++;
	}
	return (0);
}

char	**get_envpath(char **ep)
{
	if (!ep)
		return (NULL);
	while (*ep)
	{
		if (str_n_compare(*ep, "PATH=", 5))
			return (ft_split((*ep) + 5, ':'));
		ep++;
	}
	return (NULL);
}

char	*get_cmdpath(char *command, char **env)
{
	int		i;
	char	*prepath;
	char	*path_and_command;
	char	*ready_cmd;

	i = 0;
	if (!command)
		return (NULL);
	if (0 == access(command, X_OK) || env == NULL || find_slash(command))
	{
		ready_cmd = ft_substr(command, 0, ft_strlen(command));
		return (ready_cmd);
	}
	while (env[i])
	{
		prepath = ft_strjoin(env[i], "/");
		path_and_command = ft_strjoin(prepath, command);
		free(prepath);
		if (0 == access(path_and_command, X_OK))
			return (path_and_command);
		free(path_and_command);
		i++;
	}
	return (ft_substr(command, 0, ft_strlen(command)));
}
