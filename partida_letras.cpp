//
// Created by Asus on 07/11/2022.
//
#include<iostream>
#include<fstream>
#include "letters_set.h"
#include "letters_bag.h"
#include "dictionary.h"
#include "solver.h"

using namespace std;
/*
bool existe (map<char, LetterInfo> letras,char letra){
    bool existe=true;
    map<char,LetterInfo>::iterator it;
    it=letras.find(letra);
    if (it == letras.end())
        existe=false;
    return existe;
}*/

int main(int argc, char *argv[]){

    if (argc != 5){
        cerr << "\nError en el nº de argumentos";
        cerr << "\nUso: " << argv[0] << " filename, palabra";
        exit(1);
    }

    Dictionary diccionario;
    std::ifstream file(argv[1]);
    file>>diccionario;

    std::ifstream file2(argv[2]);
    LettersSet lettersSet;
    string aux;
    getline(file2,aux);

    file2>>lettersSet;

    char modo=argv[3][0];
    bool modoJuego=false;
    if(modo=='P')modoJuego=true;

    int numLetras=atoi(argv[4]);

    solver solver(diccionario,lettersSet);
    LettersBag bolsa_letras(lettersSet);
    vector<char>letras=bolsa_letras.extractLetters(numLetras);
    //vector<char>letras={'D', 'S' ,'N' ,'T' ,'D' ,'A' ,'I' ,'E', 'N'};


    cout<<"LETRAS DISPONIBLES:"<<endl;
    for(int i=0; i<letras.size();i++){
        letras[i]= ::toupper(letras[i]);
        if(i!=letras.size()-1)cout<<((letras[i]))<<" ";
        else cout<<((letras[i]));
    }
    cout<<"\nSOLUCIONES:"<<endl;
    pair<vector<string>,int> soluciones=solver.getSolutions(letras,modoJuego);
    for(int i=0; i<soluciones.first.size();i++){
        cout<<soluciones.first[i]<<endl;
    }
    cout<<"PUNTUACION:"<<endl;
    cout<<soluciones.second;


    return(0);
}