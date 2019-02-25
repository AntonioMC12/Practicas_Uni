/*! 
	\file Monomio.hpp
	\brief Definición de la clase Monomio
*/

#ifndef _MONOMIO_HPP_
#define _MONOMIO_HPP_

// Para usar la funciones pow y std::abs
#include <cmath>

// Para controlar las pre y post condiciones mediante asertos
#include <cassert>

#define COTA_ERROR 1.0e-6  //!< Cota de error para la comparación números reales

// Se incluye la clase Monomio dentro del espacio de nombre de la asigantura: ed
namespace ed
{
//!  Definición de la clase Monomio:  \f$ coeficiente \hspace{1ex} X^{grado} \f$ 
class Monomio
{
	//! \name Atributos privados de la clase Monomio
	private:

		double coeficiente_;
		int grado_;


	//! \name Funciones o métodos públicos de la clase Monomio
	public:

	//! \name Constructores de la clase Monomio

		Monomio(const double &coeficiente = 0.0 , const int &grado = 0){

		//comprobamos las precondiciones

		#ifndef NDEBUG
			assert(grado >= 0);
		#endif

		setCoeficiente(coeficiente);
		setGrado(grado);

		//comprobamos las postcondiciones

		#ifndef NDEBUG

			assert(std::abs(getCoeficiente() - coeficiente) < COTA_ERROR); //comprobamos que el coeficiente es introducido correctamente
			assert(getGrado() == grado);								 //comprobamos que el grado es introducido correctamente
		
		#endif
		}

		Monomio(Monomio &m){
			
			setCoeficiente(m.getCoeficiente());
			setGrado(m.getGrado());
		
			#ifndef NDEBUG
				
				assert(std::abs(this->getCoeficiente() - m.getCoeficiente()) < COTA_ERROR);
				assert(this->getGrado() == m.getGrado());
			
			#endif
		}

	//! \name Observadores: funciones de consulta de la clase Monomio

		double getCoeficiente() const { return coeficiente_; }
		int getGrado() const { return grado_; }



	//! \name Funciones de modificación de la clase Monomio

		void setCoeficiente( double const &coeficiente ){

			coeficiente_ = coeficiente;

			#ifndef NDEBUG

				assert(std::abs(this->getCoeficiente() - coeficiente) < COTA_ERROR);
			
			#endif
		}

		void setGrado( int const &grado ){
			 
			 grado_ = grado;

			 #ifndef NDEBUG

			 	assert(getGrado() == grado);

			 #endif
		}


	/////////////////////////////////////////////////

	//! \name Operadores de la clase Monomio

	// Operadores de asignación

		// COMPLETAR LOS COMENTARIOS DE DOXYGEN
		Monomio & operator=(Monomio const &m);

		// COMPLETAR LOS COMENTARIOS DE DOXYGEN
		Monomio & operator=(double const &x);


	// Operadores aritméticos y asignación

		// COMPLETAR LOS COMENTARIOS DE DOXYGEN
		Monomio & operator+=(Monomio const &m);

		Monomio & operator-=(Monomio const &m);

		Monomio & operator*=(Monomio const &m);

		Monomio & operator*=(double const &real);

		Monomio & operator/=(Monomio const &m);

		Monomio & operator/=(double const &real);

	/////////////////////////////////////////////////////////////////////////////////////

	//! \name Funciones lectura y escritura de la clase Monomio

	void leerMonomio();

	void escribirMonomio();


	///////////////////////////////////////////////////////////////////////

	//! \name Funciones auxiliares de la clase Monomio

	double calcularValor(double valor);



};  // Fin de la definición de la clase Monomio

}  //  Fin de namespace ed.

// _MONOMIO_HPP_

#endif
