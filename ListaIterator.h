/*
 * ListaIterator.h
 *
 *  Created on: 8 de jun. de 2016
 *      Author: apias
 */
#ifndef _ListaIterator_H_
#define _ListaIterator_H_


#include "NodoLista.h"
#include "ICollectible.h"
#include "IIterator.h"

class ListaIterator: public IIterator{
		private:
			NodoLista* current;
		public:
			ListaIterator();
			ListaIterator(NodoLista* curr);
			ICollectible* getCurrent();
			bool hasCurrent();
			void next();
			~ListaIterator();
};

#endif /* LISTAITERATOR_H_ */
