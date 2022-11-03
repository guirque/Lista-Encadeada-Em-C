#include <stdio.h>
#include <stdlib.h>

//Definicao
typedef struct linked_list
{
    int value;
    struct linked_list* next;
} llist;

//Insere elemento na primeira posicao da lista
void laddToStart(llist** aList, int add)
{
    //Criando elemento da lista. newElement e um ponteiro para esse elemento
    llist* newElement = 
    (llist*) malloc(sizeof(llist));
    
    //Modificando informacao do elemento
    newElement->value = add; //ok

    newElement->next = *aList; //Novo elemento aponta para o segundo elemento (que antes era o primeiro)
    *aList = newElement; //Ponteiro apontado por aList (inicio da cadeia) comeca a apontar para esse novo elemento
}

//Apaga um elemento numa posicao da lista
void lerase(llist** aList, int index)
{
    llist* before = NULL;
    llist* current = *aList;
    for(int i = 0; i <= index; i++)
    {
        //Encontrado
        if(i == index)
        {
            if(index != 0) before->next = current->next; //Mudando o ponteiro do anterior para o posterior
            else *aList = current->next; //Caso o elemento seja o primeiro da lista, mudamos a quem aponta o ponteiro inicial
            free(current); //Apagando o atual da memoria
        }
        //Nao Encontrado
        else
        {
            before = current;
            current = current->next;
        }
    }

}

//Cria uma lista com elemento inicial de valor especificado
llist* lcreate(int add)
{
    //Cria o ponteiro para o primeiro elemento da lista encadeada
    llist* l = (llist*) malloc(sizeof(llist));
    l->value = add;
    l->next = NULL;
    return l;
}

//Retorna o valor do elemento na posicao index
int lget(llist* aList, int index)
{
    for(int i = 0; i <= index; i++)
    {
        if(i == index) return aList->value;
        else aList = aList->next;
    }
}

//Retorna o indice do primeiro elemento de valor value. -1 caso nao exista.
int lfind(llist* aList, int value)
{
    for(int i = 0; aList != NULL; i++)
    {
        if(aList->value == value) return i;
        else aList = aList->next;
    }
    return -1;
}

//Imprime a lista
void lprint(llist* aList)
{
    printf("{");
    for(int i = 0; aList != NULL; i++)
    {
        if(aList->next != NULL)
            printf("%d, ", aList->value);
        else
            printf("%d", aList->value);
        aList = aList->next;
    }
    printf("}");
}

int main()
{
    llist* umaLista; //Criando o ponteiro da lista
    umaLista = lcreate(15); //Criando a lista em si
    
    //Adicionando elementos
    laddToStart(&umaLista, 10);
    laddToStart(&umaLista, 255);
    laddToStart(&umaLista, 87);
    laddToStart(&umaLista, 255);
    
    //Imprimindo a lista
    lprint(umaLista);
    
    //Apagando elementos da lista
    lerase(&umaLista, 0);
    lerase(&umaLista, 2);
    
    //Imprimindo apos apagar elementos
    printf("\n");
    lprint(umaLista);
    
    //Retornando um elemento a partir de um indice
    printf("\nResultado de lget: %d", lget(umaLista, 1));
    
    //Encontrando o indice do primeiro elemento com valor 255
    printf("\nIndice do primeiro elemento com valor 255: %d\n", lfind(umaLista, 255));
    
    return 0;
}
