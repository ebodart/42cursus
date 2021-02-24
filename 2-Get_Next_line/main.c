#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <limits.h>

int main(int argc, char **argv)
{
    int fd;
    int ret;
    char *line = 0;

    ret = 0;
    if (argc == 2)
    {
        fd = open(argv[1], O_RDONLY);
        while ((ret = get_next_line(fd, &line)) > 0)
        {
            printf("|%s\n", line);
            free(line);
        }
        printf("|%s\n", line);
        if (ret == -1)
        printf("--------\n An error happened\n");
        else if (ret == 0)
        {
            printf("--------\n EOF has been reached\n");
            free(line);
        }
        close(fd);
    }
    printf("gnl returned %d", ret);
    return (0);
}