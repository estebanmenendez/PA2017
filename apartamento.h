/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   apartamento.h
 * Author: lucia
 *
 * Created on 9 de junio de 2017, 07:06 PM
 */
#include "propiedad.h"

#ifndef APARTAMENTO_H
#define APARTAMENTO_H

class apartamento: public propiedad {
public:
    apartamento();
    apartamento(const apartamento& orig);
    virtual ~apartamento();
    
    void esCasa();
    void esApto();

private:

};

#endif /* APARTAMENTO_H */

