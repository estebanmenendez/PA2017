/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   dtPropZonas.cpp
 * Author: ernesto
 * 
 * Created on 11 de junio de 2017, 06:06 PM
 */

#include "dtPropZonas.h"

dtPropZonas::dtPropZonas(string codigoProp, string codigoZona) {
    this->codigoProp = codigoPorp;
    this->codigoZona = codigoZona;
}

dtPropZonas::dtPropZonas() {
}

dtPropZonas::dtPropZonas(const dtPropZonas& orig) {
}

dtPropZonas::~dtPropZonas() {
}

dtPropZonas::getcodigoProp() const{
    return this->codigoProp;
}

dtPropZonas::getcodigoZona() const{
    return this->codigoZona;
}