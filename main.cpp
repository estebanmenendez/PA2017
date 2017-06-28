/* 
 * File:   main.cpp
 * Author: lucia
 *
 * Created on 6 de mayo de 2017, 04:34 PM
 */

#include<cstdlib>
#include<cstdlib>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<typeinfo>
#include<iostream>
#include <stdexcept>
#include"dtEdificio.h"
#include"dtDepartamento.h"
#include"dtDireccion.h"
#include"dtReporteInmobiliaria.h"
#include"dtPropiedadApto.h"
#include"dtPropiedadCasa.h"
#include"dtPropiedad.h"
#include"Fabrica.h"
#include"PropInmo.h"
#include"Propiedad.h"
#include"ICollection.h"
#include"Inmobiliaria.h"
#include"Interesado.h"
#include"ListDicc.h"
#include"Usuarios.h"
#include"ListaIterator.h"
#include"ContProp.h"
#include "Administrador.h"

using namespace std;

//CASOS DE USO
void iniciarSesion();
void cerrarSesion();
void altaInmobiliaria();
void altaInteresado();
void altaEdificio();
void altaPropiedad();
void consultarPropiedad();
void consultarPropiedadDisponible();
void modificarPropiedad();
void eliminarPropiedad(); 
void enviarMsjInteresado(); // HECHO 90%
void enviarMsjInmobiliaria(); 
dtReporteInmobiliaria obtenerReporteInmo();


// MENU GENERAL DE OPCIONES ADMIN/INTER/INMO/CARGAR PRUEBA
void opcionesGenerales(); 
void cargaDatosPrueba();
void administradorOpciones(string, string);
void inmobiliariaOpciones(string, string);
void interesadoOpciones(string, string);
void adminOpciones(int opAdmin);
void inmoOpciones(int opInmo);
void interOpciones(int opInter);
//Usuarios
Usuarios * recorrerUsuarios(string, string);

/////////////////////////////////////////

int idSesion=0;
string us, pwd; // LOS DEFINO COMO VARIABLES GLOBALES PARA MOSTRAR EL USUARIO EN CADA CU

int main(int argc, char** argv) {
    
	int opcion=1;

	while (opcion !=  0){
		opcionesGenerales();
		cin >> opcion;
		switch (opcion){
			case 1 : iniciarSesion();break;
                        case 0 : break;
                }
                
	}
	
    return 0;
}

///////////////////// NUEVO /////////////////////

void opcionesGenerales(){
    cout << endl << "Gestor de Ofertas Inmobiliarias - Mi Casa"<<endl<<endl;
    cout << "1 - Iniciar Sesion" << endl;
    cout << "0 - Salir" << endl; 
}

void administradorOpciones(string us, string pwd){
    Usuarios *usu;
    Fabrica* f = Fabrica::getInstance();
    IContUsuario * isAdmin = f->getContUsuario();  //EJEMPLO
    int opAdmin=0;
    
    try{
        if(isAdmin->validarPwd(pwd)==true){
            isAdmin->iniciarSesion(us, pwd);
            cout<<"Sesion iniciada correctamente ";
            invalid_argument("Contrasena incorrecta");
        }
    }catch(invalid_argument & e){
        cout<<e.what();
        } 
    
    system("clear");
    cout << endl << "Gestor de Ofertas Inmobiliarias - Mi Casa"<<"\t"<<"Usuario: "<<us<<endl;
    cout << "\nMENU - USUARIO ADMINISTRADOR" << endl;
    cout << "1 - Alta inmobiliaria" << endl;
    cout << "2 - Alta interesado" << endl;
    cout << "3 - Obtener reporte inmobiliaria" << endl;
    cout << "4 - Cerrar sesion" << endl; 
    cin>>opAdmin;
    adminOpciones(opAdmin);

}
void consultarPropiedadDisponible(){
     string letraDpto, codigoZona,codigoProp;
    //Departamento *depto;
     
    
    cout << "Caso Uso Consultar Propiedad Interesado\n";
    
    Fabrica* f = Fabrica::getInstance();
    IContProp * i = f->getContProp();
    ICollection* colDtDep= NULL;
   
    try{
    colDtDep = i->listaDepartamentos();
    
    IIterator *dt =colDtDep->iterator();
    cout<<"Departamentos Disponibles\n";
    
    while(dt->hasNext()){
        dtDepartamento *dtD=dynamic_cast<dtDepartamento*>(dt->getCurrent());
        cout<<dtD->getletraDepartamento()<<"-"<<dtD->getnombreDepartamento()<<"\n";
        dt->next();        
    }
    cout<<"Elegir Letra Departamento\n";
    cin>>letraDpto;
    i->seleccionarDepartamentos(letraDpto);
    ICollection* colDtZona= NULL;
    colDtZona= i->listaZonasDepartamentos();
    IIterator *dtZ =colDtZona->iterator();
    cout<<"Zonas Disponibles\n";
    while(dtZ->hasNext()){
        dtZonas *dtZona=dynamic_cast<dtZonas*>(dtZ->getCurrent());
        cout<<dtZona->getCodigoZona()<<"-"<<dtZona->getNombreZona()<<"\n";
        dtZ->next();        
    }
    
    cout<<"Elegir Código Zona\n";
    cin>>codigoZona;
    i->seleccionaZona(codigoZona);

    ICollection* colDtPropDispo=NULL;
    colDtPropDispo=i->listaPropiedadesDisponibles();
    IIterator *dtprop=colDtPropDispo->iterator();
    
    while (dtprop->hasNext()) {
        dtPropiedadDisponible* dtpro=dynamic_cast<dtPropiedadDisponible*>(dtprop->getCurrent());
        cout<<dtpro->getCodigoProp()<<"-"<<dtpro->getAlquilerOVenta();
        dtprop->next();

        }
    cout<<"Elegir Código Propiedad\n";
    cin>>codigoProp;
    i->seleccionaPropiedadDisponible(codigoProp);
       
    }catch(invalid_argument & e){
            cout<<e.what();
        } 
  


}


