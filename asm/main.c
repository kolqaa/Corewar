#include <stdio.h>
#include <stdlib.h>
#include "asm.h"
#include "../op.h"

char		*ft_copyLable(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	dst = (char *)malloc(sizeof(char) * (len + 2));
	while (i < len && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = ':';
	dst[i + 1] = '\0';
	return (dst);
}

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

int    copy_file_to_array(t_data *data, int fd)
{
	char *line;

	while (get_next_line(fd, &line))
	{
		g_num_line++;
		copy_file(line, data);
		free(line);
	}
	if ((!ft_strcmp("\t", data->array[g_num_line - 1]) || !ft_strcmp("", data->array[g_num_line - 1])))
	{
		data->array[g_i - 1] = 0;
		g_i = 0;
		return (1);
	}
	printf(UNEXPECTED_INPUT);
	return (0);
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

int is_lable_char(char lbl)
{
	int i;

	i = 0;
	while (LABEL_CHARS[i])
	{
		if (lbl == LABEL_CHARS[i])
			return (1);
		i++;
	}
	return (0);
}

int confirm_lbl(char *line, t_data * data, int cmd_lbl)
{
	int i = 0;
	if (cmd_lbl)
	{
		while (line[i] == ' ' && line[i] == '\t')
			i++;
		printf("CMD:");
		while (line[i] && line[i] != SEPARATOR_CHAR && line[i] != '\t' && line[i] != ' ' && line[i] != COMMENT_CHAR)
		{
			printf("%c", line[i]);
			if (is_lable_char(line[i]))
				i++;
			else
			{
				printf("in\n");
				printf("{%c} its not lable char man!!!! WTF BITCH\n", line[i]);
				return (0);
			}
		}
		printf("\n");
		data->lable = 1;
		data->cmd_lbl_name = ft_copyLable(data->cmd_lbl_name, line, (size_t) i);
		printf("LABLE_IN_CMD:%s\n", data->cmd_lbl_name);
		printf("ITS NORM CMD LBL\n");
		return (1);
	}
	printf("FST:");
	while (line[i] != ' ' && line[i] != '\t' && line[i] != '\n' && line[i] != LABEL_CHAR && line[i] != COMMENT_CHAR)
	{
		printf("%c", line[i]);
		if (is_lable_char(line[i]))
			i++;
		else
		{
			printf("{%c} its not lable char man!!!! WTF BITCH\n", line[i]);
			return (0);
		}
	}
	printf("\n");
	data->lable = 1;
	printf("ITS NORM FIRST LABLE\n");
	return (1);
}

int exist_lable(char *lable_name, t_data *data, int line_nbr)
{
	int i;
	int find;

	i = 0;
	find = 0;
	if (!ft_strncmp(lable_name, data->array[line_nbr], ft_strlen(lable_name)))
		find++;
	while (data->array[i])
	{
		if ((i == line_nbr) || (data->array[i][0] == COMMENT_CHAR))
		{
			i++;
			continue ;
		}
		if (!ft_strncmp(lable_name, data->array[i], ft_strlen(lable_name)))
		{
			find++;
			if(data->array[i][ft_strlen(lable_name) - 1] != LABEL_CHAR) // если не добавить : к концу лейбла
				find--;
		}
		i++;
	}
	if (find)
	{
		printf("LABLE {%s} IS EXIST\n", lable_name);
		free(data->cmd_lbl_name);
		return (1);
	}
	printf("LABLE {%s} IS NOT EXITS\n", lable_name);
	free(data->cmd_lbl_name);
	return (0);
}

int check_lable(char *line, t_data *data, int line_nbr)
{
	int i;

	i = 0;
	if (line[0] == LABEL_CHAR)
	{
		printf("LABLE CHAR cant be at the begginig of string, whuzup?\n");
		return (0);
	}
	while (line[i])
	{
		if (line[i] == COMMENT_CHAR)
			break;
		if ((line[i] == LABEL_CHAR) && (line[i - 1] == DIRECT_CHAR || line[i - 1] == ',' || line[i - 1] == ' '))
		{
			if (!confirm_lbl(&line[i + 1], data, COMMAND_LABLE))
				return (0);
			if (!exist_lable(data->cmd_lbl_name, data, line_nbr))
				return (0);
		}
		if (line[i] == LABEL_CHAR && is_lable_char(line[i - 1]))
		{
			if (!confirm_lbl(line, data, FIRST_LABLE))
				return (0);
		}
		i++;
	}
	return (1);
}

int ft_wordequ(char *string_to_find, char *ins[], char *word)
{
	char *tmp;
	int k = 0;
	while (ins[k])
	{
		tmp = find_cmd_in_string(string_to_find, ins[k]);
		if (tmp)
			return (1);
		k++;
	}
	return (0);
}

int take_index_by_name(t_data *data, char *name_cmd)
{
	int i;

	i = 0;
	while (i < 17)
	{
		if (!ft_strcmp(g_op_tab[i].op, name_cmd))
			break;
		i++;
	}
	return (i);
}



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
		{
			printf("(%c", args_cmd[j]);
			if (args_cmd[j] == ',')
			{
				j++;
				break ;
			}
			data->array_args[i][k++] = args_cmd[j++];
		}
		data->array_args[i][k] = '\0';
		i++;
	}

}

