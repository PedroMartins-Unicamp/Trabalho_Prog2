/*

 *  Compilation:  gcc -o NomeDoExecutável Adoption.c
 *  Execution:    ./NomeDoExecutavel input1.txt input2.txt

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum option {
    OPTION1 = 49,
    OPTION2 = 50,
    OPTION3 = 51,
    OPTION4 = 52,
    OPTION5 = 53,
};

int flush();

int main(int argc, char *argv[]){
    FILE *fpCats, *fpDogs, *fpClients;

    if (argc != 4) {
        printf("Uso: %s <nome_do_arquivo>\n", argv[0]);
        return 1;
    }
    fpCats = fopen(argv[1], "r+");
    if (fpCats == NULL) {
        printf("Erro ao abrir o arquivo 1%s\n", argv[1]);
        return 1;
    }
    fpDogs = fopen(argv[2], "r+");
    if (fpDogs == NULL) {
        printf("Erro ao abrir o arquivo 2%s\n", argv[2]);
        return 1;
    }

    fpClients = fopen(argv[3], "r+");
    if (fpClients == NULL) {
        printf("Erro ao abrir o arquivo 3%s\n", argv[3]);
        return 1;
    }

    homeScreen(fpCats, fpDogs, fpClients);

    return 0;
}

void pageAdopt(FILE *fp1, FILE *fp2) {
 
}

void pageRegister(FILE *fp1, FILE *fp2, FILE *fp3) {
    printf("Qual cadastro você gostaria de realizar?\n");
    printf("1. Gato\n");
    printf("2. Cachorro\n");
    printf("3. Adotante\n");
    printf("4. Voltar ao menu principal\n");

    char optionbuf[4];
    char caracter; 

    scanf("%4s", optionbuf);

    switch (optionbuf[0]) {
        case (OPTION1): //cadastra os gatos
            system("cls");
            printf("Digite o nome, a idade, o peso e a raça (separados por '-'):\n");
            printf("Quando terminar, digite ponto final.\n");
            while (caracter != '.'){
                scanf("%c", &caracter);
                fputc(caracter, fp1);
            }
            break;

        case (OPTION2): //cadastra os cachorros
            system("cls");
            printf("Digite o nome, a idade, o peso e a raça (separados por '-'):\n");
            printf("Quando terminar, digite ponto final.\n");
            
            while (caracter != '.'){
                scanf("%c", &caracter);
                fputc(caracter, fp2);
            }
            break;

        case(OPTION3): //cadastra os clientes
            system("cls");
            printf("Digite o nome e CPF (separados por '-'):\n");
            printf("Quando terminar, digite ponto final.\n");
            while (caracter != '.') {
                scanf("%c", &caracter);
                fputc(caracter, fp3);
            }
            break;

        case(OPTION4):
            system("cls");
            homeScreen(fp1, fp2, fp3);
            break;

        default:
            system("cls");
            printf("Tecla invalida.\n");
            pageRegister(fp1, fp2, fp3);
            break;
    }
}

void pageConsult() {
    int fp1 = fopen("fpCats.txt", "r");
    int fp2 = fopen("fpDogs.txt", "r");
    int fp3 = fopen("fpClients.txt", "r");
    int fp4 = fopen("fpAdopts.txt", "r");

    printf("Voce entrou na página de Consulta.\n");
    printf("Qual opção você deseja consultar?\n");
    printf("1. Gato\n");
    printf("2. Cachorro\n");
    printf("3. Adotante\n");
    printf("4. Adoção\n");
    printf("5. Voltar ao menu principal\n");

    char optionbuf[5];
    char linha[100], busca[100];
    int numLinha = 0, encontrado = 0;

    scanf("%5s", optionbuf);

    switch (optionbuf[0]) {
        case (OPTION1): //consulta os gatos
            system("cls");
            printf("Digite o nome a ser buscado:\n");
            scanf("%s", busca);
            while (fgets(linha, sizeof(linha), fp1) != NULL){
                numLinha ++;
                if (strstr(linha, busca) != NULL) {
                    encontrado = 1;
                    break;
                }
            }

            if(!encontrado)
                printf("Animal encontrado na linha: %d\n", numLinha);
            else
                printf("Animal não encontrado\n");
            break;

        case (OPTION3): //consulta os cachorros
            system("cls");
            printf("Digite o nome a ser buscado:\n");
            scanf("%s", busca);
            while (fgets(linha, sizeof(linha), fp1) != NULL){
                numLinha ++;
                if (strstr(linha, busca) != NULL) {
                    encontrado = 1;
                    break;
                }
            }

            if(!encontrado)
                printf("Animal encontrado na linha: %d\n", numLinha);
            else
                printf("Animal não encontrado\n");
            break;

        case (OPTION2): //consulta os clientes
            system("cls");
            printf("Digite o nome a ser buscado:\n");
            scanf("%s", busca);
            while (fgets(linha, sizeof(linha), fp1) != NULL){
                numLinha ++;
                if (strstr(linha, busca) != NULL) {
                    encontrado = 1;
                    break;
                }
            }

            if(!encontrado)
                printf("Adotante encontrado na linha: %d\n", numLinha);
            else
                printf("Adotante não encontrado\n");
            break;

        case(OPTION5):
            system("cls");
            homeScreen(fp1, fp2, fp3);
            break;

        default:
            system("cls");
            printf("Tecla invalida.\n");
            pageRegister(fp1, fp2, fp3);
            break;
    }
}

void homeScreen(FILE *fp1, FILE *fp2, FILE *fp3) {
    for (int i = 0; i < 30; i++) {
        printf("*");
    }
    printf("\n");

    printf("O que voce deseja?\n");

    printf("1. Adocao\n");
    printf("2. Cadastrar\n");
    printf("3. Consultar\n");
    printf("4. Atualizar/Excluir\n");

    for(int i = 0; i < 30; i++) {
        printf("*");
    }
    printf("\n");

    char optionbuf[4];
    scanf("%4s", optionbuf);

    switch (optionbuf[0]) {
        case (OPTION1):
            system("cls");
            pageAdopt(fp1, fp2);
            break;

        case (OPTION2):
            system("cls");
            pageRegister(fp1, fp2, fp3);
            break;

        case (OPTION3):
            system("cls");
            pageConsult();
            break;

        default:
            system("cls");
            printf("Tecla invalida.\n");
            homeScreen(fp1, fp2, fp3);
            break;
    }
}