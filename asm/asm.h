/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtymchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 16:20:41 by vtymchen          #+#    #+#             */
/*   Updated: 2017/05/11 16:20:45 by vtymchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <fcntl.h>
# include "op.h"
#include <stdio.h>
# include "../libft/get_next_line.h"
//# include "../ft_printf/ft_printf.h"

#define NAME_ERROR "Champion name to long (Max length 128 bytes)\n"
#define COMMENT_ERROR "Champion comment too long (Max length 2048)\n"
#define LEXICAL_ERROR "Lexical error at [%d : %d]\n"
#define PROG_NAME_ERROR "Usage: <sourcefile.s> other extension not supported\n"
#define UNEXPECTED_INPUT "Syntax error - unexpected end of input (Perhaps you forgot to end with a newline ?)\n"
#define BEGINNING_LABLE_CHAR "LABLE CHAR cant be at the begginig of string, whuzup?\n"
#define NOT_LABLE_CHAR "{%c} It is not lable char!! WTF MAN\n"
#define NAME_AND_COMMENT_FIRST "MMMM... We have one little mistake here ... NAME AND COMMENT SHOULD BE FIRST THAN LABALE OR COMMAND, read SUBJECT BEFORE WRITE THIS SHIT AGAIN\n"
#define NOT_VALID_ARG_FOR_INSTRUCT "THE {%s} is not normal type for instruction %s\n"
#define TO_FEW_MUCH_ARG "To few/much arguments for {%s} command\n"
#define ONE_INSTRUCT_PER_LINE "Did you know? There is should be one instruction per line! o_O READ SUBJECT BASTARDO!!!\n"
#define COMMAND_LABLE 1
#define FIRST_LABLE 0

extern int g_num_line;
extern int g_start_mem_arr_size;
extern int g_new_mem_arr_size;
extern int g_i;

typedef struct s_data
{
	int     flag_for_name;
	int     flag_for_com;
	int     flag_for_lable;
	int     lable;
	char    cmd_lbl_name[30];
	char    *instruct_name[17];
	int     index;
	int     cmd;
	char    array_args[7][30];
	int     name;
	int     comment;
	char    **array;
	int     no_args;
	int     no_correct;
	int     arguments;
	int     find_cmd;
	char    cmp[255];
}              t_data;

typedef struct		s_line
{
	char	*label;
	char	*op;
	int		pos;
	int		need_bytes;
	char	**args;
}					t_line;

typedef struct		s_asm
{
	int				in_fd;
	int				out_fd;
	t_header		*header;
	unsigned char	*byte_code;
	int				byte;
	t_list			*lines_list;
	char			*name;
}					t_asm;

void				write_name(int in, char *line, t_asm *as);
void				write_magic(int out_fd);
void				write_comment(int in, char *line, t_asm *as);
void				write_byte_code(t_asm *as);
void				std_error();

/*
** coding byte for 1,2,3 arguments
*/

unsigned char		make_coding_byte3(int a, int b, int c);
unsigned char		make_coding_byte2(int a, int b);
unsigned char		make_coding_byte1(int a);
unsigned char		get_coding_byte(t_line *line);

/*
** write argument in out_fd
** arg can be reg, dir, indir
** dir/indir can be label
*/

void				write_arg(t_asm *as, const char *s, int index, t_line *ln);
void				write_indir(t_asm *as, const char *s, t_line *line);
void				write_dir_l(t_asm *as, const char *s, int inde, t_line *ln);
void				write_dir(t_asm *as, const char *s, int index);
void				write_to_byte_code(t_asm *as);

/*
** get_code return a code of arg
** get_index return an operation index in g_op_tab
*/

int					get_code(const char *s);
int					get_index(const char *line);
int					get_pos(t_asm *as, const char *s);
int					calc_size(t_line *line);
void				make_name(t_asm *as, const char *filename);

/*
** fill structure with op, lbl, args
*/

int					fill_label(t_line *l, char *s, int *i, int *start);
void				fill_op(t_line *l, char *s, int *i, int *start);
void				fill_args(t_line *line, char *s, int *i, int *start);

char    *find_cmd_in_string(char *find_in, char *instr);
int     parse_lbl(char *line, t_data *data, int line_nbr);
int     check_lable(char *line, t_data *data, int line_nbr);
int     confirm_lbl(char *line, t_data *data, int cmd_lbl);
int     exist_lable(char *lable_name, t_data *data, int line_nbr);
int     is_lable_char(char lbl);
char    *ft_copyLable(char *dst, const char *src, size_t len);
int     parse_cmd(char *line, t_data *data, int line_nbr);
int     check_cmd_and_args(char *line, t_data *data, int line_nbr);
int     check_cmd(char *line, t_data *data, char *instruct_name);
int     check_args(char *ins, int count, t_data *data);
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
void    find_name_cmm(char *line, t_data *data);

static t_op			g_op_tab[17] =
{
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "substraction", 1, 0},
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
	{{0}, 0, {0}, 0, 0, {0}, 0, 0}
};

#endif
