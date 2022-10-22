//Autor: Ivan Grana

#include <iostream>
#include <string>
using namespace std;

class cifra //Declaração da classe 
{
public: string encriptar(string texto, int s) //metodo da classe que encripta o texto. o parametro 's' é a chave da cifra ex:1,2,3...
{
    string resultado = ""; //declaração da string resultado
 
    for (int i = 0; i < texto.length(); i++) {
        //Cada transformação é realizada pra cada caractere
        // Encriptação das palavras maiusculas
        if (isupper(texto[i]))
            resultado += char(int(texto[i] + s - 65) % 26 + 65);
 
        // se estiverem da forma minuscula,encripta esses caracteres
        else
            resultado += char(int(texto[i] + s - 97) % 26 + 97);
    }
 
    //retorna o texto já encriptado
    return resultado;
}
};

int main(){
    cifra cesar;
    string text = "mensagemsecreta";
    cout << cesar.encriptar(text,4) << endl;
}

