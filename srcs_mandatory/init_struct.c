/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:58:45 by pgrellie          #+#    #+#             */
/*   Updated: 2024/07/19 17:29:53 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_struct(t_pipex *p, char **av, int ac, char **env)
{
	p->cmd_count = ac - 3;
	p->cmds = &av[2];
	p->envi = env;
	p->infile = av[1];
	p->outfile = av[ac - 1];
}
