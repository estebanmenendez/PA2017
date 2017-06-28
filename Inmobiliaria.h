/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Inmobiliaria.h
 * Author: ernesto
 *
 * Created on 9 de junio de 2017, 06:00 PM
 */
#include"Usuarios.h"
#include"dtDireccion.h"
#include"Propiedad.h"
#include"IDictionary.h"
#include"PropInmo.h"

#ifndef INMOBILIARIA_H
#define INMOBILIARIA_H

class Inmobiliaria : public Usuarios{
    private:
        string nombreInm;
        dtDireccion* direccion;
        IDictionary* IPropInmo;
        
    public:
        Inmobiliaria();
        Inmobiliaria(string, dtDireccion*, string,string);
        virtual ~Inmobiliaria();
        int getTipo();
        string getPwd();
        string getEmail();
        int cantMensajesPropiedad(string);
        string getAlquilerOVenta(string codProp);
        void altaMensaje(dtFecha*,dtHora*,string,Interesado*,string);
        void altaPropEnInmob(Propiedad *p);
};

#endif /* INMOBILIARIA_H */
