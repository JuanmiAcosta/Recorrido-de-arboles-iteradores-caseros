#include "letters_bag.h"
LettersBag::LettersBag(){

}
LettersBag::LettersBag(const LettersSet & letterSet) {
    LettersSet aux=letterSet;
    map<char, LetterInfo> mapAux=aux.getLetters();
    map<char, LetterInfo>::iterator it;
    for(it=mapAux.begin();it!=mapAux.end();++it){
        for(int i=0;i<(*it).second.repetitions;i++){
            insertLetter((*it).first);
        }
    }
}
void LettersBag::insertLetter (const char & l) {
    this->letters.add(l);
}
char LettersBag::extractLetter() {
    return this->letters.get();
}
vector<char> LettersBag::extractLetters(int num) {
    vector<char> aux;
    int auxiliar=num;
    if(num>size()){
        auxiliar=size();
    }
    for(int i=0;i<auxiliar;i++){
        aux.push_back(extractLetter());
    }
    return aux;
}
void LettersBag::clear() {
    this->letters.clear();
}
unsigned  int LettersBag::size() {
    return this->letters.size();
}
LettersBag LettersBag::operator=(const LettersBag &cl) {
    this->letters=cl.letters;
    return (*this);
}

