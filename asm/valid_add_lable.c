#include "asm.h"

char		*ft_copyLable(char *dst, const char *src, size_t len)
{
	size_t i;

	i = 0;
	//dst = (char *) malloc(sizeof(char) * (len + 2));
	while (i < len && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = ':';
	dst[i + 1] = '\0';
	return (dst);
}

int parse_lbl(char *line, t_data *data, int line_nbr)
{
	if (check_lable(line, data, line_nbr))
	{
		if (data->lable && !data->name && !data->comment)
			exit(printf(NAME_AND_COMMENT_FIRST));
		return (1);
	}
	printf("Lable {%s} is not exist\n", data->cmd_lbl_name);
	return (0);
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

