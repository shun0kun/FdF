#include "internal/fdf.h"

t_error	validate_file(const char *filename)
{
	int		fd;
	ssize_t	a;
	ssize_t	size;
	char	tmp[1];
	char	*buf;
	char	**tokens;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (ERR_IO);
	size = 0;
	while (1)
	{
		a = read(fd, buf, 100);
		if (a < 0)
			return (ERR_IO);
		else if (a == 0)
			break ;
		size += a;
	}
	close(fd);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (ERR_IO);
	buf = maloc(sizeof(char) * (size + 1));
	if (!buf)
		return (ERR_NOMEM);
	//...
}