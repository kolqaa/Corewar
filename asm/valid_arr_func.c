#include "asm.h"

void copy_args_to_array(t_data *data, char *args_cmd)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	while (i < g_op_tab[data->index].args_nbr)
	{
		k = 0;
		while (args_cmd[j] != ',' && args_cmd[j])
			data->array_args[i][k++] = args_cmd[j++];
		data->array_args[i][k] = '\0';
		j++;
		i++;
	}

}

void    make_array(t_data *data)
{
	if ((data->array = (char **)malloc(sizeof(char *) * g_start_mem_arr_size + 1)) == NULL)
		return ;
	data->array[g_start_mem_arr_size] = 0;
}

void copy_file(char *line, t_data *data)
{
	int index;
	int j;
	int new_mem;

	index = 0;
	if (g_i > g_start_mem_arr_size)
	{
		new_mem = g_start_mem_arr_size + g_new_mem_arr_size;
		g_new_mem_arr_size++;
		data->array = (char**)realloc(data->array, sizeof(char *) * new_mem + 1);
	}
	data->array[g_i] = (char *)malloc(sizeof(char *) * ft_strlen(line) + 1);
	j = 0;
	if (line[0] == COMMENT_CHAR)
		return;
	while (line[index])
	{
		if ((line[index] == COMMENT_CHAR && data->flag_for_name && data->flag_for_com) || (line[index] == ';'))
			break ;
		if (!data->flag_for_name || !data->flag_for_com)
			find_name_cmm(line, data);
		data->array[g_i][j++] = line[index++];
	}
	data->array[g_i++][j] = '\0';
}

void    find_name_cmm(char *line, t_data *data)
{
	int i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (!ft_strncmp(&line[i], ".name", 4))
		data->flag_for_name = 1;
	if (!ft_strncmp(&line[i], ".comment", 7))
		data->flag_for_com = 1;
}

int    copy_file_to_array(t_data *data, int fd)
{
	char *line;
	int len;

	len = 0;
	while (get_next_line(fd, &line))
	{
		g_num_line++;
		copy_file(line, data);
		free(line);
	}
	data->array[g_i] = 0;
	len = count_line(data);
	if ((!ft_strcmp("\t", data->array[len - 1]) || !ft_strcmp("", data->array[len - 1]) || !ft_strcmp("\n", data->array[len - 1])))
	{
		g_i = 0;
		return (1);
	}
	printf(UNEXPECTED_INPUT);
	return (0);
}


/*void    create_args_array(t_data *data, char *args_cmd, char *cmd_name)
{
	int i;

	i = 0;
	int k;
	int count = 0;

	k = 0;
	data->array_args = (char **)malloc(sizeof(char *) * (g_op_tab[data->index].args_nbr));
	data->array_args[g_op_tab[data->index].args_nbr] = 0;
	while (i < g_op_tab[data->index].args_nbr)
	{
		while (args_cmd[k] != ',' && args_cmd[k])
		{
			if (args_cmd[k] != ' ' && args_cmd[k] != ',')
				count++;
			k++;
		}
		data->array_args[i] = (char *)malloc(sizeof(char) * (count + 1));
		i++;
		count = 0;
	}
}
*/
