/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   dtPropiedadApto.h
 * Author: Boris
 *
 * Created on 9 de junio de 2017, 07:36 PM
 */

#include <string.h>
#include <stdio.h>
#include <iostream>
#include "dtDireccion.h"


#ifndef DTPROPIEDADAPTO_H
#define DTPROPIEDADAPTO_H

using namespace std;

class dtPropiedadApto{
    public:
        dtPropiedadApto();
        dtPropiedadApto(const dtPropiedadApto& orig);
        virtual ~dtPropiedadApto();
        dtPropiedadApto(int cantAmbiente, int cantBanios, int cantDormitorios,
        bool garage, dtDireccion* direccionProp, float mCuadradosEdificado,
        string nombreEdificio, float valor, bool ventAlq);
        
        int getcantAmbiente() const;
        int getcantBanios() const;
        int getcantDormitorios() const;
        bool getgarage() const;
        dtDireccion* getdireccionProp() const;
        float getmCuadradosEdificado() const;
        string getnombreEdificio() const;
        float getValor() const;
        bool getVentaAlq() const;
        
    private:
        int cantAmbiente;
        int cantBanios;
        int cantDormitorios;
        bool garage;
        dtDireccion* direccionProp;
        float mCuadradosEdificado;
        string nombreEdificio;
        float valor;
        bool ventAlq;
};


#endif /* DTPROPIEDADAPTO_H */

