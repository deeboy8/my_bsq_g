#ifndef BSQ_H
#define BSQ_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>

// #define my_atoi atoi
// #define my_strlen strlen

typedef struct {
  size_t rows;
  size_t columns;
  size_t size;
} bsq_t;

// struct for map importing from script
typedef struct {
  size_t rows;
  size_t columns; 
  int** matrix;
} map_t;

#define READLINE_READ_SIZE 1000000

struct s_readline {
    ssize_t count;
    ssize_t n_read;
    char buffer[READLINE_READ_SIZE];
} t_readline;


// readline
char* my_readline(int fd);

// map
void destroy_map(const map_t* map);
void print_map(const map_t* map, const bsq_t* bsq);
map_t fill_map(const char* file);

// utility
int lowest_surrounding_value(size_t num1, size_t num2, size_t num3);
int	ft_atoi(char *str);
size_t ft_strlen(const char *str);

#endif