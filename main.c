#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Produto {
    int id;
    char nome[50];
    float preco;
    int quantidadeEstoque;
};

void adicionarProduto();
int gerarId();

int main() {
    FILE *arquivo;

    // Abrir o arquivo no modo de leitura e escrita
    arquivo = fopen("db.txt", "a+");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 0;
    }

    switch (1) {
        case 1: {
            struct Produto novoProduto;

            novoProduto.id = gerarId();

            fflush(stdin);

            printf("Nome do produto: ");
            scanf("%s", novoProduto.nome);

            fflush(stdin);

            char precoString[20];

            printf("Valor do produto: ");
            scanf("%s", precoString);

            novoProduto.preco = strtof(precoString, NULL);

            fflush(stdin);

            printf("Quantidade em estoque: ");
            scanf("%d", &novoProduto.quantidadeEstoque);

            adicionarProduto(arquivo, novoProduto);
        }
    }

    return 0;
}

void adicionarProduto(FILE *arquivo, struct Produto novoProduto) {
    fprintf(arquivo, "id: %d\nnome: %s\npreco: %2.f\nquantidadeEstoque: %d\n", novoProduto.id, novoProduto.nome, novoProduto.preco, novoProduto.quantidadeEstoque);

    // Exemplo de leitura do arquivo
    rewind(arquivo);

    // Fechar o arquivo quando terminar
    fclose(arquivo);
}

int gerarId() {
    // Obter o tempo atual em segundos desde a época
    time_t t;
    time(&t);

    // Usar o tempo como semente para a função rand
    srand((unsigned int)t);

    // Gerar um número aleatório
    int numeroAleatorio = rand();

    return numeroAleatorio;
}