void    create_args_array(t_data *data, char *args_cmd, char *cmd_name)
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


int confirm_cmd(char *args_cmd, char *cmd_name, t_data *data)
{
	data->index = take_index_by_name(data, cmd_name);
	printf("instruction-->%s CONFIRM THIS-->%s cmd index = %d args_nbr=%d\n", cmd_name, args_cmd, data->index, g_op_tab[data->index].args_nbr);
	create_args_array(data, args_cmd, cmd_name);
	copy_args_to_array(data, args_cmd);
	int i = -1;
	while (++i < g_op_tab[data->index].args_nbr)
		printf("aray %s\n", data->array_args[i]);
	free(data->array_args);
	return (0);

}
int check_args(char *args_cmd, char *ins, int count, t_data *data)
{
	if ((!ft_strcmp(ins, "sti") || !ft_strcmp(ins, "add")  || !ft_strcmp(ins, "sub")  || !ft_strcmp(ins, "and")  || !ft_strcmp(ins, "or") ||
			!ft_strcmp(ins, "xor") || !ft_strcmp(ins, "ldi")  || !ft_strcmp(ins, "lldi")) && (count == 2))
		return (1);
	if ((!ft_strcmp(ins, "live") || !ft_strcmp(ins, "fork") || !ft_strcmp(ins, "lfork") || !ft_strcmp(ins, "aff") || !ft_strcmp(ins, "zjmp")) && (count == 0))
		return (1);
	if ((!ft_strcmp(ins, "ld")|| !ft_strcmp(ins, "st") || !ft_strcmp(ins, "lld")) && (count == 1))
		return (1);
	data->no_args = 1;
	printf("\n");
	return (0);
}
int   check_cmd(char *line, t_data *data, int line_nbr, char *instruct_name)
{
	int i;
	int count = 0;
	int skip = (int)ft_strlen(instruct_name);
	i = 0;
	while (i < skip)
		i++;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (ft_wordequ(&line[i], data->instruct_name, instruct_name))
	{
		data->no_correct = 1;
		printf("Did you know? There is should be one instruction per line! o_O READ SUBJECT BASTARDO!!!\n");
		return (0);
	}
	int k = i;
	while (line[i])
	{
		if (line[i] == ',')
			count++;
		i++;
	}
	if (!check_args(&line[i], instruct_name, count, data))
	{
		printf("To few/much arguments for {%s} command\n", instruct_name);
		data->no_args = 1;
		return (0);
	}
	confirm_cmd(&line[k], instruct_name, data);
	printf("OK\n");
	data->cmd = 1;
	return 1;
}