void inmobiliariaOpciones(string us, string pwd){
    string op="s";
    string confPwd;
    Fabrica* f = Fabrica::getInstance();
    IContUsuario * isInmo = f->getContUsuario();  //EJEMPLO
   cout<<"\n Inicia sesion por primera vez?";
    while(op=="s"){ 
        try{
            cin>>op;
            cout<<"Ingrese contraseña";
            cin>>pwd;
            cout<<"Confirmar contraseña";
            cin>>confPwd;
            if(isInmo->verificarContrasena(pwd, confPwd)==true){
                isInmo->activarUsuario(pwd, us);
                isInmo->iniciarSesion(us, pwd);
                cout<<"Sesion iniciada correctamente ";
                invalid_argument("COSO");
        }
        }catch(invalid_argument & e){
            cout<<e.what();
        } 
    }
    isInmo->validarPwd(pwd);
    isInmo->iniciarSesion(us, pwd);
    cout<<"Sesion iniciada correctamente ";
    
    int opInmo=0;
    system ("clear");
    cout << endl << "Gestor de Ofertas Inmobiliarias - Mi Casa"<<"\t"<<"Usuario: "<<us<<endl;
    cout << "MENU - USUARIO INMOBILIARIA" << endl;
    cout << "1 - Alta propiedad" << endl;
    cout << "2 - Modificar propiedad" << endl; 
    cout << "3 - Eliminar propiedad" << endl;
    cout << "4 - Consultar propiedad" << endl; 
    cout << "5 - Alta edificio" << endl;
    cout << "6 - Enviar mensaje inmobiliaria" << endl;
    cout << "7 - Cerrar sesion" << endl;
    cin>>opInmo;
    inmoOpciones(opInmo); 
}

void interesadoOpciones(string us, string pwd){
    string op="s";
    string confPwd;
    Fabrica* f = Fabrica::getInstance();
    IContUsuario * isInter = f->getContUsuario();  //EJEMPLO
    
    cout<<"\n Inicia sesion por primera vez?";
    while(op=="s"){ 
        try{
            cin>>op;
            cout<<"Ingrese contraseña";
            cin>>pwd;
            cout<<"Confirmar contraseña";
            cin>>confPwd;
            if(isInter->verificarContrasena(pwd, confPwd)==true){
                isInter->activarUsuario(pwd, confPwd);
                isInter->iniciarSesion(us, pwd);
                cout<<"Sesion iniciada correctamente ";
                invalid_argument("Las contraseñas no coinciden");
        }
        }catch(invalid_argument & e){
            cout<<e.what();
        } 
    }
    isInter->validarPwd(pwd);
    isInter->iniciarSesion(us, pwd);
    cout<<"Sesion iniciada correctamente ";
    
    int opInter=0;
    system ("clear");
    cout << endl << "Gestor de Ofertas Inmobiliarias - Mi Casa"<<"\t"<<"Usuario: "<<us<<endl;
    cout << "MENU - USUARIO INTERESADO" << endl;
    cout << "1 - Consultar propiedad" << endl;
    cout << "2 - Enviar mensaje interesado" << endl; 
    cout << "3 - Cerrar sesion" << endl; 
    cin>>opInter;
    //interOpciones(opInter);
    interOpciones(opInter);
    
}

void adminOpciones(int opAdmin){
    while (opAdmin !=  0){
        switch (opAdmin){
                case 1 : altaInmobiliaria(); break;
                case 2 : altaInteresado(); break;
                case 3 : obtenerReporteInmo(); break;
                case 4 : cerrarSesion(); break;
           }
        }
}

void inmoOpciones(int opInmo){
    
     //int opInmo=1;
     dtPropiedad propiedad;
     string prop;
     string nombre;
     int pisos;
     int gastosComunes;
     string msjInmo;
        
    while (opInmo !=  0){
                //cin >> opInmo;
        switch (opInmo){
                case 1 : altaPropiedad(); break;
                case 2 : modificarPropiedad(); break;
                case 3 : eliminarPropiedad(); break;
                case 4 : consultarPropiedad(); break;
                case 5 : altaEdificio(); break;
                case 6 : enviarMsjInmobiliaria(); break;
                case 7 : cerrarSesion(); break;
           }
        }
}

void interOpciones(int opInter){
    
    // int opInter=1;
     string propiedad;
     string msjInter;
        
    while (opInter !=  0){
                //cin >> opAdmin;
        switch (opInter){
                case 1 : consultarPropiedad(); break;
                case 2 : enviarMsjInteresado(); break;
                case 3 : cerrarSesion(); break;
           }
        }
}

//void cargaDatosPrueba(){}

