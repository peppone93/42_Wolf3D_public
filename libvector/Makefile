# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pchambon <pchambon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/12 00:20:28 by gbianco           #+#    #+#              #
#    Updated: 2020/08/03 23:53:36 by gbianco          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = vec.a
OBJD = compiled/
FILE = functions_0.c functions_1.c functions_2.c functions_3.c functions_4.c\
	   functions_5.c
FLAG = -Wall -Werror -Wextra

# Colors
CLRR = \033[0;31m
CLRG = \033[0;32m
CLRC = \033[0;36m
CLRW = \033[0m
VECC = $(CLRC)[LBVEC]$(CLRW)

OBJS = $(addprefix $(OBJD),$(FILE:.c=.o))

all : $(NAME)

$(NAME) : $(OBJD) $(OBJS)
	@printf	"$(VECC)%-50s [$(CLRR)%s$(CLRW)]" "Libvec compiled" "✘"
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@printf	"\r$(VECC)$(CLRG)%-50s$(CLRW) [$(CLRG)%s$(CLRW)]\n" "Libvec compiled" "✔"	

$(OBJD) :
	@mkdir -p $(OBJD)
	@printf	"$(VECC)%-50s [$(CLRG)%s$(CLRW)]\n" "Repository: $@ created" "✔"

$(OBJD)%.o : %.c vec.h
	@printf	"$(VECC)%-50s [$(CLRR)%s$(CLRW)]" "Object: $@ created" "✘"
	@gcc $(FLAG) -o $@ -c $<
	@printf	"\r$(VECC)%-50s [$(CLRG)%s$(CLRW)]\n" "Object: $@ created" "✔"

.PHONY : clean fclean re dir
.NOTPARALLEL : $(OBJS)

clean :
	@rm -rf $(OBJD)
	@printf	"$(VECC)%-50s [$(CLRG)%s$(CLRW)]\n" "Objects removed" "∙"

fclean : clean
	@rm -f $(NAME)
	@printf	"$(VECC)%-50s [$(CLRG)%s$(CLRW)]\n" "File: $(NAME) removed" "∙"

re : fclean all
