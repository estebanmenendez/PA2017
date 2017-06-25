/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Propiedad.cpp
 * Author: lucia
 * 
 * Created on 9 de junio de 2017, 06:46 PM
 */

#include "Propiedad.h"
#include "dtPropiedadCasa.h"



Propiedad::Propiedad() {
}    

Propiedad::Propiedad(const Propiedad& orig) {
}

Propiedad::Propiedad(dtPropiedadCasa pc){  
    
    string casa = "CASA1";
    this->codigoProp = casa;
    this->cantAmbientes = pc.getcantAmbiente();
    this->cantBanios = pc.getcantBanios();
    this->cantDormitorios = pc.getcantDormitorios();
    this->direccionProp = pc.getdireccionProp();
    this->garage = pc.getgarage();
    this->mCuadradosEdificado = pc.getmCuadradosEdificado();
    this->mCuadradosTotales = pc.getmetrosVerdes()+ pc.getmCuadradosEdificado();
    
    
    
    
}

Propiedad::Propiedad(dtPropiedadApto pa){
    
    string apto = "APTO1";
    this->codigoProp = apto;
    this->cantAmbientes = pa.getcantAmbiente();
    this->cantBanios = pa.getcantBanios();
    this->cantDormitorios = pa.getcantDormitorios();
    this->direccionProp = pa.getdireccionProp();
    this->garage = pa.getgarage();
    this->mCuadradosEdificado = pa.getmCuadradosEdificado();
    this->mCuadradosTotales = pa.getmCuadradosEdificado();
}

Propiedad::~Propiedad() {
}

void Propiedad::esCasaP(){
}

void Propiedad::esAptoP(){
}

void Propiedad::eliminarLinksPropInmo(){
}
string Propiedad::getCodigoProp(){
  return this->codigoProp;
}
//Casa * Propiedad::getMetrosVerdes(){}