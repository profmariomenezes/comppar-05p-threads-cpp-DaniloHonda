#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm> // Para std::min

int main() {
    const int M = 1000; // Linhas de A
    const int N = 500;  // Colunas de A, Linhas de B
    const int X = 200;  // Colunas de B
    const int BLOCK_SIZE = 16; // Tamanho do bloco

    // Inicializa as matrizes A (M x N) e B (N x X) com valores 1
    std::vector<std::vector<int>> A(M, std::vector<int>(N, 1));
    std::vector<std::vector<int>> B(N, std::vector<int>(X, 1));
    std::vector<std::vector<int>> C(M, std::vector<int>(X, 0)); // Resultado

    // Medição de tempo
    auto inicio = std::chrono::high_resolution_clock::now();
    
    // Multiplicação com blocagem
    for (int i = 0; i < M; i += BLOCK_SIZE) {
        for (int j = 0; j < X; j += BLOCK_SIZE) {
            for (int k = 0; k < N; k += BLOCK_SIZE) {
                // Limites dos blocos
                int i_max = std::min(i + BLOCK_SIZE, M);
                int j_max = std::min(j + BLOCK_SIZE, X);
                int k_max = std::min(k + BLOCK_SIZE, N);
                
                for (int ii = i; ii < i_max; ++ii) {
                    for (int jj = j; jj < j_max; ++jj) {
                        for (int kk = k; kk < k_max; ++kk) {
                            C[ii][jj] += A[ii][kk] * B[kk][jj];
                        }
                    }
                }
            }
        }
    }

    auto fim = std::chrono::high_resolution_clock::now();
    auto duracao = std::chrono::duration_cast<std::chrono::microseconds>(fim - inicio);
    std::cout << "Block order; tempo: " << duracao.count() << " microsegundos" << std::endl;

    return 0;
}