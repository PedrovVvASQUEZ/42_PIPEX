/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:22:24 by pgrellie          #+#    #+#             */
/*   Updated: 2024/07/19 19:06:25 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pipexor(t_pipex *p)
{
	int	x;
	int	returnv;

	x = 0;
	returnv = 0;
	while (x < p->cmd_count)
	{
		pipe(p->pipefd);
		p->pid[x] = fork();
		if (p->pid[x] == -1)
			exit(1);
		if (p->pid[x] == 0)
			child_process(p, x);
		else
		{
			close(p->pipefd[1]);
			if (x > 0)
				close(p->previousfd);
			p->previousfd = p->pipefd[0];
		}
		x++;
	}
	returnv = wait_da_boy(p);
	return (returnv);
}

int	main(int ac, char **av, char **env)
{
	static t_pipex	p = {0};
	int				returnv;

	if (ac != 5)
	{
		ft_putstr_fd("Error : wrong number of arguments\n", 2);
		return (1);
	}
	init_struct(&p, av, ac, env);
	p.pid = malloc(sizeof(int) * p.cmd_count);
	if (!p.pid)
	{
		ft_putstr_fd("Error : malloc failed\n", 2);
		return (1);
	}
	returnv = pipexor(&p);
	free(p.pid);
	close(p.pipefd[0]);
	close(p.pipefd[1]);
	return (returnv);
}
