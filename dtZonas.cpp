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
}

dtZonas::dtZonas(const dtZonas& orig) {
}
dtZonas::dtZonas(string codigoZona, string nombreZona){
   this->nombreZona=nombreZona;
   this->codigoZona=codigoZona;
}
dtZonas::~dtZonas() {
}

string dtZonas::getCodigoZona() const {
    return this->codigoZona;
}

string dtZonas::getNombreZona() const {
    return this->nombreZona;
}
