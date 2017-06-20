/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ColGenerica.cpp
 * Author: esteban
 * 
 * Created on 19 de junio de 2017, 06:32 PM
 */

#include "ColGenerica.h"
#include "ListaIterator.h"
#include "String.h"
ColGenerica::ColGenerica() {
//    this->dicc= new ListaDicc();
}

ColGenerica::~ColGenerica() {
}
//Propiedades
ColGenerica::ColGenerica(IDictionary* dicc){
    this->dicc= dicc;
}
void ColGenerica::addP(Propiedad* prop, StringKey* key){
    this->dicc->add(prop,key);
}
bool ColGenerica::member(StringKey* key){
    return(this->dicc->member(key));
}
Propiedad* ColGenerica::removeKey(StringKey* key){
    return((Propiedad*)this->dicc->removeKey(key));
}
Propiedad* ColGenerica::removeObj(StringKey* obj){
    return((Propiedad*)this->dicc->removeObj(obj));
}
Propiedad* ColGenerica::find(StringKey* key){
	Propiedad* a=(Propiedad*)this->dicc->find(key);
	if (a==NULL){
		delete(key);
(invalid_argument("Error: la Propiedad buscada no existe en el sistema \n"));
	}else
    	return(a);    
}
Propiedad* ColGenerica::find(ColGenerica * prop){
    ListaIterator * iter=(ListaIterator*)this->colgen->getIteratorObj();
    bool encontre=false;
    while((iter->hasCurrent())&&(!encontre)){
		ColGenerica* col=(ColGenerica()*)iter->getCurrent();
		if((col->get)==(c.getCodAs())) 
			encontre=true;
		else
			iter->next();
	}
	delete iter;
	return encontre;
    
}