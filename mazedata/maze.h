/*
 * Willem Klein Wassink, CS50, Winter 2020
 * 
 * maze.h - header file for the client-side procedurally created maze
 * 
 * A maze is a 2d array of mazenode structs. It starts with all nodes
 * being null and creates them as an avatar requests to move into a place.
 * 
 * A mazenode is an element of a maze representing one square. See maze.c for more information
 * 
 */

#ifndef __MAZE_H
#define __MAZE_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../amazing.h"

// ------------------- global types
typedef struct maze maze_t;

// ------------------- functions

// ------------------- set_wall
/* Sets a maze's neighbor to a passed-in set of coordinates
 * 
 * Inputs:
 *      a maze pointer
 *      integer (x,y) coordinates for the current node
 *      an integer 'd' representing a direction, 0 for West, 1 for North, 2 for South, 3 for East.
 *      integer (x,y) coordinates for the new neighbor
 * 
 * Outputs:
 *      False if failure (NUL maze, bad input for d, invalid coordinates)
 *      True on success
 */
bool set_neighbor(maze_t *maze, int x, int y, const int d, int neighbor_x, int neighbor_y);

// ------------------- maze_new
/* Initializes a new maze
 * 
 * Inputs:
 *      An integer width and height for the maze
 *      An integer number of avatars
 * 
 * Outputs:
 *      Pointer to new maze, or NULL if error.
 * 
 * Guarantees:
 *      All border walls will be in place
 *      All nodes' internal neighbors are NULL
 * 
 * Caller responsibilities:
 *      Deleting the maze later with maze_delete
 */
maze_t *maze_new(int height, int width, int numAvatars);

// ------------------- wall_count
/* Returns the number of walls a mazenode is neighbors with
 *
 * Inputs:
 *      a pointer to a maze
 *      integer (x,y) coordinates
 * 
 * Outputs:
 *      -1 on failure (NULL maze, invalid coordinates)
 *      number of walls in a node on success
 */
int wall_count(maze_t *maze, int x, int y);

// ------------------- maze_delete
/* Deletes all the mazenodes in a maze and then the maze itself
 * 
 * Inputs:
 *      a pointer to a valid maze
 * 
 * Ignores NULL mazes    
 */
void maze_delete(maze_t *maze);

// ------------------- unit_mazenode_print
/* Prints out the node at (x,y) in the maze
 * 
 * Inputs:
 *      a pointer to a valid maze
 *      integer x and y coordinates
 *      a pointer to a file open for writing
 * 
 * Guarantees
 *      Ignores NULL mazes
 *      Ignores NULL file pointers
 *      Ignores coordinates below zero and above width/height
 */
void unit_mazenode_print(maze_t *maze, int x, int y, FILE *fp);

// ------------------- unit_maze_print
/* Iterates over the entire maze, calling unit_mazenode_print on each location
 * 
 * Inputs:
 *      a pointer to a valid maze
 *      a pointer to a file open for writing
 */
void unit_maze_print(maze_t *maze, FILE *fp);

// ------------------- get_avatar
/* gets the avatar with the lowest ID at given x,y
 * 
 * Inputs:
 *      pointer to a valid maze
 *      integer (x,y) coordinates
 * 
 * Outputs:
 *      if no avatar is found, returns -1
 *      else returns the lowest avatarID
 */ 
int get_avatar(maze_t *maze, int x, int y);
// ------------------- set_avatar
/* Puts an avatar of a given ID into a location in a maze
 * 
 * Inputs:
 *      a pointer to a valid maze
 *      integer (x,y) coordinates
 *      an integer avatar ID
 */
bool set_avatar(maze_t *maze, int x, int y, int avatar_id, bool status);

// ------------------- check_neighbor
/* Returns an XYPos of the coordinates of the neighbor of a given node in a given direction
 * 
 * Inputs:
 *      a pointer to a valid maze
 *      integer (x,y) coordinates
 *      an integer representing the direction
 * 
 * Output:
 *      XYPos struct containing the x and y coordinates of the indicated neighbor
 *          Same coordinates = wall
 */
XYPos check_neighbor(maze_t *maze, int x, int y, int d);

// ------------------- is_wall
/* Returns an int value based on the result. Indicates whether or not a node has a wall in a certain direction
 *
 * Inputs:
 *      a pointer to a valid maze
 *      integer (x,y) coordinates
 *      an integer representing the direction
 * 
 * Outputs:
 *      0 for if there is a wall
 *      1 for if there is not a wall
 *      2 for NULL maze
 *      3 for inappropriate direction
 *      4 for negative coordinates
 *      5 for too high coordinates
 */
int is_wall(maze_t *maze, int x, int y, const int d);

#endif // __MAZE_H