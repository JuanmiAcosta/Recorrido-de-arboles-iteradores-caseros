//
// Created by luis on 2/12/22.
//

#include "solver.h"
vector<char> solver::toVector(string palabra){
    vector<char> aux;
    for(int i=0;i<palabra.size();i++){
        aux.push_back(::tolower((palabra.at(i))));
    }
    return aux;
}

LettersSet solver:: getLetterSet(vector<char> auxVector){
    LettersSet aux;
    pair< char, LetterInfo> par;
    for(int i=0;i<auxVector.size();i++){
        par.first=auxVector[i];
        par.second.repetitions=std::count(auxVector.begin(), auxVector.end(),par.first);

        aux.insert(par);
    }
    return aux;
}

solver::solver(const Dictionary & dict, const LettersSet & letters_set){
    this->dict=dict;
    this->letters_set=letters_set;
}
pair<vector<string>,int> solver::getSolutions(const vector<char> & available_letters, bool score_game){
    pair<vector<string>,int> resultado;
    //tengo abanico, 2a,... tiene mi vector todas esas letras? La añado
    string s(available_letters.begin(),available_letters.end());
    int num;

    LettersSet letras= getLetterSet(toVector(s));

    for(Dictionary::iterator it = dict.begin();it != dict.end(); ++it){
        LettersSet aux= getLetterSet(toVector(*it));
        num=0;
        for(LettersSet::iterator it2=aux.begin();it2!=aux.end();++it2){
            for(LettersSet::iterator it3=letras.begin();it3!=letras.end();++it3){

                if((*it3).first==(*it2).first){
                    if((*it3).second.repetitions>=(*it2).second.repetitions){
                        num++;
                    }
                }
            }
        }
    if(num==aux.size()){
        if(!score_game){
            if(!resultado.first.empty()){
                if(resultado.first.at(0).size()<(*it).size()){
                    resultado.first.clear();
                    resultado.first.push_back(*it);
                    resultado.second=(*it).size();
                }else if(resultado.first.at(0).size()==(*it).size()){
                    resultado.first.push_back((*it));
                }
            }else{
                resultado.first.push_back((*it));
                resultado.second=(*it).size();
            }
        }else{
            if(!resultado.first.empty()){
                if(this->letters_set.getScore(resultado.first.at(0))<this->letters_set.getScore(*it)){
                    resultado.first.clear();
                    resultado.first.push_back(*it);
                    int numqe=this->letters_set.getScore(*it);
                    resultado.second=this->letters_set.getScore(*it);
                }else if(this->letters_set.getScore(resultado.first.at(0))==this->letters_set.getScore(*it)){
                    resultado.first.push_back((*it));
                }
            }else{
                resultado.first.push_back((*it));
            }
        }
    }
    }

    return resultado;
}
