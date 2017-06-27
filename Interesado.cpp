/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Interesado.cpp
 * Author: ernesto
 * 
 * Created on 9 de junio de 2017, 06:07 PM
 */

#include "Interesado.h"

  int Interesado::getEdad(){
      
  }
  void Interesado::setEdad(){
      
  }
  Interesado::Interesado(){
      
  }
Interesado::Interesado(string nombre, string apellido,int edad, string email){
    this->nombreInt = nombre;
    this->apellidoInt = apellido;
    this->edad = edad;
    this->getEmail() = email;
}
  Interesado::~Interesado(){
      
  }
string Interesado::getTipo(){
  return "Interesado";
}
string Interesado::getPwd(){
    return this->getPwd();
}
string Interesado::getEmail(){
    return this->getEmail();
}
  int Interesado::cantMensajesPropiedad(string codProp){
    int cantMensajes= 0;
    IIterator * it=IChatInteresado->iterator();
    while (it->hasNext()) {
        Chat *ch=dynamic_cast<Chat*>(it->getCurrent());
        cantMensajes += ch->getCantidadMensaje();
        it->next();
    }
    delete it;
    return cantMensajes;
  }
    
