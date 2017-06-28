/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PropInmo.h
 * Author: esteban
 *
 * Created on 11 de junio de 2017, 06:48 PM
 */

#ifndef PROPINMO_H
#define PROPINMO_H

#include <string.h>
#include <stdio.h>
#include <iostream>
#include "Propiedad.h"
#include "Chat.h"
#include "Aviso.h"
#include "dtAvisoPropiedad.h"
#include "Venta.h"
#include "Alquiler.h"
#include "Lista.h"
class PropInmo: public ICollectible{
          
        
public:
    void altaMensaje(string ,dtFecha *, dtHora*, Interesado*);
	int getCantidadMensajes();
	void enviarMensaje(Propiedad*, string);
	void altaPropEnInmob(Propiedad*);
	void eliminarLinks();
	dtAvisoPropiedad * getAvisos();
        string esAlquileroVenta();
        PropInmo();
        PropInmo(const PropInmo& orig);
        virtual ~PropInmo();
        void crearAvisoProp(bool,float);
        void crearChat();

        
private:
        //links
        Aviso * aviPropInmo[2];
        ICollection  * IChatPropInmo;
        Propiedad * prop;


};

#endif /* PROPINMO_H */
