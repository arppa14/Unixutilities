#include <stdio.h>
#include <stdlib.h>


//Tiedostojen läpikäynti
int main(int argc, char *argv[]) {

    if (argc == 1) {
        return 0;
    }

    //Avataan tiedosto, jotta sen voi lukea
    for (int i = 1; i < argc; i++) {

        FILE *fp = fopen(argv[i], "r");

        if (fp == NULL) {
            printf("my-cat: ei voi avata tiedostoa\n");
            exit(1);
        }

        char buffer[4096];

        // Tiedoston luku rivi kerrallaan ja tulostus
        while (fgets(buffer, sizeof(buffer), fp) != NULL) {
            printf("%s", buffer);
        }

        fclose(fp);
    }

    return 0;
}