void iniciarSesion(){
//    Fabrica* f = Fabrica::getInstance();
//    IContUsuario * is = f->getContUsuario();  //EJEMPLO
    
    Usuarios * usuTipo;
    string usuario;
    int opUsr=1;
    string datos = "n";
    // PRECARGA DE DATOS
    
    cout<<"Desea precargar datos? ";
    cin>>datos;
       
    if (datos=="s"){
        cout<<"precargarDatos();";
    }
    
    // SOLICITO DATOS - AGREGAR TRY
    cout<<"\nIngrese email: ";
    cin>>us;
    cout<<"\nIngrese contrasenia: ";
    cin>>pwd;
    //usuario = usuTipo->getTipo();
    
    
    if(dynamic_cast<Administrador*>(usuTipo)->getTipo() == "Administrador"){
        opUsr == 1;
    }
    if(dynamic_cast<Interesado*>(usuTipo)->getTipo() == "Interesado"){
        opUsr == 2;
    }
    if(dynamic_cast<Inmobiliaria*>(usuTipo)->getTipo() == "Inmobiliaria"){
        opUsr == 3;
    }
    
   /* system ("clear");
    cout << endl << "Gestor de Ofertas Inmobiliarias - Mi Casa"<<"\t"<<"Usuario: "<<us<<endl;
    cout<<"\nSeleccione tipo de usuario: ";
    cout<<"\n1 - Administrador"<<endl;
    cout<<"2 - Inmobiliaria"<<endl;
    cout<<"3 - Interesado"<<endl;*/
        
    while (opUsr !=  0){
                cin >> opUsr;
        switch (opUsr){
                case 1 : administradorOpciones(us,pwd); break;
                case 2 : inmobiliariaOpciones(us,pwd); break;
                case 3 : interesadoOpciones(us,pwd); break;
           }
        }
    
}

void altaInmobiliaria (){
    Fabrica* f = Fabrica::getInstance();
    IContUsuario * in = f->getContUsuario();  //EJEMPLO
    string nombre, ciudad, calle, numero, email;
   // sistema* s= new sistema();
    dtDireccion* dir;
    
    system ("clear");
    cout<<"\n1 - Alta inmobiliaria\n";
    cout<<"Ingrese Nombre: ";
    cin>>nombre;
    cout<<"Ingrese Email: ";
    cin>>email;
    cout<<"Ingrese Ciudad: ";
    cin>>ciudad;
    cout<<"Ingrese Calle: ";
    cin>>calle;
    cout<<"Ingrese Número: ";
    cin>>numero;
    dir = new dtDireccion(ciudad,numero,calle);

   // in->altaInmobiliaria(nombre,dir);
    //taInmobiliaria(nombre, dir)

    in->altaInmobiliaria(nombre, dir, email);
    cout<<"Inmobiliaria dada de Alta ";
}

void altaPropiedad(){
    Fabrica* f = Fabrica::getInstance();
    IContProp * i = f->getContProp();  //EJEMPLO
    Departamento* depto;
    Lista * listaDep;
    Lista* listaZona;
    
    dtEdificio edif;
    string letraDep, codigoZona,ciudad, calle, numero,nEdif, VoA;
    int cAmb,cBanios,cDorm;
    float mEdif,mVerdes,valor;
    char opt,garage;
    dtPropiedadCasa * dtPropC;
    dtPropiedadApto * dtPropA;
    dtDireccion* dir;
    bool lgarage,ventAlq;
        
//    listaDep = i->listaDepartamentos();
    cout<<"Ingrese la letra del Departamento: ";
    cin>>letraDep;
    i->seleccionarDepartamentos(letraDep);
    listaZona = i->listaZonasDepartamentos();
    cout<<"Seleccione la Zona: ";
    i->seleccionaZona(codigoZona);
    cout<<"\n Ingresa Una Casa o Un Apto? C / A \n";
    cin>>opt;
    if (opt == 'C'){
    cout<<"\nDatos Casa\n";
    cout<<"Ingrese Cantidad Ambientes: \n";
    cin>>cAmb;
    cout<<"Ingrese Cantidad Baños: \n";
    cin>>cBanios;
    cout<<"Ingrese Cantidad Dormitorios: \n";
    cin>>cDorm;
    cout<<"Tiene Garage : S/N \n";
    cin>>garage; 
    if(garage =='S')
        lgarage = true;
    else
        lgarage = false;
    
    cout<<"Ingrese Ciudad: ";
    cin>>ciudad;
    cout<<"Ingrese Calle: ";
    cin>>calle;
    cout<<"Ingrese Número: ";
    cin>>numero;
    dir = new dtDireccion(ciudad,numero,calle);
    cout<<"Ingrese Metros Cuadrados Edif: \n";
    cin>>mEdif;
    cout<<"Ingrese Metros Verdes: \n";
    cin>>mVerdes;
    cout<<"Indique si  Venta o Alquiler : V/A \n";
    cin>> VoA;
    if (VoA == "A"||VoA=="a"){
    ventAlq = true;
    cout<<"Ingrese Valor del Alquiler \n";
    cin>>valor; 
    }else{
    ventAlq = false;
    cout<<"Ingrese Valor de Venta \n";
    cin>>valor;
    }
    dtPropC = new dtPropiedadCasa(cAmb,cBanios,cDorm,lgarage,dir,mEdif,mVerdes,valor,ventAlq);
    i->altaPropiedadCasa(dtPropC);
   
    }else{
    cout<<"\nDatos Apartamentos\n";
    cout<<"Ingrese Cantidad Ambientes: \n";
    cin>>cAmb;
    cout<<"Ingrese Cantidad Baños: \n";
    cin>>cBanios;
    cout<<"Ingrese Cantidad Dormitorios: \n";
    cin>>cDorm;
    cout<<"Tiene Garage : S/N \n";
    cin>>garage; 
    if(garage =='S')
        lgarage = true;
    else
        lgarage = false;
    cout<<"Ingrese Ciudad: ";
    cin>>ciudad;
    cout<<"Ingrese Calle: ";
    cin>>calle;
    cout<<"Ingrese Número: ";
    cin>>numero;
    dir = new dtDireccion(ciudad,calle,numero);
    cout<<"Ingrese Metros Cuadrados Edif: \n";
    cin>>mEdif;
    cout<<"Indique si  Venta o Alquiler : A/V \n";
    cin>>ventAlq; 
    cout<<"Ingrese Valor de Venta/ Alquiler \n";
    cin>>valor; 
    dtPropA = new dtPropiedadApto(cAmb,cBanios,cDorm,lgarage,dir,mEdif,nEdif,valor,ventAlq);
    i->altaPropiedadApto(dtPropA);
    }
}

