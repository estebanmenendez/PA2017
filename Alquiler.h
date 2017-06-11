/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alquiler.h
 * Author: esteban
 *
 * Created on 11 de junio de 2017, 06:44 PM
 */

#ifndef VENTA_H
#define VENTA_H

#include<string.h>
#include <stdio.h>
#include <iostream>
#include "Aviso.h"

using namespace std;

class alquiler : public aviso {
private:
	 int precioALquiler;
public:
    
    alquiler();
    alquiler(const alquiler & orig);
    virtual ~alquiler();
    
    void altaAlquiler(float);
    bool esVenta();
    bool esAlquiler();
    
    float getPrecioAlq();
    void setPrecio(float);

    
};

#endif /* VENTA_H */