/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:31:48 by pgrellie          #+#    #+#             */
/*   Updated: 2024/07/18 19:00:10 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	redirector(t_pipex *p, int x)
{
	if (x != 0)
	{
		dup2(p->previousfd, STDIN_FILENO);
		close(p->previousfd);
	}
	if (x != p->cmd_count - 1)
		dup2(p->pipefd[1], STDOUT_FILENO);
	close(p->pipefd[0]);
	close(p->pipefd[1]);
}
