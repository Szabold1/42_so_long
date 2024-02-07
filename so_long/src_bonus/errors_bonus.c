#include "../include_bonus/so_long_bonus.h"

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
