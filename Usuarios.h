/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */




#ifndef USUARIOS_H
#define USUARIOS_H
#include"ICollectible.h"
#include "IDictionary.h"
//#include"Propiedad.h"
#include<string.h>
#include<stdio.h>
#include<iostream>





using namespace std;

class Usuarios :public ICollectible {
private:
    string email;
    string pwd;
    
public:
    //Usuarios* getUsuario();
    virtual bool esInteresado();
    Usuarios();
    Usuarios(string,string);  
    virtual string getEmail();
    virtual string getPwd();
    virtual int getTipo();    
    virtual ~Usuarios();
    
};


#endif	// USUARIOS_H


