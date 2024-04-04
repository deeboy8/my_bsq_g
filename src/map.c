#include "bsq.h"

void destroy_map(const map_t* map) {
    for (size_t i = 0; i < map->rows; i++) {
        free(map->matrix[i]);
    }
    free(map->matrix); // what is this freeing
}

// TODO: complete signature
void print_map(const map_t* map, const bsq_t* bsq) {
  if (NULL != bsq) {
    printf("print_map::bsq.size: %d, bsq.row: %d, bsq.column: %d\n", (int)bsq->size, (int)bsq->rows, (int)bsq->columns);    
  }
  // printf("print_map::bsq.size: %d, bsq.row: %d, bsq.column: %d\n", (int)bsq->size, (int)bsq->rows, (int)bsq->columns);  
  for (size_t row = 0; row < map->rows; row++) {
    for (size_t col = 0; col < map->columns; col++) {
      char open_space = '.';
      if (NULL != bsq) { 
        size_t bsq_first_row = (bsq->rows - bsq->size) + 1;  
        size_t bsq_last_row = bsq->rows; // 
        size_t bsq_first_column = (bsq->columns - bsq->size) + 1;
        size_t bsq_last_column = bsq->columns; 
        if ((row >= bsq_first_row  && row <= bsq_last_row) && (col >= bsq_first_column && col <= bsq_last_column)) {
          // no need to access map (nested loop does that); merely output submatrix positions
          open_space = 'X';
          putchar('X');
        } else {
          putchar(map->matrix[row][col] == 1 ? 'o' : open_space);
        }
          // only reason accessing map here is because we need to decide whether to place a '.' or 'o'
          // otherwise only interested in printing output to terminal
       }
      // putchar(map->matrix[row][col] == 1 ? 'o' : open_space);
    }   
    putchar('\n');
  }
  putchar('\n');
  // printf("my_bsq::bsq.size: %d, bsq.row: %d, bsq.column: %d\n", (int)bsq->size, (int)bsq->rows, (int)bsq->columns);

    destroy_map(map);
}

map_t fill_map(const char* file) {
    // open file with generated board
    int fd = open(file, O_RDONLY);
    // perror("open");
    assert(-1 != fd);

    map_t map = {0};
    // Read number of rows from first line of file
    char* string = my_readline(fd);
    map.rows = ft_atoi(string);
    free(string);
    // Read first row & compute number of columns
    string = my_readline(fd);
    map.columns = ft_strlen(string) - 1;
    // Allocate rows * columns matrix (map)
    map.matrix = (int**) malloc(sizeof(int*) * map.rows);

    assert(map.matrix != NULL);
    // For each row, convert it to integers and store in matrix (map)
    // Row index.
    for (size_t row = 0; row < map.rows; row++) {
    map.matrix[row] = (int*) malloc(sizeof(int) * map.columns);
    }

    size_t row = 0;
    do {
    // Column index.
    for(size_t column = 0; column < map.columns; column++) {
        map.matrix[row][column] = string[column] == 'o' ? 1 : 0;
    }
    row++;
    free(string);
    // Read while not EOF
    } while ((string = my_readline(fd)) != NULL);
        
    free(string);
    return map;
}