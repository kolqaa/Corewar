#ifndef ASM_H
#define ASM_H
#include "../libft/libft.h"
//#include "../libft/ft_printf/header.h"

#define NAME_ERROR "Champion name to long (Max length 128 bytes)\n"
#define COMMENT_ERROR "Champion comment too long (Max length 2048)\n"
#define LEXICAL_ERROR "Lexical error at [%d : %d]\n"
#define PROG_NAME_ERROR "Usage: <sourcefile.s> other extension not supported\n"
#define UNEXPECTED_INPUT "Syntax error - unexpected end of input (Perhaps you forgot to end with a newline ?)\n"
#define COMMAND_LABLE 1
#define FIRST_LABLE 0
#define RETURN1 return (1);
#define RETURN0 return (0)

int g_num_line = 0;
int g_start_mem_arr_size = 5;
int g_new_mem_arr_size = 1;
int g_i = 0;

typedef struct       lst
{
	char         *lable;
	char       *command;
	int         op_code;
	struct lst    *next;
}                 m_lst;

typedef struct s_data
{
	int lable;
	char *lable_name;
	int instruction;
	int cmd;
	int name;
	int comment;
	char    **array;
	m_lst *lst;

}              t_data;


#endif

