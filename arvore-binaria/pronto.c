#include <stdio.h>
#include <stdlib.h>

typedef struct no {
  int valor;
  struct no *esq, *dir;  
} No;

typedef struct arvore {
  No *raiz;
} Arvore;

/* Protótipos */
Arvore *criarArvore();
void inserir(Arvore *arvore, int valor);
void inserirElemento(No *raiz, No *novo);
void imprimirArv(No *raiz, int nivel);
int buscar(No *raiz, int valor);

int main() {
  Arvore *arvore = criarArvore();
  int valor, valor_existe;

  inserir(arvore, 10);
  inserir(arvore, 5);
  inserir(arvore, 3);
  inserir(arvore, 6   );
  inserir(arvore, 15);
  inserir(arvore, 14);
  inserir(arvore, 16);

  imprimirArv(arvore->raiz, 0);
  

  printf("Informe o valor a ser procurado: ");
  scanf("%d", &valor);

  valor_existe = buscar(arvore->raiz, valor);
  if(valor_existe) printf("Valor encontrado!\n");
  else printf("Valor nao encontrado!\n");

  return 1;
}

Arvore *criarArvore() {
  Arvore *a = (Arvore *) malloc(sizeof(Arvore));
  a->raiz = NULL;
  return a;
}

void inserir(Arvore *arvore, int valor) {
  No *novo = (No *) malloc(sizeof(No));
  novo->valor = valor;
  novo->esq = NULL;
  novo->dir = NULL;

  if(arvore->raiz == NULL) {
    arvore->raiz = novo;
  } else {
    inserirElemento(arvore->raiz, novo);
  }
}

void inserirElemento(No *raiz, No *novo) {
  if(novo->valor < raiz->valor) {
    if(raiz->esq == NULL) {
      raiz->esq = novo;
    } else {
      inserirElemento(raiz->esq, novo);
    }
  } else {
    if(raiz->dir == NULL) {
      raiz->dir = novo;
    } else {
      inserirElemento(raiz->dir, novo);
    }
  }
}

void imprimirArv(No *raiz, int nivel) {
	printf("Nivel %d: %d\n", nivel, raiz->valor);
	if(raiz->esq != NULL) {
		nivel++;
		imprimirArv(raiz->esq, nivel);
	}
	
	if(raiz->dir != NULL) {
		imprimirArv(raiz->dir, nivel);
		nivel--;
	}
}

int buscar(No *raiz, int valor) {
  if(raiz == NULL) {
    return 0;
  } else {
    if(raiz->valor == valor) {
      return 1;
    } else {
      if(valor < raiz->valor) {
        return buscar(raiz->esq, valor);
      } else {
        return buscar(raiz->dir, valor);
      }
    }
  }
}
