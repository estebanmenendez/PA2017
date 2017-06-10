/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   dtPropiedadInmobiliaria.cpp
 * Author: Boris
 * 
 * Created on 9 de junio de 2017, 08:23 PM
 */

#include "dtPropiedadInmobiliaria.h"

dtPropiedadInmobiliaria::dtPropiedadInmobiliaria(int cantAmbiente, int cantBanios, int cantDormitorios, bool garage, dtDireccion direccionProp, float mCuadradosEdificado, float mCuadradosTotales, string nombreInm){
    this->cantAmbiente = canAmbiente;
    this->cantBanios = cantBanios;
    this->cantDormitorios = cantDormitorios;
    this->direccionProp = direccionProp;
    this->garage = garage;
    this->mCuadradosEdificado = mCuadradosEdificado;
    this->mCuadradosTotales = mCuadradosTotales;
    this->nombreInm = nombreInm;
}

dtPropiedadInmobiliaria::dtPropiedadInmobiliaria() {
}

dtPropiedadInmobiliaria::dtPropiedadInmobiliaria(const dtPropiedadInmobiliaria& orig) {
}

dtPropiedadInmobiliaria::~dtPropiedadInmobiliaria() {
}

dtPropiedadInmobiliaria::getcantAmbiente() const{
    return this->cantAmbiente;
}

dtPropiedadInmobiliaria::getcantBanios() const{
    return this->cantBanios;
}

dtPropiedadInmobiliaria::getcantDormitorios() const{
    return this->cantDormitorios;
}

dtDireccion* dtPropiedadInmobiliaria::getdireccionProp() const{
    return this->direccionProp;
}

dtPropiedadInmobiliaria::getgarage() const{
    return this->garage;
}

dtPropiedadInmobiliaria::getmCuadradosEdificado() const{
    return this->mCuadradosEdificado;
}

dtPropiedadInmobiliaria::getmCuadradosTotales() const{
    return this->mCuadradosTotales;
}

dtPropiedadInmobiliaria::getnombreInm() const{
    return this->nombreInm;
}
