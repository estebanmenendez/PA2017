/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   dtPropiedadMensaje.cpp
 * Author: Boris
 * 
 * Created on 9 de junio de 2017, 11:54 PM
 */

#include "dtPropiedadMensaje.h"

dtPropiedadMensaje::dtPropiedadMensaje(string codigoProp, dtDireccion direccionProp, int cantMensajesEnviados){
    this->cantMensajesEnviados = cantMensajesEnviados;
    this->codigoProp = codigoProp;
    this->direccionProp = direccionProp;
}

dtPropiedadMensaje::dtPropiedadMensaje() {
}

dtPropiedadMensaje::dtPropiedadMensaje(const dtPropiedadMensaje& orig) {
}

dtPropiedadMensaje::~dtPropiedadMensaje() {
}

dtPropiedadMensaje::getcodigoProp() const{
    return this->codigoProp;
}

dtDireccion* dtPropiedadMensaje::getdireccionProp() const{
    return this->direccionProp;
}

dtPropiedadMensaje::cantMensajesEnviados() const{
    return this->cantMensajesEnviados;
}