/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   zona.h
 * Author: lucia
 *
 * Created on 9 de junio de 2017, 06:45 PM
 */
#include <string.h>
#include <stdio.h>
#include <iostream>
#include "propiedad.h"

#ifndef ZONA_H
#define ZONA_H

using namespace std;

class zona {
public:
    zona();
    zona(const zona& orig);
    virtual ~zona();
    
    dtZona** getZona();
    dtPropZona** getPropZonaDpto(usuario inmobiliaria);
    propiedad getPropiedad();
private:
    string codigoZona;
    string nombreZona;
    propiedad* propiedad;
};

#endif /* ZONA_H */

