/*

 *  Compilation:  gcc -o NomeDoExecutável Adoption.c
 *  Execution:    ./NomeDoExecutavel input1.txt input2.txt

*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

enum option {
    OPTION1 = 49,
    OPTION2 = 50,
    OPTION3 = 51,
    OPTION4 = 52,
};

int flush();

void pageAdopt(FILE *fp1, FILE *fp2);

void pageRegister(FILE *fp1, FILE *fp2);

void pageSpents();

void homeScreen(FILE *fp1, FILE *fp2);

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

void pageAdopt(FILE *fp1, FILE *fp2)
{
    printf("Qual animal voce gostaria de adotar?\n");
    printf("1. Gato\n");
    printf("2. Cachorro\n");
    printf("3. Voltar ao menu principal\n");

    char optionbuf[4];
    scanf("%4s", optionbuf);

    switch (optionbuf[0])
    {
        case (OPTION1):
            system("cls");
            char cat;
            while ((cat = fgetc(fp1)) != EOF) {
                putchar(cat);
            }
            break;

        case (OPTION2):
            system("cls");
            char dog;
            while ((dog = fgetc(fp2)) != EOF) {
                putchar(dog);
            }
            break;

        case(OPTION3):
            system("cls");
            homeScreen(fp1, fp2);
            break;

        default:
            system("cls");
            printf("Tecla invalida.\n");
            pageAdopt(fp1, fp2);
            break;
    }
}

void pageRegister(FILE *fp1, FILE *fp2)
{
    printf("Qual animal voce gostaria de cadastrar?\n");
    printf("1. Gato\n");
    printf("2. Cachorro\n");
    printf("3. Voltar ao menu principal\n");

    char optionbuf[4];
    char caracter; 

    scanf("%4s", optionbuf);

    switch (optionbuf[0])
    {
        case (OPTION1):
            system("cls");
            
                printf("Digite o nome, a idade, o peso e a raça (separados por '-'):\n");
                printf("Quando terminar, digite ponto final\n");
            do
            {
                scanf("%c", &caracter);
                fputc(caracter, fp1);

            } while (caracter != '.');
            
            break;

        case (OPTION2):
            system("cls");

                printf("Digite o nome, a idade, o peso e a raça (separados por '-'):\n");
                printf("Quando terminar, digite ponto final\n");
            do
            {
                scanf("%c", &caracter);
                fputc(caracter, fp2);

            } while (caracter != '.');
            break;

        case(OPTION3):
            system("cls");
            homeScreen(fp1, fp2);
            break;

        default:
            system("cls");
            printf("Tecla invalida.\n");
            pageAdopt(fp1, fp2);
            break;
    }
}

void pageSpents()
{
    printf("Voce entrou na página de gastos.");
}

void homeScreen(FILE *fp1, FILE *fp2)
{
    for (int i = 0; i < 30; i++)
    {
        printf("*");
    }
    printf("\n");

    printf("O que voce deseja?\n");

    printf("1. Adocao\n");
    printf("2. Cadastrar\n");
    printf("3. Gastos\n");
    printf("4. Vizualizar\n");

    for(int i = 0; i < 30; i++)
    {
        printf("*");
    }
    printf("\n");

    char optionbuf[4];
    scanf("%4s", optionbuf);

    switch (optionbuf[0])
    {
        case (OPTION1):
            system("cls");
            pageAdopt(fp1, fp2);
            break;

        case (OPTION2):
            system("cls");
            pageRegister(fp1, fp2);
            break;

        case (OPTION3):
            system("cls");
            pageSpents();
            break;

        default:
            system("cls");
            printf("Tecla invalida.\n");
            homeScreen(fp1, fp2);
            break;
    }
}
