#include <stdio.h>
#include <stdlib.h>

//Struct que representa um elemento de uma lista.
typedef struct linked_list
{
    //Valor do elemento.
    int value;
    //Ponteiro para o proximo elemento na lista.
    struct linked_list* next;
} llist;

//Insere elemento na primeira posicao de uma lista.
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

//Insere elemento na posicao da lista indicada.
void linsert(llist** aList, int index, int add)
{
    //Criando elemento da lista. newElement e um ponteiro para esse elemento
    llist* newElement = 
    (llist*) malloc(sizeof(llist));
    
    //Modificando informacao do elemento
    newElement->value = add;
    
    //Elementos analisados durante busca
    llist* before = NULL;
    llist* current = *aList;
    
    for(int i = 0; i <= index; i++)
    {
        //Encontrado
        if(i == index)
        {
            newElement->next = current; //O novo elemento passa a apontar para o que esta no indice
            
            //O anterior passa a apontar para o novo elemento
            if(index != 0) before->next = newElement; //Mudando o ponteiro do anterior para o posterior
            else *aList = newElement; //Caso o elemento seja o primeiro da lista, mudamos a quem aponta o ponteiro inicial
        }
        //Nao Encontrado
        else
        {
            before = current;
            current = current->next;
        }
    }
}

//Troca o valor do elemento na posicao da lista indicada.
void lchange(llist** aList, int index, int change)
{
    //Elementos analisados durante busca
    llist* current = *aList;
    for(int i = 0; i <= index; i++)
    {
        //Encontrado
        if(i == index)
        {
            current->value = change;
        }
        //Nao Encontrado
        else
        {
            current = current->next;
        }
    }
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

//Cria uma lista com elemento inicial de valor especificado.
llist* lcreate(int add)
{
    //Cria o ponteiro para o primeiro elemento da lista encadeada
    llist* l = (llist*) malloc(sizeof(llist));
    l->value = add;
    l->next = NULL;
    return l;
}

//Retorna o valor de um elemento numa lista na posicao index.
int lget(llist* aList, int index)
{
    for(int i = 0; i <= index; i++)
    {
        if(i == index) return aList->value;
        else aList = aList->next;
    }
}

//Retorna o ponteiro para um elemento numa lista com posicao index. Caso o elemento nao exista, retorna NULL.
llist* lgetPointer(llist* aList, int index)
{
    for (int i = 0; i <= index; i++)
    {
        if (i == index) return aList;
        else aList = aList->next;
    }
    return NULL;
}

//Retorna o indice do primeiro elemento de valor value. Retorna -1 caso nao exista.
int lfind(llist* aList, int value)
{
    for(int i = 0; aList != NULL; i++)
    {
        if(aList->value == value) return i;
        else aList = aList->next;
    }
    return -1;
}

//Retorna o ponteiro do primeiro elemento de valor value. Retorna NULL caso nao exista.
llist* lfindPointer(llist* aList, int value)
{
    for (int i = 0; aList != NULL; i++)
    {
        if (aList->value == value) return aList;
        else aList = aList->next;
    }
    return NULL;
}

//Imprime uma lista.
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
