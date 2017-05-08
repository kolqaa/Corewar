#include <stdio.h>
#include <stdlib.h>
#include "asm.h"
#include "../op.h"

int check_comment(char *line)
{
	printf("check comment\n");
	printf("%s\n", line);
	return (1);
}


int check_name(char *line)
{
	printf("check name\n");
	printf("%s\n", line);
	return (1);
}


int   validate(int fd, t_data *data)
{
	char *line;

	while (get_next_line(fd, &line))
	{
		if (ft_strstr(line, NAME_CMD_STRING))
			if (!check_name(line))
				return (0);
		if (ft_strstr(line, COMMENT_CMD_STRING))
			if (!check_comment(line))
				return (0);

	}
	return (1);

}

int main(int argc, char **argv)
{
	int fd;
	t_data *data;

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
	if (!validate(fd, data))
		return (0);
	return (0);

}
