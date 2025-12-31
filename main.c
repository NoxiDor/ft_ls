//
// Created by jazema on 12/31/25.
//

#include "ls.h"

int	parse_flags(char **args)
{
	int	result;

	(void)args;
	result = 0;
	return (result);
}

// TMP main to test the struct
int	main(int argc, char **argv)
{
	int	flags;
	int	i;

	if (argc == 1)
	{
		execute(".", 0);
		return (0);
	}
	flags = parse_flags(&argv[1]);
	i = 1;
	while (i < argc)
	{
		execute(argv[i], flags);
		i++;
	}
	return (0);
}
