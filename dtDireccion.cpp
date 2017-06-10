/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   dtDireccion.cpp
 * Author: lucia
 * 
 * Created on 6 de mayo de 2017, 05:11 PM
 */

#include "dtDireccion.h"

dtDireccion::dtDireccion() {
}

dtDireccion::dtDireccion(const dtDireccion& orig) {
    
}

dtDireccion::~dtDireccion() {
}

dtDireccion::dtDireccion(string ciudad, string numero, string calle){
    this->ciudad = ciudad;
    this->numero = numero;
    this->calle = calle;
}