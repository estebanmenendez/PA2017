/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   dtPropiedadCasa.h
 * Author: Boris
 *
 * Created on 9 de junio de 2017, 05:06 PM
 */
#include <string.h>
#include <stdio.h>
#include <iostream>
#include "dtDireccion.h"


#ifndef DTPROPIEDADCASA_H
#define DTPROPIEDADCASA_H

using namespace std;

class dtPropiedadCasa{
    public:
        dtPropiedadCasa();
        dtPropiedadCasa(const dtPropiedadCasa& orig);
        virtual ~dtPropiedadCasa();
        dtPropiedadCasa(int cantAmbiente, int cantBanios, int cantDormitorios, bool garage, dtDireccion direccionProp, float mCuadradosEdificado, float metrosVerdes);
        
        int getcantAmbiente() const;
        int getcantBanios() const;
        int getcantDormitorios() const;
        bool getgarage() const;
        dtDirectcon getdireccionProp() const;
        float getmCuadradosEdificado() const;
        float getmetrosVerdes() const;
        
    private:
        int cantAmbiente;
        int cantBanios;
        int cantDormitorios;
        bool garage;
        dtDireccion direccionProp;
        float mCuadradosEdificado;
        float metrosVerdes;
        
};


#endif /* DTPROPIEDADCASA_H */

