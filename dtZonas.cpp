/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   dtZonas.cpp
 * Author: lucia
 * 
 * Created on 6 de mayo de 2017, 06:35 PM
 */

#include "dtZonas.h"

dtZonas::dtZonas() {
    this->codigoZona=1;
    this->nombreZona="quie zona";
    }

dtZonas::dtZonas(const dtZonas& orig) {
    this->codigoZona=dtZonas.codigoZona;
    this->nombreZona=dtZonas.nombreZona;
}
dtZonas::dtZonas(string codigoZona, string nombreZona){
    this->codigoZona=codigoZona;
    this->nombreZona=nombreZona;
    
}
dtZonas::~dtZonas() {
}

string dtZonas::getcodigoZona() const {
    return this->codigoZona;
}

string dtZonas::getnombreZona() const {
    return this->nombreZona;
}

void dtZonas::setNombreZona(string nombreZona) {
    this->nombreZona = nombreZona;
}

string dtZonas::getNombreZona() const {
    return nombreZona;
}

void dtZonas::setCodigoZona(string codigoZona) {
    this->codigoZona = codigoZona;
}

string dtZonas::getCodigoZona() const {
    return codigoZona;
}




