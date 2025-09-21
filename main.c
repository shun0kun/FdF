#include <stdio.h>
#include "fdf/internal/fdf.h"

int	main(int argc, char **argv)
{
	(void)argc;

	if (!fdf(argv[1]))
	{
		printf("fail\n");
		return (-1);
	}
	printf("success\n");
	return (0);
}