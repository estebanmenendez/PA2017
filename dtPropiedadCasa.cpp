/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "dtPropiedadCasa.h"

dtPropiedadCasa::dtPropiedadCasa(int cantAmbiente, int cantBanios, int cantDormitorios, bool garage, dtDireccion direccionProp, float mCuadradosEdificado, float metrosVerdes){
    this->cantAmbiente = cantAmbiente;
    this->cantBanios = cantBanios;
    this->cantDormitorios = cantDormitorios;
    this->direccionProp = direccionProp;
    this->garage = garage;
    this->mCuadradosEdificado = mCuadradosEdificado;
    this->metrosVerdes = metrosVerdes;
}

dtPropiedadCasa::dtPropiedadCasa(){
}

dtPropiedadCasa::dtPropiedadCasa(const dtPropiedadCasa& orig){
}

dtPropiedadCasa::~dtPropiedadCasa(){
}

dtPropiedadCasa::getcantAmbiente() const{
    return this->cantAmbiente;
}

dtPropiedadCasa::getcantBanios() const{
    return this->cantBanios;
}

dtPropiedadCasa::getcantDormitorios() const{
    return this->cantDormitorios;
}

dtDireccion* dtPropiedadCasa::getdireccionProp() const{
    return this->direccionProp;
}

dtPropiedadCasa::getgarage() const{
    return this->garage;
}

dtPropiedadCasa::getmCuadradosEdificado() const{
    return this->mCuadradosEdificado;
}

dtPropiedadCasa::getmetrosVerdes() const{
    return this->metrosVerdes;
}