/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:00:22 by pgrellie          #+#    #+#             */
/*   Updated: 2024/07/19 18:57:28 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	handle_exec_error(void)
{
	if (errno == ENOENT)
	{
		ft_putstr_fd("Error: No such file or directory\n", 2);
		exit(127);
	}
	else if (errno == EACCES)
	{
		ft_putstr_fd("Error: Permission denied\n", 2);
		exit(126);
	}
	else
		exit(1);
}

void	cmd_exec(t_pipex *p, char *cmd)
{
	char	**cmds;

	cmds = ft_split(cmd, ' ');
	if (!cmds)
		return ;
	cmd = cmd_path(p->envi, cmds[0]);
	if (cmd)
	{
		execve(cmd, cmds, p->envi);
		ft_free_tab(cmds);
		free(cmd);
		handle_exec_error();
	}
	else
	{
		ft_putstr_fd("Error : command not found\n", 2);
		ft_free_tab(cmds);
		exit(127);
	}
}
