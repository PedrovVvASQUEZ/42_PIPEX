/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_brr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:36:32 by pgrellie          #+#    #+#             */
/*   Updated: 2024/07/18 18:19:22 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	exit_brr(int code)
{
	if (code == 1)
	{
		ft_putstr_fd("Err: Too many args\n", 2);
		ft_putstr_fd("It should be: ./bin/pipex infile cmd1 cmd2 outfile\n", 2);
		return (1);
	}
	else if (code == 2)
	{
		ft_putstr_fd("Err : Id's malloc failed\n", 2);
		return (1);
	}
	return (0);
}
