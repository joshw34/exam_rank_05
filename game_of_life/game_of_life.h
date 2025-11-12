#ifndef GAME_OF_LIFE_H
#define GAME_OF_LIFE_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

typedef struct s_game {
  int width;
  int height;
  int iter;
  char* input;
  char** original_map;
  char** game_map;
} t_game;

// utils.c
void free_game_struct(t_game* data);
void free_array(char** arr);
char* remove_leading_zero(const char* str);
size_t ft_strlen(const char* str);
bool ft_isnum(int c);
void print_str(char* msg);
void print_error(char* msg);
int return_error(t_game* data, char* msg);

// input.c
bool get_user_input(t_game* data);

// game.c
bool run_game(t_game* data);

#endif
