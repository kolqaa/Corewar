#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/18 10:09:09 by nsimonov          #+#    #+#              #
#    Updated: 2017/02/24 12:58:57 by nsimonov         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

SRC =  my_bzero.c \
	   fill_struct.c \
	   for_nonvalid.c \
	   printd.c \
	   helpd.c \
	   mallc_and_fill_struct.c \
	   for_prec.c \
	   mallc_and_fill_struct.c \
	   with_mod_help.c \
	   my_strlen.c \
	   my_forun.c \
	   for_c.c \
	   for_p.c \
	   for_s.c \
	   is_modif.c \
	   is_flag.c \
	   ft_flag.c \
	   ft_precision.c \
	   ft_width.c \
	   ft_lentgh.c \
	   form_with_mod.c \
	   form_without_mod.c \
	   my_putstr.c \
	   my_signednbr.c \
	   for_d.c \
	   my_putchar.c \
	   lennum.c \
	   my_formin.c \
	   for_u.c \
	   for_o.c \
	   my_itoa_base.c \
	   lennum8.c \
	   lennum16.c \
	   ft_atoi.c \
	   ft_isdigit.c \
	   my_putnbr.c \
	   for_x.c \
	   ft_printf.c

OBJ = $(SRC:.c=.o)

HEADER = header.h

CC = gcc

CFLAGS = -c -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "Library $(NAME) has been compiled (all rule)."

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -o $@ $<

clean:
	@rm -f $(OBJ)
	@echo "Object files of library has been deleted (clean rule)."

fclean: clean
	@rm -f $(NAME)
	@echo "Library has been deleted (fclean rule)."

re: fclean all
