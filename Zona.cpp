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
dtPropZonas getPropZonaDpto(Usuarios){}

Propiedad getPropiedad(){}