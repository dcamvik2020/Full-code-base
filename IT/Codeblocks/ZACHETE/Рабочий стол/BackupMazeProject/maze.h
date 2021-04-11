#ifndef MAZE_H
#define MAZE_H

#define wall 0
#define pass 1

// exta function, for detecting deadlocks
bool deadend(int, int, int**, int, int);

bool ended(int** maze, int height, int width);
void mazemake(int**, int, int);


#endif // MAZE_H
