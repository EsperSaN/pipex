/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipework_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:42:49 by pruenrua          #+#    #+#             */
/*   Updated: 2023/05/29 22:25:08 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	dup_write_pipe_to_out(int *pipe)
{
	close(pipe[0]);
	dup2(pipe[1], 1);
	close(pipe[1]);
}

int	open_in_file(char	**argv, t_p *var)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (-1 == fd)
		p_error2_butexit1(errno, var, argv[1]);
	return (fd);
}

void	open_outfile_to_pipe(char *out_path, int *pipe, t_p *var)
{
	int	fd;

	fd = open(out_path, O_RDWR | O_CREAT | O_TRUNC, 0664);
	if (-1 == fd)
		p_error2_butexit1(errno, var, out_path);
	dup2(fd, 1);
	close(fd);
	close(pipe[0]);
	close(pipe[1]);
}

void	create_pipe(t_p *var)
{
	if (-1 == pipe(var->pipe))
		put_error("PIPE", errno, var);
}
