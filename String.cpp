#include "String.h"


int String::largoCadena(const char*cc) const{
		int large=0;
        	for(int i=0; cc[i]!='\0';i++)
			large++;	
		return large;
	}


// PARTE 1
	
// Constructores:
                 
    // Constructor por defecto. Construye la cadena vacía.
    String::String(){
        this->arreglo=NULL;
        this->largo=0;
    }
                             

    // Constructor por copia.
    // String(s) construye una cadena copia de s.
    String::String(const String& s){
        this->largo=s.largo;
        if (s.largo!=0){
            this->arreglo = new char[s.largo+1]; // Reserva memoria para la cadena 
            for(int i=0; i<s.largo;i++) 
                this->arreglo[i]=s.arreglo[i];
	    //pongo el caracter de fin de texto
	    this->arreglo[this->largo]='\0';
        }else this->arreglo=NULL;
        
    }
    // Constructor común.
    // String(cc) construye un String a partir la cadena de
    // caracteres indicada en cc.
    String::String (const char*cc){
        int large=largoCadena(cc);
	this->largo = large;
	//cout << "this->largo =" << this->largo << "\n"; 
	if (large > 0){
        	this->arreglo = new char[large+1];
        	for(int i=0;i<large;i++) 
        		this->arreglo[i]=cc[i];
		//pongo el caracter de fin de texto
		this->arreglo[this->largo]='\0';
//cout << "this->arreglo =" << this->arreglo << "\n";
        }
	else
	this->arreglo = NULL;
	
    }

// Destructor:
              
      // Libera la memoria utilizada por la instancia.
      String::~String(){
	if (this->arreglo!=NULL){
        	delete[] this->arreglo;
       }
	}

