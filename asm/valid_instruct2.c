#include "asm.h"

int check_cmd_and_args(char *line, t_data *data, int line_nbr)
{
	int i;
	char *instruction;

	i = 0;
	int flag = 0;
	int len = 0;
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
	if (!data->lable && !data->cmd)
		exit(printf("There is no valid line\n"));
	if (!flag && !data->lable && data->arguments) {
		exit(printf("Find argument for instruction, but didnt see instruction\n"));
	}
	if (!flag && data->lable && data->arguments){
		exit(printf("Find argument for instruction2, but didnt see instruction\n"));
	}
	else
	{
		data->arguments = 0;
		return 1;
	}
}

int parse_cmd(char *line, t_data *data, int line_nbr)
{
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

