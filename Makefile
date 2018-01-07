##
## Makefile for  in /home/munoz_d/test
## 
## Made by David Munoz
## Login   <munoz_d@epitech.net>
## 
## Started on  Thu May 19 09:43:57 2016 David Munoz
## Last update Sat Jun 18 10:04:08 2016 David Munoz
##

TARGET   = palindrome

CC       = gcc

SRC	 = main.c	\
	   help.c	\
	   check.c	\
	   utils.c	\
	   option_n.c	\
	   base.c	\
	   option_p.c	\

CFLAGS   = -W -Wall -Werror -ansi -pedantic -Iinclude

SRCDIR   = src
OBJDIR   = obj

SOURCES  := $(addprefix src/, $(SRC))

OBJECTS  := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

rm	 = rm -rf
mkdir	 = mkdir -p

$(TARGET): $(OBJECTS)
	@$(CC) $(CFLAGS) -o $@ $(OBJECTS) -L./lib/my -lmy
	@echo "\033[0;35m"$(TARGET)"\033[1;32m compilated !\033[0m"

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	@$(mkdir) $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "\033[1;32m  [OK]  \033[1;36m"$<"\033[0m"

all	: $(OBJECTS) $(TARGET)

clean	:
	@$(rm) $(OBJDIR)
	@echo "\033[1;31mBinary files deleted\033[0m"

fclean	: clean
	@$(rm) $(TARGET)
	@echo "\033[1;31mBinary and executable files are deleted\033[0m"

re	: fclean all

.PHONY: all clean fclean re
