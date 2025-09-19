#include <stdio.h>
#include "fdf/internal/fdf.h"

int	main(void)
{
	if (!fdf("10-2.fdf"))
	{
		printf("fail\n");
		return (-1);
	}
	printf("success\n");
	return (0);
}