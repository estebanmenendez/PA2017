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
<<<<<<< HEAD
#include "Lista.h"
=======
#include "Propiedad.h"
>>>>>>> 3d6417311bb5557f064f3bb6f052fa850298a12a
#include "ListDicc.h"
#include "StringKey.h"
#include "PropInmo.h"
#include "Departamento.h"
<<<<<<< HEAD
#include "Propiedad.h"
#include "dtPropiedadCasa.h"
#include"Zona.h"
=======
#include "Zona.h"
#include "Interesado.h"
#include <stdexcept>
>>>>>>> 3d6417311bb5557f064f3bb6f052fa850298a12a

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

<<<<<<< HEAD
Departamento* ContProp::seleccionarDepartamentos(string letraDepto){
    IIterator *it=IDepartamento->getIteratorObj();
    StringKey *sk=new StringKey(letraDepto);
    Departamento *d=dynamic_cast<Departamento*>(IDepartamento->find(sk));
    if(d!=NULL){return d;}
    else {throw invalid_argument("No existe ese Departamento");}
  
}



 //ListDicc * ContProp::listaZonasDepartamentos(string){}

=======

void ContProp::seleccionarDepartamentos(string letraDepto){
    
        
    
}
 ListDicc * listaZonasDepartamentos(string){
     
 }

<<<<<<< HEAD
void ContProp::seleccionarDepartamentos(string){}
>>>>>>> ba7536a33636d3110b1875f2b412a3be6d307305
=======
void seleccionarDepartamentos(string){
    
}
>>>>>>> e1c4e125832188d58bbbf66180139338b7502a74

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


<<<<<<< HEAD

=======
>>>>>>> ba7536a33636d3110b1875f2b412a3be6d307305
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
     
     
//     string email;
//     PropInmo* pi = new PropInmo;
//     pi->altaPropEnInmob(p,  )
     
     
     
}

void ContProp::altaPropiedadApto(dtPropiedadApto* propA){
    
     Propiedad* p= new Propiedad(*propA);
     StringKey* sk=new StringKey(p->getCodigoProp());//creo la clave de edificio que es el nombre
     if(IPropiedad->member(sk)!=true)//pregunto si ya existe
     IPropiedad->add(p,sk);//agrego el objeto mas la clave a la coleccion dicionario
     else throw new invalid_argument("Propiedad ya existente");
     
     
                
}

void ContProp::eliminarProp(string codigo){
<<<<<<< HEAD
    StringKey* claveP = new StringKey(codigo);
    
=======
   // StringKey* claveP = new StringKey(codigo);
>>>>>>> 3d6417311bb5557f064f3bb6f052fa850298a12a
    //bool estaProp = Diccionario->member(claveP);
//    Propiedad* p = dynamic_cast<Propiedad*>(this->Diccionario->find(claveP));
    
   
}
