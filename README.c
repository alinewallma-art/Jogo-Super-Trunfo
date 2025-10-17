//Jogo-Super-Trunfo
//Desenvolvimento de Jogo Super Trunfo - Trabalho Estácio Prog C:

#include <studio.h>

//Estrutura para armazenar os dados da carta
typedef struct {
  char estado;                //Letra de A a H
  char codigo[4];            // 2 número juntos da letra
  char nomeCidade[50];       // Nome da Cidade
  int populacao;             // Nº habitantes
  float area;                // Área em km²
  float pib;                 // PIB
  float densidade;           // População / Área (calculada) 
  float pibPerCapita;      /* PIB / População (calculada) */ 
  int pontosTuristicos;      // Nº pontos turísticos
} Carta;

// Calculo de densidade e PIB per capita para uma carta
void calcularIndicadores(Carta *c) {
    if (c->area > 0.0f)
        c->densidade = (float)c->populacao / c->area;
    else
        c->densidade = 0.0f; // Para nao dividir por zero 

    if (c->populacao > 0)
        c->pibPerCapita = c->pib / (float)c->populacao;
    else
        c->pibPerCapita = 0.0f; // Para nao dividir por zero
}

// Para imprimir os dados de uma carta
void imprimirCartaResumo(const Carta *c, int indice) {
    printf("\nCarta %d - %s (%s)  [Codigo: %s]\n", indice, c->nomeCidade, c->estado, c->codigo);
    printf("  Populacao: %d\n", c->populacao);
    printf("  Area: %.2f km^2\n", c->area);
    printf("  PIB: %.2f\n", c->pib);
    printf("  Pontos Turisticos: %d\n", c->pontosTuristicos);
    printf("  Densidade Populacional: %.2f hab/km^2\n", c->densidade);
    printf("  PIB per capita: %.2f\n", c->pibPerCapita);
}

int main(void) {
