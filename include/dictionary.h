//
// Created by fluque1995 on 8/9/21.
//

#ifndef TREE_DICTIONARY_HPP
#define TREE_DICTIONARY_HPP

#include "tree.h"
#include <string>
#include <iostream>
#include <vector>
#include <utility>
#include <set>

using namespace std;

class Dictionary {
private:
    /**
     * @brief Struct to represent a character inside the tree.
     *
     * The struct contains information about the character it that node, and
     * information marking if a valid word of the dictionary finishes in
     * that character
     */
    struct char_info {
        char character;
        bool valid_word;

        /**
         * Default constructor
         */
        inline char_info() : character(0), valid_word(false) {}

        /**
         * @brief Parameters constructor
         *
         * @param character Character to be inserted
         * @param valid Marker for word validity
         */
        inline char_info(char character, bool valid = false) : character(character), valid_word(valid) {}

        inline bool operator==(const char_info &rhs) {
          return this->character == rhs.character && this->valid_word == rhs.valid_word;
        }

        inline bool operator!=(const char_info &rhs) { return !(*this == rhs); }

        inline bool operator*() { return this->character; }

        inline friend std::ostream &operator<<(std::ostream &os, const char_info &other) {
          os << other.character << (other.valid_word ? "✓" : "×");
          return os;
        }
    };

    tree<char_info> words;
    int total_words;
    typedef tree<char_info>::node node;

    /**
     * @brief Find the lower bound of a character among the children of the current node
     *
     * If the character exists among the children of the current node, that node is returned. If not,
     * the returned node is the one with the biggest character (in terms of alphabetical order) smaller
     * than the searched one
     *
     * @param character Character to be found
     * @param current Reference node, the one whose children are going to be explored
     * @return Lower bound node for the seeked character
     */
    node findLowerBoundChildNode(char character, node current);

    /**
     * @brief Insert character as children of the current node
     *
     * This method tries to insert a new character in the tree, as a child of the current node.
     * If there already exists a node with that character, instead of inserting a new node, the
     * already existing node with the character is returned
     *
     * @param character Character to be inserted
     * @param current Reference node, the one that will be parent of the new inserted node
     * @return Node corresponding to the inserted character
     */
    node insertCharacter(char character, node current);

    /**
     * @brief Método privado llamado por el método público "getOccurrences" público
     * @param curr_node Root del "words" interno del dictionary (tree<char_info>)
     * @param c El caracter del que se sacará la información.
     * @return Devuelve el número de ocurrencias en el árbol
     */
    int getOccurrences(node curr_node, char c);
    /**
     * @brief Método privado llamado por el método público "getTotalUsages"
     * @param curr_node Root del "words" interno del dictionary (tree<char_info>)
     * @param c El caracter del que se sacará la información.
     * @return Devuelve el número de usos de la letra en el diccionario
     */
    std::pair<int, int> getTotalUsages(node curr_node, char c);

public:

    /**
     * @brief Constructor por defecto
     *
     * Crea un Dictionary vacío
     */
    Dictionary();

    /**
     * @brief Constructor de copia
     *
     * Crea un Dictionary con el mismo contenido que el que se pasa como argumento
     *
     * @param other Dictionary que se quiere copiar
     */
    Dictionary(const Dictionary &other);

    /**
     * @brief Destructor
     *
     * Limpia todos los elementos del Dictionary antes de borrarlo
     */
    ~Dictionary();

    /**
     *  \brief Limpia el Dictionary
     *
     *  Elimina todas las palabras contenidas en el conjunto
     */
    void clear() { this->words.clear(); this->total_words = 0; }

    /**
     * @brief Tamaño del diccionario
     *
     * @return Número de palabras guardadas en el diccionario
     */
    unsigned int size() const { return this->total_words; }

    /**
     * @brief Comprueba si el diccionario está vacio.
     * @return true si el diccionario está vacío, false en caso contrario
     */
    bool empty() const { return this->total_words == 0; }

    /**
     * @brief Indica si una palabra esta en el diccionario o no.
     *
     * Este método comprueba si una determinada palabra se encuentra o no en el dicccionario
     *
     * @param palabra: la palabra que se quiere buscar.
     * @return Booleano indicando si la palabra existe o no en el diccionario
     */
    bool exists(const string &val);

