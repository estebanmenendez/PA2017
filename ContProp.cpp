/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ContProp.cpp
 * Author: juan
 * 
 * Created on 9 de junio de 2017, 08:17 PM
 */
#include "ContProp.h"
#include "ICollection.h"
#include "Edificio.h"
#include "Propiedad.h"
#include "ListDicc.h"
#include "StringKey.h"
#include "Departamento.h"
#include "Zona.h"
#include "Interesado.h"
#include <stdexcept>

ContProp::ContProp() {
}

ContProp::ContProp(const ContProp& orig) {
}

ContProp::~ContProp() {
}
ListDicc * ContProp::listaDepartamentos(){
    IIterator *it =IDepartamento->getIteratorObj();
    ListDicc *resul=new ListDicc();
    while (it->hasNext()) {
        Departamento* c= dynamic_cast <Departamento*> (it->getCurrent());
        StringKey *sk=new StringKey(c->getDatos()->getletraDepartamento());
        resul->add(c->getDatos(),sk);
        it->next();
    }
    delete it;
    return resul;

}


void ContProp::seleccionarDepartamentos(string letraDepto){
    
        
    
}
 ListDicc * listaZonasDepartamentos(string){
     
 }

void seleccionarDepartamentos(string){
    
}

ListDicc* ContProp::listaZonasDepartamentos(string letraDepartamento){
    IIterator *it =IDepartamento->getIteratorObj();
    ListDicc *resZon=new ListDicc();
    while (it->hasNext()) {
        Zona* z = new Zona;
        Departamento* d= dynamic_cast <Departamento*> (it->getCurrent());
        StringKey *sk=new StringKey(d->getDatos()->getletraDepartamento());
        resZon->add(d->getZonas(letraDepartamento),sk);
        it->next();
    }
    delete it;
    return resZon;

}


void ContProp::seleccionaZona(string){}
dtPropiedadMensaje * ContProp::listaPropiedades(string){}
dtPropiedadMensaje * ContProp::seleccionaPropiedad(string,int){}
void ContProp::enviarMensaje(string){}
string ContProp::ingesrarCodProp(string){}
void ContProp::modifPropCasa(dtPropiedadCasa){}
void ContProp::modifPropApto(dtPropiedadApto){}
dtConversaInmobiliaria * ContProp::listaConversacionesInmobiliarias(){}
void ContProp::seleccionaConversacion(string){}
dtMensajes * ContProp::listaUltimosCincoMensajes(){}
void ContProp::seleccionaMensaje(string){}
void ContProp::agregaMensaje(string,string){}
dtPropiedadDisponible * ContProp::listaPropiedadesDisponibles(){}
dtPropiedadInmobiliaria * ContProp::seleccionaPropiedadDisponible(string){}
void ContProp::altaInteresado (string nombre, string apellido, int edad, string email){
    Interesado * i = new Interesado(nombre, apellido, edad, email);
    
}

void ContProp::altaEdificio(string nombre, int pisos, float gastosComunes){
    
    Edificio* e=new Edificio(nombre, pisos, gastosComunes);//creo el objeto edificio
    StringKey *sk=new StringKey(nombre);//creo la clave de edificio que es el nombre
   if(IDepartamento->member(sk)!=true)//pregunto si ya existe
    IDepartamento->add(e,sk);//agrego el objeto mas la clave a la coleccion dicionario
   else throw new invalid_argument("Edificio ya existente");
}

    dtReporteInmobiliaria* ContProp::iniciarReporte(Inmobiliaria){}
void ContProp::altaPropiedadCasa(dtPropiedadCasa*){
//    Propiedad* p= new Propiedad(dtPropiedadCasa*)
//    StringKey* k = new StringKey(Propiedad.codigoProp)
//    Lista* l = new Lista();
//    Propiedad* p = new Propiedad(dtPropiedadCasa);
//    if (dtPropiedadCasa* empr = dynamic_cast <Casa *>(emp[i]))
//    cout<<empr;
//
//    else
//    break;
//
//    Propiedad* p = new Propiedad(dtPropiedadCasa);
}

void ContProp::altaPropiedadApto(dtPropiedadApto*){
    
 // if (dtPropiedadApto* empr = dynamic_cast <Apartamento *>(emp[i]))
                
}

void ContProp::eliminarProp(string codigo){
    StringKey* claveP = new StringKey(codigo);
    //bool estaProp = Diccionario->member(claveP);
//    Propiedad* p = dynamic_cast<Propiedad*>(this->Diccionario->find(claveP));
    
   
}
