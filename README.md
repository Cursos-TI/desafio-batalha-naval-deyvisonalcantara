

# 🛳️ Batalha Naval – Habilidades em Formas Geométricas (C)

Este projeto implementa um **tabuleiro de Batalha Naval** com a capacidade de aplicar habilidades especiais representadas por matrizes geométricas (cone, cruz e octaedro) que afetam áreas específicas do mapa.

O propósito é demonstrar o uso de **matrizes 2D**, **posicionamento espacial**, limites de tabuleiro e geometria por condicionais, aplicados em linguagem C.



📌 Funcionalidades do Projeto

 ✔️ 1. Tabuleiro de 10x10

Inicializado com água (valor `0`).

✔️ 2. Navios

Representados pelo valor `3` (definido em `#define NAVIO`).

✔️ 3. Habilidades especiais

As habilidades têm tamanho `7x7` e utilizam valor `1` na matriz de habilidade, mas são desenhadas no tabuleiro com `5`.

As formas disponíveis são:

* 🔺 **Cone** (aponta para baixo)
* ✛ **Cruz**
* 🔷 **Octaedro/Losango**

 ✔️ 4. Aplicação da habilidade

A habilidade é "sobreposta" no tabuleiro respeitando:

* Posição central indicada
* Limites (bordas não geram erro)
* Navios não são sobrescritos


## 🎨 Representações no Tabuleiro

| Símbolo | Significado                  |
| ------- | ---------------------------- |
| `0`     | Água                         |
| `3`     | Navio                        |
| `5`     | Habilidade especial aplicada |

---

 🚀 Como Executar

1. Copie o código para um arquivo `.c`
   Exemplo: `batalhaNaval.c`

2. Compile o programa:

```bash
gcc batalhaNaval.c -o batalha
```

3. Execute:

```bash
./batalha
```

---

🧩 Exemplo de Aplicação

As habilidades são aplicadas no `main()` desta forma:

```c
aplicarHabilidade(tabuleiro, cone, 1, 5);
aplicarHabilidade(tabuleiro, cruz, 7, 2);
aplicarHabilidade(tabuleiro, octaedro, 5, 7);
```

Cada habilidade tem um **centro**, e o desenho é projetado ao redor.

---
 🔍 Objetivo Didático

Este projeto ajuda você a aprender:

* Manipulação de matrizes em C
* Criação de padrões geométricos via lógica condicional
* Respeitar limites de matriz
* Gerenciamento de camadas (navio vs habilidade)
* Visualização e debugging de matrizes

---

 📄 Licença

Este projeto é livre para uso acadêmico e aprendizado.

---


