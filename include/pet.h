#define IMPORT_PET_H

#include <stdlib.h>
#include <stdio.h>

typedef enum species
{
    dog = 1,
    cat
} Species;

typedef struct pet
{
    char *name;
    int age;
    float weight;

    Species specie;
    
    struct pet *next;
} Pet;
Pet* newPet(char *name, int age, float weight, Species specie)
{
    Pet *pet = (Pet*)malloc(sizeof(Pet));

    pet->name = name;
    pet->age = age;
    pet->weight = weight;
    pet->specie = specie;

    pet->next = NULL;

    return pet;
}

typedef struct petList
{
    Pet *start;
} PetList;
PetList* newPetList()
{
    PetList *list = (PetList*)malloc(sizeof(PetList));

    list->start = NULL;

    return list;
}

int isEmpty(PetList *list)
{
    return (list->start == NULL);
}

void append(PetList *list, char *name, int age, float weight, Species specie)
{
    if(isEmpty(list))
        list->start = newPet(name, age, weight, specie);
    else
    {
        Pet *aux = list->start;

        while(aux->next!=NULL)
            aux = aux->next;

        aux->next = newPet(name, age, weight, specie);
    }
}

void petListPrint(Pet *pet)
{
    if(pet != NULL)
    {
        printf("Nome: %s | Idade: %d | Peso: %f\n", pet->name, pet->age, pet->weight);
        if(pet->next!=NULL)
            petListPrint(pet->next);
    }
}