char		*find_cmd_in_string(const char *big, const char *little)
{
	int		i;
	char	*str;

	str = (char *)big;
	i = 0;
	if (*little == '\0')
		return (str);
	while (str[i])
	{
		if (!ft_strncmp(&str[i], little, ft_strlen(little)) && str[i - 1] != LABEL_CHAR && str[i + ft_strlen(little)] != LABEL_CHAR)
		{
			if (!ft_strcmp(little, "st") && str[i + 2] == 'i' && str[i + 1] != '\0')
			{
				i++;
				continue;
			}
			if (!ft_strcmp(little, "st") && str[i + 2] != ' ' && str[i + 1] != '\0')
			{
				i++;
				continue;
			}
			return (&str[i]);
		}
		i++;
	}
	return (NULL);
}

int check_cmd_and_args(char *line, t_data *data, int line_nbr)
{
	int i;

	i = 0;
	while (data->instruct_name[i])
	{
		char *instruction = find_cmd_in_string(line, data->instruct_name[i]);
		if (instruction)
		{
			if (!check_cmd(instruction, data, line_nbr, data->instruct_name[i]))
				return (0);
		}
		i++;
	}
	return 1;
}

int parse_lbl(char *line, t_data *data, int line_nbr)
{
	if (check_lable(line, data, line_nbr))
	{
		if (data->lable && !data->name && !data->comment)
		{
			printf("MMMM... We have one little mistake here ... NAME AND COMMENT SHOULD BE FIRST THAN LABALE OR COMMAND, read SUBJECT BEFORE WRITE THIS SHIT AGAIN ;) GL\n");
			return (0);
		}
		return (1);
	}
	return (1);
}

int parse_cmd(char *line, t_data *data, int line_nbr)
{
	if (check_cmd_and_args(line, data, line_nbr))
	{
		if (data->cmd && !data->name && !data->comment)
		{
			printf("MMMM... We have one little mistake here ... NAME AND COMMENT SHOULD BE FIRST THAN LABALE OR COMMAND, read SUBJECT BEFORE WRITE THIS SHIT AGAIN ;) GL\n");
			return (0);
		}
		return (1);
	}
	if (data->no_args || data->no_correct)
		return (0);
	return (1);
}

int   parse_file(t_data *data)
{
	int i;

	i = 0;
	while (data->array[i])
	{
		if ((data->array[i][0] == COMMENT_CHAR) || (!ft_strcmp("", data->array[i])))
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
		i++;
	}
	return 1;
}

int check_again(t_data *data)
{
	if ((data->name && !data->comment) || (!data->name && data->comment))
	{
		printf("Name and comment is necessary in champion\n");
		return (0);
	}
	if (!data->lable && !data->cmd && data->name && data->comment)
	{
		printf("It cant be null file after name and comment\n");
		return (0);
	}
	return (1);
}

int   check_prog_name(char *prog_name)
{
	int len;

	len = (int)ft_strlen(prog_name) - 1;
	while (prog_name[len] && len > 0)
	{
		if (prog_name[len] == 's' && prog_name[len - 1] == '.' && len >= 2)
			return (1);
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
	if (!copy_file_to_array(data, fd))
		return (0);
	if (!parse_file(data))
		return (0);
	if (!check_again(data))
		return (0);
	//if (is_valid_file(data))
	//	return (1);

	printf("end while start printing...\n");
	sleep(222);
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

int main(void)
{
	int fd;
	t_data *data;

	data = (t_data*)malloc(sizeof(*data));
	ft_memset(data, 0, sizeof(*data));
	init_mas(data);
//	if (argc != 2)
//	{
//		printf("Usage: <sourcefile.s> other extension not supported\n");
//		return (0);
//	}
	char *file = "../corewar/champs/ex.s";
	if ((fd = open(file, O_RDONLY)) == -1)
	{
		printf("Cannot read \"{%s}\" file", file);
		return 0;
	}
	if (!validate(fd, data, file))
		return (0);
//	int i  = 0;
//	while (data->array[i])
//	{
//		if (!ft_strcmp("", data->array[i]))
//			printf("WOW");
//		printf("{%s}\n", data->array[i]);
//		i++;
//	}
	return (0);

}
