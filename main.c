#include "cofoJoelFilho.h"
#include <stdio.h>

#define FALSE 0
#define TRUE 1

int main(void) {
  Cofo *cofo;
  int stat, maxItems = 0, elm = 0, destruido = FALSE;

  printf("quantos itens, no máximo, você quer pôr no cofo? ");
  scanf("%d", &maxItems);
  cofo = cofCreate(maxItems);

  if (cofo != NULL) {
    while (elm >= 0) {
      printf("digite um elemento para pôr no Cofo (coloque um número negativo para pular): ");
      scanf("%d", &elm);
      cofInsert(cofo, elm);
    }

    elm = 1;
    while (elm >= 0) {
      printf("digite um elemento para buscar no cofo (coloque um número negativo para encerrar o programa): ");
      scanf("%d", &elm);

      if (elm < 0) {
        break;
      };

      stat = cofQuery(cofo, elm);

      if (stat) {
        printf("%d estava na coleção \n\n", elm);
        cofRemove(cofo, elm);

        stat = cofQuery(cofo, elm);

        printf("deletando item... \n\n");

        printf("elemento deletado: %d\n\n", elm);
      } else {
        printf("elemento não encontrado \n\n");
      }
    }
    destruido = cofDestroy(cofo);

    if (destruido) {
      printf("cofo destruido...");
    }
  }

  return FALSE;
}