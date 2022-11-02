#include <stdio.h>
#include <stdlib.h>

//Definicao
//llist*: ponteiro para elemento da lista (sao o L e os ponteiro dentro da lista)
//llist: um elemento da lista
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
    
    //printf("Elemento adicionado: %d\n", (**aList).value);
    //printf("Seu próximo é: %d\n", (**aList).next->value);
}

llist* lcreate()
{
    //Cria o ponteiro para o primeiro elemento da lista encadeada
    llist* l = (llist*) malloc(sizeof(llist));
    return l;
} //ok

//Usar ponteiro de ponteiro permite que se pegue seu conteudo (primeiro elemento) assim como modifique a quem aponta.
//Usar ponteiro permite que se pegue o primeiro elemento (apenas)
int lget(llist* aList, int index)
{
    for(int i = 0; i <= index; i++)
    {
        if(i == index) return aList->value;
        else aList = aList->next;
    }
} //ok

int main()
{
    llist* umaLista; //Criando o ponteiro da lista
    umaLista = lcreate(); //Criando a lista em si
    
    //Adicionando elementos
    laddToStart(&umaLista, 10); 
    laddToStart(&umaLista, 255);
    laddToStart(&umaLista, 87);

    //Retornando um elemento a partir de um indice
    printf("\nResultado de lget: %d\n", lget(umaLista, 0));
    
    return 0;
}