
#include"Usuarios.h"

#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

class Administrador : public Usuarios{
    
    public:
        string getTipo();
        string getEmail();
        string getPwd();
        Administrador();
        Administrador(string, string);
        virtual ~Administrador();      
   
};
#endif /* ADMINISTRADOR_H */
