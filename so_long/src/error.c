#include "../include/so_long.h"

// print error message with perror() and exit
void	exit_error(char *message)
{
	perror(message);
	exit(EXIT_FAILURE);
}