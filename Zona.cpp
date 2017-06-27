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

#include "Zona.h"
#include "Inmobiliaria.h"

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
    int cantidad= 0;
    IIterator *it =IPropiedad->getIteratorObj();
    Lista *resul=new Lista();
    while (it->hasNext()) {
        Propiedad* p= dynamic_cast <Propiedad*> (it->getCurrent());
        cantidad = dynamic_cast<Interesado*>(usuario)->cantMensajesPropiedad(p->getCodigoProp());
        resul->add(p->getPropiedad(cantidad));
        it->next();
    }
    delete it;
    return resul;
}

Lista* Zona::ultimosCincoMensajes(string codProp){
   Lista *resul=new Lista();
    StringKey *sk= new StringKey(codProp);
    Propiedad *p=dynamic_cast<Propiedad*>(IPropiedad->find(sk));
    if(p!=NULL)
        p->getUltimosCinco();
    else 
        throw invalid_argument("No existe esa Propiedad");
    
return resul;
}
dtPropZonas getPropZonaDpto(Usuarios){}

Propiedad getPropiedad(){}

void Zona::altaPropiedad(Propiedad * p, StringKey* sk){
     
    if(IPropiedad->member(sk)!=true)
    IPropiedad->add(p,sk);
    else throw new invalid_argument("Propiedad ya existente");    

}