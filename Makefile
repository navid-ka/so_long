NAME = $(BINDIR)/so_long
CFLAGS = -Wall -Werror -Wextra #-g -fsanitize=address
SRCDIR = src
OBJDIR = obj
BINDIR = bin
HEADERS = include/so_long.h include/struct.h include/defines.h include/errors.h
SRC = 	src/main.c src/sl_map.c src/sl_map_parse_rect.c src/sl_map_parse_char.c \
		src/sl_map_parse_backtracking.c src/sl_errors.c src/sl_image_loader.c \
		src/sl_map_draw.c src/sl_player_movement.c src/sl_game_input.c \
		src/sl_var_init.c src/sl_player_check_movements.c
OBJECTS = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRC))
COLOR_RESET = $(shell tput sgr0)
COLOR = $(shell tput setaf 2)
KAOMOJI_SUCCESS = (づ ᴗ _ᴗ)づ♡
KAOMOJI_REMOVE = (ノಠ益ಠ)ノ彡┻━┻
LIBFT = include/libft/bin/libft.a
MLX = include/mlx/libmlx.a

#Only for MLX proyects
OLD_MAKE = /usr/bin/make3.81 #make

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