    /**
     * @brief Inserta una palabra en el diccionario
     *
     * @param val palaba a insertar en el diccionario
     * @return Booleano que indica si la inserción ha tenido éxito. Una palabra se inserta
     * con éxito si no existía previamente en el diccionario
     */
    bool insert(const string &val);

    /**
     * @brief Elimina una palabra del diccionario
     *
     * @param val Palabra a borrar del diccionario
     *
     * @return Booleano que indica si la palabra se ha borrado del diccionario
     */
    bool erase(const string &val);

    /**
     * @brief Sobrecarga del operador de asignación
     */
    Dictionary &operator=(const Dictionary &dic);

    /**
     * @brief Sobrecarga del operador de entrada
     *
     * Permite leer las palabras de un fichero de texto e introducirlas en el
     * diccionario
     *
     * @param is Flujo de entrada
     * @param dic Diccionario a rellenar
     * @return Flujo de entrada para poder encadenar el operador
     */
    friend istream &operator>>(istream &is, Dictionary &dic);

    /**
     * @brief Sobrecarga del operador de salida
     *
     * Permite imprimir el diccionario completo a un flujo de salida
     *
     * @param os Flujo de salida, donde imprimir el diccionario
     * @param dic Diccionario a imprimir
     * @return Flujo de salida, para poder encadenar el operador
     */
    friend ostream &operator<<(ostream &os, const Dictionary &dic);

    //////////////////////////////////////////////// Recursive functions ///////////////////////////////////////////////
    /**
      @brief Se le pasa la letra de la cuál queremos saber su número de ocurrencias en el árbol.
      @param c Letra de la que sacaremos la información.
      @post Nos devuelve su número de ocurrencias.
**/
    int getOccurrences(const char c);
/**
      @brief Se le pasa la letra de la cuál queremos saber su número de usu en el diccionario.
      @param c Letra de la que sacaremos la información.
      @post Nos devuelve su número de usos.
**/
    int getTotalUsages(const char c);

    ///////////////////////////////////////////////////// Iterator ////////////////////////////////////////////////////

    class iterator {
    private:
        std::string curr_word;
        tree<char_info>::const_preorder_iterator iter;

    public:
        /**
      @brief Constructor por defecto del iterador de diccionario.
      @post La current word será vacía, y el iterador interno de tree<char_info> usa el constructor po defecto.
**/
        iterator();

        /**
      @brief Constructor de copia del iterador de diccionario.
      @param iter es un iterador de tree<char_info>.
      @post También pone la current word vacía e iguala el iterador interno al pasado como argumento.
**/
        iterator(tree<char_info>::const_preorder_iterator iter);

        /**
      @brief Sobrecarga del operador *.
      @post En este caso devolveremos la current word.
**/
        std::string operator*();

        /**
      @brief Sobrecarga del operador ++.
      @post Mientras que la letra actual (nodo) no sea una palabra válida establecemos ciertas reglas con el current_level del iterador interno que vayan modificando la current
      word hasta dar con la próxima palabra válida, y devolvemos ese iterador.
**/
        iterator &operator++();

        /**
      @brief Sobrecarga del operador ==.
      @post Comparamos si los dos iteradores internos de tree<char_info> sean iguales.
**/
        bool operator==(const iterator &other);

        /**
      @brief Sobrecarga del operador !=.
      @post Comparamos si los dos iteradores internos de tree<char_info> sean desiguales.
**/
        bool operator!=(const iterator &other);

    };

    /**
      @brief Método begin() del iterador de diccionario.
      @post Colocamos el iterador interno en su begin().
**/
    iterator begin() const;

    /**
      @brief Método end() del iterador de diccionario.
      @post Colocamos el iterador interno en su end().
**/
    iterator end() const;

    ///////////////////////////////////////////////// Letters Iterator /////////////////////////////////////////////////

    class possible_words_iterator {
    public:
        possible_words_iterator();

        possible_words_iterator(node current_node, vector<char> available_letters);

        possible_words_iterator(const possible_words_iterator &other);

        possible_words_iterator &operator=(const possible_words_iterator &other);

        bool operator==(const possible_words_iterator &other) const;

        bool operator!=(const possible_words_iterator &other) const;

        possible_words_iterator &operator++();

        std::string operator*() const;

    private:
        multiset<char> available_letters;
        int level;
        node current_node;
        string current_word;

    };

    possible_words_iterator possible_words_begin(vector<char> available_characters) const;

    possible_words_iterator possible_words_end() const;
};

#endif //TREE_DICTIONARY_HPP
