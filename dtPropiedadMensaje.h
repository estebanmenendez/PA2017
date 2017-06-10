/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   dtPropiedadMensaje.h
 * Author: Boris
 *
 * Created on 9 de junio de 2017, 11:54 PM
 */

#include <string.h>
#include <stdio.h>
#include <iostream>
#include "dtDireccion.h"

#ifndef DTPROPIEDADMENSAJE_H
#define DTPROPIEDADMENSAJE_H

using namespace std;

class dtPropiedadMensaje {
public:
    
    dtPropiedadMensaje();
    dtPropiedadMensaje(const dtPropiedadMensaje& orig);
    virtual ~dtPropiedadMensaje();
    dtPropiedadMensaje(string codigoProp, dtDireccion direccionProp, int cantMensajesEnviados);
    
    string getcodigoProp() const;
    dtDireccion getdireccionProp() const;
    int cantMensajesEnviados() const;
    
private:
    string codigoProp;
    dtDireccion direccionProp;
    int cantMensajesEnviados;
    

};

#endif /* DTPROPIEDADMENSAJE_H */

