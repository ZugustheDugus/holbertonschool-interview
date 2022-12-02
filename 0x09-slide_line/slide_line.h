#ifndef SLIDE_LINE_H
#define SLIDE_LINE_H 


/*Macros*/
#define SLIDE_LEFT 'L'
#define SLIDE_RIGHT 'R'


/* libraries */
#include <stdio.h>
#include <stdlib.h>


/* prototypes */
int slide_line(int *line, size_t size, int direction);
int slide_it(int *line, size_t size, int direction);
void reverse_array(int *line, size_t size);
void add_array(int *line, size_t size);


#endif /* SLIDE_LINE_H */
