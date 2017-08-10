#include "asm.h"

int is_arg(char *str)
{


	if (str[0] == 'r' && ft_isdigit((str[1])))
		return (1);
	else if (str[0] == '%')

		return (1);
	else
		return (0);
}
int cmd_exist(char *str)
{
	int i;

	i = 0;
	while (i < 16)
	{

		if (!ft_strcmp(str, g_op_tab[i].op))
			return (1);
		i++;
	}
	return (0);
}

int start_argument(t_data *data, char *arg)
{
	int i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] == 'r' && ft_isdigit(arg[i + 1]) && ft_atoi(&arg[i + 1]) <= 99)
		{
			data->arguments = 1;
			return (1);
		}
		else if (arg[i] == '%')
		{
			if (arg[i + 1] == '-')
				i++;
			if ((arg[i + 1] == ':') || ft_isdigit(arg[i + 1]))
			{
				data->arguments = 1;
				return (1);
			}
			else
				return (0);
		}
		i++;
	}
	return  (0);

}
int   check_str(char *str, int i, t_data *data, int size_st)
{
	int j;

	j = 0;
	if (i >= size_st)
		return (1);
	memset(data->cmp, 0, sizeof(data->cmp));
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i] != ' ' && str[i] != '\t' && str[i])
		data->cmp[j++] = str[i++];
	if (cmd_exist(data->cmp))
		data->find_cmd++;
	else if (data->cmp[ft_strlen(data->cmp) - 1] == ':' || data->cmp[0] == LABEL_CHAR)
	{
		data->flag_for_lable = 1;
		memset(data->cmp, 0, sizeof(data->cmp));
	}
	else if (start_argument(data, data->cmp))
		return (1);
	else
		exit(printf("This one {%s} not valid line, this is not instruction/lable/argument, looks more like bullshit\n", data->cmp));
	check_str(str, i, data, size_st);
	return (0);
}

void    clear_variable(t_data *data)
{
	data->flag_for_lable= 0;
	data->find_cmd = 0;
	data->arguments = 0;
}

void    check_result(t_data *data, char *line)
{
	if (data->find_cmd > 1)
		exit(printf(ONE_INSTRUCT_PER_LINE));
	else if ((!data->find_cmd&& !data->flag_for_lable) ||
			(!data->find_cmd && data->flag_for_lable && data->arguments))
		exit(printf("Error at line {%s} there is arguments without instruction\n", line));
	else if (data->find_cmd && !data->arguments)
		exit(printf("In line {%s} instruction without/or incorrect arguments\n", line));
}

int check_cmd_and_args(char *line, t_data *data, int line_nbr)
{
	int i;
	char *instruction;
	int len = 0;
	int flag = 0;

	i = 0;
	check_str(line, 0, data, (int)ft_strlen(line) - 1);
	check_result(data, line);
	clear_variable(data);
	while (data->instruct_name[i])
	{
		instruction = find_cmd_in_string(line, data->instruct_name[i]);
		if (instruction)
		{
			len = (int)ft_strlen(instruction);
			if(instruction[len - 1] == ':' || instruction[len - 2] == ':')
				break ;
			if (!check_cmd(instruction, data, data->instruct_name[i]))
				return (0);
			flag = 1;
		}
		i++;
	}
	//if (!data->lable && !data->cmd)
	//	exit(printf("There is no valid line\n"));
	//if (!flag && !data->lable && data->arguments)
	//	exit(printf("Find argument for instruction, but didnt see instruction\n"));
	//if (!flag && data->lable && data->arguments){
	//	exit(printf("Find argument for instruction2, but didnt see instruction\n"));
	//}
	//else
	//{
	//	data->arguments = 0;
	//	return 1;
	//}
}

int parse_cmd(char *line, t_data *data, int line_nbr)
{

	if (!data->name || !data->comment)
		exit(printf(NAME_AND_COMMENT_FIRST));
	int i = 0;
	while (line[i])
	{
		if (line[i] == ',' || line[i] == 'r' || line[i] == '%')
		{
			if (line[i] == 'r' && !ft_isdigit(line[i + 1]))
				break;
			data->arguments++;
		}
		i++;
	}
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

