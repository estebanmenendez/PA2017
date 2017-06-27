/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Zona.h
 * Author: lucia
 *
 * Created on 9 de junio de 2017, 06:45 PM
 */
#include <string.h>
#include <stdio.h>
#include <iostream>
#include"ICollectible.h"
#include"IDictionary.h"
#include"Propiedad.h"
#include"Usuarios.h"
#include"dtZonas.h"
#include"dtPropiedadApto.h"
#include"dtPropZonas.h"
#include"dtPropiedadMensaje.h"
#include"Usuarios.h"
#include"Lista.h"


#ifndef ZONA_H
#define ZONA_H

using namespace std;

class Zona: public ICollectible {
public:
    Zona();
    Zona(const Zona& orig);
    virtual ~Zona();
    
    dtZonas* getZonas();
    dtPropZonas getPropZonaDpto(Usuarios);
    Propiedad getPropiedad();
   Lista* listaPropiedades(Usuarios*);
    void setNombreZona(string nombreZona);
    string getNombreZona() const;
    void setCodigoZona(string codigoZona);
    string getCodigoZona() const;
    void altaPropiedad(Propiedad *, StringKey *);
private:
    string codigoZona;
    string nombreZona;
    IDictionary * IPropiedad;
};

#endif /* ZONA_H */

