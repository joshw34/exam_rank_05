#include "game_of_life.h"
static void print_result(char** map) {
  for (size_t i = 0; map[i]; ++i) {
    print_str(map[i]);
    putchar('\n');
  }
}

char** init_empty_game_map(t_game* data) {
  char** result = calloc(data->height + 1, sizeof(char*));
  if (!result)
    return NULL;
  for (size_t i = 0; i < data->height; ++i) {
    result[i] = calloc(data->width + 1, sizeof(char));
    if (!result[i])
      return free_array(result), NULL;
    for (size_t j = 0; j < data->width; ++j)
      result[i][j] = ' ';
  }
  return result;
}

size_t count_living_neighbours(t_game* data, size_t x, size_t y) {
  char** original = data->original_map;
  size_t end_x = data->width - 1;
  size_t end_y = data->height - 1;
  size_t total = 0;

  if (x > 0 && y > 0 && original[y-1][x-1] == '0')
    ++total;
  if (y > 0 && original[y-1][x] == '0')
    ++total;
  if (x < end_x && y > 0 && original[y-1][x+1] == '0')
    ++total;
  if (x < end_x && original[y][x+1] == '0')
    ++total;
  if ( x < end_x && y < end_y && original[y+1][x+1] == '0')
    ++total;
  if (y < end_y && original[y+1][x] == '0')
    ++total;
  if (x > 0 && y < end_y && original[y+1][x-1] == '0')
    ++total;
  if (x > 0 && original[y][x-1] == '0')
    ++total;

  return total;
}

bool run_game(t_game* data) {
  if (data->iter == 0)
    return print_result(data->original_map), true;
  data->game_map = init_empty_game_map(data);
  if (!data->game_map)
    return false;
  for (size_t iter = 0; iter < data->iter; ++iter) {
    for (size_t y = 0; y < data->height; ++y) {
      for (size_t x = 0; x < data->width; ++x) {
        char c = data->original_map[y][x];
        size_t living = count_living_neighbours(data, x, y);
        if (living == 2 && c == '0')
          data->game_map[y][x] = '0';
        else if (living == 3)
          data->game_map[y][x] = '0';
      }
    }
    if (iter + 1 < data->iter) {
      free_array(data->original_map);
      data->original_map = data->game_map;
      data->game_map = init_empty_game_map(data);
      if (!data->game_map)
        return false;
    }
  }
  print_result(data->game_map);
  return true;
}
