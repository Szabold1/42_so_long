/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszabo <bszabo@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:10:22 by bszabo            #+#    #+#             */
/*   Updated: 2024/02/08 13:10:26 by bszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	err_msg(char *msg)
{
	ft_printf_fd(STDERR_FILENO, "Error\n");
	if (msg && errno)
		perror(msg);
	else if (msg)
		ft_printf_fd(STDERR_FILENO, "%s\n", msg);
	else if (errno)
		perror(NULL);
	else
		ft_printf_fd(STDERR_FILENO, "so_long error\n");
}
