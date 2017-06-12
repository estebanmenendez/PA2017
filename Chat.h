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
#include "Usuarios.h"
using namespace std;

class Chat {
public:
    Chat();
    Chat(const Chat& orig);
    virtual ~Chat();
    int getChat();
    void setChat(Chat);
    
    void eliminarLinksMensajes();
    bool esDelUsuario(Usuarios);
    int getCantidadMensaje();
    bool pertPropUsuario(Propiedad,Usuarios);
    dtMensajes ** getUltimosCinco();
    void enviaMensaje(string);

private: 
    //Mensaje * msje;

};

#endif /* CHAT_H */