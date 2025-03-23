#include <stdio.h>

// Estrutura da Carta
struct Carta {
    char estado[30];
    char codigo[10];
    char cidade[30];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade;
    float pib_per_capita;
};

int main() {
    // Cartas pré-definidas
    struct Carta carta1 = {"SP", "001", "São Paulo", 12300000, 1521.0, 230000.0, 10};
    struct Carta carta2 = {"RJ", "002", "Rio de Janeiro", 6000000, 1200.0, 160000.0, 8};

    // Calculando Densidade e PIB per capita
    carta1.densidade = carta1.populacao / carta1.area;
    carta2.densidade = carta2.populacao / carta2.area;
    carta1.pib_per_capita = carta1.pib / carta1.populacao;
    carta2.pib_per_capita = carta2.pib / carta2.populacao;

    // Comparação fixa por POPULAÇÃO (pode trocar para outro atributo manualmente)
    printf("Comparação de cartas (Atributo: População):\n");
    printf("Carta 1 - %s (%s): %d\n", carta1.cidade, carta1.estado, carta1.populacao);
    printf("Carta 2 - %s (%s): %d\n", carta2.cidade, carta2.estado, carta2.populacao);

    if (carta1.populacao > carta2.populacao) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.cidade);
    } else if (carta1.populacao < carta2.populacao) {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.cidade);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}
