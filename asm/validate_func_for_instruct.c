#include "asm.h"

int get_type(t_data *data, char *arg)
{
	int i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] == 'r' && ft_isdigit(arg[i + 1]) && ft_atoi(&arg[i + 1]) <= 99)
			return (T_REG);
		else if (arg[i] == '%')
		{
			if ((arg[i + 1] == ':') || ft_isdigit(arg[i + 1]))
				return (T_DIR);
			else
				return (0);
		}
		else if (arg[i] >= '0' && arg[i] <= '9')
			return (T_IND);
		else if (arg[i] == ':')
			return (T_IND);
		i++;

	}
	return  (0);

}

int confirm_cmd(char *args_cmd, char *cmd_name, t_data *data)
{
	data->index = take_index_by_name(data, cmd_name);
	create_args_array(data, args_cmd, cmd_name);
	copy_args_to_array(data, args_cmd);
	int i = -1;
	while (++i < g_op_tab[data->index].args_nbr)
	{
		if (g_op_tab[data->index].type[i] & get_type(data, data->array_args[i]))
			continue;
		else
			exit(printf(NOT_VALID_ARG_FOR_INSTRUCT, data->array_args[i], cmd_name));
	}
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
		exit(printf(ONE_INSTRUCT_PER_LINE));
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
		data->no_args = 1;
		exit(printf(TO_FEW_MUCH_ARG, instruct_name));
	}
	confirm_cmd(&line[k], instruct_name, data);
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

int parse_cmd(char *line, t_data *data, int line_nbr)
{
	if (check_cmd_and_args(line, data, line_nbr))
	{
		if (data->cmd && !data->name && !data->comment)
			exit(printf(NAME_AND_COMMENT_FIRST));
		return (1);
	}
	if (data->no_args || data->no_correct)
		return (0);
	return (1);
}

