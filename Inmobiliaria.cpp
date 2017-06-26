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

#include "Inmobiliaria.h"

Inmobiliaria::Inmobiliaria(){
    
}

Inmobiliaria::~Inmobiliaria(){
    
}

Inmobiliaria::Inmobiliaria(string nombre, dtDireccion* dir, string email){
    this->nombreInm = nombre;
    this->direccion = dir;
    Usuarios::getEmail()=email;
}     

void Inmobiliaria::altaPropEnInmob(Propiedad *p, string email){
     PropInmo* pi= new PropInmo();
     StringKey* sk=new StringKey(p->getCodigoProp());//creo la clave de edificio que es el nombre
     if(IPropInmo->member(sk)!=true)//pregunto si ya existe
     IPropInmo->add(pi,sk);//agrego el objeto mas la clave a la coleccion dicionario
     else throw new invalid_argument("Propiedad ya existente");  
         
}

