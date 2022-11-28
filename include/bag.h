#ifndef __BAG_H__
#define __BAG_H__


/**
 * @brief TDA Bag
 *
 * Este TDA es un template que almacena objetos en un vector de T.
 */

#include <iostream>
#include <stack>
#include <set>
#include <vector>
#include <map>
#include <string>
#include<algorithm>

using namespace std;

template <class T>
class Bag {
private:
    /**
      @brief Es el vector interno de la clase. Con el podremos acceder a las repeticiones y puntaje de las letras.
    **/
    vector<T> v;

public:


    /**
      @brief Constructor por defecto.
      @post Crea un vector de T vacío.
    **/
    Bag() {
        //v=new vector<T>();
    }

    /**
      @brief Constructor de copia.
      @param other otro Bag<T>, con el cual igualamos nuestro objeto interno a él.
      @post Crea una copia exacta de otro objeto tipo Bag.
    **/
    Bag(const Bag<T> &other) {
        (*this) = other;
    }

    /**
      @brief Añade un elemento a la bolsa.
      @param element Elemento de tipo T,que se añade a la bolsa.
      @pre element no puede ser nulo.
      @post Añade el elemento al final del vector de la bolsa.
    **/
    void add(const T &element) {
        v.push_back(element);
    }

    /**
      @brief Coge un valor al azar de la bolsa (del vector), lo devuelve y lo elimina.
      @post Devuelve un objeto al azar y lo elimina.
      @return Objeto de tipo T, elegido al azar de la bolsa y eliminado de la misma.
    **/
    T get() {
        int aux;
        T aux2;
        srand(time(NULL));
        aux=rand()%v.size();
        aux2= v.at(aux);
        v.at(aux)=v.at(v.size()-1);
        v.pop_back();
        return aux2;
    }

    /**
      @brief Elimina todos los elementos del vector, es decir, limpia la bolsa.
      @post La bolsa se queda vacía.
    **/
    void clear() {
        v.clear();
    }

    /**
      @brief Devuelve el número de elementos de la bolsa.
      @return Devuelve un unsigned int con el número de elementos en el vector de la bolsa.
    **/
    unsigned int size() const {
        return v.size();
    }


    /**
      @brief Booleano que comprueba si una bolsa está vacía o no (si el vector interno tiene size=0).
      @return True si la bolsa está vacía, False si no.
    **/
    bool empty() {
        return v.empty();
    }


    /**
      @brief Sobrecarga del operador de asignación.
      @param cl bolsa de letras nueva a copiar.
      @post Se copia el vector interno del objeto Bag pasado como parámetro al vector interno de la bolsa..
    **/
    const Bag<T> operator=(const Bag<T> &cl) {
        v.clear();
        v=cl.v;
        return (*this);
    }

};
#endif
