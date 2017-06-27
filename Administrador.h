
#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H// </editor-fold>

#include"Usuarios.h"

class Administrador : public Usuarios{
    
    public:
        string getTipo();
        string getEmail();
        string getPwd();
        Administrador();
        Administrador(string, string);
        virtual ~Administrador();      
        //int cantMensajesPropiedad(string);
       
   
};

#endif	// ADMINISTRADOR_H

