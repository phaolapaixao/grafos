#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CIDADES 10
#define MAX_CAMINHOS 100
#define MAX_CAMINHO_TAMANHO 20

// Enum para representar as cidades, para clareza e menos erro de índice
typedef enum {
    CORRENTE,
    GILBUES,
    BOM_JESUS,
    FLORIANO,
    OEIRAS,
    TERESINA,
    CAMPO_MAIOR,
    PIRIPIRI,
    LUIS_CORREIA,
    PARNAIBA
} Cidade;

const char* nomesCidades[MAX_CIDADES] = {
    "Corrente", "Gilbués", "Bom Jesus", "Floriano", "Oeiras",
    "Teresina", "Campo Maior", "Piripiri", "Luís Correia", "Parnaíba"
};

int matrizAdj[MAX_CIDADES][MAX_CIDADES];

int todosCaminhos[MAX_CAMINHOS][MAX_CAMINHO_TAMANHO];
int tamanhoCaminhos[MAX_CAMINHOS];
int totalCaminhos = 0;

int idxMenor = -1;
int idxMaior = -1;

void inicializarGrafo() {
    for (int i = 0; i < MAX_CIDADES; i++)
        for (int j = 0; j < MAX_CIDADES; j++)
            matrizAdj[i][j] = 0;
}

void adicionarEstrada(Cidade origem, Cidade destino) {
    matrizAdj[origem][destino] = 1;
}

void buscarCaminhosRecursivo(Cidade atual, Cidade destino, int visitados[], int caminho[], int nivel) {
    visitados[atual] = 1;
    caminho[nivel] = atual;
    nivel++;

    if (atual == destino) {
        if (totalCaminhos >= MAX_CAMINHOS) {
            printf("Limite maximo de caminhos alcancado!\n");
            visitados[atual] = 0;
            return;
        }
        for (int i = 0; i < nivel; i++) {
            todosCaminhos[totalCaminhos][i] = caminho[i];
        }
        tamanhoCaminhos[totalCaminhos] = nivel;
        totalCaminhos++;
    } else {
        for (int vizinho = 0; vizinho < MAX_CIDADES; vizinho++) {
            if (matrizAdj[atual][vizinho] && !visitados[vizinho]) {
                buscarCaminhosRecursivo(vizinho, destino, visitados, caminho, nivel);
            }
        }
    }

    visitados[atual] = 0; 
}

void imprimirTodosCaminhos() {
    printf("\n--- Todos os caminhos encontrados ---\n");
    for (int i = 0; i < totalCaminhos; i++) {
        printf("Caminho %d (%d cidades): ", i + 1, tamanhoCaminhos[i]);
        for (int j = 0; j < tamanhoCaminhos[i]; j++) {
            printf("%s", nomesCidades[todosCaminhos[i][j]]);
            if (j < tamanhoCaminhos[i] - 1)
                printf(" -> ");
        }
        printf("\n");
    }
}

void encontrarMenorEMaiorCaminhos() {
    if (totalCaminhos == 0) return;

    idxMenor = 0;
    idxMaior = 0;
    for (int i = 1; i < totalCaminhos; i++) {
        if (tamanhoCaminhos[i] < tamanhoCaminhos[idxMenor]) idxMenor = i;
        if (tamanhoCaminhos[i] > tamanhoCaminhos[idxMaior]) idxMaior = i;
    }
}

void imprimirMenorEMaiorCaminhos() {
    if (idxMenor == -1 || idxMaior == -1) {
        printf("Nenhum caminho encontrado.\n");
        return;
    }

    printf("\n--- Caminho mais curto ---\n");
    printf("(%d cidades): ", tamanhoCaminhos[idxMenor]);
    for (int i = 0; i < tamanhoCaminhos[idxMenor]; i++) {
        printf("%s", nomesCidades[todosCaminhos[idxMenor][i]]);
        if (i < tamanhoCaminhos[idxMenor] - 1)
            printf(" -> ");
    }
    printf("\n");

    printf("\n--- Caminho mais longo ---\n");
    printf("(%d cidades): ", tamanhoCaminhos[idxMaior]);
    for (int i = 0; i < tamanhoCaminhos[idxMaior]; i++) {
        printf("%s", nomesCidades[todosCaminhos[idxMaior][i]]);
        if (i < tamanhoCaminhos[idxMaior] - 1)
            printf(" -> ");
    }
    printf("\n");
}

int main() {
    inicializarGrafo();

    adicionarEstrada(CORRENTE, GILBUES);
    adicionarEstrada(GILBUES, BOM_JESUS);
    adicionarEstrada(BOM_JESUS, FLORIANO);
    adicionarEstrada(FLORIANO, OEIRAS);
    adicionarEstrada(OEIRAS, TERESINA);
    adicionarEstrada(TERESINA, CAMPO_MAIOR);
    adicionarEstrada(CAMPO_MAIOR, PIRIPIRI);
    adicionarEstrada(PIRIPIRI, LUIS_CORREIA);
    adicionarEstrada(LUIS_CORREIA, PARNAIBA);
    
    adicionarEstrada(TERESINA, PARNAIBA);
    adicionarEstrada(BOM_JESUS, TERESINA);

    int visitados[MAX_CIDADES] = {0};
    int caminhoAtual[MAX_CAMINHO_TAMANHO];
    totalCaminhos = 0;

    printf("Buscando todos os caminhos de Corrente a Parnaíba...\n");
    buscarCaminhosRecursivo(CORRENTE, PARNAIBA, visitados, caminhoAtual, 0);

    imprimirTodosCaminhos();
    encontrarMenorEMaiorCaminhos();
    imprimirMenorEMaiorCaminhos();

    return 0;
}
