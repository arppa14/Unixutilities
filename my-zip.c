#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("my-zip: tiedosto1 [tiedosto2 ...]\n");
        exit(1);
    }

    int prev = EOF;
    int count = 0;

    for (int i = 1; i < argc; i++) {
        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL) {
            printf("my-zip: ei voi avata tiedostoa tiedosto\n");
            exit(1);
        }

        int c;
        while ((c = fgetc(fp)) != EOF) {
            if (prev == EOF) {
                prev = c;
                count = 1;
            } else if (c == prev) {
                count++;
            } else {
                char ch = (char)prev;
                fwrite(&count, sizeof(int), 1, stdout);
                fwrite(&ch, sizeof(char), 1, stdout);

                prev = c;
                count = 1;
            }
        }

        fclose(fp);
    }

    if (prev != EOF) {
        char ch = (char)prev;
        fwrite(&count, sizeof(int), 1, stdout);
        fwrite(&ch, sizeof(char), 1, stdout);
    }

    return 0;
}