// Operadores:
              
      // operator=(s) Asigna al objeto implícito la cadena s.
      String& String::operator=(const String& s){
	//cout << "Entre en Asignacion (s)\n";
	if (this != &s){
		if (this->arreglo!=NULL)
			delete[] this->arreglo;
        this->largo=s.largo;
        if (s.arreglo!=NULL){ 
           	this->arreglo= new char[this->largo+1];
           	for(int i=0; i<this->largo; i++)
           	this->arreglo[i]=s.arreglo[i];
			 //pongo el caracter de fin de texto
			this->arreglo[this->largo]='\0';
             	}else this->arreglo=NULL;
         }
         return *this;
      }


        String& String::operator=(const char* cc){
//		cout << "Entre en Asignacion (cc)\n";
            if (this->arreglo!=NULL)
		delete[] this->arreglo;
            int large=largoCadena(cc);
            this->largo= large;
	    if (large > 0){
            	this->arreglo= new char[this->largo+1];
            	for(int i=0; i<this->largo;i++)
                	this->arreglo[i]= cc[i];
		//pongo el caracter de fin de texto
		this->arreglo[this->largo]='\0';
	    }else
		this->arreglo= NULL;
	    return(*this);
	}
      
      
        // operator+(s) Retorna el resultado de la concatenación
        // del objeto implícito y s.
        String String:: operator+(const String& s) const{
//			cout << "Entre en + (string)\n";
			String nuevo;
			nuevo.largo= this->largo + s.largo;
			if (nuevo.largo> 0){
				nuevo.arreglo= new char[nuevo.largo+1];
				for(int i=0;i<this->largo;i++)
					nuevo.arreglo[i]= this->arreglo[i];
				for(int j=this->largo;j<nuevo.largo;j++)
					nuevo.arreglo[j]= s.arreglo[j-this->largo];
				//pongo el caracter de fin de texto
				nuevo.arreglo[nuevo.largo]='\0';
			}
			return nuevo;
	}
		
       String String:: operator+(const char*cc) const{
	//	   cout << "Entre en + (cc)\n";
		   	String nuevo;
			int a=largoCadena(cc);
			int large= this->largo + a;
			nuevo.largo=large;
		   	
			if (large> 0){
				nuevo.arreglo= new char[large+1];
				for(int i=0;i<this->largo;i++)
					nuevo.arreglo[i]= this->arreglo[i];
				for(int j=this->largo;j<large;j++)
					nuevo.arreglo[j]= cc[j-this->largo];
				//pongo el caracter de fin de texto
				nuevo.arreglo[large]='\0';
				
			}
			
			return nuevo;
		}


      
      // operator+=(s) Asigna el resultado de la concatenación
      // del objeto implícito y s sobre el objeto implícito.
      String& String:: operator+=(const String& s){
//		  cout << "Entre en += (string)\n";
		  int auxLargo= this->largo;
		  this->largo += s.largo;
			char * nuevo;
			if (this->largo> 0){
				nuevo= new char[this->largo+1];
				for(int i=0;i<auxLargo;i++)
					nuevo[i]= this->arreglo[i];
				for(int j=auxLargo;j<this->largo;j++)
					nuevo[j]= s.arreglo[j-auxLargo];
				nuevo[largo]='\0';
			}else
				nuevo=NULL;
			if (this->arreglo!=NULL)
				delete[] this->arreglo;
			this->arreglo=nuevo;
			return *this;
		  
		 }


	String& String:: operator+=(const char* cc){
//		cout << "Entre en += (cc)\n";
	int auxLargo= this->largo;
	this->largo += largoCadena(cc);
	char *nuevo;
	if (this->largo> 0){
		nuevo= new char[this->largo+1];
		for(int i=0;i<auxLargo;i++)
			nuevo[i]= this->arreglo[i];
		for(int j=auxLargo;j<this->largo;j++)
			nuevo[j]= cc[j-auxLargo];
		nuevo[largo]='\0';
	}
	else
		nuevo=NULL;
	if (this->arreglo!=NULL)
		delete[] this->arreglo;
	//Libera la memoria que tenia antes el objeto implicito 
	this->arreglo=nuevo;
	return *this;
	}




	// operator!() Retorna true sii la cadena es vacía. 
	bool String::operator!()const{
		return (this->largo==0);
	}
      // operator==(s) Retorna true sii la cadena del objeto
       // implícito es igual a s.
       bool String::operator==(const String& s) const{
//		cout << "Entre en == (s)\n";

	if ((s.largo==0) && (this->largo==0))
		return true;
	else{
               if ((s.arreglo!=NULL) && (this->arreglo!=NULL))
                       return (strcmp(this->arreglo,s.arreglo)==0);
               else
			if(( s.arreglo!=NULL) || (this->arreglo!=NULL))
				return false;
			else return true;
       }
}

       bool String::operator==(const char*cc) const{
//		cout << "Entre en == (cc)\n";
	if (largoCadena(cc)==this->largo){
		if (largoCadena(cc)==0)
			return true;
		else
               		if ((cc!=NULL) && (this->arreglo!=NULL)){
				return (strncmp(this->arreglo,cc,this->largo)==0);}
               		else
				if(( cc!=NULL) || (this->arreglo!=NULL))
					return false;
				else return true;
       }
	else return false;

}

       

       // operator!=(s) Retorna true sii la cadena del objeto
       // implícito es distinta de s.
       bool String::operator!=(const String& s) const{

	if ((s.largo==0) && (this->largo==0))
		return false;
	else{

	    if ((s.arreglo!=NULL) && (this->arreglo!=NULL))
                       return (strcmp(this->arreglo,s.arreglo)!=0);
               else
			if(( s.arreglo!=NULL) || (this->arreglo!=NULL))
				return true;
			else return false;
              
       }
}

       bool String::operator!=(const char* cc) const{

	if ((largoCadena(cc)==0) && (this->largo==0))
		return false;
	else{
	    if ((cc!=NULL) && (this->arreglo!=NULL))
                       return (strcmp(this->arreglo,cc)!=0);
               else
			if(( cc!=NULL) || (this->arreglo!=NULL))
				return true;
			else return false;
       }
}

       // operator<(s) Retorna true sii la cadena del
       // objeto implícito es menor que la cadena s.
       bool String::operator<(const String& s) const{
	if ((s.largo==0) && (this->largo==0))
		return false;
	else{
                if ((s.arreglo!=NULL) && (this->arreglo!=NULL))
			return (strcmp(this->arreglo,s.arreglo)<0);

               else
			if(this->arreglo==NULL)
				return true;
			else return false;
       }
}

       bool String::operator<(const char* cc) const{
	if ((largoCadena(cc)==0) && (this->largo==0))
		return false;
	else{
               if ((cc!=NULL) && (this->arreglo!=NULL))
                       return (strcmp(this->arreglo,cc)<0);
               else
			if(this->arreglo==NULL)
				return true;
			else return false;
       }
}

       // operator>(s) Retorna true sii la cadena del
       // objeto implícito es mayor que la cadena s.
       bool String::operator>(const String& s) const{
	if ((s.largo==0) && (this->largo==0))
		return false;
	else{
            if ((s.arreglo!=NULL) && (this->arreglo!=NULL))

                       return (strcmp(this->arreglo,s.arreglo)>0);

               else
			if(s.arreglo==NULL)
				return true;
			else return false;
       }
}

       bool String::operator>(const char* cc) const{
	if ((largoCadena(cc)==0) && (this->largo==0))
		return false;
	else{
            if ((cc!=NULL) && (this->arreglo!=NULL))
                       return (strcmp(this->arreglo,cc)>0);
               else
			if(cc==NULL)
				return true;
			else return false;
       }
}

       // operator<=(s) Retorna true sii la cadena del
       // objeto implícito es menor o igual que la cadena s.

       bool String::operator<=(const String& s) const{
	if ((s.largo==0) && (this->largo==0))
		return true;
	else{
	       if ((s.arreglo!=NULL) && (this->arreglo!=NULL))
                       return (strcmp(this->arreglo,s.arreglo)<=0);
               else
			return(this->arreglo==NULL);
       }
}
    
       
       bool String::operator<=(const char* cc) const{
	if ((largoCadena(cc)==0) && (this->largo==0))
		return true;
	else{
       if ((cc!=NULL) && (this->arreglo!=NULL))
                       return (strcmp(this->arreglo,cc)<=0);
               else
			return(this->arreglo==NULL);
       }
}

       // operator>=(s) Retorna true sii la cadena del
       // objeto implícito es mayor o igual que la cadena s.

       bool String::operator>=(const String& s) const{
	if ((s.largo==0) && (this->largo==0))
		return true;
	else{
          if ((s.arreglo!=NULL) && (this->arreglo!=NULL))
                       return (strcmp(this->arreglo,s.arreglo)>=0);
               else
			return(s.arreglo==NULL);
       }
}

       bool String::operator>=(const char* cc) const{
	if ((largoCadena(cc)==0) && (this->largo==0))
		return true;
	else{
                if ((cc!=NULL) && (this->arreglo!=NULL))
                       return (strcmp(this->arreglo,cc)>=0);
               else
			return(cc==NULL);
       }
}
      
	// operator[i] Retorna el carácter de la cadena del
	// objeto implícito en la posición i.
	// Si i esta fuera de rango lanzar std::out_of_range.
	
	char String::operator[](unsigned int i) const{
	//if((i>=0) && (i< this->largo))
	if(i< (unsigned)this->largo)
		return(this->arreglo[i]);
	else	
		throw out_of_range("Out of range en operator[]");
	}

