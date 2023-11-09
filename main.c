#include "get_next_line.h"
#include <stdio.h>

void leaks()
{system("leaks -q a.out");}
int main(void) {
    int fd;
    char *line;

    atexit(leaks);
    fd = open("quijote.txt", O_RDONLY);
    line = get_next_line(fd);
    
    while(line)
    {
        printf("%s", line);
        free(line);
        line = get_next_line(fd);
    }
}
