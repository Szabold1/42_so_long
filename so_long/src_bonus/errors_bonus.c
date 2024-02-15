/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszabo <bszabo@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:13:11 by bszabo            #+#    #+#             */
/*   Updated: 2024/02/08 13:13:14 by bszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

void	err_msg(char *msg, int show_errno)
{
	ft_printf_fd(STDERR_FILENO, "Error\n");
	if (msg && show_errno == 0)
		ft_printf_fd(STDERR_FILENO, "%s\n", msg);
	else if (msg && show_errno == 1)
	{
		if (errno)
			perror(msg);
		else
			ft_printf_fd(STDERR_FILENO, "%s\n", msg);
	}
	else if (!msg && show_errno == 1)
		perror(NULL);
	else
		ft_printf_fd(STDERR_FILENO, "so_long error\n");
}
