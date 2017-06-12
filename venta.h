/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   venta.h
 * Author: esteban
 *
 * Created on 9 de junio de 2017, 08:26 PM
 */

#ifndef VENTA_H
#define VENTA_H

#include<string.h>
#include <stdio.h>
#include <iostream>
#include "aviso.h"

class venta:public aviso {
private:
	int precioTotalVenta;
public:
   
    void venta();
    void venta(const venta& orig);
    virtual ~venta();
    
    void altaVenta();
    bool esVenta();
    bool esAlquiler();
    
    int getPrecioTotalVenta();
    setPrecioTotalVenta(int precioAlquiler);

};

#endif /* VENTA_H */



	
