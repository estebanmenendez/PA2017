/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Usuarios.h
 * Author: ernesto
 *
 * Created on 9 de junio de 2017, 05:41 PM
 */

#include"ICollectible.h"
#include "IDictionary.h"
#include<string.h>
#include <stdio.h>
#include <iostream>

#ifndef USUARIOS_H
#define USUARIOS_H



using namespace std;

class Usuarios :public ICollectible {
private:
    string email;
    string pwd;
    IDictionary * IPropInmo;
public:
    Usuarios* getUsuario();
    bool esInteresado();
    string getEmail();
    string getPwd();
    string getTipo();
    Usuarios();
    virtual ~Usuarios();
    string getAlquilerOVenta(string codProp);
    
};
#endif /* USUARIOS_H */
