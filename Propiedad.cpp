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
#include "PropInmo.h"
#include "Alquiler.h"
#include "Venta.h"



Propiedad::Propiedad() {
}    

Propiedad::Propiedad(const Propiedad& orig) {
}

Propiedad::Propiedad(dtPropiedadCasa pc){  
    
    string codCasa = "CASA1";
    this->codigoProp = codCasa;
    this->cantAmbientes = pc.getcantAmbiente();
    this->cantBanios = pc.getcantBanios();
    this->cantDormitorios = pc.getcantDormitorios();
    this->direccionProp = pc.getdireccionProp();
    this->garage = pc.getgarage();
    this->mCuadradosEdificado = pc.getmCuadradosEdificado();
    this->mCuadradosTotales = pc.getmetrosVerdes()+ pc.getmCuadradosEdificado();
    
    
    
    
}

Propiedad::Propiedad(dtPropiedadApto pa){
    
    string codApto = "APTO1";
    this->codigoProp = codApto;
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

dtPropiedadMensaje * Propiedad::getPropiedad(int cantidad){
    
    return new dtPropiedadMensaje(this->codigoProp,this->direccionProp,cantidad);
}

 dtMensajes* Propiedad::getUltimosCinco( ){
     
 }
//Casa * Propiedad::getMetrosVerdes(){}
