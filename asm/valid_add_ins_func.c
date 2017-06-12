#include "asm.h"

int    check_r(char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i] != 'r')
		i++;
	i++;
	while (str[i])
	{
		if(ft_isdigit(str[i]) || str[i] == ' ' || str[i] == '\t')
			i++;
		else
			exit(printf("{%s} 1 is not normal arguments for instruction\n", str));
	}
	return (1);
}

int     check_proc(char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i] != DIRECT_CHAR)
		i++;
	i++;
	if (str[i] == '-')
		i++;
	if (str[i] == LABEL_CHAR)
	{
		while (str[i])
			i++;
		return (1);
	}
	while (str[i])
	{
		if (ft_isdigit(str[i]) || str[i] == ' ' || str[i] == '\t')
			i++;
		else if (str[i] == COMMENT_CHAR)
			break;
		else
			exit(printf("{%s} 3 is not normal arguments for instruction\n", str));
	}
	return (1);

}

int check_digit(char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]) || str[i] == ' ' || str[i] == '\t')
			i++;
		else
			exit(printf("{%s} 2 is not normal arguments for instruction\n", str));
	}
	return (1);
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
		else if (arg[i] == DIRECT_CHAR)
		{
			if (arg[i + 1] == '-')
				i++;
			if ((arg[i + 1] == LABEL_CHAR) || ft_isdigit(arg[i + 1]))
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