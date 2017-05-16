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

int check_comment(int k, char *line, t_data *data)
{
	static int quotes = 0;
	static int read_byte = 0;
	int i = 0;

	while (line[i])
	{
		if (line[i] == '\"')
			quotes++;
		read_byte++;
		i++;
	}
	if (!check_byte(read_byte, COMMENT_CMD_STRING))
		return (0);
	if (quotes == 2)
	{
		data->comment = 1;
		return (1);
	}
	else
		check_comment(k + 1, data->array[k + 1], data);
	return (1);
}

int check_name(int k, char *line, t_data *data)
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
		check_name(k + 1, data->array[k + 1], data);
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
	}
	data->array[g_i] = (char *)malloc(sizeof(char *) * ft_strlen(line) + 1);
	j = 0;
	while (line[index])
		data->array[g_i][j++] = line[index++];
	data->array[g_i][j] = '\0';
	g_i++;
}

void    make_array(t_data *data)
{
	if ((data->array = (char **)malloc(sizeof(char *) * g_start_mem_arr_size + 1)) == NULL)
		return ;
	data->array[g_start_mem_arr_size] = 0;
}

void    copy_file_to_array(t_data *data, int fd)
{
	char *line;

	while (get_next_line(fd, &line))
	{
		g_num_line++;
		copy_file(line, data);
		free(line);
	}
	data->array[g_num_line] = 0;
}

void    write_line(m_lst **lst, char *line)
{
	printf("call\n");
	m_lst *tmp;
	m_lst *tmp2;

	tmp = (m_lst *)malloc(sizeof(*tmp));
	tmp->command = ft_strdup(line);
	tmp->next = NULL;
	if (*lst == NULL)
		*lst = tmp;
	else
	{
		tmp2 = *lst;
		while (tmp2->next != NULL)
			tmp2 = tmp2->next;
		tmp2->next = tmp;
	}

}

int parse_line(char *line, t_data *data)
{
	int i;

	i = 0;
	if (is_lbl(line))
		return (0);
	if (is_cmd(line))
		return (0);
}

void    parse_file(t_data *data)
{
	int i;
	m_lst *head;

	i = 0;
	int j = 0;
	while (data->array[i])
	{
		if (!ft_strcmp("", data->array[i]))
		{
			i++;
			continue ;
		}
		//write_line(&(data->lst), data->array[i]);
		if (ft_strstr(data->array[i], NAME_CMD_STRING) && data->itfirst)
			if (!check_name(i, data->array[i], data))
				return ;
		if (ft_strstr(data->array[i], COMMENT_CMD_STRING) && data->itfirst)
			if (!check_comment(i, data->array[i], data))
				return ;
		if (!parse_line(data->array[i], data))
			return ;
		i++;
	}
//	head = data->lst;
//	while (head != NULL)
//	{
//		printf("LST {%s}\n", head->command);
//		head = head->next;
//	}
	printf("before sellp\n");
	sleep(222);

}

int   check_prog_name(char *prog_name)
{
	int len;

	len = ft_strlen(prog_name) - 1;
	while (prog_name[len] && len > 0)
	{
		if (prog_name[len] == 's' && prog_name[len - 1] == '.') {
			printf("valid prog\n");
			return (1);
		}
		len--;
	}
	printf(PROG_NAME_ERROR);
	return (0);

}


int   validate(int fd, t_data *data, char *prog_name)
{
	if (!check_prog_name(prog_name))
		return (0);
	make_array(data);
	copy_file_to_array(data, fd);
	parse_file(data);
	//if (is_valid_file(data))
	//	return (1);
//	return (0);
//		if (ft_strstr(line, NAME_CMD_STRING))
//			if (!check_name(fd, line, data))
//				return (0);
//		if (ft_strstr(line, COMMENT_CMD_STRING))
//			if (!check_comment(fd, line, data))
//				return (0);
	printf("end while start printing...\n");
	return (1);

}

int main(int argc , char **argv)
{
	int fd;
	t_data *data;

	data = (t_data*)malloc(sizeof(*data));
	data->itfirst = 1;
	data->name = 0;
	data->comment = 0;
	data->lst = NULL;
	if (argc != 2)
	{
		printf("Usage: <sourcefile.s> other extension not supported\n");
		return (0);
	}
	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		printf("Cannot read \"{%s}\" file", argv[1]);
		return 0;
	}
	if (!validate(fd, data, argv[1]))
		return (0);
	int i  = 0;
	while (data->array[i])
	{
		printf("{%s}\n", data->array[i]);
		i++;
	}
	return (0);

}
