/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */



#include"ICollectible.h"
#include "IDictionary.h"
#ifndef USUARIOS_H
#define USUARIOS_H

#include"Propiedad.h"
#include<string.h>
#include<stdio.h>
#include<iostream>





using namespace std;

class Usuarios :public ICollectible {
private:
    string email;
    string pwd;
    IDictionary * IPropInmo;
public:
    Usuarios* getUsuario();
    bool esInteresado();
    virtual string getEmail();
    virtual string getPwd();
    virtual string getTipo();
    
    Usuarios();
    virtual ~Usuarios();
    string getAlquilerOVenta(string codProp);
    
};


#endif	// USUARIOS_H


