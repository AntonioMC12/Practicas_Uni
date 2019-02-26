/*! 
	\file operadoresExternosMonomios.hpp
	\brief Ficheros con los prototipos de los operadores externos de la clase Monomio
	\author Antonio Muñoz Cubero
*/

#ifndef _OperadoresExternosMonomios_HPP_
#define _OperadoresExternosMonomios_HPP_

// Facilita la entrada y salida
#include <iostream>

#include "Monomio.hpp"

// Para la sobrecarga de los operadores de flujo: << y >>
using std::istream;
using std::ostream;

// Espacio de nombre de la asigantura: ed
namespace ed{

//////////////////////////////////////////////////////////////////////////////////////
	// Operadores externos que no pertenecen a la clase Monomio

	//! \name Operadores de igualdad  

	/**
	 * @brief Operador logico de igualdad, te permite saber si m1 == m2
	 * 
	 * @param m1 
	 * @param m2 
	 * @return true 
	 * @return false 
	 */
	bool operator==(ed::Monomio const & m1, ed::Monomio const & m2);

	/**
	 * @brief Operador logico de igualdad, te permite saber si m1 == valor
	 * 
	 * @param m1 
	 * @param valor 
	 * @return true 
	 * @return false 
	 */
	bool operator==(ed::Monomio const & m1, double const valor);

	/**
	 * @brief Operador logico de igualdad, te permite saber si valor == m1
	 * 
	 * @param valor 
	 * @param m1 
	 * @return true 
	 * @return false 
	 */
	bool operator==(double const valor, ed::Monomio const & m1);

	//! \name Operadores de desigualdad 

	/**
	 * @brief Operador logico de desigualdad, te permite saber si m1 != m2
	 * 
	 * @param m1 
	 * @param m2 
	 * @return true 
	 * @return false 
	 */
	bool operator!=(ed::Monomio const & m1, ed::Monomio const & m2);

	/**
	 * @brief Operador logico de desigualdad, te permite saber si valor =! m1
	 * 
	 * @param valor 
	 * @param m1 
	 * @return true 
	 * @return false 
	 */
	bool operator!=(double const valor, ed::Monomio const & m1);

	/**
	 * @brief Operador logico de desigualdad, te permite saber si m1 =! valor
	 * 
	 * @param m1 
	 * @param valor 
	 * @return true 
	 * @return false 
	 */
	bool operator!=(ed::Monomio const & m1, double const valor);

	///////////////////////////////////////////////////

	//! \name Operadores unarios prefijos

	/**
	 * @brief Devuelve la suma de un monomio
	 * 
	 * @param m 
	 * @return ed::Monomio& 
	 */

	ed::Monomio & operator+(ed::Monomio const & m);

	/**
	 * @brief Devuelve la resta de un monomio
	 * 
	 * @param m 
	 * @return ed::Monomio& 
	 */
	ed::Monomio & operator-(ed::Monomio const & m);


	//////////////////////////////////////////////////////////

	//! \name Operador binario de la suma 

	/**
	 * @brief Nos permite sumar monomios
	 * 
	 * @param m1 
	 * @param m2 
	 * @return ed::Monomio& 
	 */
	 ed::Monomio & operator+ (ed::Monomio const &m1, ed::Monomio const &m2);


	//////////////////////////////////////////////////////////
	//! \name Operador binario de la resta

	/**
	 * @brief Operador binario que nos permite restar
	 * 
	 * @param m1 
	 * @param m2 
	 * @return ed::Monomio& 
	 */

	ed::Monomio & operator- (ed::Monomio const &m1,  ed::Monomio const &m2);


	///////////////////////////////////////////////////////////////////////////
	//! \name Operadores binarios de la multiplicación

	/**
	 * @brief Operador binario que nos permite multiplicar dos monomios
	 * 
	 * @param m1 
	 * @param m2 
	 * @return ed::Monomio& 
	 */

	ed::Monomio & operator* (ed::Monomio const &m1,  ed::Monomio const &m2);

	/**
	 * @brief Operador binario que nos permite multiplicar un valor por un monomio
	 * 
	 * @param valor 
	 * @param m 
	 * @return ed::Monomio& 
	 */
	ed::Monomio & operator* (double const valor, ed::Monomio const &m);

	/**
	 * @brief Operador binario que nos permite multiplicar un monomio por un valor
	 * 
	 * @param m 
	 * @param valor 
	 * @return ed::Monomio& 
	 */

	ed::Monomio & operator* (ed::Monomio const &m, double const valor);		

	///////////////////////////////////////////////////////////////////////////

	//! \name Operadores binarios de la división 

	/**
	 * @brief Operador binaro que nos permite la division de monomios
	 * 
	 * @param m1 
	 * @param m2 
	 * @return ed::Monomio& 
	 */

	ed::Monomio & operator/ (ed::Monomio const &m1, ed::Monomio const &m2);

	/**
	 * @brief Operador binario que nos permite la division de un monomio por un valor
	 * 
	 * @param m 
	 * @param valor 
	 * @return ed::Monomio& 
	 */

	ed::Monomio & operator/ (ed::Monomio const &m, double const valor);

	/**
	 * @brief Operador binario que nos permite la division de un valor entre un monomio
	 * 
	 * @param valor 
	 * @param m 
	 * @return ed::Monomio& 
	 */
	ed::Monomio & operator/ (double const valor, ed::Monomio const &m);
	/////////////////////////////////////////////////////////////////////////////

	//! \name Sobrecarga de los operadores de entrada y salida 

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	 istream &operator>>(istream &stream, ed::Monomio &m);

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	 ostream &operator<<(ostream &stream, ed::Monomio const &m);

}  // Fin de namespace ed.

#endif // _OperadoresExternosMonomios_HPP_


