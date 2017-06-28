
#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H// </editor-fold>

#include"Usuarios.h"

class Administrador : public Usuarios{
    
    public:
        int getTipo();
        string getEmail();
        string getPwd();
        Administrador(string,string);
        
        virtual ~Administrador();      
        
        //int cantMensajesPropiedad(string);
       
   
};

#endif	// ADMINISTRADOR_H

