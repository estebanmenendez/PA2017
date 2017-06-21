/*
 * Lista.h
 *
 *  Created on: 8 de jun. de 2016
 *      Author: apias
 */

#ifndef LISTA_H_
#define LISTA_H_


#include "NodoLista.h"
#include "ICollection.h"
#include "ICollectible.h"
#include "IIterator.h"
#include "ListaIterator.h"

//inserto al final asi puede estar ordenada si me insertan en orden

class Lista:public ICollection{
	protected:
		NodoLista* pri; //es dummy
		NodoLista* ult;
		unsigned int tam;
	public:
		Lista();
		void add(ICollectible* elem);
		virtual bool member(ICollectible* elem);
		virtual bool remove(ICollectible* elem);
//		unsigned int size();
		ICollectible* first();
		ICollectible* last();
		ListaIterator* getIterator();
		virtual ~Lista();
};

#endif /* LISTA_H_ */
