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

class Alquiler : public Aviso{
private:
	 int precioALquiler;
public:
    
    Alquiler();
    Alquiler(const Alquiler & orig);
    virtual ~Alquiler();
    
    void altaAlquiler(float);
    bool esVenta();
    bool esAlquiler();
    
    float getPrecioAlquiler();
    void setPrecioAlquiler(float);

    
};

#endif /* VENTA_H */