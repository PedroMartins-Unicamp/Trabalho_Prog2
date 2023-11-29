#ifndef IMPORT_ADOPTION_H
    #include "./adoption.h"
#endif


int main(int argc, char *argv[])
{
    FILE *fpCats, *fpDogs;

    if (argc != 3) {
        printf("Uso: %s <nome_do_arquivo>\n", argv[0]);
        return 1;
    }
    fpCats = fopen(argv[1], "r");
    if (fpCats == NULL) {
        printf("Erro ao abrir o arquivo 1%s\n", argv[1]);
        return 1;
    }
    fpDogs = fopen(argv[2], "r");
    if (fpDogs == NULL) {
        printf("Erro ao abrir o arquivo 2%s\n", argv[2]);
        return 1;
    }

    homeScreen(fpCats, fpDogs);

    return 0;
}