void enviarMsjInmobiliaria(){}

void enviarMsjInteresado(){
    string letraDpto, codigoZona,codigoProp;
    //Departamento *depto;    
    cout << "Caso Uso Enviar Mensaje Interesado\n";
    
    Fabrica* f = Fabrica::getInstance();
    IContProp * i = f->getContProp();
    ICollection* colDtDep= NULL;
    try{
    colDtDep = i->listaDepartamentos();
    
    IIterator *dt =colDtDep->iterator();
    cout<<"Departamentos Disponibles\n";
    
    while(dt->hasNext()){
        dtDepartamento *dtD=dynamic_cast<dtDepartamento*>(dt->getCurrent());
        cout<<dtD->getletraDepartamento()<<"-"<<dtD->getnombreDepartamento()<<"\n";
        dt->next();        
    }
    
    cout<<"Elegir Letra Departamento\n";
    cin>>letraDpto;
    i->seleccionarDepartamentos(letraDpto);
    
     ICollection* colDtZona= NULL;
    colDtZona= i->listaZonasDepartamentos();
    
    
    IIterator *dtZ =colDtZona->iterator();
    cout<<"Zonas Disponibles\n";
    
    while(dtZ->hasNext()){
        dtZonas *dtZona=dynamic_cast<dtZonas*>(dtZ->getCurrent());
        cout<<dtZona->getCodigoZona()<<"-"<<dtZona->getNombreZona()<<"\n";
        dtZ->next();        
    }
    
    cout<<"Elegir Código Zona\n";
    cin>>codigoZona;
    i->seleccionaZona(codigoZona);
    
    
    ICollection* colDtPropMensaje= NULL;
    colDtPropMensaje = i->listaPropiedades();
    
    cout<<"Propiedades y Mensajes\n";
    IIterator *dtPM = colDtPropMensaje->iterator();
    while(dtPM->hasNext()){
        dtPropiedadMensaje *dtPMens=dynamic_cast<dtPropiedadMensaje*>(dtPM->getCurrent());
        cout<<dtPMens->getcodigoProp()<<"-"<<dtPMens->getdireccionProp()<<"-"<<dtPMens->getCantMensajesEnviados()<<"\n";
        dtPM->next();        
    }
    
    cout<<"Elegir Código Propiedad\n";
    cin>>codigoProp;
    
    ICollection* colDtMensajes = NULL;
    colDtMensajes = i->seleccionaPropiedad(codigoProp);
    
    
    }catch(invalid_argument & e){
	cout << e.what();
    }
}
//
void altaInteresado(){

    cout << endl << "Gestor de Ofertas Inmobiliarias - Mi Casa"<<"\t"<<"Usuario: "<<us<<endl;
    cout<<"\n2 - Alta interesado\n";
    Fabrica* f = Fabrica::getInstance();
    IContUsuario * i = f->getContUsuario();  //EJEMPLO
    // buscarUsr(email);
    string nombre, apellido, email;
    int edad;
    string seguir="s";

    while(seguir!="s"){
        try{
            cout<<"Ingrese nombre: ";
            cin>>nombre;
            cout<<"Ingrese apellido: ";
            cin>>apellido;
            cout<<"Ingrese edad: ";
            cin>>edad;
            cout<<"Ingrese email: ";
            cin>>email;              
            i->altaInteresado(nombre, apellido, edad, email);
            cout<<"Usuario inmobiliaria creado correctamente ";
            invalid_argument("COSO");
        }catch(invalid_argument & e){
            cout<<e.what();
        }
    }

    cout<<"\nDesea ingresar otro? ";
    cin>>seguir;
}

 dtReporteInmobiliaria obtenerReporteInmo(){
    cout << endl << "Gestor de Ofertas Inmobiliarias - Mi Casa"<<"\t"<<"Usuario: "<<us<<endl;
    cout<<"\n - Obtener Reporte Inmobiliaria";
    
}
//
void cerrarSesion(){}
//    string opCerrar="n";
//    cout<<"Cerrar Sesion";
//    
//    cout<<"\nDesea cerrar sesion?";
//    cin>>opCerrar;
//    if (opCerrar){
//        //recorrerSesiones(idSesion); // idSesion es una variable global
//        // Destruir todo
//    }
//}
void modificarPropiedad(){}
//    cout << endl << "Gestor de Ofertas Inmobiliarias - Mi Casa"<<"\t"<<"Usuario: "<<us<<endl;
//    cout<<"\n Modificar Propiedad";
//    string codigoProp;
//    
//    cout<<"\nIngrese codigo propiedad: ";
//    cin>>codigoProp;
//    // recorrerPropiedades(codigoProp);
//    //     
//}
//
void eliminarPropiedad(){
    cout<<endl<< "Gestor de Ofertas Inmobiliarias - Mi Casa"<<"\t"<<"Usuario: "<<us<<endl;
    cout<<"Desarrollo Eliminar Propiedad";
    string codigo;
    Fabrica* f = Fabrica::getInstance();
    IContProp * i = f->getContProp();
    
    cout<<endl<<"Ingrese el codigo de la propiedad que desee eliminar: ";
    cin>>codigo;
    //dtProp = new dtPropiedad(codigoProp);
            
    i->eliminarProp(codigo);
    
}

