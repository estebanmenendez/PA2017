/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   dtZonas.h
 * Author: lucia
 *
 * Created on 6 de mayo de 2017, 06:35 PM
 */

#ifndef DTZONAS_H
#define DTZONAS_H
#include <string.h>
#include <stdio.h>
#include <iostream>
#include "ICollectible.h"

using namespace std;

class dtZonas: public ICollectible {
public:
    dtZonas();
    dtZonas(const dtZonas& orig);
    virtual ~dtZonas();
    dtZonas(string codigoZona, string nombreZona);
    dtZonas seleccionaZona(string codigoZona);
    dtZonas listaZonaDepartamento();
    
    
     void setNombreZona(string nombreZona);
     string getNombreZona() const;
     void setCodigoZona(string codigoZona);
     string getCodigoZona() const; 
    
private:
    
    string codigoZona;
    string nombreZona;

};

#endif /* DTZONAS_H */

