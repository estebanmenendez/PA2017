#include "Lista.h"
#include "ICollectible.h"
#include "ICollection.h"
#include "NodoLista.h"

using namespace std;

Lista::Lista(){
	this->pri=new NodoLista();
	this->tam=0;
	this->ult=this->pri;
}

void Lista::add(ICollectible* elem){
	NodoLista* n=new NodoLista(NULL,elem);
	this->ult->setNext(n);
	this->tam++;
	this->ult=this->ult->getNext();
}

bool Lista::member(ICollectible* elem){
	NodoLista* iter=this->pri;
	while ((iter->hasNext()) && (iter->getNext()->getElem()!=elem)){
		iter=iter->getNext();
	}
	if (iter->hasNext())
		return(true);
	else
		return(false);
}

bool Lista::remove(ICollectible* elem){
	NodoLista* iter=this->pri;
	while ((iter->hasNext()) && (iter->getNext()->getElem()!=elem)){
		iter=iter->getNext();
	}
	if (iter->hasNext()){
		NodoLista* aux= iter->getNext();
		iter->setNext(iter->getNext()->getNext());
		this->tam--;
		aux->setNext(NULL);
		delete(aux);
		return(true);
	}
	else
		return(false);
}

//unsigned int Lista::size(){
//	return(this->tam);
//}

ListaIterator* Lista:: getIterator(){
	return(new ListaIterator(this->pri));
}

ICollectible* Lista::first(){
	return(this->pri->getNext()->getElem());
}

ICollectible* Lista::last(){
	return(this->ult->getElem());
}

Lista::~Lista(){
	this->ult=NULL;
	delete(this->pri);
}
