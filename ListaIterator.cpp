/*
 * ListaIterator.cpp
 *
 *  Created on: 8 de jun. de 2016
 *      Author: apias
 */

#include "ListaIterator.h"


ListaIterator::ListaIterator(){
this->current=NULL;
}
ListaIterator::ListaIterator(NodoLista* curr){
	this->current=curr;
}
ICollectible* ListaIterator::getCurrent(){
		return(this->current->getNext()->getElem());
}

bool ListaIterator:: hasCurrent(){
	return(this->current->hasNext());	
}
void  ListaIterator:: next(){
    this->current=this->current->getNext();
}
ListaIterator::~ListaIterator(){}

