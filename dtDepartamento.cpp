/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   dtDepartamento.cpp
 * Author: lucia
 * 
 * Created on 6 de mayo de 2017, 06:16 PM
 */

#include "dtDepartamento.h"

dtDepartamento::dtDepartamento( string letraDepartamento, string nombreDepartamento){
    this->letraDepartamento = letraDepartamento;
    this->nombreDepartamento = nombreDepartamento;
}

dtDepartamento::dtDepartamento() {
}

dtDepartamento::dtDepartamento(const dtDepartamento& orig) {
}

dtDepartamento::~dtDepartamento() {
}

string dtDepartamento::getletraDepartamento() const {
    return this->letraDepartamento;
}

string dtDepartamento::getnombreDepartamento() const {
    return this->nombreDepartamento;
}



