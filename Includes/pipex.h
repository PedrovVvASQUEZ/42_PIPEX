/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:18:31 by pgrellie          #+#    #+#             */
/*   Updated: 2024/07/19 21:26:46 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/***********************/
/*  LIBRARIES IMPORTS  */
/***********************/

# include "../Libraries/pedro_lib/pedro_lib.h"
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <signal.h>
# include <errno.h>

/************************/
/*      STRUCTURES      */
/************************/

typedef struct s_pipex
{
	pid_t		pipefd[2];
	int			cmd_count;
	int			*pid;
	int			previousfd;
	char		**cmds;
	char		**envi;
	char		*infile;
	char		*outfile;
	int			fd_in;
	int			fd_out;
}				t_pipex;

/************************/
/*	    PROTOTYPES	    */
/************************/

char	*cmd_path(char **envi, char *cmd);
char	*find_env(char **pathsss, char *cmd);
void	file_opener(t_pipex *p, int i_o);
int		exit_brr(int code);
void	child_process(t_pipex *p, int x);
void	cmd_exec(t_pipex *p, char *cmd);
void	init_struct(t_pipex *p, char **av, int ac, char **env);
void	redirector(t_pipex *p, int x);
int		wait_da_boy(t_pipex *p);
void	handle_exec_error(void);

#endif