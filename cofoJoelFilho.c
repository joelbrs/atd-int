#include "cofoJoelFilho.h"
#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1

typedef struct _cofo_ {
  int numItems;
  int maxItems;
  int *item;
} Cofo;

Cofo *cofCreate(int maxItems) {
  Cofo *cofo;

  if (maxItems > 0) {
    cofo = (Cofo *)malloc(sizeof(Cofo));
    if (cofo != NULL) {
      cofo->item = (int *)malloc(sizeof(int) * maxItems);

      cofo->maxItems = maxItems;
      cofo->numItems = 0;

      return cofo;
    }
    free(cofo);
  }
  return NULL;
};

int cofInsert(Cofo *c, int item) {
  if (c != NULL && c->numItems < c->maxItems) {
    c->item[c->numItems] = item;
    c->numItems++;

    return TRUE;
  }
  return FALSE;
};

int cofRemove(Cofo *c, int key) {
  int i, j;
  if (c != NULL) {
    if (c->numItems > 0) {
      i = 0, j = 0;
      while (i < c->numItems && c->item[i] != key) {
        i++;
      }
      if (c->item[i] == key) {
        for (j = i; j < c->numItems; j++) {
          c->item[j] = c->item[j + 1];
        }
        c->numItems--;
        return key;
      }
    }
  }
    return FALSE;
  };

  int cofQuery(Cofo * c, int key) {
    if (c != NULL && c->numItems > 0) {
      for (int i = 0; i < c->numItems; i++) {
        if (c->item[i] == key) {
          return TRUE;
        }
      }
    }
    return FALSE;
  };

  int cofDestroy(Cofo * c) {
    if (c != NULL) {
      if (c->numItems != 0) {
        c->numItems = 0;
      }
      free(c->item);
      free(c);

      return TRUE;
    }
    return FALSE;
  };
