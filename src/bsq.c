#include "bsq.h"

bsq_t my_bsq(const map_t* map) {
  size_t i, j;
  size_t sub[map->rows][map->columns];

  // set sub matrix cells to zero
  for(i = 0; i < map->rows; i++) {
    for (j = 0; j < map->columns; j++) {
      sub[i][j] = 0;
    }
  }

  // set first column of sub-matrix
  for (i = 0; i < map->rows; i++) {
    sub[i][0] = map->matrix[i][0];
  }

  // set first row of sub-matrix
  for (j = 0; j < map->columns; j++) {
    sub[0][j] = map->matrix[0][j];
  }
  
  // fill empty "cells" in sub matrix
  for (i = 1; i < map->rows; i++) {
    for (j = 1; j < map->columns; j++) {
      // checking to determine if surrounding "cells" are empty
      if (map->matrix[i][j] == 0) {
        int jastin = lowest_surrounding_value(sub[i][j - 1], sub[i - 1][j], sub[i - 1][j - 1]) + 1;
        sub[i][j] = jastin;
        // printf("%d", sub[i][j]);
      } else {
        sub[i][j] = 0;
      }
    }
  }

  bsq_t bsq = {0};

  for(i = 0; i < map->rows; i++) {
    for (j = 0; j < map->columns; j++) {
      if (bsq.size < sub[i][j]) { 
        bsq.size = sub[i][j];
        bsq.rows = i;
        bsq.columns = j;
      }
    }
  }
   
  return bsq;
}

int main(int argc, char* argv[]) {
    if (argc == 2) {
      // convert map from chars to ints and fill 
      map_t map = fill_map(argv[1]);
      
      // print_map(&map, NULL);
      // create 2D array
      bsq_t sub =  my_bsq(&map);
    
      print_map(&map, &sub);
    }
  
    return 0;

}