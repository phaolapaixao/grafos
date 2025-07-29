#include <stdio.h>
#include <string.h>

#define MAX 10
#define MAX_CAM 50

char *cidades[MAX] = {
    "Corrente", "Gilbués", "Bom Jesus", "Floriano", "Oeiras",
    "Teresina", "Campo Maior", "Piripiri", "Luís Correia", "Parnaíba"
};

int grafo[MAX][MAX]; 

int todosCaminhos[MAX_CAM][MAX]; 
int tamCaminhos[MAX_CAM];        
int total = 0;                   

void busca(int atual, int destino, int visitados[], int caminho[], int nivel) {
    visitados[atual] = 1;
    caminho[nivel] = atual;
    nivel++;

    if (atual == destino) {
        for (int i = 0; i < nivel; i++) {
            todosCaminhos[total][i] = caminho[i];
        }
        tamCaminhos[total] = nivel;
        total++;
    } else {
        for (int i = 0; i < MAX; i++) {
            if (grafo[atual][i] && !visitados[i]) {
                busca(i, destino, visitados, caminho, nivel);
            }
        }
    }
    visitados[atual] = 0; 
}

int main() {
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            grafo[i][j] = 0;

    grafo[0][1] = 1;
    grafo[1][2] = 1;
    grafo[2][3] = 1;
    grafo[3][4] = 1;
    grafo[4][5] = 1;
    grafo[5][6] = 1;
    grafo[6][7] = 1;
    grafo[7][8] = 1;
    grafo[8][9] = 1;
    grafo[5][9] = 1;
    grafo[2][5] = 1;

    printf("Conexões do grafo:\n");
    for (int i = 0; i < MAX; i++) {
        printf("%s -> ", cidades[i]);
        for (int j = 0; j < MAX; j++) {
            if (grafo[i][j]) printf("%s ", cidades[j]);
        }
        printf("\n");
    }

    int visitados[MAX] = {0};
    int caminho[MAX];
    busca(0, 9, visitados, caminho, 0);

    printf("\nTodos os caminhos de Corrente até Parnaíba:\n");
    for (int i = 0; i < total; i++) {
        printf("Caminho %d (%d cidades): ", i + 1, tamCaminhos[i]);
        for (int j = 0; j < tamCaminhos[i]; j++) {
            printf("%s", cidades[todosCaminhos[i][j]]);
            if (j < tamCaminhos[i] - 1) printf(" -> ");
        }
        printf("\n");
    }

    if (total > 0) {
        int menor = 0, maior = 0;
        for (int i = 1; i < total; i++) {
            if (tamCaminhos[i] < tamCaminhos[menor]) menor = i;
            if (tamCaminhos[i] > tamCaminhos[maior]) maior = i;
        }

        printf("\nMenor caminho (%d cidades): ", tamCaminhos[menor]);
        for (int j = 0; j < tamCaminhos[menor]; j++) {
            printf("%s", cidades[todosCaminhos[menor][j]]);
            if (j < tamCaminhos[menor] - 1) printf(" -> ");
        }
        printf("\n");

        printf("Maior caminho (%d cidades): ", tamCaminhos[maior]);
        for (int j = 0; j < tamCaminhos[maior]; j++) {
            printf("%s", cidades[todosCaminhos[maior][j]]);
            if (j < tamCaminhos[maior] - 1) printf(" -> ");
        }
        printf("\n");
    } else {
        printf("\nNenhum caminho encontrado!\n");
    }

    return 0;
}
