# include "../include/so_long.h"

// 1. check if number of arguments matches
// 2. check if file extension is .ber
// 3. check if map in the file is valid
void	check_args(int argc, char *argv[])
{
	int	len;

	if (argc != 2)
		exit_error("Error\nInvalid number of arguments\n");
	len = ft_strlen(argv[1]);
	if (ft_strncmp(argv[1] + len - 4, ".ber", 4) != 0)
		exit_error("Error\nInvalid file extension\n");
	check_map(argv[1]);
}

int	main(int argc, char *argv[])
{
	check_args(argc, argv);
}