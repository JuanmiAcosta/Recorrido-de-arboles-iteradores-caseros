//
// Created by luis on 2/12/22.
//

#ifndef P04_JUEGO_LETRAS_solver_H
#define P04_JUEGO_LETRAS_solver_H

#include <iostream>
#include <fstream>
#include <stack>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include "dictionary.h"
#include "letters_set.h"


using namespace std;
class solver {
private:
    Dictionary dict;
    LettersSet letters_set;
public:
    /**
     * @brief El constructor con parámetros del solver, tiene asociado un Dictionary y un LettersSet
     * @param dict El dictionary que contendrá el solver.
     * @param lettersset El lettersSet que contendrá el solver.
     * @return Crea e inicializa un solver.
     */
    solver(const Dictionary & dict, const LettersSet & letters_set);
    /**
     * @brief Construye el vector de soluciones a partir de las letras de una partida.
     * @param available_letters Vector de letras disponibles durante la partida, saldrán desordenador de un lettersbag.
     * @param score_game Indicará el tipo de partida (true-->puntuación / false --> longitud).
     * @return El vector de palabras con las mejores soluciones y la puntuación que obtienen.
     */
    pair<vector<string>,int> getSolutions(const vector<char> & available_letters, bool score_game);
    /**
     * @brief Una palabra se pasa a un vector de char para un major uso en el método anterior.
     * @param palabra La palabra que se pasará a vector de char.
     * @return Devuelve un vector de char a partir de la palabra.
     */
    vector<char> toVector(string palabra);
    /**
     * @brief Construye un lettersset a partir de un vector de char, va recogiendo sus letras y las veces que se repiten en el vector.
     * @param auxvector El vector de char con el que se trabajará.
     * @return Devuelve un lettersset.
     */
    LettersSet getLetterSet(vector<char> auxVector);
};


#endif //P04_JUEGO_LETRAS_solver_H
