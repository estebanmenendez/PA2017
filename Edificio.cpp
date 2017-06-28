/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Edificio.cpp
 * Author: ernesto
 * 
 * Created on 9 de junio de 2017, 07:14 PM
 */

#include "Edificio.h"
#include "dtEdificio.h"

    Edificio::Edificio (){}
    Edificio::Edificio(const Edificio& orig){}

Edificio::Edificio(string nombre, int pisos, float gastosComunes) {
    this->nombreEdificio=nombre;
    this->cantpisosEdificio=pisos;
    this->gastosComunes=gastosComunes;
    
}

void Edificio::SetGastosComunes(float gastosComunes) {
    this->gastosComunes = gastosComunes;
}

float Edificio::GetGastosComunes() const{
    return gastosComunes;
}

void Edificio::SetCantpisosEdificio(int cantpisosEdificio) {
    this->cantpisosEdificio = cantpisosEdificio;
}

int Edificio::GetCantpisosEdificio() const {
    return cantpisosEdificio;
}

void Edificio::SetNombreEdificio(string nombreEdificio) {
    this->nombreEdificio = nombreEdificio;
}

string Edificio::GetNombreEdificio() const {
    return nombreEdificio;
}

dtEdificio* Edificio::getEdificio(){
    return new dtEdificio(this->nombreEdificio, this->cantpisosEdificio, this->gastosComunes);
}

Edificio::~Edificio(){}