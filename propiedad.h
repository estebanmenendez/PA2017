/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   propiedad.h
 * Author: lucia
 *
 * Created on 9 de junio de 2017, 06:46 PM
 */

#include <string.h>
#include <stdio.h>
#include <iostream>

#ifndef PROPIEDAD_H
#define PROPIEDAD_H

using namespace std;

class propiedad {
public:
    propiedad();
    propiedad(const propiedad& orig);
    virtual ~propiedad();
    
  void esCasa();
  void esApto();
  bool perteneceInmobiliaria(usuario inmobiliaria);
  dtPropiedadMensaje** getPropiedad(usu usuario);
  dtMensajes** getUltimosCinco(usu usuario);
  void eliminarLinksPropInmo();
  dtPropiedad** getPropiedad();
    
private:
    string codigoProp;
    int cantAmbientes;
    int cantBanios;
    int cantDormitorios;
    bool garage;
    direccion direccionProp;
    float mCuadradosEdificado;
    float mCuadradosTotales;

};

#endif /* PROPIEDAD_H */

