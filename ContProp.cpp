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
#include "Lista.h"
#include "ListDicc.h"
#include "StringKey.h"
#include "PropInmo.h"
#include "Departamento.h"
#include "Propiedad.h"
#include "dtPropiedadCasa.h"
#include "Zona.h"
#include "Interesado.h"
#include <stdexcept>

ContProp::ContProp() {
    
}

ContProp::ContProp(const ContProp& orig) {
}

ContProp::~ContProp() {
}
Lista * ContProp::listaDepartamentos(){
    IIterator *it =IDepartamento->getIteratorObj();
    Lista *resul=new Lista();
    while (it->hasNext()) {
        Departamento* c= dynamic_cast <Departamento*> (it->getCurrent());
        StringKey *sk=new StringKey(c->getDatos()->getletraDepartamento());
        resul->add(c->getDatos());
        it->next();
    }
    delete it;
    return resul;

}

Departamento* ContProp::seleccionarDepartamentos(string letraDepto){
    IIterator *it=IDepartamento->getIteratorObj();
    StringKey *sk=new StringKey(letraDepto);
    Departamento *d=dynamic_cast<Departamento*>(IDepartamento->find(sk));
    if(d!=NULL){
        return d;
    }
    else {throw invalid_argument("No existe ese Departamento");}
  
}
Zona* ContProp::seleccionaZona(string letrazona){
    //IIterator * it=IZona->getIteratorObj();
    StringKey *sk= new StringKey(letrazona);
    Zona *z=dynamic_cast<Zona*>(IDepartamento->find(sk));
    if(z!=NULL){return z;}
    else {throw invalid_argument("No existe ese Departamento");
    }
}


Lista* ContProp::listaZonasDepartamentos(string letraDepartamento){
    StringKey *sk=new StringKey(letraDepartamento);

    IIterator *it =IDepartamento->getIteratorObj();
    Lista *resZon=new Lista();
    string letra;
    Zona *zon1=new Zona;
    while (it->hasNext()) {
        Departamento* d= dynamic_cast <Departamento*> (it->getCurrent());
        zon1=d->getZona(letra);
        StringKey *sk=new StringKey(zon1->getCodigoZona());
        resZon->add(zon1);
        it->next();
    }
    delete it;
    return resZon;
    

}

Lista * ContProp::listaPropiedades(string){}

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
    StringKey* sk=new StringKey(nombre);//creo la clave de edificio que es el nombre
    if(IDepartamento->member(sk)!=true)//pregunto si ya existe
    IDepartamento->add(e,sk);//agrego el objeto mas la clave a la coleccion dicionario
    else throw new invalid_argument("Edificio ya existente");
}

    dtReporteInmobiliaria* ContProp::iniciarReporte(Inmobiliaria){}
    
    
void ContProp::altaPropiedadCasa(dtPropiedadCasa* propC){
    
     Propiedad* p= new Propiedad(*propC);
     StringKey* sk=new StringKey(p->getCodigoProp());//creo la clave de edificio que es el nombre
     if(IPropiedad->member(sk)!=true)//pregunto si ya existe
     IPropiedad->add(p,sk);//agrego el objeto mas la clave a la coleccion dicionario
     else throw new invalid_argument("Propiedad ya existente");
     
     string email;
     //Inmobiliaria->getEmail();
     PropInmo* pi = new PropInmo();
     //pi->altaPropEnInmob(p,email);
     
     
     Aviso* av = new Aviso();
     if(propC->getVentaAlq())
     av->crearAvisoProp();   
     
     
     
     
     
}

void ContProp::altaPropiedadApto(dtPropiedadApto* propA){
    
     Propiedad* p= new Propiedad(*propA);
     StringKey* sk=new StringKey(p->getCodigoProp());//creo la clave de edificio que es el nombre
     if(IPropiedad->member(sk)!=true)//pregunto si ya existe
     IPropiedad->add(p,sk);//agrego el objeto mas la clave a la coleccion dicionario
     else throw new invalid_argument("Propiedad ya existente");
     
     
                
}

void ContProp::eliminarProp(string codigo){
    StringKey* claveP = new StringKey(codigo);
    

   // StringKey* claveP = new StringKey(codigo);
    //bool estaProp = Diccionario->member(claveP);
//    Propiedad* p = dynamic_cast<Propiedad*>(this->Diccionario->find(claveP));
    
   
}
