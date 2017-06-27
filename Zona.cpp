/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Zona.cpp
 * Author: lucia
 * 
 * Created on 9 de junio de 2017, 06:45 PM
 */

#include <stdexcept>

#include "Zona.h"
#include "PropInmo.h"
#include "IContUsuario.h"

Zona::Zona() {}

void Zona::setNombreZona(string nombreZona) {
    this->nombreZona = nombreZona;
}

string Zona::getNombreZona() const {
    return nombreZona;
}

void Zona::setCodigoZona(string codigoZona) {
    this->codigoZona = codigoZona;
}

string Zona::getCodigoZona() const {
    return codigoZona;
}

Zona::Zona(const Zona& orig) {}

Zona::~Zona() {}

dtZonas* Zona::getZonas(){
    return new dtZonas(codigoZona, nombreZona);
}

Lista* Zona::listaPropiedades(Usuarios* usuario){
    
}
Lista * Zona::listaPropDisponible(Usuarios *usu){
    IIterator *it=IPropiedad->getIteratorObj();
    Lista *resul=new Lista();
    while (it->hasNext()) {
        
        dtPropiedadDisponible*p= dynamic_cast<dtPropiedadDisponible*>(it->getCurrent());
       
        resul->add(p->getPropiedadDisponible(usu));
    
    }
    delete it;
    return resul;
}

Propiedad * Zona::seleccionaPropDisponible(string codprop){
     IIterator *it=IPropiedad->getIteratorObj();
    StringKey *sk=new StringKey(codprop);
    Propiedad *p=dynamic_cast<Propiedad*>(IPropiedad->find(sk));
    if(p!=NULL){
        return p;
    }
    else
    throw invalid_argument("No existe esa Propiedad");
  
}
dtPropZonas getPropZonaDpto(Usuarios){}

Propiedad getPropiedad(){}