void consultarPropiedad(){
    Fabrica *f = Fabrica::getInstance();
    IContProp *i=f->getContProp();
    i->listaPropiedadesDisponibles();
}

void altaEdificio(){
    string nombre;
    int pisos;
    float gastosComunes;
    Fabrica* f = Fabrica::getInstance();
    IContProp *i=f->getContProp();
         cout<<"Ingrese nombre del edificio: "<<endl;
         cin>>nombre;
         cout<<"Ingrese la cantidad de pisos: "<<endl;
         cin>>pisos;
         cout<<"Ingrese el valor de los gastos comunes: "<<endl;
         cin>>gastosComunes;
      //   dtEdificio *dtedi = new dtEdificio(nombre,pisos,gastosComunes);
       i->altaEdificio(nombre,pisos,gastosComunes);
       
      cout << endl << "Gestor de Ofertas Inmobiliarias - Mi Casa"<<"\t"<<"Usuario: "<<us<<endl;
}

//////////////////////CARGAR DATOS YA SABES////////////////////////////////////////

//usuarios
void cargarUsuInmo(){
    Fabrica * f = Fabrica::getInstance();
    IContUsuario* itUInmo = f->getContUsuario();
    string email, pwd, nombre, ciudad, calle, numero;
    dtDireccion* dirInmo;
    
    email = "inm1@sis.com";
    pwd = "pass4";
    nombre = "Selmo";
    ciudad = "Paysandu";
    calle = "Benitez";
    numero = "1134";
    dirInmo = new dtDireccion(ciudad, calle, numero);
    itUInmo->altaInmobiliaria(nombre, dirInmo, email);
    
    email = "inm2@sis.com";
    pwd = "pass5";
    nombre = "Garcia";
    ciudad = "Paysandu";
    calle = "Rivera";
    numero = "1340";
    dirInmo = new dtDireccion(ciudad, calle, numero);
    itUInmo->altaInmobiliaria(nombre, dirInmo, email);
   
    email = "inm3@sis.com";
    pwd = "pass6";
    nombre = "Invernissi";
    ciudad = "Salto";
    calle = "Comercio";
    numero = "234";
    dirInmo = new dtDireccion(ciudad, calle, numero);
    itUInmo->altaInmobiliaria(nombre, dirInmo, email);
    
    email = "inm4@sis.com";
    pwd = "pass7";
    nombre = "Solei";
    ciudad = "Montevideo";
    calle = "Inca";
    numero = "3456";
    dirInmo = new dtDireccion(ciudad, calle, numero);
    itUInmo->altaInmobiliaria(nombre, dirInmo, email);
    
}

void cargarUsuInteresado(){
    Fabrica * f = Fabrica::getInstance();
    IContUsuario* itUInmo = f->getContUsuario();
    string email, pwd, nombreInt, apellidoInt, ciudad, calle, numero;
    int edadInt;
    
    email = "int1@sis.com";
    pwd = "passt1";
    nombreInt = "Julio";
    apellidoInt = "Chaz";
    edadInt = 34;
    itUInmo->altaInteresado(nombreInt, apellidoInt, edadInt, email);
    
    email = "int2@sis.com";
    pwd = "passt2";
    nombreInt = "Andrea";
    apellidoInt = "Berruti";
    edadInt = 56;
    itUInmo->altaInteresado(nombreInt, apellidoInt, edadInt, email);
    
    email = "int3@sis.com";
    pwd = "passt3";
    nombreInt = "Sonia";
    apellidoInt = "Braga";
    edadInt = 45;
    itUInmo->altaInteresado(nombreInt, apellidoInt, edadInt, email);
    
    email = "int4@sis.com";
    pwd = "passt4";
    nombreInt = "Alfonso";
    apellidoInt = "Mier";
    edadInt = 30;
    itUInmo->altaInteresado(nombreInt, apellidoInt, edadInt, email);
    
    email = "int5@sis.com";
    pwd = "passt5";
    nombreInt = "Juan";
    apellidoInt = "Alpi";
    edadInt = 60;
    itUInmo->altaInteresado(nombreInt, apellidoInt, edadInt, email);
    
}

