#include <stdio.h>

int	main(void)
{
	if (!fdf("in.txt"))
	{
		printf("fail\n");
		return (-1);
	}
	printf("success\n");
	return (0);
}