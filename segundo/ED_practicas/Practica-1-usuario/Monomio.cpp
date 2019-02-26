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
		this->setCoeficiente(this->getCoeficiente() / real);

		//assertos
		return *this;
	}

return *this;
}


///////////////////////////////////////////////////////////////////////

// Funciones lectura y escritura de la clase Monomio

void ed::Monomio::leerMonomio() {
	double coeficiente_auxiliar;
	int grado_auxiliar;

	std::cout << "Introduce los valores del monomio:" << std::endl;
	std::cout << "\tCoeficiente: ";
	std::cin >> coeficiente_auxiliar;
	std::cout << "\tGrado (mayor o igual a 0): ";
	std::cin >> grado_auxiliar;

	while(grado_auxiliar < 0){
		std::cout << "Introduzca un grado mayor o igual a 0: ";
		std::cin >> grado_auxiliar;
	}

	setCoeficiente(coeficiente_auxiliar);
	setGrado(grado_auxiliar);
}

void ed::Monomio::escribirMonomio(){
	int coeficiente = this->getCoeficiente();
	double grado = this->getGrado();

	if (coeficiente != 1){
		std::cout<<coeficiente;
	}
	else if(coeficiente == -1){
		std::cout<<"-";
	}

	if (grado > COTA_ERROR){ 
		std::cout<<"X";
		if(std::abs(grado - 1) > COTA_ERROR){  
			std::cout<<"^"<<grado;
		}
	}
	std::cout<<std::endl;
}




///////////////////////////////////////////////////////////////////////

// Funciones auxiliares de la clase Monomio

double ed::Monomio::calcularValor(double valor){

	//calculamos el resultado del monomio "coeficiente * valor ^ grado"

	return pow((this->getCoeficiente()* valor), this->getGrado());

}

// COMPLETAR