/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Departamento.h
 * Author: lucia
 *
 * Created on 9 de junio de 2017, 06:33 PM
 */
#include <string.h>
#include <stdio.h>
#include <iostream>
#include "Zona.h"
#include "Lista.h"
#include"dtZonas.h"
#include"dtPropiedadApto.h"
#include"dtDepartamento.h"
#include"dtPropEnDpto.h"
#include "ICollectible.h"

#ifndef DEPARTAMENTO_H
#define DEPARTAMENTO_H

using namespace std;

class Departamento:public ICollectible {
public:
    Departamento();
    Departamento(string,string);
    Departamento(const Departamento& orig);
    virtual ~Departamento();
    
    Lista* getZonas();
    Zona *getZona(string);
    dtDepartamento *getDatos();
    dtPropEnDpto* getpropEnDepto(Usuarios inmobiliaria);
    string getLetraDpto();
    void agregarZona(dtZonas*);
    
private:
    string letraDpto;
    string nombreDpto;
    IDictionary* IZona;

};

#endif /* DEPARTAMENTO_H */

