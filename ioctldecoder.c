#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("No ioctl cmd provided, bailing...\n");
        return 1;
    }

    const long int cmd = strtol(argv[1], NULL, 16);
    const int type = (cmd >> 24) & 0xFF;
    const int number = (cmd & 0x00FF0000) >> 16;
    const int direction = (cmd & 0xC000) >> 14;
    const int size = (cmd & 0x00003FFF);

    printf("ioctl cmd: %ld\n", cmd);
    printf("  type: %d\n", type);
    printf("  number: %d\n", number);
    printf("  direction: %d\n", direction);
    printf("  size: %d\n", size);
    return 0;
}
