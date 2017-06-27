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

#include <string.h>
#include <stdio.h>
#include <iostream>
#include"ICollectible.h"
#include"dtDireccion.h"

#include"dtPropiedadMensaje.h"
#include"dtMensajes.h"
#include"dtPropiedad.h"
#include"dtPropiedadCasa.h"
#include"dtPropiedadApto.h"
#include "dtPropiedadDisponible.h"

#ifndef PROPIEDAD_H
#define PROPIEDAD_H

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
  dtPropiedadMensaje * getPropiedad( );
  dtMensajes* getUltimosCinco( );
  void eliminarLinksPropInmo();
  string getCodigoProp();
  dtPropiedadDisponible* getPropiedadDisponible(Usuarios *usu);
//  Casa * getMetrosVerdes();
    
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
//

};

#endif /* PROPIEDAD_H */

