/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   casa.h
 * Author: lucia
 *
 * Created on 9 de junio de 2017, 07:06 PM
 */
#include "propiedad.h"

#ifndef CASA_H
#define CASA_H

class casa: public propiedad  {
public:
    casa();
    casa(const casa& orig);
    virtual ~casa();
    void esCasa();
    void esApto();
    
private:
    float metrosVerdes;
};

#endif /* CASA_H */

