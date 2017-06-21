#include "NodoLista.h"
#include "String.h"

NodoLista::NodoLista(){
	this->elem=NULL;
	this->next=NULL;
}

NodoLista::NodoLista(NodoLista* next, ICollectible* elem){
	this->elem=elem;
	this->next=next;
}

NodoLista::~NodoLista(){
	this->elem=NULL;
	if(this->hasNext())
		delete(this->next);
}

void NodoLista::setNext(NodoLista* next){
	this->next=next;
}

bool NodoLista::hasNext(){
	return(this->next!=NULL);
}

NodoLista* NodoLista::getNext(){
	return(this->next);
}

ICollectible* NodoLista::getElem(){
	return(this->elem);
}

void NodoLista::setElem(ICollectible* elem){
	this->elem=elem;
}