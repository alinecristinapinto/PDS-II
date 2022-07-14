#include <iostream>
#include <map>  // Isto é uma dica. 

using namespace std;

int main() {
  string palavra;
  map<string, int> freqPalavras;
  
  while (getline(cin, palavra, ' ')) {  
    freqPalavras[palavra] ++;
  }  
  
  string comum = freqPalavras.begin()->first;
  map<string, int>::iterator itr;

  for (itr = freqPalavras.begin(); itr != freqPalavras.end(); ++itr) {
    if(itr->second > freqPalavras.find(comum)->second){
        comum = itr->first;
    }
  }
  
  cout << comum << endl;  
  
  return 0;
}