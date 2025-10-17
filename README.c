#include <stdio.h>
#include <string.h>

// Estrutura que representa uma carta do Super Trunfo
typedef struct {
    char estado[3];
    char codigo[4];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidade;
    float pibPerCapita;
} Carta;

int main() {
    // ==== CARTAS PRÉ-DEFINIDAS ====
    Carta carta1 = {
        .estado = "A",
        .codigo = "A01",
        .nomeCidade = "Sao Paulo",
        .populacao = 12325000,
        .area = 1521.11f,
        .pib = 699280.0f,
        .pontosTuristicos = 50
    };

    Carta carta2 = {
        .estado = "B",
        .codigo = "B02",
        .nomeCidade = "Rio de Janeiro",
        .populacao = 6748000,
        .area = 1200.25f,
        .pib = 300500.0f,
        .pontosTuristicos = 30
    };

    // Calculo de densidade e PIB per capita
    carta1.densidade = carta1.populacao / carta1.area;
    carta2.densidade = carta2.populacao / carta2.area;
    carta1.pibPerCapita = carta1.pib / carta1.populacao;
    carta2.pibPerCapita = carta2.pib / carta2.populacao;

    int atributo1, atributo2;
    float valor1A = 0, valor2A = 0;
    float valor1B = 0, valor2B = 0;
    float soma1 = 0, soma2 = 0;

    // MENU 1
    printf("=== SUPER TRUNFO - Comparação Avançada ===\n");
    printf("\nEscolha o PRIMEIRO atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Populacional\n");
    printf("6 - PIB per Capita\n");
    printf("Digite sua opção: ");
    scanf("%d", &atributo1);

    // MENU 2 (DINAMICO)
    printf("\nEscolha o SEGUNDO atributo (diferente do primeiro):\n");
    for (int i = 1; i <= 6; i++) {
        if (i != atributo1) {
            switch (i) {
                case 1: printf("1 - População\n"); break;
                case 2: printf("2 - Área\n"); break;
                case 3: printf("3 - PIB\n"); break;
                case 4: printf("4 - Pontos Turísticos\n"); break;
                case 5: printf("5 - Densidade Populacional\n"); break;
                case 6: printf("6 - PIB per Capita\n"); break;
            }
        }
    }
    printf("Digite sua opção: ");
    scanf("%d", &atributo2);

    // Validação
    if (atributo1 < 1 || atributo1 > 6 || atributo2 < 1 || atributo2 > 6 || atributo1 == atributo2) {
        printf("\n❌ Opções inválidas ou repetidas. Reinicie o programa.\n");
        return 1;
    }

    // ATRIBUI VALORES 
    float getValor(Carta c, int atributo) {
        switch (atributo) {
            case 1: return c.populacao;
            case 2: return c.area;
            case 3: return c.pib;
            case 4: return c.pontosTuristicos;
            case 5: return c.densidade;
            case 6: return c.pibPerCapita;
            default: return 0;
        }
    }

    // Atribui valores de cada atributo
    valor1A = getValor(carta1, atributo1);
    valor2A = getValor(carta2, atributo1);
    valor1B = getValor(carta1, atributo2);
    valor2B = getValor(carta2, atributo2);

    // APRESENTA OS DADOS DAS CARTAS 
    printf("\n CARTAS DO JOGO\n");
    printf("Carta 1: %s (%s-%s)\n", carta1.nomeCidade, carta1.estado, carta1.codigo);
    printf("Carta 2: %s (%s-%s)\n", carta2.nomeCidade, carta2.estado, carta2.codigo);

    // NOMES DOS ATRIBUTOS PARA EXIBICAO 
    char nomeA[30], nomeB[30];
    char *nomes[] = {"", "População", "Área", "PIB", "Pontos Turísticos", "Densidade Populacional", "PIB per Capita"};
    strcpy(nomeA, nomes[atributo1]);
    strcpy(nomeB, nomes[atributo2]);

    printf("\n COMPARACAO DE ATRIBUTOS \n");
    printf("%s:\n  %s = %.2f | %s = %.2f\n", nomeA, carta1.nomeCidade, valor1A, carta2.nomeCidade, valor2A);
    printf("%s:\n  %s = %.2f | %s = %.2f\n", nomeB, carta1.nomeCidade, valor1B, carta2.nomeCidade, valor2B);

    // COMPARAÇÃO COM OPERADOR TERNARIO
    float pontos1A = (atributo1 == 5) ? (valor1A < valor2A) : (valor1A > valor2A);
    float pontos2A = (atributo1 == 5) ? (valor2A < valor1A) : (valor2A > valor1A);
    float pontos1B = (atributo2 == 5) ? (valor1B < valor2B) : (valor1B > valor2B);
    float pontos2B = (atributo2 == 5) ? (valor2B < valor1B) : (valor2B > valor1B);

    // SOMA DOS ATRIBUTOS
    soma1 = valor1A + valor1B;
    soma2 = valor2A + valor2B;

    printf("\n RESULTADO FINAL \n");
    printf("%s - Soma total: %.2f\n", carta1.nomeCidade, soma1);
    printf("%s - Soma total: %.2f\n", carta2.nomeCidade, soma2);

    // VENCEDOR 
    if (soma1 > soma2)
        printf("\n Resultado: %s Venceu!\n", carta1.nomeCidade);
    else if (soma2 > soma1)
        printf("\n Resultado: %s Venceu!\n", carta2.nomeCidade);
    else
        printf("\n Resultado: Empate!\n");

    return 0;
}
