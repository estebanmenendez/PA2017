/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ContUsuario.h
 * Author: esteban
 *
 * Created on 12 de junio de 2017, 07:50 PM
 */

#ifndef CONTUSUARIO_H
#define CONTUSUARIO_H

#include"IContUsuario.h"
#include"IDictionary.h"
#include"Usuarios.h"

using namespace std;

class ContUsuario : public IContUsuario {
   
    public:
        ContUsuario();
        ContUsuario(const ContUsuario& orig);
        virtual ~ContUsuario();

        void altaInmobiliaria(string, dtDireccion*, string); // HECHO
        void altaInteresado(string,string,int,string); // HECHO
        Usuarios * usuarioLogueado(); // HECHO
        void iniciarSesion(string, string); // HECHO
        bool verificarContrasena(string, string); // HECHO
        void activarUsuario(string, string); // HECHO
        bool validarPwd(string); // HECHO
        void altaSesion(Usuarios * usu);
        void cancelarAccion();
        dtReporteInmobiliaria * obtenerReporteInmobiliarias();
        void CerrarSesion();

    private:
        
        IDictionary * IInmobiliaria;
        IDictionary * IInteresados;
        IDictionary * IAdministrador;
        IDictionary * IUsuario;
        Usuarios * usuLog;

      
};

#endif /* CONTUSUARIO_H */

