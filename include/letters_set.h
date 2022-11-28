#ifndef __LETTER_SET_H__
#define __LETTER_SET_H__

/**
 * @brief TDA LetterInfo
 *
 * Contiene información sobre un determinado carácter del juego de las
 * letras. En concreto, almacena información sobre el número de repeticiones de
 * la letra en la partida y de la puntuación que otorga al utilizarse en una
 * palabra
 */

/**
 * @brief TDA LettersSet
 *
 * Este TDA representa un conjunto de letras, con la información necesaria para
 * jugar una partida al juego de las letras, es decir, el número de repeticiones
 * que tenemos de la letra y la puntuación que dicha letra otorga cuando se
 * utiliza en una palabra
 */

#include <iostream>
#include <fstream>
#include <stack>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

const int COMIENZO_MINUS = 97; //a
const int FINAL_MINUS = 122; //z

struct LetterInfo {
    int repetitions;
    int score;
};

class LettersSet{
private:
    /**
      @brief Es el map interno de la clase. Con el podremos acceder a las repeticiones y puntaje de las letras.
    **/
    map<char, LetterInfo> letters;

public:
    /**
      @brief Inicializa un LettersSet.
      @post Lo inicializa vacío.
    **/
    LettersSet();

    /**
      @brief Inicializa un LettersSet.
      @param other otro LettersSet, por lo que es un constructor de copia.
      @pre se ha de sobrecargar el operador de asignación "=" antes.
      @post Es una copia del otro LettersSet.
    **/
    LettersSet(const LettersSet & other);

    /**
      @brief Inserta un valor en el LettersSet, si este ya está, se aumenta su repetición en el mismo. Devuelve un booleano que indica si se insertó el valor o sólo se incrementó su repetición.
      @param val Es un pair como los que tiene "letters".
      @post Si no estaba ese "key" se inserta, si estaba se aumenta su repetición.
    **/
    bool insert (const pair< char,LetterInfo > & val);

    /**
      @brief Borra el pair que contenga esa key.
      @param key Es la letra clave del pair a borrar
      @post Se devuelve un booleano con la info. de si se borró o no.
    **/
    bool erase (const char & key);

    /**
      @brief Se hace "clear" del map "letters" interno.
      @post Se deja vacío.
    **/
    void clear();

    /**
      @brief Indica si el map interno "letters" está vacío o no.
      @post Se devuelve un booleano con la info. de si está vacío o no.
    **/
    bool empty() const;

    /**
      @brief Indica el tamaño del "letters" interno.
      @post Se devuelve un entero con el tamaño.
    **/
    unsigned int size() const;

    /**
      @brief Devuelve la puntuación de una palabra en particular.
      @param word es la palabra cuyo puntaje se calculará.
      @post Se devuelve un entero con la suma de los puntajes de todas sus letras.
    **/
    int getScore (string word);

    /**
      @brief Sobrecarga del operador de asignación.
      @param cl Un LettersSet.
      @pre Se ha de llamar con otro LettersSet.
      @post Se le hace una copia de todos los parámetros de cl.
    **/
    LettersSet & operator= (const LettersSet &cl);

    /**
      @brief Sobrecarga del operador de indexación.
      @param val es la key del map "letters".
      @post Se hace uso del operador de indexación de map.
    **/
    LetterInfo& operator [] (const char &val);

    /**
      @brief Sobrecarga del operador de de salida.
      @param os flujo de datos.
      @param cl LettersSet a sacar por la salida estándar
      @post Se van sacando todos los datos del pair char y LetterInfo.
    **/
    friend ostream& operator << (ostream &os, const LettersSet &cl); //Lo declaramos friend para poder acceder a los atributos de la clase

    /**
      @brief Sobrecarga del operador de entrada.
      @param is flujop de datos.
      @param cl LettersSet en el que insertar los datos.
      @post Se le van metiendo los datos del fichero al LetterSet.
    **/
    friend istream& operator >>(istream &is, LettersSet &cl);

    //COSECHA PROPIA PARA QUE FUNCIONEN LAS COSAS

    /**
      @brief Devuelve el letters interno del objeto.
    **/
    map<char, LetterInfo> getLetters();

    bool existe (char letra);

    class iterator{
    private:
        map<char,LetterInfo>::iterator it;
    public:
        iterator(){};

        iterator(const map<char,LetterInfo>::iterator ot){
            it = ot;
        }

        ~iterator(){};

        iterator &operator=(const map<char,LetterInfo>::iterator &i){
            it=i;
            return (*this);
        }

        const pair<char,LetterInfo> operator *() const{
            return *it;
        }

        iterator &operator++(){
            ++it;
            return (*this);
        }

        iterator &operator--(){
            --it;
            return (*this);
        }

        iterator &operator--(int){
            it--;
            return (*this);
        }

        iterator &operator++(int){
            it++;
            return (*this);
        }

        bool operator ==(const iterator &ot){
            return it == ot.it;
        }

        bool operator !=(const iterator &ot){
            return it != ot.it;
        }

    };

    class const_iterator {
    private:
        map<char, LetterInfo>::const_iterator it;
    public:
        const_iterator() {};

        ~const_iterator() {};

        const_iterator(map<char, LetterInfo>::const_iterator iterator) {

        }
    };

    const_iterator cbegin() const{
        const_iterator it;
        it = this->letters.begin();
        return it;
    }

    const_iterator cend() const{
        const_iterator it;
        it = this->letters.end();
        return it;
    }

    iterator begin(){
        iterator it;
        it = this->letters.begin();
        return it;
    }

    iterator end(){
        iterator it;
        it = this->letters.end();
        return it;
    }

};


#endif