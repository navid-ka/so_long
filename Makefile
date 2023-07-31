NAME = $(BINDIR)/so_long
CFLAGS = -Wall -Werror -Wextra -g
SRCDIR = src
OBJDIR = obj
BINDIR = bin
HEADERS = include/so_long.h include/struct.h include/defines.h
SRC = src/main.c src/sl_map.c
OBJECTS = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRC))
COLOR_RESET = $(shell tput sgr0)
COLOR = $(shell tput setaf 2)
KAOMOJI_SUCCESS = (づ ᴗ _ᴗ)づ♡
KAOMOJI_REMOVE = (ノಠ益ಠ)ノ彡┻━┻
LIBFT = include/libft/bin/libft.a
MLX = include/mlx/libmlx.a

#Only for MLX proyects
OLD_MAKE = /usr/bin/make3.81 

all: 
	@$(MAKE) -sC include/libft
	@$(OLD_MAKE) -sC include/mlx
	@$(MAKE) ${NAME} --no-print-directory

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@printf "$(COLOR)\rCompiling (╮°-°)╮┳━┳ : $(COLOR_RESET)$<"
	@mkdir -p $(@D)
	@gcc $(CFLAGS) -c $< -o $@ -Iinclude/libft/include -Iinclude/mlx

${NAME}: ${OBJECTS} ${HEADERS} Makefile ${LIBFT} ${MLX}
	@mkdir -p $(@D)
	@gcc $(CFLAGS) -o ${NAME} ${OBJECTS} -Iinclude/libft/include -Linclude/libft/bin -lft \
	-Iinclude/mlx -Linclude/mlx -lmlx -framework OpenGL -framework AppKit
	@printf "\n$(COLOR)$(KAOMOJI_SUCCESS) Successfully compiled!$(COLOR_RESET)"

fclean: clean
	@rm -rf ${BINDIR}
	@$(MAKE) -C include/libft fclean
	@$(MAKE) -C include/mlx clean

clean:
	@echo "$(COLOR)$(KAOMOJI_REMOVE)$(COLOR_RESET)"
	@rm -rf ${OBJDIR}

re: fclean all

p: 
	make && make clean && make run
run: 
	exec ./bin/so_long

pull: 
	@git submodule update --init
	@git submodule update --recursive --remote
	@printf "$(COLOR)$(KAOMOJI_SUCCESS) Pull submodule success!$(COLOR_RESET)\n"
	@git pull
	@printf "$(COLOR)$(KAOMOJI_SUCCESS) Pull success!$(COLOR_RESET)\n"

git: fclean
	@echo "Pulled recursive"
	@echo "Commit:"
	@read MSG; \
	git commit -am "$$MSG"
	git push

.PHONY: clean all fclean re git pull run
