#include <fstream>
#include <iostream>

#include "dictionary.h"

using namespace std;

int main(int argc, char *argv[])
{
  if(argc != 2){
    cout << "Los parametros son: " << endl;
    cout << "1.- El fichero con el diccionario" << endl;
    return 1;
  }

  ifstream f_diccionario(argv[1]);

  if(!f_diccionario){
    cout << "No puedo abrir el fichero " << argv[1] << endl;
    return 0;
  }

  Dictionary diccionario;
  f_diccionario >> diccionario;

  for (Dictionary::iterator it = diccionario.begin(); it != diccionario.end(); ++it){
    cout << *it << endl;
  }

  return 0;
}
