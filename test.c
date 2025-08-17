#include <stdio.h>
#include <stdbool.h>

typedef enum e_err
{
	mon,
	two = 2
}	t_err;

int	main(void)
{
	t_err	errno;
	bool	flag;

	flag = 1;
	errno = two;
	if (flag)
		printf("%d\n", errno);
	return (0);
}