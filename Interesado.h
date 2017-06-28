/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Interesado.h
 * Author: ernesto
 *
 * Created on 9 de junio de 2017, 06:07 PM
 */
#include"Usuarios.h"
#include"ICollection.h"
#include "Chat.h"

#ifndef INTERESADO_H
#define INTERESADO_H

class Interesado :public Usuarios{
    private: 
        int edad;
        string nombreInt;
        string apellidoInt;
        ICollection* IChatInteresado;
        public:
            int getEdad();
            void setEdad();
            int getTipo();
            string getPwd();
            string getEmail();
            Interesado(string nombre, string apellido,int edad, string email,string);
            int cantMensajesPropiedad(string);
            Interesado();
            virtual ~Interesado();
};
#endif /* INTERESADO_H */
