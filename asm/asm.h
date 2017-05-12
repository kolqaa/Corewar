#ifndef ASM_H
#define ASM_H
#include "../libft/libft.h"
//#include "../libft/ft_printf/header.h"

#define NAME_ERROR "Champion name to long (Max length 128 bytes)\n"
#define COMMENT_ERROR "Champion comment too long (Max length 2048)\n"
#define LEXICAL_ERROR "Lexical at [%d : %d]\n"

int num_line = 0;

typedef struct s_data
{
	char *file;
}              t_data;

#endif
