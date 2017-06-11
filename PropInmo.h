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
#include "Usuarios.h"

class propInmo {
          
        
public:
        
	int getCantidadMensajes(Usuarios);
	void enviarMensaje(Propiedad, string);
	void altaPropEnInmob(Propiedad, string);
	void eliminarLinks();
	void getAvisos();
    
        propInmo();
        propInmo(const propInmo& orig);
        virtual ~propInmo();
        
private:
        //Aviso * aviPropInmo;
        //Chat * chatPropInmo;
        //Propiedad * prop;

};

#endif /* PROPINMO_H */