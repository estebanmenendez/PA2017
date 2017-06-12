/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   dtPropEnDpto.cpp
 * Author: ernesto
 * 
 * Created on 11 de junio de 2017, 06:11 PM
 */

#include "dtPropEnDpto.h"

dtPropEnDpto::dtPropEnDpto(string codigoProp, string letraDepartamento){
    this->codigoProp = codigoProp;
    this->letraDepartamento = letraDepartamento;
}

dtPropEnDpto::dtPropEnDpto() {
}

dtPropEnDpto::dtPropEnDpto(const dtPropEnDpto& orig) {
}

dtPropEnDpto::~dtPropEnDpto() {
}

dtPropEnDpto::getcodigoProp() const{
    return this->codigoProp;
}

dtPropEnDpto::getletraDepartamento() const{
    return this->letraDepartamento;
}