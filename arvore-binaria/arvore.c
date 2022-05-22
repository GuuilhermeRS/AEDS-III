#include <stdio.h>
#include <stdlib.h>

typedef struct no {
  int valor;
  struct no *esq, *dir;
} s_no;

typedef struct arvore {
  s_no *raiz;
} s_arvore;


/* PROTÓTIPOS DAS FUNÇÕES */
s_arvore *criarArv();
s_no *criarNo(int valor);
void inserir(s_arvore *arv, s_no *no);
void inserirEsquerda(s_no *raiz, s_no *no);
void inserirDireita(s_no *raiz, s_no *no);
void imprimirArv(s_arvore *raiz);
int buscar(s_no *raiz, int valor);
int altura(s_no *raiz);
void imprimirPreOrdem(s_no *raiz);
void imprimirInOrdem(s_no *raiz);
void imprimirPosOrdem(s_no *raiz);
s_no *remover(s_no *raiz, int valor);


int main() {
  s_arvore *arv = criarArv();
  int removido;
  
  int busca, valor, altura_arvore;

  inserir(arv, criarNo(7));
  inserir(arv, criarNo(13));
  inserir(arv, criarNo(20));
  inserir(arv, criarNo(4));
  inserir(arv, criarNo(1));
  inserir(arv, criarNo(18));
  inserir(arv, criarNo(5));
  inserir(arv, criarNo(11));
  
  
  printf("\nIn-ordem:   ");
  imprimirInOrdem(arv->raiz);

  printf("\nPre-ordem:    ");
  imprimirPreOrdem(arv->raiz);

  printf("\nPos-ordem:   ");
  imprimirPosOrdem(arv->raiz);

  altura_arvore = altura(arv->raiz);
  printf("\nAltura: %d\n", altura_arvore);

  printf("\nInforme o valor a ser procurado na arvore: ");
  scanf("%d", &valor); 

  busca = buscar(arv->raiz, valor);
  if(busca) printf("Valor encontrado!\n");
  else printf("Valor nao encontrado!\n");

  

  

  printf("\nIn-ordem: ");
  imprimirInOrdem(arv->raiz);

  remover(arv->raiz, 13);
  
  printf("\nIn-ordem: ");
  imprimirInOrdem(arv->raiz);




  


    

  return 0;
}

s_arvore *criarArv() {
  s_arvore *arv = (s_arvore *)malloc(sizeof(s_arvore));
  if(arv == NULL) {
    printf("Erro ao alocar memória para a árvore.\n");
    exit(1);
  }

  arv->raiz = NULL;
  return arv;
}

s_no *criarNo(int valor) {
  s_no *no = (s_no *)malloc(sizeof(s_no));
  if(no == NULL) {
    printf("Erro ao alocar memória para o nó.\n");
    exit(1);
  }

  no->valor = valor;
  no->esq = NULL;
  no->dir = NULL;

  return no;
}

void inserir(s_arvore *arv, s_no *no) {
  if(arv->raiz == NULL) {
    arv->raiz = no;
  } else {
    if(no->valor < arv->raiz->valor) {
      inserirEsquerda(arv->raiz, no);
    } else {
      inserirDireita(arv->raiz, no);
    }
  }
}

void inserirEsquerda(s_no *raiz, s_no *no) {
  if(raiz->esq == NULL) {
    raiz->esq = no;
  } else {
    if(no->valor < raiz->esq->valor) {
      inserirEsquerda(raiz->esq, no);
    } else {
      inserirDireita(raiz->esq, no);
    }
  }
}

void inserirDireita(s_no *raiz, s_no *no) {
  if(raiz->dir == NULL) {
    raiz->dir = no;
  } else {
    if(no->valor < raiz->dir->valor) {
      inserirEsquerda(raiz->dir, no);
    } else {
      inserirDireita(raiz->dir, no);
    }
  }
}

void imprimirArv(s_arvore *arv) {
	printf("      %d \n", arv->raiz->valor);
  printf("  %d     %d\n", arv->raiz->esq->valor, arv->raiz->dir->valor);
  printf("%d  %d   %d  %d\n",
    arv->raiz->esq->esq->valor, arv->raiz->esq->dir->valor,
    arv->raiz->dir->esq->valor, arv->raiz->dir->dir->valor
  );
  printf("              %d\n", arv->raiz->dir->dir->esq->valor);
}

int buscar(s_no *raiz, int valor) {
  if(raiz == NULL) {
    return 0;
  } else {
    if(valor == raiz->valor) {
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

int altura(s_no *raiz) {
  if(raiz == NULL) {
    return 0;
  } else {
    int esq = altura(raiz->esq);
    int dir = altura(raiz->dir);

    if(esq > dir) {
      return esq + 1;
    } else {
      return dir + 1;
    }
  }
}

void imprimirPreOrdem(s_no *raiz) {
  if(raiz != NULL) {
    printf("%d ", raiz->valor);
    imprimirPreOrdem(raiz->esq);
    imprimirPreOrdem(raiz->dir);
  }
}

void imprimirInOrdem(s_no *raiz) {
  if(raiz!= NULL) {
    imprimirInOrdem(raiz->esq);
    printf("%d ", raiz->valor);
    imprimirInOrdem(raiz->dir);
  }
}

void imprimirPosOrdem(s_no *raiz) {
  if(raiz != NULL) {
    imprimirPosOrdem(raiz->esq);
    imprimirPosOrdem(raiz->dir);
    printf("%d ", raiz->valor);
  }
}

s_no *remover(s_no *raiz, int valor) {
  if(raiz == NULL) {
    printf("Valor nao encontrado!\n");
    return NULL;
  } else {
    // procurar o nó a remover
    if(raiz->valor == valor) {

      // Remover nó folha
      if(raiz->esq == NULL && raiz->dir == NULL) {
        s_no *aux = raiz;
        raiz = NULL;
        free(aux);
        return raiz;
      }

      // Remover nó com um filho
      if(raiz->esq != NULL && raiz->dir == NULL 
      || raiz->dir != NULL && raiz->esq == NULL) {
        s_no *aux = raiz;
        if(raiz->esq != NULL) {
          raiz = raiz->esq;
        } else {
          raiz = raiz->dir;
        }
        free(aux);
        return raiz;
      }

      // Remover nó com dois filhos
      if(raiz->esq != NULL && raiz->dir != NULL) {
        s_no *aux = raiz;
        s_no *aux2 = raiz->dir;

        // encontrar o sucessor
        raiz = raiz->dir;
        while(raiz->esq != NULL) {
          raiz = raiz->esq;
        }
        raiz->esq = aux->esq;

        while(aux2->esq != raiz) {
          aux2 = aux2->esq;
        }

        if(raiz->dir == NULL) {
          raiz->dir = aux2;
          aux2->esq = NULL;
        } else {
          aux2->esq = raiz->dir;
          raiz->dir = aux2;
        }

        free(aux);
        return raiz;
      }


    } else {
      if(valor < raiz->valor) {
        raiz->esq = remover(raiz->esq, valor);
      } else {
        raiz->dir = remover(raiz->dir, valor);
      }
      return raiz;
    }
  }
}




