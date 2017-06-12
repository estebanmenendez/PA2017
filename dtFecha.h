/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   dtFecha.h
 * Author: Boris
 *
 * Created on 10 de junio de 2017, 12:22 AM
 */

#include <stdio.h>
#include <iostream>

#ifndef DTFECHA_H
#define DTFECHA_H

using namespace std;

class dtFecha {
public:
    dtFecha();
    dtFecha(const dtFecha& orig);
    virtual ~dtFecha();
    dtFecha(int dd, int mm, int aa);
    
    int getDias() const;
    int getMeses() const;
    int getAnios() const;
    
private:
    int dd;
    int mm;
    int aa;

};

#endif /* DTFECHA_H */

