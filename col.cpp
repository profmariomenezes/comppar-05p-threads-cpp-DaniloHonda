#include <iostream>
#include <vector>
#include <chrono>

int main() {
    const int M = 1000; // Linhas de A
    const int N = 500;  // Colunas de A, Linhas de B
    const int X = 200;  // Colunas de B

    // Inicializa as matrizes A (M x N) e B (N x X) com valores 1
    std::vector<std::vector<int>> A(M, std::vector<int>(N, 1));
    std::vector<std::vector<int>> B(N, std::vector<int>(X, 1));
    std::vector<std::vector<int>> C(M, std::vector<int>(X, 0)); // Resultado

    // Medição de tempo
    auto inicio = std::chrono::high_resolution_clock::now();
    
    // Multiplicação por coluna
    for (int j = 0; j < X; ++j) {         // Colunas de B
        for (int i = 0; i < M; ++i) {     // Linhas de A
            for (int k = 0; k < N; ++k) { // Colunas de A, Linhas de B
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    auto fim = std::chrono::high_resolution_clock::now();
    auto duracao = std::chrono::duration_cast<std::chrono::microseconds>(fim - inicio);
    std::cout << "Column order; tempo: " << duracao.count() << " microsegundos" << std::endl;

    return 0;
}