void cargarEdificios(){
    Fabrica * f = Fabrica::getInstance();
    IContProp* itE = f->getContProp();
    string nombreEdificio;
    int cantPisos;
    float gastosComunes;
    
    nombreEdificio = "Apache Valiente";
    cantPisos = 4;
    gastosComunes = 1234;
    itE->altaEdificio(nombreEdificio, cantPisos, gastosComunes);
    
    nombreEdificio = "Mebeo";
    cantPisos = 20;
    gastosComunes = 3452;
    itE->altaEdificio(nombreEdificio, cantPisos, gastosComunes);
    
    nombreEdificio = "Socrates";
    cantPisos = 34;
    gastosComunes = 456;
    itE->altaEdificio(nombreEdificio, cantPisos, gastosComunes);
    
    nombreEdificio = "El Burdel";
    cantPisos = 12;
    gastosComunes = 800;
    itE->altaEdificio(nombreEdificio, cantPisos, gastosComunes);
    
    nombreEdificio = "Milajo";
    cantPisos = 5;
    gastosComunes = 900;
    itE->altaEdificio(nombreEdificio, cantPisos, gastosComunes);
    
}

void cargarPropAptos(){
    Fabrica * f = Fabrica::getInstance();
    IContProp* itPA = f->getContProp();
    dtPropiedadApto* PropApto;
    int cantAmbiente, cantDormitorios, cantBanios;
    bool garage, ventAlq;
    dtDireccion* direccionProp;
    float mCuadradosEdificado, mCuadradosTotales, valor;
    string nombreEdificio, codigoProp, ciudad, calle, numero, nombreInmo, nombreZona;
    
    //////////           Apartamento 1
    
    codigoProp = "1111";
    cantAmbiente = 2;
    cantDormitorios = 1;
    cantBanios = 1;
    garage = false;
    ciudad = "Montevideo";
    calle = "Iturria";
    numero = "1115";
    direccionProp = new dtDireccion(ciudad, calle, numero);
    mCuadradosEdificado = 34;
    mCuadradosTotales = 34;
    nombreEdificio = "Apache Valiente";
    nombreInmo = "Selmo";
    ventAlq = true;
    valor = 34567;
    nombreZona = "Zona1";
    PropApto = new dtPropiedadApto(cantAmbiente, cantDormitorios, cantBanios, garage, direccionProp, mCuadradosEdificado, nombreEdificio, valor, ventAlq);
    itPA->altaPropiedadApto(PropApto);
    
    //////////////       Apartamento 2
    
    codigoProp = "1112";
    cantAmbiente = 3;
    cantDormitorios = 1;
    cantBanios = 1;
    garage = false;
    ciudad = "Montevideo";
    calle = "Iturria";
    numero = "1115";
    direccionProp = new dtDireccion(ciudad, calle, numero);
    mCuadradosEdificado = 35;
    mCuadradosTotales = 35;
    nombreEdificio = "Apache Valiente";
    nombreInmo = "Selmo";
    ventAlq = true;
    valor = 65789;
    nombreZona = "Zona1";
    PropApto = new dtPropiedadApto(cantAmbiente, cantDormitorios, cantBanios, garage, direccionProp, mCuadradosEdificado, nombreEdificio, valor, ventAlq);
    itPA->altaPropiedadApto(PropApto);
    
    ////////////         Apartamento 3
    
    codigoProp = "1113";
    cantAmbiente = 2;
    cantDormitorios = 1;
    cantBanios = 1;
    garage = true;
    ciudad = "Rivera";
    calle = "CALLEJON";
    numero = "456";
    direccionProp = new dtDireccion(ciudad, calle, numero);
    mCuadradosEdificado = 45;
    mCuadradosTotales = 45;
    nombreEdificio = "Mebeo";
    nombreInmo = "Garcia";
    ventAlq = false;
    valor = 7689;
    nombreZona = "Zona2";
    PropApto = new dtPropiedadApto(cantAmbiente, cantDormitorios, cantBanios, garage, direccionProp, mCuadradosEdificado, nombreEdificio, valor, ventAlq);
    itPA->altaPropiedadApto(PropApto);
    
    ////////////////     Apartamento 4
    
    codigoProp = "1113";
    cantAmbiente = 7;
    cantDormitorios = 3;
    cantBanios = 2;
    garage = true;
    ciudad = "Rivera";
    calle = "CORCEGA ";
    numero = "3456";
    direccionProp = new dtDireccion(ciudad, calle, numero);
    mCuadradosEdificado = 34;
    mCuadradosTotales = 34;
    nombreEdificio = "Socrates";
    nombreInmo = "Garcia";
    ventAlq = false;
    valor = 6789;
    nombreZona = "Zona3";
    PropApto = new dtPropiedadApto(cantAmbiente, cantDormitorios, cantBanios, garage, direccionProp, mCuadradosEdificado, nombreEdificio, valor, ventAlq);
    itPA->altaPropiedadApto(PropApto);
    
    /////////////         Apartamento 5
    
    codigoProp = "1115";
    cantAmbiente = 4;
    cantDormitorios = 1;
    cantBanios = 1;
    garage = false;
    ciudad = "Artigas";
    calle = "LUCRECIA";
    numero = "456";
    direccionProp = new dtDireccion(ciudad, calle, numero);
    mCuadradosEdificado = 25;
    mCuadradosTotales = 25;
    nombreEdificio = "El Burdel";
    nombreInmo = "Invernissi";
    ventAlq = false;
    valor = 7890;
    nombreZona = "Zona4";
    PropApto = new dtPropiedadApto(cantAmbiente, cantDormitorios, cantBanios, garage, direccionProp, mCuadradosEdificado, nombreEdificio, valor, ventAlq);
    itPA->altaPropiedadApto(PropApto);
    
    //////////////////      Apartamento 6
    
    codigoProp = "1116";
    cantAmbiente = 2;
    cantDormitorios = 1;
    cantBanios = 1;
    garage = false;
    ciudad = "Artigas";
    calle = "LUCRECIA";
    numero = "456";
    direccionProp = new dtDireccion(ciudad, calle, numero);
    mCuadradosEdificado = 17;
    mCuadradosTotales = 17;
    nombreEdificio = "El Burdel";
    nombreInmo = "Solei";
    ventAlq = false;
    valor = 768;
    nombreZona = "Zona4";
    PropApto = new dtPropiedadApto(cantAmbiente, cantDormitorios, cantBanios, garage, direccionProp, mCuadradosEdificado, nombreEdificio, valor, ventAlq);
    itPA->altaPropiedadApto(PropApto);
    
}

