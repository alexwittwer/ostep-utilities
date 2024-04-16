#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define BUFFER_SIZE (512)

int main (int argc, char **argv) {
    if (argv[1] == NULL){
        printf("No file selected. Closing.\n");
        return 0;
    }

    for (int i = 1; i < argc; i++ ) {
        FILE *file = fopen(argv[i], "r");
        if (file == NULL) {
            perror("fopen");
            exit(1);
        }

        char buffer[BUFFER_SIZE];
        while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
            printf("%s", buffer);
        }
        
        fclose(file);
    }

    return 0;
}
