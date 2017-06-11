/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Aviso.h
 * Author: esteban
 *
 * Created on 11 de junio de 2017, 06:42 PM
 */

#ifndef AVISO_H
#define AVISO_H

#include<string.h>
#include <stdio.h>
#include <iostream>
#include "PropInmo.h"

class aviso {
       
public:
    aviso();
    aviso(const aviso& orig);
    virtual ~aviso();
       
    virtual void setAviso();
    virtual aviso getAviso();
    
    virtual void crearAvisoProp(Propiedad);
    virtual void altaAlquiler();
    virtual void altaVenta(float);
  

private:    
    Alquiler *propEnAlq;
    Venta *propEnVenta;

    

};

#endif /* AVISO_H */