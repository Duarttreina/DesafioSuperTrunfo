
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
    float atributo
};

// Função para exibir atributos disponíveis
void exibir_menu(int excluir) {
    printf("Escolha um atributo para comparar:\n");
    if (excluir != 1) printf("1 - População\n");
    if (excluir != 2) printf("2 - Área\n");
    if (excluir != 3) printf("3 - PIB\n");
    if (excluir != 4) printf("4 - Pontos Turísticos\n");
    if (excluir != 5) printf("5 - Densidade Populacional\n");
    if (excluir != 6) printf("6 - PIB per capita\n");
    printf("Opção: ");
}

int main() {
    struct Carta carta1 = {"SP", "001", "São Paulo", 12300000, 1521.0, 230000.0, 10};
    struct Carta carta2 = {"RJ", "002", "Rio de Janeiro", 6000000, 1200.0, 160000.0, 8};

    // Calculando Densidade e PIB per capita
    carta1.densidade = carta1.populacao / carta1.area;
    carta2.densidade = carta2.populacao / carta2.area;
    carta1.pib_per_capita = carta1.pib / carta1.populacao;
    carta2.pib_per_capita = carta2.pib / carta2.populacao;

    int atributo1 = 0, atributo2 = 0;
    float valor1_c1 = 0, valor1_c2 = 0, valor2_c1 = 0, valor2_c2 = 0;

    // Escolha do 1º atributo
    exibir_menu(0);
    scanf("%d", &atributo1);

    // Escolha do 2º atributo, excluindo o primeiro
    exibir_menu(atributo1);
    scanf("%d", &atributo2);

    // Função auxiliar para pegar o valor do atributo
    float pegar_valor(struct Carta c, int atributo) {
        switch(atributo) {
            case 1: return c.populacao;
            case 2: return c.area;
            case 3: return c.pib;
            case 4: return c.pontos_turisticos;
            case 5: return c.densidade;
            case 6: return c.pib_per_capita;
            default: return 0;
        }
    }

    // Pegando valores para carta1 e carta2 dos 2 atributos
    valor1_c1 = pegar_valor(carta1, atributo1);
    valor1_c2 = pegar_valor(carta2, atributo1);
    valor2_c1 = pegar_valor(carta1, atributo2);
    valor2_c2 = pegar_valor(carta2, atributo2);

    // Comparação dos dois atributos separadamente
    int pontos_c1 = 0, pontos_c2 = 0;

    // Comparação atributo 1
    if (atributo1 == 5) { // Densidade Populacional
        valor1_c1 < valor1_c2 ? pontos_c1++ : (valor1_c1 > valor1_c2 ? pontos_c2++ : 0);
    } else {
        valor1_c1 > valor1_c2 ? pontos_c1++ : (valor1_c1 < valor1_c2 ? pontos_c2++ : 0);
    }

    // Comparação atributo 2
    if (atributo2 == 5) {
        valor2_c1 < valor2_c2 ? pontos_c1++ : (valor2_c1 > valor2_c2 ? pontos_c2++ : 0);
    } else {
        valor2_c1 > valor2_c2 ? pontos_c1++ : (valor2_c1 < valor2_c2 ? pontos_c2++ : 0);
    }

    // Exibição dos resultados
    printf("\nResultado da rodada:\n");
    printf("Carta 1: %s (%s)\n", carta1.cidade, carta1.estado);
    printf("Carta 2: %s (%s)\n\n", carta2.cidade, carta2.estado);

    printf("Atributo 1: %d -> %s vs %s = %.2f x %.2f\n", atributo1,
           carta1.cidade, carta2.cidade, valor1_c1, valor1_c2);

    printf("Atributo 2: %d -> %s vs %s = %.2f x %.2f\n", atributo2,
           carta1.cidade, carta2.cidade, valor2_c1, valor2_c2);

    // Soma dos pontos
    printf("\nTotal de pontos:\n");
    printf("%s: %d pontos\n", carta1.cidade, pontos_c1);
    printf("%s: %d pontos\n", carta2.cidade, pontos_c2);

    // Resultado final com ternário
    pontos_c1 > pontos_c2 ? printf("Vencedor: %s\n", carta1.cidade) :
    (pontos_c2 > pontos_c1 ? printf("Vencedor: %s\n", carta2.cidade) : printf("Empate!\n"));

    return 0;
}
