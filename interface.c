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

    //Modificando elemento e imprimindo lista
    lchange(&umaLista, 2, 100);
    printf("-> Alterado o valor do elemento na posicao 2 para 100.\n");
    printf("-> Impressao: ");
    lprint(umaLista);
    printf("\n");

    //Retornando um elemento a partir de um indice
    printf("-> Resultado de lget na posicao 1: %d\n", lget(umaLista, 1));

    //Encontrando o indice do primeiro elemento com valor 255
    printf("-> Indice do primeiro elemento com valor 255: %d\n", lfind(umaLista, 255));
    
    //Para nao fechar o programa sem dar tempo de leitura para o usuario
    int espera;
    scanf("%d", &espera);
    return 0;
}
