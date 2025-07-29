# 🚗 Caminhos entre Cidades (Grafo em C)

Este projeto implementa um **grafo direcionado** em **linguagem C** para representar cidades do estado do **Piauí** como **vértices**, e estradas como **arestas**.  
O programa encontra **todos os caminhos possíveis** de **Corrente até Parnaíba**, exibindo também **o menor e o maior caminho** em quantidade de cidades.

---

## 📌 Funcionalidades
✅ Representa as cidades como vértices em um **grafo direcionado**  
✅ Mostra todas as conexões existentes entre as cidades  
✅ Encontra **todos os caminhos possíveis** de Corrente até Parnaíba  
✅ Exibe o **menor** e **o maior caminho** encontrados  

---

## 📂 Estrutura do Código


### 🔹 Definições
```c
#define MAX 10       // Número máximo de cidades
#define MAX_CAM 50   // Número máximo de caminhos possíveis
```

### 🔹 Lista de cidades
```c
char *cidades[MAX] = {
    "Corrente", "Gilbués", "Bom Jesus", "Floriano", "Oeiras",
    "Teresina", "Campo Maior", "Piripiri", "Luís Correia", "Parnaíba"
};
```

### 🔹 Estruturas principais
- `grafo[MAX][MAX]` → matriz de adjacência que indica as conexões entre as cidades  
- `todosCaminhos[MAX_CAM][MAX]` → armazena todos os caminhos encontrados  
- `tamCaminhos[MAX_CAM]` → guarda o tamanho de cada caminho  
- `total` → conta quantos caminhos foram encontrados  

---

## 🔍 Como Funciona a Busca
O programa utiliza **Busca em Profundidade (DFS)**:

1. Começa em **Corrente (índice 0)**  
2. Visita recursivamente as cidades conectadas  
3. Sempre que chega em **Parnaíba (índice 9)**, salva o caminho encontrado  
4. Ao voltar na recursão, **desmarca a cidade** (backtracking) para permitir outros caminhos  

---

## 📸 Saída
---
<img width="1230" height="392" alt="image" src="https://github.com/user-attachments/assets/1bed2daf-5f62-4c27-8d97-2026fda4698b" />

---

## 🛠️ Estrutura do Grafo
O grafo é definido manualmente no código:
```c
grafo[0][1] = 1; // Corrente -> Gilbués
grafo[1][2] = 1; // Gilbués -> Bom Jesus
grafo[2][3] = 1; // Bom Jesus -> Floriano
grafo[3][4] = 1; // Floriano -> Oeiras
grafo[4][5] = 1; // Oeiras -> Teresina
grafo[5][6] = 1; // Teresina -> Campo Maior
grafo[6][7] = 1; // Campo Maior -> Piripiri
grafo[7][8] = 1; // Piripiri -> Luís Correia
grafo[8][9] = 1; // Luís Correia -> Parnaíba
grafo[5][9] = 1; // Teresina -> Parnaíba
grafo[2][5] = 1; // Bom Jesus -> Teresina
```

---

## 📖 Conceitos Envolvidos
📌 **Grafo direcionado** → As estradas possuem sentido único  
📌 **Matriz de adjacência** → Representação das conexões  
📌 **Busca em Profundidade (DFS)** → Algoritmo para encontrar todos os caminhos  
📌 **Backtracking** → Remove a marcação de cidades visitadas para explorar novos caminhos  

---

## 📜 Licença
📄 Este projeto é de livre utilização para fins acadêmicos.
