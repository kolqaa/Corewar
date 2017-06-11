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
	int i = 0;
	int count = 0;
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '\t')
			count++;
		else
			count--;
		i++;
	}
	if (count == len)
		return (1);
	else
		return (0);

}

int check_other(t_data *data, int i)
{
	if (!parse_lbl(data->array[i], data, i))
		return 0;
	if (!parse_cmd(data->array[i], data, i))
		return (0);
	return (1);
}

int check_name_comm(t_data *data, int i)
{
	int j = 0;
	while (data->array[i][j] == ' ' || data->array[i][j] == '\t')
		j++;
	if (!ft_strncmp(&data->array[i][j], NAME_CMD_STRING, 4))
	{
		check_name(i, &data->array[i][j], data, -1);
		return (1);
	}
	if (!ft_strncmp(&data->array[i][j], COMMENT_CMD_STRING, 7))
	{
		check_comment(i, &data->array[i][j], data, -1);
		return (1);
	}
	return (0);

}
int   parse_file(t_data *data)
{
	int i;

	i = 0;
	while (data->array[i])
	{
		printf("eror %s\n", data->array[i]);
		if (!ft_strcmp(data->array[i], "") || !ft_strcmp(data->array[i], "\t") || line_is_empty(data->array[i]))
		{
			i++;
			continue ;
		}
		if (check_name_comm(data, i))
		{
			i++;
			continue;
		}
		if (!check_other(data, i))
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
