#include "asm.h"

int check_byte(int read_byte, char *name)
{
	if (!ft_strcmp(name, COMMENT_CMD_STRING))
	{
		if (read_byte > COMMENT_LENGTH)
		{
			printf(COMMENT_ERROR);
			return (0);
		}
	}
	else if (read_byte > PROG_NAME_LENGTH)
	{
		printf(NAME_ERROR);
		return (0);
	}
	return (1);
}

int check_comment(int k, char *line, t_data *data, int i)
{
	static int quotes = 0;
	static int read_byte = 0;

	while (line[++i])
	{
		if (line[i] == '\"')
			quotes++;
		read_byte++;
		if (quotes > 2)
		{
			printf(LEXICAL_ERROR, k, i);
			return (0);
		}
	}
	if (!check_byte(read_byte, COMMENT_CMD_STRING))
		return (0);
	if (quotes == 2)
	{
		data->comment = 1;
		return (1);
	}
	else
		check_comment(k + 1, data->array[k + 1], data, -1);
	return (1);
}

int check_name(int k, char *line, t_data *data, int i)
{
	static int quotes = 0;
	static int read_byte = 0;

	while (line[++i])
	{
		if (line[i] == '\"')
			quotes++;
		read_byte++;
		if (quotes > 2)
		{
			printf(LEXICAL_ERROR, k, i);
			return (0);
		}
	}
	if (!check_byte(read_byte, NAME_CMD_STRING))
		return (0);
	if (quotes == 2)
	{
		data->name = 1;
		return (1);
	}
	else
		check_name(k + 1, data->array[k + 1], data, -1);
	return (1);
}

