#include <stdio.h>
#include <stdlib.h>
#include "asm.h"



void    validate(char *line, FILE *file, t_data *data)
{

}

int main(int argc, char **argv)
{
	int fd;
	char *line;
	t_data *data;
	int i;

	data = (t_data*)malloc(sizeof(*data));
	if (argc != 2)
	{
		printf("usage: file with player {.s}");
		return (0);
	}
	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		printf("Cannot read \"{%s}\" file", argv[1]);
		return 0;
	}
	while (get_next_line(fd, &line))
	{
		int len = ft_strlen(line);
		data->file = (char *)malloc(sizeof(char) * (len + 1));
		data->file = ft_strjoin(line, data->file);
		data->file[len + 1] = ';';
	}
	printf("%s\n", data->file);
	return (0);

}
