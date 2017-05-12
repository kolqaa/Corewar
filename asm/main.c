#include <stdio.h>
#include <stdlib.h>
#include "asm.h"
#include "../op.h"


int check_comment(int fd, char *line)
{
	printf("%d\n", num_line);
	static int quotes = 0;
	static int read_byte = 0;
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\"')
			quotes++;
		i++;
		read_byte++;
	}
	if (read_byte > COMMENT_LENGTH)
	{
		printf(COMMENT_ERROR);
		return (0);
	}
	if (quotes == 2 && read_byte < COMMENT_LENGTH) {
		printf("comment valid\n");
		return (1);
	}
	else
	{
		free(line);
		get_next_line(fd, &line);
		num_line++;
		check_comment(fd, line);
	}
	return (1);
}


int check_name(int fd, char *line)
{
	static int quotes = 0;
	static int read_byte = 0;
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\"')
			quotes++;
		i++;
		read_byte++;
	}
	if (read_byte > PROG_NAME_LENGTH)
	{
		printf(NAME_ERROR);
		return (0);
	}
	if (quotes == 2 && read_byte < PROG_NAME_LENGTH) {
		printf("name valid\n");
		return (1);
	}
	else
	{
		free(line);
		get_next_line(fd, &line);
		num_line++;
		check_name(fd, line);
	}
	return (1);
}


int   validate(int fd, t_data *data)
{
	char *line;

	while (get_next_line(fd, &line))
	{
		num_line++;
		if (line[0] == COMMENT_CHAR)
			continue ;
		if (ft_strstr(line, NAME_CMD_STRING))
			if (!check_name(fd, line))
				return (0);
		if (ft_strstr(line, COMMENT_CMD_STRING))
			if (!check_comment(fd, line))
				return (0);
		if (line[0] == '<')
		{
			printf(LEXICAL_ERROR, num_line, 1);
		}

	}
	return (1);

}

int main(int argc , char **argv)
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
