#include <iostream>
#include <vector>

class Matriz {
private:
    std::vector<std::vector<int>> dados;
    int linhas;
    int colunas;

public:
    Matriz(int lin, int col) : linhas(lin), colunas(col), dados(lin, std::vector<int>(col, 0)) {}

    // Sobrecarga do operador de adição
    Matriz operator+(const Matriz& outra) {
        if (linhas != outra.linhas || colunas != outra.colunas) {
            throw std::runtime_error("As matrizes devem ter as mesmas dimensões para serem somadas.");
        }

        Matriz resultado(linhas, colunas);

        for (int i = 0; i < linhas; ++i) {
            for (int j = 0; j < colunas; ++j) {
                resultado.dados[i][j] = dados[i][j] + outra.dados[i][j];
            }
        }

        return resultado;
    }

    // Sobrecarga do operador de saída (<<)
    friend std::ostream& operator<<(std::ostream& os, const Matriz& matriz) {
        for (int i = 0; i < matriz.linhas; ++i) {
            for (int j = 0; j < matriz.colunas; ++j) {
                os << matriz.dados[i][j] << "\t";
            }
            os << std::endl;
        }
        return os;
    }
};

int main() {
    Matriz matriz1(2, 2);
    matriz1 = Matriz(2, 2);  // Cria uma matriz 2x2 preenchida com zeros

    Matriz matriz2(2, 2);
    matriz2 = Matriz(2, 2);  // Cria outra matriz 2x2 preenchida com zeros

    matriz1 = matriz1 + matriz2;

    std::cout << "Matriz resultante:" << std::endl;
    std::cout << matriz1;

    return 0;
}
