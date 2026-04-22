#include <stdio.h>  // Biblioteca padrão para entrada e saída (printf, scanf, fgets)
#include <string.h> // Biblioteca para manipulação de strings (strcspn)

int main() {
    // Declaração de variáveis
    char nomeLivro[100]; // Vetor de caracteres para armazenar até 99 letras + o nulo (\0)
    char autor[100];     // Vetor para o nome do autor
    int paginas;         // Variável inteira para a quantidade de páginas

    printf("=== SISTEMA DE AQUISICOES - LIVRARIA ===\n\n");

    // --- 1. Entrada do Título ---
    printf("Titulo do Livro: ");
    /* fgets(onde_salvar, tamanho_maximo, de_onde_ler):
       Lê uma linha inteira do teclado (stdin), incluindo espaços.
    */
    fgets(nomeLivro, sizeof(nomeLivro), stdin);
    
    /* Tratamento da String:
       O fgets armazena o 'Enter' (\n) no final da string.
       strcspn localiza a posição do \n e o substitui por 0 (fim da string).
    */
    nomeLivro[strcspn(nomeLivro, "\n")] = 0; 

    // --- 2. Entrada do Autor ---
    printf("Autor da Obra:   ");
    fgets(autor, sizeof(autor), stdin);
    autor[strcspn(autor, "\n")] = 0; 

    // --- 3. Entrada de Páginas ---
    
    

    printf("N. de Paginas:   ");
    /* Validação de Entrada:
       scanf retorna o número de itens lidos com sucesso. 
       Se o usuário digitar uma letra em vez de número, o resultado será != 1, 
       ativando o erro e encerrando o programa (return 1).
    */
    if (scanf("%d", &paginas) != 1) {
        printf("\n[ERRO] Entrada invalida para paginas.\n");
        return 1; 
    }

    // --- SAÍDA FORMATADA (Relatório) ---
    /*
       %-15s : Reserva 15 espaços, alinha o texto à ESQUERDA (-).
       %04d  : Exibe um inteiro com 4 dígitos, preenchendo com zeros (ex: 0042).
    */
    printf("\n========================================\n");
    printf("%-15s | %s\n", "CATEGORIA", "INFORMACAO");
    printf("----------------------------------------\n");
    printf("%-15s | %-20s\n", "TITULO", nomeLivro);
    printf("%-15s | %-20s\n", "AUTOR", autor);
    printf("%-15s | %04d paginas\n", "VOLUME", paginas);
    printf("========================================\n");

    return 0; // Indica que o programa terminou com sucesso
}