// Operaciones:
               
// length() devuelve la cantidad de caracteres
// de la cadena.
	unsigned int String::length() const{
		return(unsigned (this->largo));
	} 
      
// isSubString(s1) devuelve true sii s1 es subcadena
// del objeto implícito.
// Dadas las cadenas s y s1, s1 es subcadena de s siiString s14=s11.subString(0,8);
// existen cadenas x e y tales que s = x + s1 + y.
	bool String::isSubString(const String& s1) const{
	int l_sub=s1.largo;
	int l_iter=this->largo;
	bool es=false;
	char* iter=this->arreglo;
	while(!es && l_iter>=l_sub){
		es=(strncmp(iter,s1.arreglo,l_sub)==0);
		iter++;
		l_iter--;
	}
	return(es);
	}
		
		
		
	bool String::isSubString(const char* cc) const{
	int l_sub= largoCadena(cc);
	int l_iter=this->largo;
	bool es=false;
	char* iter=this->arreglo;
	while(!es && l_iter>=l_sub){
		es=(strncmp(iter,cc,l_sub)==0);
		iter++;
		l_iter--;
	}
	return(es);

}
      
// subString(inf, sup) devuelve la subcadena del objeto
// implícito que se encuentra entre las posiciones dadas
// por inf y sup (inf y sup inclusive).
// Si inf y/o sup se van de rango lanzar std::out_of_range.
// Si inf > sup lanzar la excepción std::invalid_argument.
	String String::subString(unsigned int inf, unsigned int sup) const{
	String sub_s;
	if (((inf<(unsigned)this->largo) && (sup<(unsigned)this->largo))&& (inf<=sup)){
	//cuando no lanza ninguna excepcion
		
		sub_s.largo= sup-inf+1;
		sub_s.arreglo= new char[sub_s.largo+1];
		unsigned int i=0;
		for(unsigned int j=inf;j<=sup ;j++){
			sub_s.arreglo[i]=this->arreglo[j];
			i++;
		}
		sub_s.arreglo[sub_s.largo]='\0';
		return(sub_s);
	}else{
		if((inf>=(unsigned)this->largo) || (sup>=(unsigned)this->largo)){
			throw out_of_range("Out of range en subString");
		}else{
			if( inf>sup){
				throw invalid_argument("Invalid argument en subString");
			}
		}
	return(sub_s);             
	}
	}
		
		

      
