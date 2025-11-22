#include <stdio.h>
#include <stdlib.h>
#include "listaLigada.h"

void inserirClienteMenu(Lista *li){
    CLIENTE novoCliente;

    system("cls");

    printf("Codigo: ");
    scanf("%d", &novoCliente.cod);
    getchar();

    printf("Nome: ");
    fgets(novoCliente.nome, 80, stdin);

    printf("Empresa: ");
    fgets(novoCliente.empresa, 80, stdin);

    printf("Departamento: ");
    fgets(novoCliente.departamento, 30, stdin);

    printf("Telefone: ");
    fgets(novoCliente.telefone, 14, stdin);

    printf("Celular: ");
    fgets(novoCliente.celular, 15, stdin);

    printf("Email: ");
    fgets(novoCliente.email, 80, stdin);

    inserirCliente(li, novoCliente);
}