void cargarPropCasa(){
    Fabrica * f = Fabrica::getInstance();
    IContProp* itPC = f->getContProp();
    dtPropiedadCasa* PropCasa;
    string ciudad, calle, numero, nombreZona, nombreInmo, codigoProp;
    int cantAmbiente, cantDormitorios, cantBanios;
    bool garage, ventaAlq;
    dtDireccion* direccionProp;
    float mCuadradosEdificado, valor, metrosVerdes, mCuadradosTotales;
    
    ///////////     Casa 1
    
    codigoProp = "2111";
    cantAmbiente = 12;
    cantDormitorios = 5;
    cantBanios = 1;
    garage = true;
    ciudad = "Mdeo";
    calle = "Chana";
    numero = "2345";
    direccionProp = new dtDireccion(ciudad, calle, numero);
    mCuadradosEdificado = 34;
    mCuadradosTotales = 44;
    metrosVerdes = 10;
    nombreInmo = "Selmo";
    ventaAlq = true;
    valor = 45000;
    nombreZona = "Zona5";    
    PropCasa = new dtPropiedadCasa(cantAmbiente, cantBanios, cantDormitorios, garage, direccionProp, mCuadradosEdificado, metrosVerdes, valor, ventaAlq);
    itPC->altaPropiedadCasa(PropCasa);
    
    ///////////     Casa 2
    
    codigoProp = "2112";
    cantAmbiente = 2;
    cantDormitorios = 1;
    cantBanios = 1;
    garage = false;
    ciudad = "Paysandu";
    calle = "Gloria";
    numero = "345";
    direccionProp = new dtDireccion(ciudad, calle, numero);
    mCuadradosEdificado = 35;
    mCuadradosTotales = 55;
    metrosVerdes = 20;
    nombreInmo = "Selmo";
    ventaAlq = true;
    valor = 34560;
    nombreZona = "Zona1";    
    PropCasa = new dtPropiedadCasa(cantAmbiente, cantBanios, cantDormitorios, garage, direccionProp, mCuadradosEdificado, metrosVerdes, valor, ventaAlq);
    itPC->altaPropiedadCasa(PropCasa);
    
    ///////////     Casa 3
    
    codigoProp = "2113";
    cantAmbiente = 3;
    cantDormitorios = 1;
    cantBanios = 1;
    garage = false;
    ciudad = "Salto";
    calle = "CHAPAZ";
    numero = "345";
    direccionProp = new dtDireccion(ciudad, calle, numero);
    mCuadradosEdificado = 12;
    mCuadradosTotales = 22;
    metrosVerdes = 10;
    nombreInmo = "Garcia";
    ventaAlq = true;
    valor = 13000;
    nombreZona = "Zona1";    
    PropCasa = new dtPropiedadCasa(cantAmbiente, cantBanios, cantDormitorios, garage, direccionProp, mCuadradosEdificado, metrosVerdes, valor, ventaAlq);
    itPC->altaPropiedadCasa(PropCasa);
    
    ///////////     Casa 4
    
    codigoProp = "2114";
    cantAmbiente = 6;
    cantDormitorios = 3;
    cantBanios = 2;
    garage = true;
    ciudad = "Canelones";
    calle = "JUANICO";
    numero = "456";
    direccionProp = new dtDireccion(ciudad, calle, numero);
    mCuadradosEdificado = 34;
    mCuadradosTotales = 34;
    metrosVerdes = 0;
    nombreInmo = "Invernissi";
    ventaAlq = false;
    valor = 20000;
    nombreZona = "Zona2";    
    PropCasa = new dtPropiedadCasa(cantAmbiente, cantBanios, cantDormitorios, garage, direccionProp, mCuadradosEdificado, metrosVerdes, valor, ventaAlq);
    itPC->altaPropiedadCasa(PropCasa);
    
    ///////////     Casa 5
    
    codigoProp = "2115";
    cantAmbiente = 3;
    cantDormitorios = 1;
    cantBanios = 1;
    garage = false;
    ciudad = "Fray Bentos";
    calle = "VENECIA";
    numero = "3456";
    direccionProp = new dtDireccion(ciudad, calle, numero);
    mCuadradosEdificado = 25;
    mCuadradosTotales = 25;
    metrosVerdes = 0;
    nombreInmo = "Solei";
    ventaAlq = false;
    valor = 56789;
    nombreZona = "Zona1";    
    PropCasa = new dtPropiedadCasa(cantAmbiente, cantBanios, cantDormitorios, garage, direccionProp, mCuadradosEdificado, metrosVerdes, valor, ventaAlq);
    itPC->altaPropiedadCasa(PropCasa);
    
}

