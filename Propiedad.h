/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Propiedad.h
 * Author: lucia
 *
 * Created on 9 de junio de 2017, 06:46 PM
 */

#ifndef PROPIEDAD_H
#define PROPIEDAD_H


#include <string.h>
#include <stdio.h>
#include <iostream>
#include"Lista.h"
#include"Usuarios.h"
#include"ICollectible.h"
#include"dtDireccion.h"
#include"dtPropiedadMensaje.h"
#include"dtMensajes.h"
#include"dtPropiedad.h"
#include"dtPropiedadCasa.h"
#include"dtPropiedadApto.h"
#include "dtPropiedadInmobiliaria.h"


using namespace std;

class Propiedad :public ICollectible {
public:
    Propiedad();
    Propiedad(dtPropiedadCasa);
    Propiedad(dtPropiedadApto);
    Propiedad(const Propiedad& orig);
    virtual ~Propiedad();
    
  void esCasaP();
  void esAptoP();
  bool perteneceInmobiliaria();
  dtPropiedadMensaje * getPropiedad(int);
  Lista* getUltimosCinco();
  void eliminarLinksPropInmo();
  string getCodigoProp();
  dtPropiedadInmobiliaria* getPropiedadDisponible();

private:
    string codigoProp;
    int cantAmbientes;
    int cantBanios;
    int cantDormitorios;
    bool garage;
    dtDireccion * direccionProp;
    float mCuadradosEdificado;
    float mCuadradosTotales;
    
//    // link con Prop-Inmo  
//    
//    PropInmo* propinmo;
};
#endif	// PROPIEDAD_H

