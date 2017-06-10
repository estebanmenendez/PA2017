/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   dtDepartamento.h
 * Author: lucia
 *
 * Created on 6 de mayo de 2017, 06:16 PM
 */
#include <string.h>
#include <stdio.h>
#include <iostream>

#ifndef DTDEPARTAMENTO_H
#define DTDEPARTAMENTO_H

using namespace std;

class dtDepartamento {
public:
    dtDepartamento();
    dtDepartamento(const dtDepartamento& orig);
    virtual ~dtDepartamento();
    dtDepartamento(string letraDepartamento, string nombreDepartamento);
    dtDepartamento seleccionaDepartamento(string letraDepartamento);
    dtDepartamento** listarDepartamento();
    
    string getletraDepartamento() const;
    string getnombreDepartamento() const;    
   
    
    
private:
    string letraDepartamento;
    string nombreDepartamento;

};

#endif /* DTDEPARTAMENTO_H */

