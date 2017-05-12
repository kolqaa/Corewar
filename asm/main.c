#include <stdio.h>
#include <stdlib.h>
#include "asm.h"
#include "../op.h"


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

int check_comment(int fd, char *line, t_data *data)
{
	static int quotes = 0;
	static int read_byte = 0;
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\"')
			quotes++;
		read_byte++;
		i++;
	}
	if (!check_byte(read_byte, COMMENT_CMD_STRING))
		return (0);
	if (quotes == 2) {
			data->comment = 1;
			return (1);
	}
	else
	{
		free(line);
		get_next_line(fd, &line);
		g_num_line++;
		check_comment(fd, line, data);
	}
	return (1);
}

int check_name(int fd, char *line, t_data *data)
{
	static int quotes = 0;
	static int read_byte = 0;
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\"')
			quotes++;
		read_byte++;
		i++;
	}
	if (!check_byte(read_byte, NAME_CMD_STRING))
		return (0);
	if (quotes == 2)
	{
		data->name = 1;
		return (1);
	}
	else
	{
		free(line);
		get_next_line(fd, &line);
		g_num_line++;
		check_name(fd, line, data);
	}
	return (1);
}

void copy_file(char *line, t_data *data)
{
	int index;
	int j;
	int new_mem;

	new_mem = 0;
	index = 0;
	if (g_i > g_start_mem_arr_size)
	{
		new_mem = g_start_mem_arr_size + g_new_mem_arr_size;
		g_new_mem_arr_size++;
		data->array = (char**)realloc(data->array, sizeof(char *) * new_mem + 1);
		data->array[new_mem] = 0;
	}
	data->array[g_i] = (char *)malloc(sizeof(char *) * ft_strlen(line) + 1);
	j = 0;
	while (line[index])
	{
		data->array[g_i][j] = line[index];
		j++;
		index++;
	}
	data->array[g_i][j] = '\0';
	g_i++;
}

void    make_array(t_data *data)
{
	if ((data->array = (char **)malloc(sizeof(char *) * g_start_mem_arr_size + 1)) == NULL)
		return ;
	data->array[g_start_mem_arr_size] = 0;
}

int   validate(int fd, t_data *data)
{
	char *line;

	make_array(data);
	while (get_next_line(fd, &line))
	{
		g_num_line++;
		if (line[0] == '\0')
		{
			g_num_line--;
			free(line);
			continue;
		}
		if (data->name && data->comment)
		{
			copy_file(line, data);
		}
		if (line[0] == COMMENT_CHAR)
		{
			free(line);
			continue;
		}
		if (ft_strstr(line, NAME_CMD_STRING))
			if (!check_name(fd, line, data))
				return (0);
		if (ft_strstr(line, COMMENT_CMD_STRING))
			if (!check_comment(fd, line, data))
				return (0);
		free(line);
	}
	printf("end while start printing...\n");
	return (1);

}

int main(int argc , char **argv)
{
	int fd;
	t_data *data;

	data = (t_data*)malloc(sizeof(*data));
	data->name = 0;
	data->comment = 0;
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
	printf("Gnum %d\n", g_num_line);
	printf("%s", data->array[200]);
	return (0);

}
