# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albernar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/09 16:51:13 by albernar          #+#    #+#              #
#    Updated: 2024/12/09 17:33:33 by albernar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	libftprintf.a

CC			:=	cc

CFLAGS		:=	-Wall -Werror -Wextra -Iincludes

AR			:=	ar

AFLAGS		:=	-rcs

SRCS_DIR	:=	./srcs/
SRCS_B_DIR	:=	./srcs_bonus/
OBJS_DIR	:=	.objs/
UTILS_DIR	:=	./utils/

SRCS        :=	ft_printf.c \
				ft_printf_utils.c \

SRCS_B      :=	ft_printf_bonus.c \
				integers/handle_dec.c \
				integers/handle_hex.c \
				integers/handle_oct.c \
				integers/handle_ptr.c \
				parsing/flags_manage.c \
				parsing/flags_parsing.c \
				strings/handle_char.c \
				strings/handle_string.c \
				utils/utils_puts.c \

UTILS_SRCS	:=	ft_atoi.c \
				ft_itoa.c \
				ft_memcpy.c \
				ft_putchar_fd.c \
				ft_putnbr_fd.c \
				ft_putstr_fd.c \
				ft_strdup.c \
				ft_strlcat.c \
				ft_strlcpy.c \
				ft_strlen.c \

UTILS_OBJS	:=	$(addprefix $(OBJS_DIR), $(UTILS_SRCS:.c=.o))
OBJS        :=	$(addprefix $(OBJS_DIR), $(SRCS:.c=.o))
OBJS_B      :=	$(addprefix $(OBJS_DIR), $(SRCS_B:.c=.o))

TPUT   		:=	tput -T xterm-256color
_RESET 		:=	$(shell $(TPUT) sgr0)
_BOLD  		:=	$(shell $(TPUT) bold)
_ITALIC		:=	$(shell $(TPUT) sitm)
_UNDER 		:=	$(shell $(TPUT) smul)
_GREEN 		:=	$(shell $(TPUT) setaf 2)
_YELLOW		:=	$(shell $(TPUT) setaf 3)
_RED   		:=	$(shell $(TPUT) setaf 1)
_GRAY  		:=	$(shell $(TPUT) setaf 8)
_PURPLE		:=	$(shell $(TPUT) setaf 5)

OBJS_TOTAL		:=	$(words $(OBJS))
OBJS_B_TOTAL	:=	$(words $(OBJS_B))
UTILS_TOTAL		:=	$(words $(UTILS_OBJS))
N_OBJS			:=  $(shell find $(SRCS_DIR) -type f -name $(OBJS) 2>/dev/null | wc -l)
N_OBJS_B		:=  $(shell find $(SRCS_B_DIR) -type f -name $(OBJS_B) 2>/dev/null | wc -l)
N_OBJS_UTILS	:=  $(shell find $(UTILS_DIR) -type f -name $(UTILS_OBJS) 2>/dev/null | wc -l)
UTILS_TOTAL		:=  $(shell echo $$(( $(UTILS_TOTAL) - $(N_OBJS_UTILS) )))
OBJS_TOTAL		:=  $(shell echo $$(( $(OBJS_TOTAL) - $(N_OBJS) )))
OBJS_B_TOTAL	:= 	$(shell echo $$(( $(OBJS_B_TOTAL) - $(N_OBJS_B) )))
CURR_OBJ		:=  0
CURR_OBJ_B		:=  0
CURR_UTILS_OBJ	:=  0

all: $(OBJS_DIR) $(NAME)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(addprefix $(OBJS_DIR), $(dir $(SRCS_B)))

$(NAME): $(UTILS_OBJS) $(OBJS)
	@$(AR) $(AFLAGS) $(NAME) $(UTILS_OBJS) $(OBJS)
	@printf "$(_BOLD)$(NAME)$(_RESET) compiled $(_GREEN)$(_BOLD)successfully$(_RESET)\n\n"

bonus: $(OBJS_DIR) $(UTILS_OBJS) $(OBJS_B)
	@rm -rf $(NAME)
	@$(AR) $(AFLAGS) $(NAME) $(UTILS_OBJS) $(OBJS_B)
	@printf "$(_BOLD)$(NAME)$(_RESET) BONUS compiled $(_GREEN)$(_BOLD)successfully$(_RESET)\n\n"

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@$(CC) $(CFLAGS) -o $@ -c $<
	@$(eval CURR_OBJ=$(shell echo $$(( $(CURR_OBJ) + 1 ))))
	@$(eval PERCENT=$(shell echo $$(( $(CURR_OBJ) * 100 / $(OBJS_TOTAL) ))))
	@printf "$(_GREEN)($(_BOLD)%3s%%$(_RESET)$(_GREEN)) $(_RESET)Compiling $(_BOLD)$(_PURPLE)$<$(_RESET)\n" "$(PERCENT)"

$(OBJS_DIR)%.o: $(UTILS_DIR)%.c
	@$(CC) $(CFLAGS) -o $@ -c $<
	@$(eval CURR_UTILS_OBJ=$(shell echo $$(( $(CURR_UTILS_OBJ) + 1 ))))
	@$(eval PERCENT=$(shell echo $$(( $(CURR_UTILS_OBJ) * 100 / $(UTILS_TOTAL) ))))
	@printf "$(_GREEN)($(_BOLD)%3s%%$(_RESET)$(_GREEN)) $(_RESET)Compiling $(_BOLD)$(_PURPLE)$<$(_RESET)\n" "$(PERCENT)"

$(OBJS_DIR)%.o: $(SRCS_B_DIR)%.c
	@$(CC) $(CFLAGS) -o $@ -c $<
	@$(eval CURR_OBJ_B=$(shell echo $$(( $(CURR_OBJ_B) + 1 ))))
	@$(eval PERCENT=$(shell echo $$(( $(CURR_OBJ_B) * 100 / $(OBJS_B_TOTAL) ))))
	@printf "$(_GREEN)($(_BOLD)%3s%%$(_RESET)$(_GREEN)) $(_RESET)Compiling $(_BOLD)$(_PURPLE)$<$(_RESET)\n" "$(PERCENT)"

clean:
	@rm -rf $(OBJS_DIR)
	@printf "\n$(_BOLD)All objects are $(_GREEN)cleaned$(_RESET)! 🎉\n\n"

fclean: clean
	@rm -f $(NAME)
	@printf "Cleaned $(_BOLD)$(NAME)$(_RESET)!\n\n"

re: fclean all