#include <stdio.h>
#include <stdlib.h>
#include "lista-encadeada.h"

int main()
{
    printf("Aplicativo destinado a testar o arquivo lista-encadeada.h.\n Seu codigo utiliza-se das funcionalidades por ele disponibilizadas.\n\n");
    
    llist* umaLista; //Criando o ponteiro da lista
    umaLista = lcreate(15); //Criando a lista em si
    printf("-> Lista criada. Primeiro elemento tem valor 15.\n");

    //Adicionando elementos
    laddToStart(&umaLista, 10);
    laddToStart(&umaLista, 255);
    laddToStart(&umaLista, 87);
    laddToStart(&umaLista, 255);
    printf("-> Elementos adicionados: 10, 255, 87, 255.\n");

    //Imprimindo a lista
    printf("-> Impressao: ");
    lprint(umaLista);
    printf("\n");

    //Apagando elementos da lista
    lerase(&umaLista, 0);
    printf("-> Elemento na posicao 0 foi apagado.\n");
    lerase(&umaLista, 2);
    printf("-> Elemento na posicao 2 foi apagado.\n");

    //Imprimindo apos apagar elementos
    printf("-> Impressao: ");
    lprint(umaLista);
    printf("\n");

    //Adicionando elementos, e imprimindo lista
    linsert(&umaLista, 2, 76);
    printf("-> Elemento de valor 76 adicionado na posicao 2.\n");
    printf("-> Impressao: ");
    lprint(umaLista);
    printf("\n");

    //Guardando ponteiro do elemento na posicao 2
    llist* x = lgetPointer(umaLista, 2);
    printf("-> Elemento na posicao 2 guardado como x (com lgetPointer).\n");
    printf("-> Valor de x: %d\n", x->value);

    //Modificando elemento e imprimindo lista
    lchange(&umaLista, 2, 100);
    printf("-> Alterado o valor do elemento na posicao 2 para 100.\n");
    printf("-> Impressao: ");
    lprint(umaLista);
    printf("\n");

    //Reanalisando o valor de x apos modificacao.
    printf("-> Valor de x: %d\n", x->value);

    //Retornando um elemento a partir de um indice
    printf("-> Resultado de lget na posicao 1: %d\n", lget(umaLista, 1));
    printf("-> Resultado de value com lgetPointer na posicao 1: %d\n", lgetPointer(umaLista, 1)->value);

    //Encontrando o indice do primeiro elemento com valor 255
    printf("-> Indice do primeiro elemento com valor 255: %d\n", lfind(umaLista, 255));
    
    //Elemento que vem logo apos o primeiro elemento de valor 255
    printf("-> Elemento que vem logo apos o primeiro elemento de valor 255 (com lfindPointer): %d\n", lfindPointer(umaLista, 255)->next->value);

    //Para nao fechar o programa sem dar tempo de leitura para o usuario
    int espera;
    scanf("%d", &espera);
    return 0;
}
