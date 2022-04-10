# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tonted <tonted@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 00:37:48 by tonted            #+#    #+#              #
#    Updated: 2022/04/10 19:33:52 by tonted           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Configuration of paths
SRCDIR := src
OBJDIR := obj
INCDIR := include
LIBFTDIR := libft

# Name of the final executable
NAME = pipex

# Decide whether the commands will be shwon or not
VERBOSE = TRUE

# TODO add to rules .o.c
# ENTRYPOINT = src/pipex.c

# Unit Test management
UTEST = .test/_test_main.c
USRCS = $(wildcard .test/*.c)

# Create the list of directories
DIRS = $(shell find $(SRCDIR) -type d | sed 's/$(SRCDIR)\///g' | sed -n '1!p')
SRCDIRS	= $(foreach dir, $(DIRS), $(addprefix $(SRCDIR)/, $(dir)))
OBJDIRS = $(foreach dir, $(DIRS), $(addprefix $(OBJDIR)/, $(dir)))

# Create a list of *.c sources in DIRS
SRCS = $(wildcard src/*.c)
SRCS += $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.c))
# SRCS := $(filter-out $(ENTRYPOINT), $(SRCS))

# Define objects for all sources
OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

# Name the compiler & flags
CC = clang
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -iquote$(INCDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(HIDE)$(CC) $(CFLAGS) -c  $< -o $@

all			: buildrepo $(NAME)

$(NAME)		: $(OBJS)
	$(HIDE)$(MAKE) -C $(LIBFTDIR)
	$(HIDE)$(CC) $(CFLAGS) $(OBJS) -L./libft -lft -o $(NAME)
	@printf $(GREEN)"[$@] program created\n"$(RESET)

clean		:
	$(HIDE)rm -rf $(OBJDIR)
	$(HIDE)$(MAKE) clean -C $(LIBFTDIR)
	@printf $(YELLOW)"[$(NAME)] objects removed\n"$(RESET)

fclean		: clean
	$(HIDE)rm -f $(NAME)
	$(HIDE)$(MAKE) fclean -C $(LIBFTDIR)

re			: fclean all

buildrepo	:
	$(HIDE)$(call make-repo)

print	:
	@echo $(DIRS)
	@echo $(SRCS)

leak = -leaks --atExit --
# leak = 

test	: all
# $(leak) ./pipex file1 "ls -l" "wc -l" file2
	$(leak) ./pipex file1 "ls" "cat" "wc -l" file2

testh	: all
# $(leak) ./pipex file1 "ls -l" "wc -l" file2
	$(leak) ./pipex here_doc "EOF" cat wc file2
	

.PHONY		: clean fclean all re $(OBJDIR) buildrepo print

# Create
define make-repo
	$(HIDE)mkdir -p $(OBJDIR)
	$(HIDE)for dir in $(DIRS); \
   	do \
	mkdir -p $(OBJDIR)/$$dir; \
   	done
endef

# Color
BLACK := "\e[0;30m"
RED := "\e[0;31m"
GREEN := "\e[0;32m"
YELLOW := "\e[0;33m"
BLUE := "\e[0;34m"
MAGENTA := "\e[0;35m"
CYAN := "\e[0;36m"
RESET :="\e[0m"

# Hide or not the calls depending of VERBOSE
ifeq ($(VERBOSE),TRUE)
    HIDE =
else
    HIDE = @
endif