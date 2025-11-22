#include <stdio.h>
#include <stdlib.h>
#include "listaLigada.h"
#include "manipularLista.h"

int main()
{
    Lista *li = criarLista();

    FILE *arqLeitura = fopen("clientes.txt", "rb");
    recuperarDados(li, arqLeitura);
    fclose(arqLeitura);

    FILE *arqEscrita = fopen("clientes.txt", "wb");

    int escolha = 1;

    while(escolha != 7){
        system("cls");
        printf("ACME S.A - BANCO DE CLIENTES\n\n");

        printf("1 - Inserir novo cliente\n");
        printf("2 - Relatorio completo de clientes\n");
        printf("3 - Buscar cliente por codigo\n");
        printf("4 - Buscar cliente(s) por nome\n");
        printf("5 - Editar dados de cliente\n");
        printf("6 - Remove cliente\n");
        printf("7 - Salvar e sair\n\n");

        scanf("%d", &escolha);
        getchar();

        switch(escolha){
        case 1:
            inserirClienteMenu(li);
            break;
        case 2:
            imprimirClientes(li);
            getchar();
            break;
        }
    }
    system("cls");
    salvarLista(li, arqEscrita);
    fclose(arqEscrita);

    printf("Programa finalizado!\n");


    return 0;
}
