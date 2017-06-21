/*
 * Nodo.h
 *
 *  Created on: 8 de jun. de 2016
 *      Author: apias
 */

#ifndef NODO_H_
#define NODO_H_

#include <stdlib.h>
#include "ICollectible.h" 

class NodoLista{
	private:
		ICollectible* elem;
		NodoLista* next;
	public:
		//constructores
		NodoLista();
		NodoLista(NodoLista* next, ICollectible* elem);

		//destructor
		virtual ~NodoLista();

		//operaciones
		void setNext(NodoLista* next);		
		bool hasNext();
		NodoLista* getNext();
		ICollectible* getElem();
		void setElem(ICollectible* elem);
};

#endif /* NODO_H_ */
