#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define BUFFER_SIZE (512)

int main(int argc, char **argv)
{
    if (argv[2] == NULL)
    {
        printf("No file selected. Closing.\n");
        return 0;
    }

    if (argv[1] == NULL)
    {
        printf("No search term provided.\n");
        return 0;
    }

    FILE *file = fopen(argv[2], "r");
    if (file == NULL)
    {
        perror("fopen");
        exit(1);
    }

    char **lineptr;
    size_t *n;
    while (getline(lineptr, n, file) != NULL)
    {
        printf("%s", lineptr);
    }

    fclose(file);

    return 0;
}
