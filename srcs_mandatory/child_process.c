/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:40:02 by pgrellie          #+#    #+#             */
/*   Updated: 2024/07/19 17:30:07 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(t_pipex *p, int x)
{
	free(p->pid);
	redirector(p, x);
	if (x == 0 || x == p->cmd_count - 1)
		file_opener(p, x);
	cmd_exec(p, p->cmds[x]);
	free(p->pid);
	exit(127);
}
