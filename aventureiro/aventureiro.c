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
    struct Carta carta1 = {"SP", "001", "São Paulo", 12300000, 1521.0, 230000.0, 10};
    struct Carta carta2 = {"RJ", "002", "Rio de Janeiro", 6000000, 1200.0, 160000.0, 8};

    // Calculando Densidade e PIB per capita
    carta1.densidade = carta1.populacao / carta1.area;
    carta2.densidade = carta2.populacao / carta2.area;
    carta1.pib_per_capita = carta1.pib / carta1.populacao;
    carta2.pib_per_capita = carta2.pib / carta2.populacao;

    int opcao;
    printf("Escolha o atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Populacional\n");
    printf("6 - PIB per capita\n");
    printf("Opção: ");
    scanf("%d", &opcao);

    switch(opcao) {
        case 1:
            printf("\nComparação de População:\n");
            printf("%s: %d habitantes\n", carta1.cidade, carta1.populacao);
            printf("%s: %d habitantes\n", carta2.cidade, carta2.populacao);
            if (carta1.populacao > carta2.populacao)
                printf("Vencedor: %s\n", carta1.cidade);
            else if (carta1.populacao < carta2.populacao)
                printf("Vencedor: %s\n", carta2.cidade);
            else
                printf("Empate!\n");
            break;
        case 2:
            printf("\nComparação de Área:\n");
            printf("%s: %.2f km²\n", carta1.cidade, carta1.area);
            printf("%s: %.2f km²\n", carta2.cidade, carta2.area);
            if (carta1.area > carta2.area)
                printf("Vencedor: %s\n", carta1.cidade);
            else if (carta1.area < carta2.area)
                printf("Vencedor: %s\n", carta2.cidade);
            else
                printf("Empate!\n");
            break;
        case 3:
            printf("\nComparação de PIB:\n");
            printf("%s: R$ %.2f milhões\n", carta1.cidade, carta1.pib);
            printf("%s: R$ %.2f milhões\n", carta2.cidade, carta2.pib);
            if (carta1.pib > carta2.pib)
                printf("Vencedor: %s\n", carta1.cidade);
            else if (carta1.pib < carta2.pib)
                printf("Vencedor: %s\n", carta2.cidade);
            else
                printf("Empate!\n");
            break;
        case 4:
            printf("\nComparação de Pontos Turísticos:\n");
            printf("%s: %d pontos\n", carta1.cidade, carta1.pontos_turisticos);
            printf("%s: %d pontos\n", carta2.cidade, carta2.pontos_turisticos);
            if (carta1.pontos_turisticos > carta2.pontos_turisticos)
                printf("Vencedor: %s\n", carta1.cidade);
            else if (carta1.pontos_turisticos < carta2.pontos_turisticos)
                printf("Vencedor: %s\n", carta2.cidade);
            else
                printf("Empate!\n");
            break;
        case 5:
            printf("\nComparação de Densidade Populacional:\n");
            printf("%s: %.2f hab/km²\n", carta1.cidade, carta1.densidade);
            printf("%s: %.2f hab/km²\n", carta2.cidade, carta2.densidade);
            if (carta1.densidade < carta2.densidade)
                printf("Vencedor: %s\n", carta1.cidade);
            else if (carta1.densidade > carta2.densidade)
                printf("Vencedor: %s\n", carta2.cidade);
            else
                printf("Empate!\n");
            break;
        case 6:
            printf("\nComparação de PIB per capita:\n");
            printf("%s: R$ %.2f\n", carta1.cidade, carta1.pib_per_capita);
            printf("%s: R$ %.2f\n", carta2.cidade, carta2.pib_per_capita);
            if (carta1.pib_per_capita > carta2.pib_per_capita)
                printf("Vencedor: %s\n", carta1.cidade);
            else if (carta1.pib_per_capita < carta2.pib_per_capita)
                printf("Vencedor: %s\n", carta2.cidade);
            else
                printf("Empate!\n");
            break;
        default:
            printf("Opção inválida.\n");
    }

    return 0;
}
