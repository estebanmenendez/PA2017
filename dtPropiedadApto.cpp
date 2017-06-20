/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "dtPropiedadApto.h"

dtPropiedadApto::dtPropiedadApto(int cantAmbiente, int cantBanios, int cantDormitorios, bool garage, dtDireccion* direccionProp, float mCuadradosEdificado, string nombreEdificio){
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

int dtPropiedadApto::getcantAmbiente() const{
    return this->cantAmbiente;
}

int dtPropiedadApto::getcantBanios() const{
    return this->cantBanios;
}

int dtPropiedadApto::getcantDormitorios() const{
    return this->cantDormitorios;
}

dtDireccion* dtPropiedadApto::getdireccionProp() const{
    return this->direccionProp;
}

bool dtPropiedadApto::getgarage() const{
    return this->garage;
}

float dtPropiedadApto::getmCuadradosEdificado() const{
    return this->mCuadradosEdificado;
}

string dtPropiedadApto::getnombreEdificio() const{
    return this->nombreEdificio;
}
