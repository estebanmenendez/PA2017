/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ContUsuario.cpp
 * Author: esteban
 * 
 * Created on 12 de junio de 2017, 07:50 PM
 */

#include "ContUsuario.h"

using namespace std;

    IContUsuario::IContUsuario() {
    }

    IContUsuario::IContUsuario(const IContUsuario& orig) {
    }

    IContUsuario::~IContUsuario() {
    }

      void IContUsuario::altaInteresado(){
    }
      void IContUsuario::altaSesion(){

    }
      void IContUsuario::cancelarAccion(){

    }
    dtReporteInmobiliaria ** IContUsuario::obtenerReporteInmobiliarias (){

    }

      Usuarios ** IContUsuario::usuarioLogueado(){

    }
        void IContUsuario::altaInmobiliaria( string nombre, dtDireccion * direccion, string email){
    }

        void IContUsuario::iniciarSesion(string tipoUsuario , string email){

}
        bool IContUsuario::verificarContrasena(string pwd , string pwdConfirmacion ){
}
        void IContUsuario::activarUsuario(string tipoUsuario ,string email ){

        }
        void IContUsuario::validarPwd( string contrasena ){

        }


        void IContUsuario::CerrarSesion( int idSesion ){

        }