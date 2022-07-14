#include <iostream>
#include <string>

using namespace std;

void contadorVogais(string palavra){
    int countVogais [5] = {0};
    char vogais [5] = {'a', 'e', 'i', 'o', 'u'};
    
    for(int i=0; i < palavra.length(); i++){
        if(palavra[i] == vogais[0]) countVogais[0] += 1;
        else if(palavra[i] == vogais[1]) countVogais[1] += 1;
        else if(palavra[i] == vogais[2]) countVogais[2] += 1;
        else if(palavra[i] == vogais[3]) countVogais[3] += 1;
        else if(palavra[i] == vogais[4]) countVogais[4] += 1;
    }
    
    for(int i=0; i < 5; i++){
        if(countVogais[i] != 0) {
            cout << vogais[i] << " " << countVogais[i] << endl;
        }
    }
}

int main() {
    string palavra;
    
    cin >> palavra;
    
    contadorVogais(palavra);
    
    return 0;
}