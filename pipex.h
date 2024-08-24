/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:50:25 by pruenrua          #+#    #+#             */
/*   Updated: 2023/05/29 22:09:04 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <errno.h>

typedef struct t_pipe{
	int		pipe[2];
	int		*process_pid;
	int		count;
	char	**envbox;
	int		status;
	int		in_file;
	int		ac;
}	t_p;

/* RUNCMD.c */
void	run_command(char *cmd, char **envbox, int to_input, char **ev);
int		is_execute(char *cmd);

/* ERROR.c */
void	putstr_fd(char *str, int fd);
void	put_error(char *str, int errornum, t_p *var);
void	put_errorcmd(char *str, char *cmd_p, char **cmd_a, int errnum);
void	err_cmd(int	*ecode, int errnum, char *cmd);
void	free_st(t_p *var);
void	p_error2_butexit1(int errornum, t_p *var, char *file);

/* PIPEWORK.c */
int		open_in_file(char	**argv, t_p *var);
void	open_outfile_to_pipe(char *out_path, int *pipe, t_p *var);
void	dup_write_pipe_to_out(int *pipe);
void	change_read_pipe_to_in(int *in_file, int *pipe);
void	create_pipe(t_p *var);

/* PIPEX TOOLS.c */
char	**get_envpath(char **ep);
char	*get_cmdpath(char *command, char **env);
int		find_slash(char *str);

/* HELP.c */
size_t	ft_strlen(const char *s);
int		str_n_compare(const char *s1, const char *s2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	count_on_me(char const *s, char c);
size_t	how_long(char const *s, char c);

/* HELP2.c */
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);

/* FREE.c */
void	free2d(char	**ptr);
void	free_st(t_p *var);

#endif