void cargarZonas(){
    Fabrica * f = Fabrica::getInstance();
    IContProp* itZ = f->getContProp();
    string nombreZ,codigoZ,Departamento;
    
    nombreZ="Zona1";
    codigoZ="101";
    Departamento="A";
    itZ->altaZona(nombreZ,codigoZ,Departamento);
    nombreZ="Zona2";
    codigoZ="101";
    Departamento="A";
    itZ->altaZona(nombreZ,codigoZ,Departamento);
    nombreZ="Zona3";
    codigoZ="101";
    Departamento="B";
   itZ->altaZona(nombreZ,codigoZ,Departamento);
    nombreZ="Zona4";
    codigoZ="101";
    Departamento="D";
    itZ->altaZona(nombreZ,codigoZ,Departamento);
    nombreZ="Zona5";
    codigoZ="101";
    Departamento="V";
    itZ->altaZona(nombreZ,codigoZ,Departamento);
     
}

void cargarDeptos(){
    Fabrica * f = Fabrica::getInstance();
    IContProp* itD = f->getContProp();
    string letraDepto, nombreDepto;
    dtDepartamento* depto;
   
    letraDepto = "A";
    nombreDepto = "Canelones";
    depto = new dtDepartamento(letraDepto, nombreDepto);
    itD->altaDepto(depto);
   
    letraDepto = "A";
    nombreDepto = "Canelones";
    depto = new dtDepartamento(letraDepto, nombreDepto);
    itD->altaDepto(depto);
   
    letraDepto = "B";
    nombreDepto = "Maldonado";
    depto = new dtDepartamento(letraDepto, nombreDepto);
    itD->altaDepto(depto);
   
    letraDepto = "C";
    nombreDepto = "Rocha";
    depto = new dtDepartamento(letraDepto, nombreDepto);
    itD->altaDepto(depto);
   
    letraDepto = "D";
    nombreDepto = "Salto";
    depto = new dtDepartamento(letraDepto, nombreDepto);
    itD->altaDepto(depto);
   
    letraDepto = "E";
    nombreDepto = "Montevideo";
    depto = new dtDepartamento(letraDepto, nombreDepto);
    itD->altaDepto(depto);
   
}

void cargarMensajes(){
    Fabrica * f = Fabrica::getInstance();
    IContUsuario* m = f->getContUsuario();
    string usuario, mensaje, inmobiliaria,propiedad;
    usuario="T1";
    mensaje="Estoy Interesado";
    inmobiliaria="I1";
    propiedad="C1";
    dtFecha *fecha =new dtFecha(25,5,2016);
    dtHora *hora=new dtHora(13,02);
    m->altamensaje(usuario, mensaje, fecha, hora, inmobiliaria, propiedad);
    usuario="T2";

    mensaje="Cuanto cuesta?";
    inmobiliaria="I3";
    propiedad="C4";
    dtFecha *fecha0 =new dtFecha();
    dtHora *hora0=new dtHora(12,30);
    m->altamensaje(usuario, mensaje, fecha0, hora0, inmobiliaria, propiedad);
    
    usuario="T3";
    mensaje="PERDON ME EQUIVOQUE";
    inmobiliaria="I1";
    propiedad="C1";
    
    dtFecha *fecha1 =new dtFecha(23,5,2016);
    dtHora *hora1=new dtHora(12,35);
    m->altamensaje(usuario, mensaje, fecha1, hora1, inmobiliaria, propiedad);
    
    usuario="T4";
    mensaje="Quiero hacer una oferta ya!";
    inmobiliaria="I2";
    propiedad="AP1";
    dtFecha *fecha2 =new dtFecha(1,6,2016);
    dtHora *hora2=new dtHora(0,30);
    m->altamensaje(usuario, mensaje, fecha2, hora2, inmobiliaria, propiedad);
    
    usuario="T1";
    mensaje="Tiene humedad?";
    inmobiliaria="I4";
    propiedad="AP2";
    dtFecha *fecha3 =new dtFecha(2,6,2016);
    dtHora *hora3=new dtHora(12,45);
    m->altamensaje(usuario, mensaje, fecha3, hora3, inmobiliaria, propiedad);
    
    usuario="T5";
    mensaje="Cual es el precio?";
    inmobiliaria="I1";
    propiedad="AP3";
    dtFecha *fecha4 =new dtFecha(3,6,2016);
    dtHora *hora4=new dtHora(2,5);
    m->altamensaje(usuario, mensaje, fecha4, hora4, inmobiliaria, propiedad);
    
    
}

void cargaDatosPrueba(){
    cout << "CUCargarDatos()" << endl;
//    Fabrica * f = Fabrica::getInstance();
//    IContProp * itp = f->getContProp();	
    // Par\E1metros 
	
    //cargarUsuAdmin();
    cargarUsuInmo();
    cargarUsuInteresado();
    cargarEdificios();
    cargarPropAptos();
    cargarPropCasa();
    cargarZonas();
    cargarDeptos();
    cargarMensajes();
}

