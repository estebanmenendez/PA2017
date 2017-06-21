/*
 * ListDiccIterator.cpp
 *
 *  Created on: 8 de jun. de 2016
 *      Author: apias
 */

#include "ListDiccIterator.h"


//constructores
ListDiccIterator::ListDiccIterator(){}
ListDiccIterator::ListDiccIterator(NodoDicc* current){
    this->current=current;
}
//operaciones
ICollectible* ListDiccIterator:: getCurrent(){
	return(this->current->getNext()->getPar());
}
    		
bool ListDiccIterator::hasCurrent(){
   return(this->current->hasNext());
}

void ListDiccIterator::next(){
    this->current=this->current->getNext();
}

//destructor
ListDiccIterator::~ListDiccIterator(){
	//this->current= NULL;
}