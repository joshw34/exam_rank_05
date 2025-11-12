#include "game_of_life.h"

static bool overflow_check(char* arg) {
  long test = 0;
  for (size_t i = 0; arg[i]; ++i) {
    test *= 10;
    test += (arg[i] - '0');
  }
  return test > INT_MAX;
}

static bool verify_num(char* arg) {
  size_t len = ft_strlen(arg);

  if (len == 0)
    return false;

  if (len == 1 && !ft_isnum(arg[0]))
    return false;

  size_t first_digit = 0;
  
  if (len > 1 && arg[0] == '+')
    first_digit = 1;

  for (size_t i = first_digit; arg[i]; ++i) {
    if (!ft_isnum(arg[i]))
      return false;
  }
  
  char* test_val = remove_leading_zero(arg);
  if (!test_val)
    return false;

  if (ft_strlen(test_val) > 10)
    return free(test_val), false;

  if (overflow_check(test_val))
    return free(test_val), false;

  free(test_val);
  return true;
}

static bool check_args(char** args) {
  for (size_t i = 0; args[i]; ++i) {
    if (!verify_num(args[i]))
      return false;
  }
  if (atoi(args[0]) == 0 || atoi(args[1]) == 0)
    return false;
  return true;
}

t_game* init_game_data(char** args) {
  t_game* data = calloc(1, sizeof(t_game));
  if (!data)
    return NULL;
  data->width = atoi(args[0]);
  data->height = atoi(args[1]);
  data->iter = atoi(args[2]);
  data->input = NULL;
  data->original_map = calloc(data->height + 1, sizeof(char*));
  if (!data->original_map)
    return free_game_struct(data), NULL;
  for (size_t i = 0; i < data->height; ++i) {
    data->original_map[i] = calloc(data->width + 1, sizeof(char));
    if (!data->original_map[i])
      return free_game_struct(data), NULL;
    for (size_t j = 0; j < data->width; ++j) {
      data->original_map[i][j] = ' ';
    }
  }
  return data;
}

int main(int ac, char** av) {
  if (ac != 4)
    return return_error(NULL, "Incorrect number of arguments\n");
  if (!check_args(av + 1))
    return return_error(NULL, "Invalid arguments\n");
  t_game* data = init_game_data(av + 1);
  if (!get_user_input(data))
    return return_error(data, "Failed to read user input\n");
  if (!run_game(data))
    return return_error(data, "Malloc error");
  free_game_struct(data);
  return 0;
}
