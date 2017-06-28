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
#include"Interesado.h"
#include"dtZonas.h"
#include"dtPropiedadApto.h"
#include"dtPropZonas.h"
#include"dtPropiedadMensaje.h"
#include"dtPropiedadDisponible.h"
#include "Inmobiliaria.h"
#include "PropInmo.h"
#include "IContUsuario.h"
#include "ListDicc.h"
//#include "ContUsuario.h"

#include"Lista.h"
//#include"ContUsuario.h"

#ifndef ZONA_H
#define ZONA_H

using namespace std;

class Zona: public ICollectible {
public:
    Zona();
    Zona(const Zona& orig);
     Zona(string,string);
    virtual ~Zona();
    Lista * listaPropDisponible(Usuarios *);
    dtZonas* getZonas();
    dtPropZonas getPropZonaDpto(Usuarios);
    Propiedad getPropiedad();
   Lista* listaPropiedades(string );
    void setNombreZona(string nombreZona);
    string getNombreZona() const;
    void setCodigoZona(string codigoZona);
    string getCodigoZona() const;
    dtPropiedadInmobiliaria *seleccionaPropDisponible(string codprop);    
    void altaPropiedad(Propiedad *, StringKey *);
    Lista* ultimosCincoMensajes(string codProp);
private:
    string codigoZona;
    string nombreZona;
    IDictionary * IPropiedad;
};

#endif /* ZONA_H */
