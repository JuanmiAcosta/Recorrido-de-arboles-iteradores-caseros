#ifndef __LETTERS_BAG_H__
#define __LETTERS_BAG_H__

/**
 * @brief TDA LettersBag
 *
 * Este TDA almacena un elemento de la plantilla Bag de chars.
 */

#include <iostream>
#include <stack>
#include <set>
#include <vector>
#include <map>
#include <string>
#include<algorithm>
#include "bag.h"
#include "letters_set.h"

using namespace std;
class LettersBag {
private:
    Bag <char> letters;
public:

    /**
      @brief Constructor por defecto.
      @post Crea una Bolsa de char vacía.
    **/
    LettersBag();

    /**
      @brief Constructor con parámetros. Recibe un letterSet, y tenemos que rellenar nuestro LetterBag con las letras que contenga el letterSet pasado por parámetro.
      @param letterSet LettersSet con el cual rellenamos nuestra bolsa, con las letras que contenga el parámetro, y tantas veces como sus repeticiones.
      @post Crea una bolsa con las letras del letterSet.
    **/
    LettersBag(const LettersSet & letterSet);

    /**
      @brief Introduce una letra en la bolsa.
      @param l Letra a insertar en la bolsa.
      @post Añade una letra a la bolsa.
    **/
    void insertLetter (const char & l);

    /**
      @brief Extrae una letra aleatoria de la bolsa y la borra
      @post Elimina una letra de la bolsa.
    **/
    char extractLetter();

    /**
      @brief Extrae un conjunto de letras de la bolsa, las elimina y devuelve la lista de las letras extraidas.
      @param num Entero con el número de letras a extraer.
      @pre El parámetro debe ser mayor que el número de letras de la bolsa.
      @post Borra tantas letras como el parámetro indique.
      @return Vector con las letras extraidas
    **/
    vector<char> extractLetters(int num);

    /**
      @brief Limpia el LettersBag. Elimina todo el contenido de la bolsa.
      @post Elimina todos los elementos de la bolsa y deja la bolsa vacía.
    **/
    void clear();

    /**
      @brief Devuelve el tamaño de la bolsa.
      @return Devuelve un unsigned int con el tamaño de la bolsa.
    **/
    unsigned  int size();

    /**
      @brief Sobrecarga del operador de asignación.
      @param cl bolsa de letras nueva a copiar.
      @post Se copia el vector interno del objeto Bag pasado como parámetro al vector interno de la bolsa.
    **/
    LettersBag operator=(const LettersBag &cl);


};
#endif
