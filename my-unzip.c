#include <stdio.h>
#include <stdlib.h>

// Jos ei tiedostoja, niin antaa virheen
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("my-unzip: file1 [file2 ...]\n");
        exit(1);
    }

    // käydään kaiikki pakatut tiedostot läpi
    for (int i = 1; i < argc; i++) {
        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL) {
            printf("my-unzip: cannot open file\n");
            exit(1);
        }


        int count;
        char ch;

        // Luetaan yksi kerrallaan ja tuostetaan myöhemmin X kertaa
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
