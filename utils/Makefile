#			-->|   Files to Compile   |<--
FILES_L		=		ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint			\
					ft_memset ft_bzero ft_memcpy ft_memmove ft_memchr ft_memcmp		\
					ft_toupper ft_tolower ft_strchr ft_strrchr ft_strnstr			\
					ft_strlen ft_strncmp ft_strlcpy ft_strlcat ft_atoi ft_itoa		\
					ft_calloc ft_strdup ft_substr ft_strjoin ft_strtrim ft_split	\
					ft_strmapi ft_striteri											\
					ft_putchar_fd ft_putstr_fd ft_putnbr_fd ft_putendl_fd			\
					ft_lstnew ft_lstadd_front ft_lstadd_back ft_lstsize ft_lstlast	\
					ft_lstdelone ft_lstclear ft_lstiter ft_lstmap ft_mtx_free		\
					ft_mtxlen ft_atol

FILES_P		=		aux_itoas aux_types aux_checks aux_builds aux_data aux_format ft_printf

FILES_G		=		get_next_line_utils get_next_line

#			-->|   Titles   |<--
HEAD		=		"42 Utils Build"
NAME		=		ft_utils_lib.a
RUN			=		build.exe

L_HEAD		=		"42 Library"
P_HEAD		=		"42 Printf"
G_HEAD		=		"Get Next Line"

#			-->|   Command Definitions   |<--
INC_DIR		=		includes
LIB_DIR		=		libft/
PTF_DIR		=		ft_printf/
GNL_DIR		=		gnl/
OBJ_DIR		=		objects/

SRC_L		=		$(addprefix $(LIB_DIR), $(addsuffix .c, $(FILES_L)))
SRC_P		=		$(addprefix $(PTF_DIR), $(addsuffix .c, $(FILES_P)))
SRC_G		=		$(addprefix $(GNL_DIR), $(addsuffix .c, $(FILES_G)))
OBJ_L		=		$(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES_L)))
OBJ_P		=		$(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES_P)))
OBJ_G		=		$(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES_G)))

FLAGS		=		-g -Wall -Wextra -Werror -I
BUFFER		=		-D BUFFER_SIZE=42
MAX_FD		=		-D MAX_FD=4096
COMPILE		=		@cc $(FLAGS) $(INC_DIR) -c $< -o $@

RMV			=		@rm -rf $(OBJ_DIR)
CRT			=		@ar -rcs $(NAME)
AR			=		@ar -rcs $(NAME) $(OBJ_L) $(OBJ_P) $(OBJ_G)
EXE			=		@cc $(FLAGS) $(INC_DIR) -o $(RUN) .main.c $(NAME) && ./$(RUN)

#			-->|   Colors & Messages   |<--
START		=		start
MID			=		mid
MID2		=		mid2

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
T_MID		=		@echo "		$(GRAY)..."
T_REMOVE_O	=		@echo "$(MAGENTA)$(HEAD): Objects Removed!$(DEF)\n"
T_REMOVE_A	=		@echo "$(BMAGENTA)$(HEAD): All Files Removed!$(DEF)\n"
T_COMPILED	=		@echo "\n$(BGREEN)	     $(HEAD) Compiled!   $(GRAY)|<--$(DEF)\n"
T_EXECUTING	=		@echo "\n$(GRAY)-->|	$(BLUE)Executing: $(BCYAN)$(NAME) - main.c $(BLUE)at $(WHITE)exe $(GRAY)...$(DEF)"
T_EXECUTED	=		@echo "$(GRAY)	...$(BGREEN)Execution Ended!   $(GRAY)|<--$(DEF)\n"

#			-->|   Rules   |<--
.PHONY: all bonus clean fclean re exe

all: $(START) $(NAME)
	$(AR)
	$(T_COMPILED)

clean:
	$(RMV)
	$(T_REMOVE_O)

fclean:
	$(RMV) $(NAME) $(RUN)
	$(RMV_E)
	$(T_REMOVE_A)

re: fclean all

exe: re
	$(T_EXECUTING)
	$(EXE)
	$(T_EXECUTED)

#			-->|   File Dependencies   |<--
$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: $(LIB_DIR)%.c | $(OBJ_DIR)
	$(T_COMPILING)
	$(COMPILE)

$(OBJ_DIR)%.o: $(PTF_DIR)%.c | $(OBJ_DIR)
	$(T_COMPILING)
	$(COMPILE)

$(OBJ_DIR)%.o: $(GNL_DIR)%.c | $(OBJ_DIR)
	$(T_COMPILING)
	$(COMPILE)

$(NAME): $(OBJ_L) $(MID) $(OBJ_P) $(MID2) $(OBJ_G)
	$(CRT)

$(START):
	$(T_CREATING)
	$(T_BUILDING)

$(MID):
	$(T_MID)

$(MID2):
	$(T_MID)
