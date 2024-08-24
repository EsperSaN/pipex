/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doctype.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:54:38 by pruenrua          #+#    #+#             */
/*   Updated: 2023/05/29 22:25:56 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	do_doctype(char *cutoffstr)
{
	char	*buff;
	int		fd[2];
	int		cflen;

	cflen = ft_strlen(cutoffstr);
	if (-1 == pipe(fd))
	{
		putstr_fd("PIPE ERROR", 2);
		exit(1);
	}
	while (1)
	{
		write(1, "> ", 2);
		buff = get_next_line(0);
		if (0 != cflen && str_n_compare(buff, cutoffstr, cflen))
			break ;
		else if (buff[0] == '\n' && cflen == 0)
			break ;
		write(fd[1], buff, ft_strlen(buff));
		free(buff);
	}
	free(buff);
	close(fd[1]);
	return (fd[0]);
}
