/*! 
   \file  operadoresExternosMonomios.cpp
	\brief Ficheros con el código de los operadores externos de la clase Monomio
*/


//  Ficheros de cabecera
#include <iostream>

#include "operadoresExternosMonomios.hpp"


//  Se incluyen los operadores sobrecargados dentro del espacio de nombres ed
namespace ed 
{
	// Operadores de igualdad
	
	// COMPLETAR

	bool operator==(ed::Monomio const & m1, ed::Monomio const & m2)
	{
		
		if((abs(m1.getCoeficiente() - m2.getCoeficiente() )) && (m1.getGrado() == m2.getGrado())){
			return true;
		}
		else { return false; }
	}

	bool operator==(ed::Monomio const & m1, double const valor){

		if(abs(m1.getCoeficiente() - valor) && (m1.getGrado() == 0)){
			return true;
		}
		else{ return false; }
	}

	bool operator==(double const valor, ed::Monomio const & m1){
				if(abs(m1.getCoeficiente() - valor) && (m1.getGrado() == 0)){
			return true;
		}
		else{ return false; }
	}




	// Operadores de desigualdad

	// COMPLETAR
	bool operator!=(ed::Monomio const & m1, ed::Monomio const & m2){

		if (abs((m1.getCoeficiente() - m2.getCoeficiente()) <= COTA_ERROR) || m1.getGrado() != m2.getGrado()) {
			return true;
		}
		else{ return false; }
	}

	bool operator!=(double const valor, ed::Monomio const & m1){

		if((m1.getGrado() != 0) || (valor != m1.getCoeficiente())){
			return true;
		}
		else{ return false; }
	}

	bool operator==(double const valor, ed::Monomio const & m1){
		
		if((m1.getGrado() != 0) || (valor != m1.getCoeficiente())){
			return true;
		}
		else{ return false; }		
	}


	// COMPLETAR LOS OTROS OPERADORES DE DESIGUALDAD


	////////////////////////////////////////////////////////////

	// Operadores unarios prefijos 

	// COMPLETAR
	ed::Monomio & operator+(ed::Monomio const & m)
	{
		// COMPLETAR Y MODIFICAR
		// Se crea un nuevo objeto
		ed::Monomio *nuevo = new ed::Monomio();


		// Se devuelve el resultado
		return *nuevo;
	}

	ed::Monomio & operator- (ed::Monomio const &m){

		// Se crea un nuevo objeto
		ed::Monomio *nuevo = new ed::Monomio();

		*nuevo = m;

		nuevo->setCoeficiente(-(nuevo->getCoeficiente()));

		// Se devuelve el resultado
		return *nuevo;
	}	

	// COMPLETAR EL OTRO OPERADOR UNARIO PREFIJO: resta


	////////////////////////////////////////////////////////////
	// Operadores aritméticos binarios

	// Suma
	ed::Monomio & operator+ (ed::Monomio const &m1, ed::Monomio const &m2){

		// Se crea un nuevo objeto
		ed::Monomio *nuevo = new ed::Monomio();

			nuevo->setCoeficiente(m1.getCoeficiente() + m2.getCoeficiente());
			nuevo->setGrado(m1.getGrado());

	
		// Se devuelve el resultado
		return *nuevo;
	}



	////////////
	// Resta

	ed::Monomio & operator- (ed::Monomio const &m1,  ed::Monomio const &m2){

		// Se crea un nuevo objeto
		ed::Monomio *nuevo = new ed::Monomio();

			nuevo->setCoeficiente(m1.getCoeficiente() - m2.getCoeficiente());
			nuevo->setGrado(m1.getGrado());

		// Se devuelve el resultado
		return *nuevo;
	}


	//////////////////
	// Multiplicación

	ed::Monomio & operator* (ed::Monomio const &m1,  ed::Monomio const &m2){
		
		ed::Monomio *nuevo = new ed::Monomio();

			nuevo->setCoeficiente((m1.getCoeficiente())*(m2.getCoeficiente()));
			nuevo->setGrado(m1.getGrado() + m2.getGrado());
	
		return *nuevo;
	}

	ed::Monomio & operator* (ed::Monomio const &m, double const valor){

		ed::Monomio *nuevo = new ed::Monomio();

			nuevo->setCoeficiente(m.getCoeficiente()*valor);
			nuevo->setGrado(m.getGrado());

		return *nuevo;
	}

	ed::Monomio & operator* (double const valor, ed::Monomio const &m){

		ed::Monomio *nuevo = new ed::Monomio();

			nuevo->setCoeficiente(m.getCoeficiente()*valor);
			nuevo->setGrado(m.getGrado());

		return *nuevo;
	}


	////////////
	// División

	ed::Monomio & operator/ (ed::Monomio const &m1, ed::Monomio const &m2){

		ed::Monomio *nuevo = new ed::Monomio();

			nuevo->setCoeficiente((m1.getCoeficiente()/m2.getCoeficiente()));
			nuevo->setGrado(m1.getGrado() - m2.getGrado());

		return *nuevo;
	}

	ed::Monomio & operator/ (ed::Monomio const &m, double const valor){

		ed::Monomio *nuevo = new ed::Monomio();

			nuevo->setCoeficiente(m.getCoeficiente()/valor);
			nuevo->setGrado(m.getGrado());

		return *nuevo;
	}
	
	ed::Monomio & operator/ (double const valor, ed::Monomio const &m){

		ed::Monomio *nuevo = new ed::Monomio();

			nuevo->setCoeficiente(m.getCoeficiente()/valor);
			nuevo->setGrado(m.getGrado());

		return *nuevo;
	}
	
	
	
	/////////////////////////////////////////////////////////////////////////////

	//  Sobrecarga del operador de entrada
	istream &operator>>(istream &stream, ed::Monomio &m) 
	{
		// COMPLETAR

   		// Se devuelve el flujo de entrada
		return stream;
	}


	//  Sobrecarga del operador de salida
	ostream &operator<<(ostream &stream, ed::Monomio const &m) 
	{
		// COMPLETAR

		// Se devuelve el flujo de salida
		return stream;
	}


}  // namespace ed
