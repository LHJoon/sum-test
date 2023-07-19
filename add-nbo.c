#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>

int read_file(const char *filename, uint32_t *number) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        fprintf(stderr, "file '%s'error.\n", filename);
        return 1;
    }

    if (fread(number, sizeof(uint32_t), 1, file) != 1) {
        fprintf(stderr, "file '%s'error.\n", filename);
        fclose(file);
        return 1;
    }

    *number = ntohl(*number);  // network byte order to host byte order

    fclose(file);

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "using: %s <file1> <file2>\n", argv[0]);
        return 1;
    }

    uint32_t num1, num2, sum;

    if (read_file(argv[1], &num1)) {
        return 1;
    }

    if (read_file(argv[2], &num2)) {
        return 1;
    }

    sum = num1 + num2;

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", num1, num1, num2, num2, sum, sum);

    return 0;
}
