#include "game_of_life.h"

void free_game_struct(t_game* data) {
  if (!data)
    return;
  if (data->original_map) {
    for (size_t i = 0; data->original_map[i]; ++i)
      free(data->original_map[i]);
    free(data->original_map);
  }
  if (data->game_map) {
    for (size_t i = 0; data->game_map[i]; ++i)
      free(data->game_map[i]);
    free(data->game_map);
  }
  if (data->input)
    free(data->input);
  free(data);
}

void free_array(char** arr) {
  if (!arr)
    return;
  for (size_t i = 0; arr[i]; ++i)
    free(arr[i]);
  free(arr);
}

char* remove_leading_zero(const char* str) {
  size_t len = ft_strlen(str);
  char* result = calloc(len + 1, sizeof(char));
  if (!result)
    return NULL;

  size_t i = 0;
  size_t j = 0;

  if (str[i] == '+')
    ++i;

  while (str[i] == '0')
    ++i;

  while (str[i]) {
    result[j] = str[i];
    ++i;
    ++j;
  }

  return result;
}

size_t ft_strlen(const char* str) {
  size_t i = 0;
  if (!str)
    return i;
  while (str[i])
    ++i;
  return i;
}

bool ft_isnum(int c) {
  return c > 47 && c < 58;
}

void print_str(char* msg) {
  for (size_t i = 0; msg[i]; ++i)
    putchar(msg[i]);
}

void print_error(char* msg) {
  print_str("Error: ");
  print_str(msg);
}

int return_error(t_game* data, char* msg) {
  free_game_struct(data);
  print_error(msg);
  return 1;
}
