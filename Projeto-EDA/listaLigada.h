typedef struct cliente{
    int cod;
    char nome[80];
    char empresa[80];
    char departamento[30];
    char telefone[14];
    char celular[15];
    char email[80];
}CLIENTE;

typedef struct no* Lista;

Lista *criarLista();
void imprimirClientes(Lista *li);
void inserirCliente(Lista *li, CLIENTE cli);
void liberaLista(Lista *li);
void salvarListaBinario(Lista *li, FILE *arq);
