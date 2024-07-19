/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_opener.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 16:39:55 by pgrellie          #+#    #+#             */
/*   Updated: 2024/07/19 19:45:55 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	file_opener(t_pipex *p, int i_o)
{
	if (i_o == 0)
	{
		p->fd_in = open(p->infile, O_RDONLY);
		if (p->fd_in < 0)
		{
			perror(p->infile);
			exit(0);
		}
		dup2(p->fd_in, STDIN_FILENO);
		close(p->fd_in);
	}
	else if (i_o == p->cmd_count - 1)
	{
		p->fd_out = open(p->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (p->fd_out < 0)
		{
			perror(p->outfile);
			exit(1);
		}
		dup2(p->fd_out, STDOUT_FILENO);
		close(p->fd_out);
	}
}
