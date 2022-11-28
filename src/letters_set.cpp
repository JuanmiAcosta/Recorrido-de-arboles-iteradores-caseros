#include "letters_set.h"

LettersSet & LettersSet::operator= (const LettersSet &cl){
    map<char,LetterInfo> aux (cl.letters);
    this->letters.swap(aux);
}

map<char, LetterInfo> LettersSet::getLetters(){
    return letters;
}

LettersSet::LettersSet(){

}

LettersSet::LettersSet( const LettersSet &other){
    (*this) = other;
}

bool LettersSet::insert (const pair< char, LetterInfo> & val){
    bool exito=false;

    if (this->getLetters()[val.first].repetitions == 0) {
        letters.insert(val);
        exito = true;
    }else if(this->getLetters()[val.first].repetitions > 0){
        this->getLetters()[val.first].repetitions++;
    }

    return exito;
}

bool LettersSet::erase (const char & key){
    bool exito=false;
    map<char,LetterInfo>::iterator it;
    it=this->letters.find('key'); //Hacemos un iterador de map para buscar la key y borrarla si está en el map
    if (it != this->letters.end()){
        this->letters.erase(it);
        exito=true;
    }
    return exito;
}

void LettersSet::clear(){
    this->letters.clear();
}

bool LettersSet::empty() const{
    return (this->letters.empty());
}

unsigned int LettersSet::size() const{
    return (this->letters.size());
}

int LettersSet::getScore (string word){ // SE PUEDE HACER CON TOUPPER, YA SE HARÁ.
    int suma=0;
    for ( string::iterator it=word.begin(); it!=word.end(); ++it){
        char letra_mayu=(*it);

        if ((*it) >= COMIENZO_MINUS && (*it) <= FINAL_MINUS){//comienzo de letras mayu
            letra_mayu = toupper((*it)); //distancia de letra min a letra mayu
        }
        suma += this->getLetters()[letra_mayu].score;

    }
    return suma;
}

LetterInfo& LettersSet::operator [] (const char &val){
    return this->letters[val];
}

ostream& operator << (ostream &os, const LettersSet &cl){
    map<char,LetterInfo>::iterator it;
    LettersSet map_aux(cl);

    for (it=map_aux.getLetters().begin() ; it!=map_aux.getLetters().end(); ++it){
        os << "\nLa letra " << it->first << " está " << it->second.repetitions << " veces repetida, y tiene punt. de " << it->second.score;
    }
    return os;
}

istream& operator >>(istream &is, LettersSet &cl){
    char Letra;    int Cant;    int Punt;
    while (is){
        is >> Letra >> Cant >> Punt;
        LetterInfo aux;
        aux.repetitions=Cant;
        aux.score=Punt;
        pair <char, LetterInfo> futLetters;
        futLetters.first=Letra;
        futLetters.second=aux;
        cl.insert(futLetters);
    }
    return is;
}
