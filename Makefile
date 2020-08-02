#wolf3d peppone

NAME = wolf3d

# COLOR------------------------
CLRR = \033[0;31m
CLRG = \033[0;32m
CLRB = \033[0;34m
CLRC = \033[0;36m
CLRW = \033[0m
LIBC = $(CLRC)[LIBFT]$(CLRW)
VECC = $(CLRC)[LBVEC]$(CLRW)
MTXC = $(CLRC)[LBMTX]$(CLRW)
SDLC = $(CLRC)[LBSDL]$(CLRW)
WOLF = $(CLRB)[WLF3D]$(CLRW)
#------------------------------

SANI = -g -fsanitize=address
SDL_FL = `sdl2-config --cflags`
SDL_LB = `sdl2-config --libs`
GCC = gcc -Wall -Wextra -Werror

SRD = ./srcs/
OBD = ./compiled/
CDE = main.c sdl.c sdl_loop.c map.c horizontal.c vertical.c\
	  angles.c groundsky.c wall.c raycast.c sprites.c sprites_sort.c\
	  arguments.c checkgrid.c
SDL_D = ./libsdl/SDL2-2.0.10
SDL_A = $(SDL_D)/.compiled
SRC = $(addprefix $(SRD), $(CDE))
OBJ = $(addprefix $(OBD), $(CDE:.c=.o))

all: compile_lib $(NAME) #print
	@printf	"$(WOLF)Everything done\n"

# INCL-------------------------
INC_W = ./includes/$(NAME).h
INC = -I ./includes/
INC += -I ./libft/
INC += -I ./libvector/
INC += -I ./libsdl/includes/
#------------------------------

# LIBS-------------------------
LIB = ./libft/libft.a
LIB += ./libvector/vec.a

compile_lib:  lib_sdl lib_ft lib_vec
lib_sdl: $(SDL_A)
$(SDL_A):
	@printf "$(SDLC)$(CLRR)Compilation can take some time, please wait green check\n"
	@printf	"$(SDLC)%-50s [$(CLRR)%s$(CLRW)]" "SDL library compiled" "✘"
	@cd libsdl && tar -xf SDL2-2.0.10.tar.gz
	@cd $(SDL_D) && ./configure > /dev/null
	@cd $(SDL_D) && make -s >/dev/null 2>/dev/null
	@cd $(SDL_D) && make -s install > /dev/null
	@cd $(SDL_D) && touch .compiled > /dev/null
	@touch $(SDL_A) > /dev/null
	@printf	"\r$(SDLC)%-50s [$(CLRG)%s$(CLRW)]\n" "SDL library compiled" "✔"
lib_ft: 
	@make -s -C libft/
lib_vec:
	@make -s -C libvector/
#------------------------------

# EXE--------------------------
$(NAME): $(OBJ) $(LIB)
	@printf	"$(WOLF)%-50s [$(CLRR)%s$(CLRW)]" "$(NAME) compiled" "✘"
	@$(GCC) -o wolf3d $(OBJ) $(LIB) $(SDL_LB) -lm
	@printf	"\r$(WOLF)$(CLRG)%-50s$(CLRW) [$(CLRG)%s$(CLRW)]\n" "$(NAME) compiled" "✔"
#------------------------------
# OBJECTS----------------------
$(OBD)%.o: $(SRD)%.c $(INC_W)
	@printf "$(WOLF)%-50s [$(CLRR)%s$(CLRW)]" "Object $@ created" "✘"
	@$(GCC) $(FLAG) -c $< -o $@ $(INC) $(SDL_FL)
	@printf "\r$(WOLF)%-50s [$(CLRG)%s$(CLRW)]\n" "Object $@ created" "✔"
#------------------------------

clean:
	@make -s -C libft/ clean
	@make -s -C libvector/ clean
	@rm -rf $(OBJ)
	@printf	"$(WOLF)%-50s [$(CLRG)%s$(CLRW)]\n" "Objects removed" "∙"
fclean: clean
	@rm -f libft/libft.a
	@printf	"$(LIBC)%-50s [$(CLRG)%s$(CLRW)]\n" "File: libft.a removed" "∙"
	@rm -f libvector/vec.a
	@printf	"$(VECC)%-50s [$(CLRG)%s$(CLRW)]\n" "File: vec.a removed" "∙"
	@rm -rf $(NAME)
	@printf	"$(WOLF)%-50s [$(CLRG)%s$(CLRW)]\n" "File: $(NAME) removed" "∙"

hclean: fclean
	@printf	"$(SDLC)%-50s [$(CLRG)%s$(CLRW)]\n" "Folder: SDL2 removed" "∙"
	@rm -rf $(SDL_D)

re: fclean all

print:
	@printf "SRD variable: $(SRD)\n"
	@printf "OBD variable: $(OBD)\n"
	@printf "CDE variable: $(CDE)\n"
	@printf "SRC variable: $(SRC)\n"
	@printf "OBJ variable: $(OBJ)\n"

.PHONY: all re clean fclean check_lib sdl_clean print
