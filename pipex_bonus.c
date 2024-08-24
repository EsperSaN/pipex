/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:50:36 by pruenrua          #+#    #+#             */
/*   Updated: 2023/05/29 22:45:39 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	var_init(t_p *var, int ac)
{
	int	i;

	i = 0;
	var->ac = ac;
	var->status = 0;
	var->pipe[0] = -1;
	var->pipe[1] = -1;
	var->in_file = -1;
	var->count = 0;
	var->envbox = NULL;
	var->process_pid = malloc(sizeof(int) * ac - 3);
	if (var->process_pid == NULL)
		put_error("Malloc Error SRY", errno, var);
	while (i < ac - 3)
	{
		var->process_pid[i] = -1;
		i++;
	}
}

int	waiting_for_all_child(t_p *var)
{
	var->count = -1;
	while (++var->count < var->ac - 3)
	{
		if (var->process_pid[var->count] != -1)
			waitpid(var->process_pid[var->count], &(var->status), WUNTRACED);
	}
	free_st(var);
	return (WEXITSTATUS(var->status));
}

void	child_pipe_and_run(char	**av, t_p *var, char	**ev)
{
	if (var->count == 0)
		var->in_file = open_in_file(av, var);
	if (var->count == var->ac - 4)
		open_outfile_to_pipe(av[var->ac - 1], var->pipe, var);
	else
		dup_write_pipe_to_out(var->pipe);
	run_command(av[var->count + 2], var->envbox, var->in_file, ev);
}

void	mom_connect_and_go(t_p *var)
{
	if (var->in_file > -1)
		close(var->in_file);
	var->in_file = dup(var->pipe[0]);
	close(var->pipe[0]);
	close(var->pipe[1]);
	var->count++;
}

int	main(int ac, char **av, char **ev)
{		
	t_p	var;

	var_init(&var, ac);
	if (ac < 5)
		put_error("input must be 'infile cmd1 cmd2 cmd.... outfile'", 22, &var);
	var.envbox = get_envpath(ev);
	if (str_n_compare(av[1], "here_doc", 8) && av[2])
	{
		var.in_file = do_doctype(av[2]);
		var.count = 1;
	}
	while (var.count < ac - 3)
	{
		create_pipe(&var);
		var.process_pid[var.count] = fork();
		if (var.process_pid[var.count] == -1)
			put_error("FORK", errno, &var);
		if (var.process_pid[var.count] == 0)
			child_pipe_and_run(av, &var, ev);
		else if (var.process_pid[var.count] > 0)
			mom_connect_and_go(&var);
	}
	return (waiting_for_all_child(&var));
}
