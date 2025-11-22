#include <stdio.h>
#include <stdlib.h>
#include "listaLigada.h"

//Struct do tipo no - armazena dados do tipo struct Cliente e um ponteiro para outro no
struct no{
    CLIENTE dados;
    struct no *prox;
};

//Funcao para criar lista
Lista *criarLista(){
    Lista *li;
    li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL){
        *li = NULL;
    }
    return li;
}


void liberaLista(Lista *li){
    if(li != NULL){
        struct no *ptrNo;
        while(*li
               != NULL){
            ptrNo = *li;
            *li = (*li)->prox;
            free(ptrNo);
        }
        free(li);
    }
}


void inserirCliente(Lista *li, CLIENTE cli){
    system("cls");

    //verificacao - lista nao aponta para nenhum no
    if(li == NULL){
        printf("Verifique a criacao da lista!");
        return;
    }

    struct no *noNovoCliente = (struct no*) malloc(sizeof(struct no));

    //verificacao - erro de alocacao do ponteiro no temporario
    if (noNovoCliente == NULL){
        printf("Erro ao alocar memoria");
        return;
    }

    noNovoCliente->dados = cli;

    //verificacao - insercao com lista vazia
    if(*li == NULL){
        noNovoCliente->prox = *li;
        *li = noNovoCliente;
    } else{
        //encontra a posicao para inserir novo no com base no codigo - ordem crescente
        struct no *ant, *atual = *li;
        while(atual != NULL && atual->dados.cod < cli.cod){
            ant = atual;
            atual = atual->prox;
        }
        //verificacao - codigo ja existente
        if(atual == NULL || atual->dados.cod != cli.cod){
            //verificacao - insercao no primeiro no
            if(atual == *li){
                noNovoCliente->prox = *li;
                *li = noNovoCliente;
            }else{
                noNovoCliente->prox = ant->prox;
                ant->prox = noNovoCliente;
            }
        }else {
            printf("Codigo ja existe, verifique os codigos disponiveis!");
        }
    }
}

void imprimirClientes(Lista *li){
    system("cls");
    if(li != NULL){
        struct no *ptrNo = *li;

        while(ptrNo != NULL){
            printf("%d\n%s\n%s\n%s\n%s\n%s\n%s\n\n", ptrNo->dados.cod, ptrNo->dados.nome, ptrNo->dados.empresa,ptrNo->dados.departamento, ptrNo->dados.telefone, ptrNo->dados.celular, ptrNo->dados.email);
            ptrNo = ptrNo->prox;
        }
    }
}


void salvarListaBinario(Lista *li, FILE *arq){
    Lista ptrNo = *li;
    while(ptrNo != NULL){
        fwrite(&(ptrNo->dados), sizeof(CLIENTE), 1, arq);
        ptrNo = ptrNo->prox;
    }
}

