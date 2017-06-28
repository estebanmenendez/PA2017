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

#include <string.h>
#include <stdio.h>
#include <iostream>
//#include "Propiedad.h"
//#include "Usuarios.h"
#include "dtMensajes.h"
#include "ICollectible.h"
#include "ICollection.h"
#include "Interesado.h"

using namespace std;

class Chat: public ICollectible {
public:
    
    Chat();
    
    Chat(const Chat& orig);
    virtual ~Chat();
    int getChat();
    void setChat(int);    
    void eliminarLinksMensajes();
    bool esDelUsuario();
    int getCantidadMensaje();
    bool pertPropUsuario();
    dtMensajes ** getUltimosCinco();
    void enviaMensaje(string);
    void setInteresado(Interesado *);
    void altaMensaje(string mensa,dtFecha* fecha,dtHora* hora, Interesado *);
    
private: 
    ICollection * IMensajes;
    Interesado * Inter;
};

#endif /* CHAT_H */