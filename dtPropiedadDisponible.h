/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   dtPropiedadDsiponible.h
 * Author: Boris
 *
 * Created on 9 de junio de 2017, 08:08 PM
 */

#include <string.h>
#include <stdio.h>
#include <iostream>
#include "dtDireccion.h"
#include "ICollectible.h"
#include "Usuarios.h"
#include "ICollectible.h"
#ifndef DTPROPIEDADDSIPONIBLE_H
#define DTPROPIEDADDSIPONIBLE_H

using namespace std;

class dtPropiedadDisponible:public ICollectible{
public:
        dtPropiedadDisponible();
        dtPropiedadDisponible(const dtPropiedadDisponible& orig);
        virtual ~dtPropiedadDisponible();
        dtPropiedadDisponible(string codigoProp, dtDireccion* direccionProp, string alquilerOVenta);
        
        string getcodigoProp() const;
        dtDireccion* getdireccionProp() const;
        string getalquilerOVenta() const;
        void setAlquilerOVenta(string alquilerOVenta);
        string getAlquilerOVenta() const;
        void setDireccionProp(dtDireccion* direccionProp);
        dtDireccion* getDireccionProp() const;
        void setCodigoProp(string codigoProp);
        string getCodigoProp() const;
        dtPropiedadDisponible * getPropiedadDisponible(Usuarios*);
    private:
        string codigoProp;
        dtDireccion* direccionProp;
        string alquilerOVenta;
};


#endif /* DTPROPIEDADDSIPONIBLE_H */

