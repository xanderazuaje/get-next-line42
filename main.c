#include "get_next_line.h"
#include <stdio.h>

int main(void) {
    int fd;
    char *line;

    fd = open("1char.txt", O_RDONLY);
    line = "";

    while(line)
    {
        line = get_next_line(fd);
        printf("%s", line);
        free(line);
    }
}
