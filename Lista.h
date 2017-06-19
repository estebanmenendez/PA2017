/*
 * Lista.h
 *
 *  Created on: 8 de jun. de 2016
 *      Author: apias
 */

#ifndef LISTA_H_
#define LISTA_H_

#include "NodoDicc.h"
#include "IIterator.h"
#include "ICollectible.h"
#include "IDictionary.h"
#include "ListDiccIterator.h"
#include "ListDiccIteratorObj.h"
#include "ListDiccIteratorKey.h"

class Lista: public ICollection {
private:
  Nodo *first;

public:
  Lista();
  ~Lista();

  void add(ICollectible *);
  void remove(ICollectible *);
  bool member(ICollectible *);
  IIterator *iterator();
  
    void add(ICollectible* elem,IKey* key);
    bool member(IKey* key);
    ICollectible* removeKey(IKey* key);
    ICollectible* removeObj(ICollectible* obj);
    ICollectible* find(IKey* key);
    ListDiccIteratorObj* getIteratorObj();
    ListDiccIteratorKey* getIteratorKey();
    unsigned int size();

  bool isEmpty();
};

#endif /* LISTA_H_ */
