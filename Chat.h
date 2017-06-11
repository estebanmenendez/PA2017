/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Chat.h
 * Author: esteban
 *
 * Created on 11 de junio de 2017, 06:45 PM
 */


#ifndef CHAT_H
#define CHAT_H

#include<string.h>
#include <stdio.h>
#include <iostream>
#include "PropInmo.h"

using namespace std;

class chat {
public:
    chat();
    chat(const chat& orig);
    virtual ~chat();
    int getCodChat();
    void setCodChat(chat);
    
    void eliminarLinksMensajes();
    bool esDelUsuario(Usuarios);
    int getCantidadMensaje();
    bool pertPropUsuario(Propiedad,Usuarios);
    dtMensajes * getUltimosCinco();
    void enviaMensaje(string);

private: 
    mensaje * msje;

};

#endif /* CHAT_H */