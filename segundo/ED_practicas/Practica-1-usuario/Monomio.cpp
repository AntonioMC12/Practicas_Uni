/*! 
   \file  Monomio.cpp
   \brief Fichero que contiene el código de las funciones de la clase Monomio
*/


//  Ficheros de cabecera
#include <iostream>

#include "Monomio.hpp"

// Operadores de asignación

// COMPLETAR

ed::Monomio & ed::Monomio::operator=(ed::Monomio const &m)
{

	//podemos usar los modificadores para asignar los diferentes atributos.

	setCoeficiente(m.getCoeficiente());
	setGrado(m.getGrado());

	assert(getCoeficiente() == m.getCoeficiente());
	assert(getGrado() == m.getGrado());


	// Se devuelve el objeto actual
	return *this;
}


ed::Monomio & ed::Monomio::operator=(double const &x)
{
	//podemo usar los modificadores para asignar los diferentes atributos.

	setCoeficiente(x);
	setGrado(0);

	assert(getCoeficiente() == x);
	assert(getGrado() == 0);

	// Se devuelve el objeto actual
	return *this;
}



//////////////////////////////////////////////////////////////

// Operadores aritméticos y asignación

// COMPLETAR

ed::Monomio & ed::Monomio::operator+=(ed::Monomio const &m)
{
	//precondicion
	if (m.getGrado() == grado_) {
		
		this->setCoeficiente(this->getCoeficiente() + m.getCoeficiente());

		/*comprobamos que El coeficiente del monomio actual se ha incrementado con el coeficiente
		  del monomio “m”.*/
		assert(this->getCoeficiente() == this->getCoeficiente() - m.getCoeficiente());

		assert(m.getCoeficiente() == coeficiente_);

		return *this;
		
	}
	

	// Se devuelve el objeto actual
	return *this;
}

ed::Monomio & ed::Monomio::operator-=(ed::Monomio const &m){

	//precondicion
	if(m.getGrado() == this->getGrado()){

		this->setCoeficiente(this->getCoeficiente() - m.getCoeficiente());

		//assertos

		return *this;
	}

	return *this;
}

ed::Monomio & ed::Monomio::operator*=(ed::Monomio const &m){

	//multiplicamos los coeficientes
	this->setCoeficiente(this->getCoeficiente() * m.getCoeficiente());
	//se suman los grados
	this->setGrado(this->getGrado() + m.getGrado());


	//assertos
	
	return *this;
}

ed::Monomio & ed::Monomio::operator*=(double const &real){

	this->setCoeficiente(this->getCoeficiente() * real);

	//assertos


return *this;
}

ed::Monomio & ed::Monomio::operator/=(ed::Monomio const &m){

	if (m.getGrado() <= this->getGrado() && m.getCoeficiente() > COTA_ERROR) {
		
		this->setCoeficiente(this->getCoeficiente() / m.getCoeficiente());
		this->setGrado(this->getGrado() - m.getGrado());

		return *this;

	}
	
return *this;

}

ed::Monomio & ed::Monomio::operator/=(double const &real){

	if(real > COTA_ERROR){
		this->setCoeficiente(this->getCoeficiente / real);

		//assertos
		return *this;
	}

return *this;
}


///////////////////////////////////////////////////////////////////////

// Funciones lectura y escritura de la clase Monomio

void ed::Monomio::leerMonomio(){

	int aux1 = 0;
	double aux2;

	std::cout<<"Introduce por Teclado un valor para el coeficiente"<<std::endl;
	std::cin>>aux2;
	this->setCoeficiente(aux2);

	while(aux1 < 0){
		std::cout<<"Introduzca un Grado valido"<<std::endl;
		std::cin>>aux1;
	}
	this->setGrado(aux1);

	assert(this->getGrado() >= 0);


}




///////////////////////////////////////////////////////////////////////

// Funciones auxiliares de la clase Monomio

double ed::Monomio::calcularValor(double valor){

	//calculamos el resultado del monomio "coeficiente * valor ^ grado"

	return pow((this->getCoeficiente()* valor), this->getGrado());

}

// COMPLETAR

