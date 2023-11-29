/*

 *  Compilation:  gcc -o NomeDoExecutável Adoption.c
 *  Execution:    ./NomeDoExecutavel input1.txt input2.txt

*/

#define IMPORT_ADOPTION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef IMPORT_PET_H
    #include "./include/pet.h"
#endif

#ifndef IMPORT_ERRORS_H
    #include "./include/errors.h"
#endif

#define CAT_DATABSE_FILE_PATH "./Database/cats.txt"
#define DOG_DATABSE_FILE_PATH "./Database/dogs.txt"


void pageAdopt()
{
    FILE *file;
    int opt;
    int validChoice = 0;
    Species specie;

    printf("Qual animal voce gostaria de adotar?\n");
    printf("1. Cachorro\n");
    printf("2. Gato\n");
    printf("3. Voltar ao menu principal\n");

    printf("> ");
    scanf("%d", &opt);

    switch(opt)
    {
        case(1):
            file = fopen(DOG_DATABSE_FILE_PATH, "r");
            if(file == NULL)
                exit(ERROR_FAILED_TO_OPEN_FILE);

            specie = dog;
            validChoice = 1;

            break;
        
        case(2):
            file = fopen(CAT_DATABSE_FILE_PATH, "r");
            if(file == NULL)
                exit(ERROR_FAILED_TO_OPEN_FILE);

            specie = cat;
            validChoice = 1;

            break;
        
        case(3):
            //TODO
            validChoice = 1;
            break;
        
        default:
            printf("Opcao Invalida.\n");
            break;
    }

    getchar();

    PetList *list = newPetList();
    
    char name[40];
    int age;
    float weight;


    // Le o arquivo e carrega a lista
    while(fgetc(file) != EOF)
    {
        fseek(file, 0, SEEK_CUR-1);
        fgets(name, 40, file);
        name[strcspn(name, "\n")] = 0;
        printf("STRING: %s\n", name);
        

        if(fscanf(file, "%d,%f", &age, &weight) != 2)
        {
            fclose(file);
            printf("ERROR_FAILED_TO_READ_DATA_FROM_FILE\n");
            exit(ERROR_FAILED_TO_READ_DATA_FROM_FILE);
        }
        append(list, name, age, weight, specie);
    }

    petListPrint(list->start);
    printf("Animais Na Lista:\n");


    // Recebe informacoes e adiciona o animal na lista
    printf("Informe o nome do animal: ");
    fgets(name, 40, stdin);
    name[strcspn(name, "\n")] = 0;

    printf("Informe a idade do animal: ");
    scanf("%d", &age);

    printf("Informe o peso do animal: ");
    scanf("%f", &weight);

    append(list, name, age, weight, specie);
    fclose(file);


    switch(opt)
    {
        case(1):
            file = fopen(DOG_DATABSE_FILE_PATH, "a");
            if (file == NULL)
                exit(ERROR_FAILED_TO_OPEN_FILE);
            break;

        case(2):
            file = fopen(CAT_DATABSE_FILE_PATH, "a");
            if (file == NULL)
                exit(ERROR_FAILED_TO_OPEN_FILE);
            break;

    }

    fprintf(file, "\n%s\n", name);
    fprintf(file, "%d,%f", age, weight);
    fclose(file);
}


int main(void)
{
    pageAdopt();

    
    return 0;
}


   /*switch(opt)
    {
        case(1):
            FILE *file = fopen(DOG_DATABSE_FILE_PATH, "a");
            if(file == NULL)
                exit(ERROR_FAILED_TO_OPEN_FILE);
            int dogAge;
            char dogName[40];

            printf("Insira o nome do cachorro: ");
            fgets(dogName, 50, stdin);
            dogName[strcspn(dogName, "\n")] = 0;

            printf("Insira a idade do cachorro: ");
            scanf("%d", &dogAge);

            Student *node = list->start;
            for (int i = 0; i < 10; i++)
            {
                if(node == NULL)
                    exit(NULL_REFERENCE_ERROR);

                fprintf(file, "%d %.2f\n", node->ra, node->grade);
                node = node->next;
            }


    fclose(file);

            system("cls");
            while ((cat = fgetc(file)) != EOF) {
                putchar(cat);
            }
            break;


    }


}

void pageAdopt(FILE *filepath1, FILE *filepath2)
{
    printf("Qual animal voce gostaria de adotar?\n");
    printf("1. Gato\n");
    printf("2. Cachorro\n");
    printf("3. Voltar ao menu principal\n");

    int opt;
    scanf("%d", opt);

    switch (opt)
    {
        case (1):
            system("cls");
            char cat;
            while ((cat = fgetc(fp1)) != EOF) {
                putchar(cat);
            }
            break;

        case (2):
            system("cls");
            char dog;
            while ((dog = fgetc(fp2)) != EOF) {
                putchar(dog);
            }
            break;

        case(3):
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

void pageRegister(FILE *fp1, FILE *fp2);

void pageSpents();

void homeScreen(FILE *fp1, FILE *fp2);


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
*/