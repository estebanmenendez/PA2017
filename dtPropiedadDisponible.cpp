/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "dtPropiedadDisponible.h"

dtPropiedadDisponible::dtPropiedadDisponible(string codigoProp, dtDireccion* direccionProp, string alquilerOVenta){
    this->codigoProp = codigoProp;
    this->direccionProp = direccionProp;
    this->alquilerOVenta = alquilerOVenta;
}

dtPropiedadDisponible::dtPropiedadDisponible(){
}

dtPropiedadDisponible::dtPropiedadDisponible(const dtPropiedadDisponible& orig){
}

dtPropiedadDisponible::~dtPropiedadDisponible(){
}

string dtPropiedadDisponible::getcodigoProp() const{
    return this->codigoProp;
}
dtDireccion* dtPropiedadDisponible::getdireccionProp() const{
    return this->direccionProp;
}

string dtPropiedadDisponible::getalquilerOVenta() const{
    return this->alquilerOVenta;
}
