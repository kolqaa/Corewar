#ifndef ASM_H
#define ASM_H
#include "../libft/libft.h"
//#include "../op.h"
#include <stdio.h>
//#include "../libft/ft_printf/header.h"

#define NAME_ERROR "Champion name to long (Max length 128 bytes)\n"
#define COMMENT_ERROR "Champion comment too long (Max length 2048)\n"
#define LEXICAL_ERROR "Lexical error at [%d : %d]\n"
#define PROG_NAME_ERROR "Usage: <sourcefile.s> other extension not supported\n"
#define UNEXPECTED_INPUT "Syntax error - unexpected end of input (Perhaps you forgot to end with a newline ?)\n"
#define BEGINNING_LABLE_CHAR "LABLE CHAR cant be at the begginig of string, whuzup?\n"
#define NOT_LABLE_CHAR "{%c} It is not lable char!! WTF MAN\n"
#define NAME_AND_COMMENT_FIRST "MMMM... We have one little mistake here ... NAME AND COMMENT SHOULD BE FIRST THAN LABALE OR COMMAND, read SUBJECT BEFORE WRITE THIS SHIT AGAIN\n"
#define NOT_VALID_ARG_FOR_INSTRUCT "oh my god!!! are you joke?!! THE {%s} is not normal type for instruction %s\n"
#define TO_FEW_MUCH_ARG "To few/much arguments for {%s} command\n"
#define ONE_INSTRUCT_PER_LINE "Did you know? There is should be one instruction per line! o_O READ SUBJECT BASTARDO!!!\n"
#define COMMAND_LABLE 1
#define FIRST_LABLE 0

# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3


#define MAX_ARGS_NUMBER			4
#define MAX_PLAYERS				4
#define MEM_SIZE				(4*1024)
#define IDX_MOD					(MEM_SIZE / 8)
#define CHAMP_MAX_SIZE			(MEM_SIZE / 6)

#define COMMENT_CHAR			'#'
#define LABEL_CHAR				':'
#define DIRECT_CHAR				'%'
#define SEPARATOR_CHAR			','

#define LABEL_CHARS				"abcdefghijklmnopqrstuvwxyz_0123456789"

#define NAME_CMD_STRING			".name"
#define COMMENT_CMD_STRING		".comment"

#define REG_NUMBER				16

#define CYCLE_TO_DIE			1536
#define CYCLE_DELTA				50
#define NBR_LIVE				21
#define MAX_CHECKS				10

/*
**
*/

typedef char	t_arg_type;

#define T_REG					1
#define T_DIR					2
#define T_IND					4
#define T_LAB					8

/*
**
*/

# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define COREWAR_EXEC_MAGIC		0xea83f3

extern int g_num_line;
extern int g_start_mem_arr_size;
extern int g_new_mem_arr_size;
extern int g_i;

typedef struct s_data
{
	int     lable;
	char    *cmd_lbl_name;
	char    *instruct_name[17];
	int     index;
	int     cmd;
	char    **array_args;
	int     name;
	int     comment;
	char    **array;
	int     no_args;
	int     no_correct;
	int     arguments;
	int     is_empty;
}              t_data;

typedef struct		header_s
{
	unsigned int		magic;
	char				prog_name[PROG_NAME_LENGTH + 1];
	unsigned int		prog_size;
	char				comment[COMMENT_LENGTH + 1];
}					header_t;


typedef struct    s_op
{
	char        op[5];
	int            args_nbr;
	t_arg_type    type[3];
	char        op_code;
	int            cycles;
	char        desc[100];
	int            coding_byte;
	int            flag;
}                t_op;

static struct s_op  g_op_tab[17] =
		{
				{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0},
				{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0},
				{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0},
				{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
				{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
				{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
						"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
				{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
						"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
				{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
						"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
				{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1},
				{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
						"load index", 1, 1},
				{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
						"store index", 1, 1},
				{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1},
				{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0},
				{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
						"long load index", 1, 1},
				{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1},
				{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0},
				{0, 0, {0}, 0, 0, 0, 0, 0}
		};


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
int     line_is_empty(char *line);

#endif

