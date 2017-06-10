/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   departamento.h
 * Author: lucia
 *
 * Created on 9 de junio de 2017, 06:33 PM
 */
#include <string.h>
#include <stdio.h>
#include <iostream>
#include "zona.h"

#ifndef DEPARTAMENTO_H
#define DEPARTAMENTO_H

using namespace std;

class departamento {
public:
    departamento();
    departamento(const departamento& orig);
    virtual ~departamento();
    
    dtZona** getZonas(d departamento);
    Zona getZona(codigoZona string);
    dtDepartamento getDatos();
    dtPropEnDepto** getpropEnDepto(usuario inmobiliaria);
    zona * getZona();
    
private:
    string letraDpto;
    string nombreDpto;
    zona* zona;

};

#endif /* DEPARTAMENTO_H */

