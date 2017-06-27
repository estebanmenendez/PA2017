/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Usuarios.cpp
 * Author: ernesto
 * 
 * Created on 9 de junio de 2017, 05:41 PM
 */

#include "Usuarios.h"
<<<<<<< HEAD
#include "PropInmo.h"
=======
#include "Inmobiliaria.h"
>>>>>>> fe34853a63c88723e46550e1d1017a7e36ef272d

Usuarios::Usuarios(){
    
}
Usuarios::~Usuarios(){
    
}

 Usuarios* Usuarios::getUsuario(){
     
 }
    bool Usuarios::esInteresado(){
        
    }
    string Usuarios::getEmail(){
        
    }
    string Usuarios::getPwd(){
        
    }
    string Usuarios::getTipo(){
        
    }
<<<<<<< HEAD
    
    string Usuarios::getAlquilerOVenta(string codProp){
        IIterator *it = IPropInmo->getIteratorObj();
        StringKey*sk=new StringKey(codProp);
        PropInmo *c=dynamic_cast<PropInmo*>(IPropInmo->find(sk));
       return c->esAlquileroVenta();
                    
    }
=======
>>>>>>> fe34853a63c88723e46550e1d1017a7e36ef272d
