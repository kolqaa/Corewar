#include <stdio.h>
#include <stdlib.h>
#include "asm.h"
#include <ctype.h>

int g_num_line = 0;
int g_start_mem_arr_size = 5;
int g_new_mem_arr_size = 1;
int g_i = 0;

int    line_is_empty(char *line)
{
	int len = (int)ft_strlen(line);

	if (len <= 1)
		return (1);
	else
		return (0);

}

int   parse_file(t_data *data)
{
	int i;

	i = 0;
	while (data->array[i])
	{
		if ((data->array[i][0] == COMMENT_CHAR) || (!ft_strcmp("", data->array[i])) || line_is_empty(data->array[i]))
		{
			i++;
			continue;
		}
		if (ft_strstr(data->array[i], NAME_CMD_STRING))
		{
			if (!check_name(i, data->array[i], data, -1))
				return 0;
			i++;
			continue;
		}
		if (ft_strstr(data->array[i], COMMENT_CMD_STRING))
		{
			if (!check_comment(i, data->array[i], data, -1))
				return 0;
			i++;
			continue;
		}
		if (!parse_lbl(data->array[i], data, i))
			return 0;
		if (!parse_cmd(data->array[i], data, i))
			return (0);
		data->lable = 0;
		i++;
	}
	return 1;
}

int   validate(int fd, t_data *data, char *prog_name)
{
	if (!check_prog_name(prog_name))
		return (0);
	make_array(data);
	if (!copy_file_to_array(data, fd))
		return (0);
	if (!parse_file(data))
		return (0);
	if (!check_again(data))
		return (0);
	return (1);

}

void    init_mas(t_data *data)
{
	data->instruct_name[0] = "lldi";
	data->instruct_name[1] = "ld";
	data->instruct_name[2] = "sti";
	data->instruct_name[3] = "add";
	data->instruct_name[4] = "sub";
	data->instruct_name[5] = "and";
	data->instruct_name[6] = "or";
	data->instruct_name[7] = "xor";
	data->instruct_name[8] = "zjmp";
	data->instruct_name[9] = "ldi";
	data->instruct_name[10] = "aff";
	data->instruct_name[11] = "fork";
	data->instruct_name[12] = "lld";
	data->instruct_name[13] = "live";
	data->instruct_name[14] = "lfork";
	data->instruct_name[15] = "st";
	data->instruct_name[16] = NULL;
}

int main(int argc, char **argv)
{
	int fd;
	t_data *data;

	data = (t_data*)malloc(sizeof(*data));
	ft_memset(data, 0, sizeof(*data));
	init_mas(data);
	data->arguments = 0;
	if (argc != 2)
	{
		printf("Usage: <sourcefile.s> other extension not supported\n");
		return (0);
	}
	//char *file = "../corewar/champs/ex.s";
	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		printf("Cannot read \"{%s}\" file", argv[1]);
		return 0;
	}
	if (!validate(fd, data, argv[1]))
		return (0);
	printf("CHETKIY IGROK EBA EDEM DALSHE\n");
	return (0);

}
