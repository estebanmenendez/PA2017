/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "dtPropiedadApto.h"

dtPropiedadApto::dtPropiedadApto(int cantAmbiente, int cantBanios, int cantDormitorios, bool garage, dtDireccion direccionProp, float mCuadradosEdificado, string nombreEdificio){
    this->cantAmbiente = cantAmbiente;
    this->cantBanios = cantBanios;
    this->cantDormitorios = cantDormitorios;
    this->direccionProp = direccionProp;
    this->garage = garage;
    this->mCuadradosEdificado = mCuadradosEdificado;
    this->nombreEdificio = nombreEdificio;
}

dtPropiedadApto::dtPropiedadApto(const dtPropiedadApto& orig){
}

dtPropiedadApto::dtPropiedadApto(){
}

dtPropiedadApto::~dtPropiedadApto(){
}

dtPropiedadApto::getcantAmbiente() const{
    return this->cantAmbiente;
}

dtPropiedadApto::getcantBanios() const{
    return this->cantBanios;
}

dtPropiedadApto::getcantDormitorios() const{
    return this->cantDormitorios;
}

dtDireccion* dtPropiedadApto::getdireccionProp() const{
    return this->direccionProp;
}

dtPropiedadApto::getgarage() const{
    return this->garage;
}

dtPropiedadApto::getmCuadradosEdificado() const{
    return this->mCuadradosEdificado;
}

dtPropiedadApto::getnombreEdificio() const{
    return this->nombreEdificio;
}
