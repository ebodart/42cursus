#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
 
int main(int argc, char **argv)
{
    int fd;
    int i;
    int ret;
    char *line;

    i = -1;
    ret = 0;
    if (argc == 2)
    {
        fd = open(argv[1], O_RDONLY);
        while (++i < 10)
        {
            line = "123456";
            ret = get_next_line(fd, &line);
            printf("%d %d : %s\n", i, ret, line);
            free(line);
        }
    }
    return (0);
}
