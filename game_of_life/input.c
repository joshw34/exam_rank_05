#include "game_of_life.h"

static void create_original_map(t_game* data) {
  if (!data->input)
    return;
  size_t x = 0;
  size_t y= 0;
  size_t end_x = data->width - 1;
  size_t end_y = data->height - 1;
  int write = -1;
  for (size_t i = 0; data->input[i]; ++i) {
    char c = data->input[i];
    if (c == 'x')
      write *= -1;
    else if (c == 'w' && y > 0)
      --y;
    else if (c == 'a' && x > 0)
      --x;
    else if (c == 's' && y < end_y)
      ++y;
    else if (c == 'd' && x < end_x)
      ++x;
    if (write == 1)
      data->original_map[y][x] = '0';
  }
}

static void add_buffer_to_input(char* input, char* buffer) {
  size_t i = 0;
  size_t j = 0;

  while (input[i])
    ++i;
  while (buffer[j]) {
    input[i] = buffer[j];
    ++i;
    ++j;
  }
  input[i] = '\0';
}

bool get_user_input(t_game* data) {
  char* input = NULL;
  char* buffer = calloc(11, sizeof(char));
  size_t total_bytes = 0;

  if (!buffer)
    return false;

  ssize_t bytes_read;
  while ((bytes_read = read(STDIN_FILENO, buffer, 10)) > 0) {
    total_bytes += bytes_read;
    char* temp = realloc(input, total_bytes + 1);
    if (!temp) {
      free(input);
      free(buffer);
      return false;
    }
    input = temp;
    if (total_bytes == bytes_read)
      input[0] = '\0';
    add_buffer_to_input(input, buffer);
    free(buffer);
    buffer = calloc(11, sizeof(char));
    if (!buffer) {
      free(input);
      return false;
    }
  }
  free(buffer);
  data->input = input;
  create_original_map(data);
  return true;
}
