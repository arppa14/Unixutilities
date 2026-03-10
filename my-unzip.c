#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("my-unzip: tiedosto1 [tiedosto2 ...]\n");
        exit(1);
    }

    for (int i = 1; i < argc; i++) {
        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL) {
            printf("my-unzip: ei voida avata tiedostoa\n");
            exit(1);
        }

        int count;
        char ch;

        while (fread(&count, sizeof(int), 1, fp) == 1) {
            if (fread(&ch, sizeof(char), 1, fp) != 1) {
                break;
            }

            for (int j = 0; j < count; j++) {
                printf("%c", ch);
            }
        }

        fclose(fp);
    }

    return 0;
}
