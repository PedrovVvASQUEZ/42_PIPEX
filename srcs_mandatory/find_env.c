/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:57:50 by pgrellie          #+#    #+#             */
/*   Updated: 2024/07/19 18:55:27 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_env(char **pathsss, char *cmd)
{
	int		x;
	char	*path;
	char	*tmp;

	x = 0;
	while (pathsss[x])
	{
		path = ft_strjoin(pathsss[x], "/");
		tmp = path;
		path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(path, F_OK | X_OK) == 0)
		{
			ft_free_tab(pathsss);
			return (path);
		}
		free(path);
		x++;
	}
	ft_free_tab(pathsss);
	return (NULL);
}
