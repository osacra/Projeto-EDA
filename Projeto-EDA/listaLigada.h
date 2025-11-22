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
void salvarLista(Lista *li, FILE *arq);
void recuperarDados(Lista *li, FILE *arq);
