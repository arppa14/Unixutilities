#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Stackoverflow keskusteluista getline käyttö
// Luetaan syöte rivi kerrrallaan ja tulostetaan osumat
static void grep_stream(const char *searchterm, FILE *fp) {
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    // Kaikkien rivien läpikäynti
    while ((nread = getline(&line, &len, fp)) != -1) {
        if (strstr(line, searchterm) != NULL) {
            printf("%s", line);
        }
    }

    free(line);
}

// Jos ei hakusanaa niin virhe
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("my-grep: seaechterm[file ...]\n");
        exit(1);
    }

    char *searchterm = argv[1];

    // Jos ei tiedostoja, niin luetaan tandardisyötettä
    if (argc == 2) {
        grep_stream(searchterm, stdin);
        return 0;
    }

    // Virhe jos tiedostoa ei voi avata
    for (int i = 2; i < argc; i++) {
        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL) {
            printf("my-grep: cannot open file\n");
            exit(1);
        }

        grep_stream(searchterm, fp);
        fclose(fp);
    }

    return 0;
}