// replace(c1, c2) Devuelve la cadena resultado de sustituir
// todas las ocurrencias de c1 por c2.
	String String::replace(char c1, char c2) const{
		String s;
		
		if (this->largo>0){
			s.largo=this->largo;
			s.arreglo= new char[this->largo];
			for (int i=0; i<this->largo; i++)
				if (this->arreglo[i]==c1)
					s.arreglo[i]=c2;
				else
					s.arreglo[i]=this->arreglo[i];
			s.arreglo[this->largo] = '\0';
		}
		return s;
	}
      
// toUpperCase() Devuelve la cadena resultado de sustituir
// todas las ocurrencias de caracteres en minúscula
// por su equivalente en mayúscula.
	String String::toUpperCase() const{
		String s;
		if(this->largo>0){
			s.largo=this->largo;
			s.arreglo= new char[s.largo+1];
			for(int i=this->largo-1; i>=0; i--){
				if ((this->arreglo[i]>='a')&&(this->arreglo[i]<='z'))
					s.arreglo[i]=this->arreglo[i]-( 'a' -'A');
				else{
					if(this->arreglo[i]=='h')
						s.arreglo[i]='H';
					else 
						s.arreglo[i]=this->arreglo[i];
				}
			}
		s.arreglo[s.largo]='\0';
		}
		
		return s;
	}



	
	
      
// toLowerCase() Devuelve la cadena resultado de sustituir
// todas las ocurrencias de caracteres en mayúscula
// por su equivalente en minúscula.

String String::toLowerCase() const{ 
	String s;
	if(this->largo>0){
		s.largo=this->largo;
		s.arreglo= new char[s.largo+1];
		for(int i=this->largo; i>=0; i--){
			if ((this->arreglo[i]>='A')&&(this->arreglo[i]<='Z'))
					s.arreglo[i]=this->arreglo[i]+('a' -'A');
			else{
				if(this->arreglo[i]=='H')
					s.arreglo[i]='h';
				else 
					s.arreglo[i]=this->arreglo[i];
			}
		}
	s.arreglo[s.largo]='\0';
	}
	return s;
	}


	char* String::getCadena() const{
		char* c;
		if (this->largo>0){
			c= new char[this->largo+1];
			for(int i=0;i<this->largo;i++){
				c[i]=this->arreglo[i];
			}
			c[this->largo]='\0';
		}else{
			c=NULL;
		}
		return c;
	}






// PARTE 2

         // Escribe una cadena de caracteres en un flujo cualquiera.
         ostream& operator<<(ostream& o, const String& s){
		if(s.length()!=0){
			char* cad= s.getCadena();
			o << cad;
			delete[] cad;
		}
		return o;
		
	}
         
	istream & operator>>(istream &i, String&s){
		char c[257];
		int z = 0;
		do{
			cin.get(c[z]);
			z++;
		}
		while((z < 257)&&(c[z-1] != '\n'));
		char* cc = new char[z];
		for ( int j=0; j<(z-1); j++ )
			cc[j] = c[j];
		cc[z-1] = '\0';
		if (z == 257){
			char d = c[z];
			while (d != '\n')
				cin.get(d);
		};
		s = String (cc);
		delete []cc;
		return i;		
	}
      


// PARTE 3

	// Operadores de comparación entre char* e instancias de String.
	bool operator==(const char* cc, const String& s){
		return (s==cc);
	}
	
	bool operator!=(const char* cc, const String& s){
		return (s!=cc);	
	}
	
	bool operator<(const char* cc, const String& s){
		return (s>cc);		
	}
	
	bool operator>(const char* cc, const String& s){
		return (s<cc);	
	}
	
	bool operator<=(const char* cc, const String& s){
		return (s>=cc);
	}
	
	bool operator>=(const char* cc, const String& s){
		return (s<=cc);
	}