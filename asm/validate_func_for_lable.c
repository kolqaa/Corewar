#include "asm.h"

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

int help_confirm_lable(char *line, t_data *data, int cmd_lbl)
{
	while (line[i] != ' ' && line[i] != '\t' && line[i] != '\n' && line[i] != LABEL_CHAR && line[i] != COMMENT_CHAR)
	{
		if (is_lable_char(line[i]))
			i++;
		else
		{
			printf("{%c} its not lable char man!!!! WTF BITCH\n", line[i]);
			return (0);
		}
	}
	data->lable = 1;
	return (1);
}

int confirm_lbl(char *line, t_data * data, int cmd_lbl)
{
	int i = 0;
	if (cmd_lbl)
	{
		while (line[i] == ' ' && line[i] == '\t')
			i++;
		while (line[i] && line[i] != SEPARATOR_CHAR && line[i] != '\t' && line[i] != ' ' && line[i] != COMMENT_CHAR)
		{
			if (is_lable_char(line[i]))
				i++;
			else
			{
				printf("{%c} its not lable char man!!!! WTF BITCH\n", line[i]);
				return (0);
			}
		}
		data->lable = 1;
		data->cmd_lbl_name = ft_copyLable(data->cmd_lbl_name, line, (size_t) i);
		return (1);
	}
	if(!help_confirm_lable(line, data, cmd_lbl))
		return (0);
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
		free(data->cmd_lbl_name);
		return (1);
	}
	free(data->cmd_lbl_name);
	return (0);
}

int check_lable(char *line, t_data *data, int line_nbr)
{
	int i;

	i = 0;
	if (line[0] == LABEL_CHAR)
	{
		printf(BEGINNING_LABLE_CHAR);
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


