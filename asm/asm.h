#ifndef ASM_H
#define ASM_H
#include "../libft/libft.h"
#include "../op.h"
#include <stdio.h>
//#include "../libft/ft_printf/header.h"

#define NAME_ERROR "Champion name to long (Max length 128 bytes)\n"
#define COMMENT_ERROR "Champion comment too long (Max length 2048)\n"
#define LEXICAL_ERROR "Lexical error at [%d : %d]\n"
#define PROG_NAME_ERROR "Usage: <sourcefile.s> other extension not supported\n"
#define UNEXPECTED_INPUT "Syntax error - unexpected end of input (Perhaps you forgot to end with a newline ?)\n"
#define BEGINNING_LABLE_CHAR "LABLE CHAR cant be at the begginig of string, whuzup?\n"
#define COMMAND_LABLE 1
#define FIRST_LABLE 0

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
	int     lable;
	char    *cmd_lbl_name;
	int     instruction;
	char    *instruct_name[17];
	int     index;
	int     cmd;
	char    **array_args;
	int     name;
	int     comment;
	char    **array;
	int     no_args;
	int     no_correct;
}              t_data;

char    *find_cmd_in_string(const char *big, const char *little);
int     parse_lbl(char *line, t_data *data, int line_nbr);
int     check_lable(char *line, t_data *data, int line_nbr);
int     confirm_lbl(char *line, t_data *data, int cmd_lbl);
int     exist_lable(char *lable_name, t_data *data, int line_nbr);
int     is_lable_char(char lbl);
char    *ft_copyLable(char *dst, const char *src, size_t len);
int     parse_cmd(char *line, t_data *data, int line_nbr);
int     check_cmd_and_args(char *line, t_data *data, int line_nbr);
int     check_cmd(char *line, t_data *data, int line_nbr, char *instruct_name);
int     check_args(char *args_cmd, char *ins, int count, t_data *data);
int     confirm_cmd(char *args_cmd, char *cmd_name, t_data *data);
int     get_type(t_data *data, char *arg);
void    create_args_array(t_data *data, char *args_cmd, char *cmd_name);
void    copy_args_to_array(t_data *data, char *args_cmd);
int     copy_file_to_array(t_data *data, int fd);
void    make_array(t_data *data);
void    copy_file(char *line, t_data *data);
int     ft_wordequ(char *string_to_find, char *ins[], char *word);
int     take_index_by_name(t_data *data, char *name_cmd);
int     check_prog_name(char *prog_name);
int     check_again(t_data *data);
int     check_byte(int read_byte, char *name);
int     check_comment(int k, char *line, t_data *data, int i);
int     check_name(int  k, char *line, t_data *data, int i);
int     take_index_by_name(t_data *data, char *name_cmd);


#endif

