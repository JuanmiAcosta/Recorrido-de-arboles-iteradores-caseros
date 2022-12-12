#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "dictionary.h"

using namespace std;

int main(int argc, char *argv[])
{
/*  srand(time(NULL));

  ifstream dict_file(argv[1]);
  vector <char> available_letters;
  for (int i = 2; i < argc; ++i) {
    available_letters.push_back(std::tolower(argv[i][0]));
  }
  if(!dict_file){
    cerr << "No puedo abrir el fichero " << argv[1] << endl;
    return 0;
  }

  Dictionary dictionary;
  dict_file >> dictionary;

  vector <string> available_words;
  for (auto it = dictionary.possible_words_begin(available_letters); it != dictionary.possible_words_end(); ++it) {
    available_words.push_back(*it);
  }

  for (auto word: available_words){
    cout << word << endl;
  }*/

  return 0;
}
