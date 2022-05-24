#include <stdio.h>
#include <stdlib.h>

struct no {
  int info;
  struct no *esq, *dir;
};

typedef struct no s_no;

/* Protótipos */
s_no *criar_no();
s_no *inserir(s_no *raiz, int info);
void imprimir(s_no *raiz);
void liberar(s_no *raiz);
int buscar(s_no *raiz, int info);
s_no *remover(s_no *raiz, int info);



int main () {
  s_no *arvore = criar_no();

  arvore = inserir(arvore, 10);
  arvore = inserir(arvore, 20);
  arvore = inserir(arvore, 5);
  arvore = inserir(arvore, 2);
  arvore = inserir(arvore, 29);
  arvore = inserir(arvore, 15);

  remover(arvore, 2);

  imprimir(arvore);

  
  

  printf("\n");
  liberar(arvore);
  return 0;
}

s_no *criar_no() {
  return NULL;
}

s_no *inserir(s_no *raiz, int info) {
  if (raiz == NULL) {
    raiz = (s_no *) malloc(sizeof(s_no));
    raiz->info = info;
    raiz->esq = NULL;
    raiz->dir = NULL;

    return raiz;
  } else {
    if (info < raiz->info) {
      raiz->esq = inserir(raiz->esq, info);
    } else {
      raiz->dir = inserir(raiz->dir, info);
    }
  }

  return raiz;
}

void imprimir(s_no *raiz) {
  if (raiz != NULL) {
    imprimir(raiz->esq);
    printf("%d ", raiz->info);
    imprimir(raiz->dir);
  }
}

void liberar(s_no *raiz) {
  if (raiz != NULL) {
    liberar(raiz->esq);
    liberar(raiz->dir);
    free(raiz);
  }
}

int buscar(s_no *raiz, int info) {
  if (raiz == NULL) {
    return 0;
  } else {
    if (info == raiz->info) {
      return 1;
    } else {
      if (info < raiz->info) 
        return buscar(raiz->esq, info);
      else 
        return buscar(raiz->dir, info);
    }
  }
}

s_no *remover(s_no *raiz, int info) {
  if (raiz != NULL) {
    if (info < raiz->info) {
      raiz->esq = remover(raiz->esq, info);
    } else if (info > raiz->info) {
      raiz->dir = remover(raiz->dir, info);
    } else {
      // Remover nó folha
      if (raiz->dir == NULL && raiz->esq == NULL) {
        free(raiz);
        return NULL;

        // Remover nó com 1 filho
      }
    }
  }
}


