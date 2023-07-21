NAME = $(BINDIR)/so_long
CFLAGS = -Wall -Werror -Wextra -g 
SRCDIR = src
OBJDIR = obj
BINDIR = bin
SRC = src/main.c 
OBJECTS = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRC))
COLOR_RESET = $(shell tput sgr0)
COLOR = $(shell tput setaf 2)
KAOMOJI_SUCCESS = (づ ᴗ _ᴗ)づ♡
KAOMOJI_REMOVE = (ノಠ益ಠ)ノ彡┻━┻


$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@printf "$(COLOR)\rCompiling (╮°-°)╮┳━┳ : $(COLOR_RESET)$<"
	@mkdir -p $(@D)
	@gcc $(CFLAGS) -c $< -o $@ -Iinclude/libft/include -Iinclude/mlx

${NAME}: ${OBJECTS}
	@mkdir -p $(@D)
	@$(MAKE) -C include/libft
	@$(MAKE) -C include/mlx
	@gcc $(CFLAGS) -o ${NAME} ${OBJECTS} -Iinclude/libft/include -Linclude/libft/bin -lft \
	-Iinclude/mlx -Linclude/mlx -lmlx -framework OpenGL -framework AppKit
	@printf "\n$(COLOR)$(KAOMOJI_SUCCESS) Successfully compiled!$(COLOR_RESET)"

all: ${NAME}

fclean: clean
	@rm -rf ${BINDIR}
	@$(MAKE) -C include/libft fclean
	@$(MAKE) -C include/mlx clean

clean:
	@echo "$(COLOR)$(KAOMOJI_REMOVE)$(COLOR_RESET)"
	@rm -rf ${OBJDIR}

re: fclean all

pull: 
	git submodule update --recursive --remote
	@printf "\n$(COLOR)$(KAOMOJI_SUCCESS) Pull submodule success!$(COLOR_RESET)"
	git pull

git: fclean
	git submodule update --recursive --remote
	@echo "Pulled recursive"
	@echo "Commit:"
	@read MSG; \
	git commit -am "$$MSG"
	git push

.PHONY: clean all fclean re git pull
