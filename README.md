# my_bsq

## About
`my_bsq` -- traverses map and prints the biggest square on a map

## How to compile
Compile by running `make` in the root directory

## Synopsis
`my_bsq [map.txt]`

## Description
`my_bsq` finds the largest square on a board while avoiding obstacles. The board is represented by a file passed as the program’s argument. The following requirements are:

- The first line of the text file contains the number of lines on the board (and only that)
- "." (representing a free space) and "o" (representing an obstacle) are the only allowed characters for the other lines
- All the lines will be the same length (except the first one), and that length is at least 1
- The map will have at least one line
- Each line is terminated by `\n`.

The program prints the board, displaying the biggest square with '.' replaced by "X" to represent the largest square found.

## Map generation
To generate a new map, run the following: 
`perl map_generator.pl <num_rows> <num_cols> <density_of_obstacles> > <output_file.txt>`

## Implementation notes
This project is implemented using dynamic programming.# my_bsq_g
