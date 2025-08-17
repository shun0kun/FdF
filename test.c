#include <stdio.h>

typedef enum e_err
{
	mon,
	two = 2
}	t_err;

int	main(void)
{
	t_err	errno;

	errno = two;
	printf("%d\n", errno);
	return (0);
}