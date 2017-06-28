/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Inmobiliaria.cpp
 * Author: ernesto
 * 
 * Created on 9 de junio de 2017, 06:00 PM
 */

#include <stdexcept>

#include "Inmobiliaria.h"

Inmobiliaria::Inmobiliaria(){
    
}

Inmobiliaria::~Inmobiliaria(){
    
}

Inmobiliaria::Inmobiliaria(string nombre, dtDireccion* dir, string email){
    this->nombreInm = nombre;
    this->direccion = dir;
    this->getEmail()=email;
}     

void Inmobiliaria::altaPropEnInmob(Propiedad *p){
     PropInmo* pi= new PropInmo();
     StringKey* sk=new StringKey(p->getCodigoProp());//creo la clave de edificio que es el nombre
     if(IPropInmo->member(sk)!=true){//pregunto si ya existe
     IPropInmo->add(pi,sk);//agrego el objeto mas la clave a la coleccion dicionario
     }
     else throw new invalid_argument("Propiedad en Inmobiliaria ya existente");      
}

string Inmobiliaria::getTipo(){
  return "Inmobiliaria";
}

string Inmobiliaria::getPwd(){
    return this->getPwd();
}

string Inmobiliaria::getEmail(){
   return this->getEmail();
}
int Inmobiliaria::cantMensajesPropiedad(string codProp){
    int cantMensajes = 0;
    StringKey *sk= new StringKey(codProp);
    PropInmo *p=dynamic_cast<PropInmo*>(IPropInmo->find(sk));
    if(p!=NULL)
        cantMensajes +=  p->getCantidadMensajes();   
    else 
        throw invalid_argument("No existe esa Zona");
    return cantMensajes;
    }
    
void Inmobiliaria::altaMensaje(dtFecha* fecha,dtHora* hora,string mensaje, Interesado * usu,string propiedad){
     StringKey * sk=new StringKey(propiedad);
     PropInmo *p=dynamic_cast<PropInmo*>(IPropInmo->find(sk));
     p->altaMensaje(mensaje,fecha,hora,usu);
     
     }
