#ifndef __COFO_H
#define __COFO_H

typedef struct _cofo_ Cofo;

/*--------------
Funções que implementam as operações do Cofo (de inteiros)
* --------------*/

/* CRIA um novo Cofo
  Pré-condição: maxItems > 0
  Pós-condição: retorna o endereço de um novo Cofo
  (Inteiros) vazio ou NULL se não conseguir criar
*/
Cofo *cofCreate(int maxItens);

/* ADICIONA um ITEM no Cofo
  Pré-condição : (c é um Cofo criado por uma chamada a
  cofCreate) e (o Cofo não esta cheio)
  Pós-condição: item foi adicionado ao cofo
*/
int cofInsert(Cofo *c, int item);

/* RETIRA um ITEM do Cofo
  Pré-condição: (c é um Cofo criado por uma chamada a
  cofCreate) e && (existe pelo menos um item no Cofo)
  Pós-condição: item foi eliminado do cofo
*/
int cofRemove(Cofo *c, int item);

/* ENCONTRA um ITEM no Cofo
  Pré-condição: (c é um Cofo criado por uma chamada a cofCreate)
  Pós-condição: retorna o item se ele, identificado por key, existir no Cofo
  ou FALSE caso contrátrio
*/
int cofQuery(Cofo *c, int key);

/* DESTRÓI um Cofo
  Pré-condição: (c é um Cofo criado por uma chamada a cofCreate e que está
  vazia) Pós-condição: a memoria usada pelo Cofo foi liberada
*/
int cofDestroy(Cofo *c);

#endif
