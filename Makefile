#			-->|   Files to Compile   |<--
FILES		=		stk_ops_dumb stk_ops_core stk_ops_comp stk_aux_read args_to_stk aux_utils

#			-->|   Titles   |<--
HEAD		=		"42 Push Swap"
NAME		=		push_swap.a
RUN			=		exe
UTL			=		ft_utils_lib.a

#			-->|   Command Definitions   |<--
UTL_DIR		=		utils/
INC_DIR		=		./
SRC_DIR		=		./
OBJ_DIR		=		objects/

SRC			=		$(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))
OBJ			=		$(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))

FLAGS		=		-g -Wall -Wextra -Werror -I
BUFFER		=		-D BUFFER_SIZE=42
MAX_FD		=		-D MAX_FD=4096
COMPILE		=		@cc $(FLAGS) $(INC_DIR) -c $< -o $@

AR_EXT		=		@make --no-print-directory -C $(UTL_DIR) all && cp $(UTL_DIR)$(UTL) $(NAME)
M_C			=		@make --no-print-directory -C $(UTL_DIR) clean
M_F			=		@make --no-print-directory -C $(UTL_DIR) fclean

RMV			=		@rm -rf $(OBJ_DIR)
CRT			=		@ar -rcs $(NAME)
AR			=		@ar -rcs $(NAME) $(OBJ)
EXE			=		@cc $(FLAGS) $(INC_DIR) -o $(RUN) push_swap.c $(NAME)

#			-->|   Colors & Messages   |<--
START		=		start

GRAY		=		\033[0;30m
GREEN		=		\033[0;32m
YELLOW		=		\033[0;33m
BLUE		=		\033[0;34m
MAGENTA		=		\033[0;35m
CYAN		=		\033[0;36m
WHITE		=		\033[0;37m
DEF			=		\033[0;39m

BGREEN		=		\033[1;32m
BYELLOW		=		\033[1;33m
BBLUE		=		\033[1;34m
BMAGENTA	=		\033[1;35m
BCYAN		=		\033[1;36m

T_CREATING	=		@echo "$(GRAY)-->|	$(BBLUE)Creating $(HEAD) at $(NAME) $(GRAY)...\n"
T_BUILDING	=		@echo "	$(GRAY)... $(BYELLOW)Building $(NAME) $(GRAY)... \n"
T_COMPILING	=		@echo "	$(GRAY)... $(YELLOW)Compiling $(WHITE)$(FLAGS): $(YELLOW)$< $(GRAY)..."
T_REMOVE_O	=		@echo "$(MAGENTA)$(HEAD): Objects Removed!$(DEF)\n"
T_REMOVE_A	=		@echo "$(BMAGENTA)$(HEAD): All Files Removed!$(DEF)\n"
T_COMPILED	=		@echo "\n$(BGREEN)	     $(HEAD) Compiled!   $(GRAY)|<--$(DEF)\n"
T_EXECUTING	=		@echo "\n$(GRAY)-->|	$(BLUE)Executing: $(BCYAN)$(NAME) $(BLUE)at $(WHITE)$(RUN) $(GRAY)...$(DEF)"
T_EXECUTED	=		@echo "$(GRAY)	./exe $(DEF)"

#			-->|   Rules   |<--
.PHONY: all bonus clean fclean re exe

all: $(START) $(NAME) $(OBJ)
	$(AR)
	$(T_COMPILED)
	$(T_EXECUTING)
	$(EXE)
	$(T_EXECUTED)

clean:
	$(M_C)
	$(RMV)
	$(T_REMOVE_O)

fclean:
	$(M_F)
	$(RMV) $(NAME) $(RUN)
	$(T_REMOVE_A)

re: fclean all

exe: re

#			-->|   File Dependencies   |<--
$(START):
	$(T_CREATING)
	$(T_BUILDING)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	$(T_COMPILING)
	$(COMPILE)

$(NAME):
	$(AR_EXT)
