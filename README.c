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
  int pontosTuristicos;      // Nº pontos turísticos
} Carta;

int main() {
  Carta cartas[2]; //Vetor para armazenar 2 cartas

for (int i = 0; i < 2; i++) {
printf ("\n Cadastro da Carta %d \n", i + 1);

printf ("Digite o estado (A-H): ");
sacnf("%c", &cartas[i].estado);

printf ("Digite o código da carta (ex: A01): ");
scanf("%3s", cartas[i].codigo);

printf ("Digite o nome da Cidade: ");
scanf(" %[^\n]", cartas[i].nomeCidade);

printf ("Digite a população da cidade: ");
scanf("%d", &cartas[i].populacao);

printf("Digite a area em km²: ");
scanf("%f", &cartas[i].area);

printf("Digite o PIB: ");
scanf("%f", &cartas[i].pib);

printf("Digite o numero de pontos turisticos: ");
scanf("%d", &cartas[i].pontosTuristicos);

}

// Para exibir as cartas cadastradas
printf("\n CARTAS CADASTRADAS \n");
for (int i = 0; i < 2; i++) {
  printf("\n CARTA %d\n", i + 1);
  printf("Estado: %c\n", cartas[i].estado);
  printf("Codigo: %s\n", cartas[i].codigo);
  printf("Cidade: %s\n", cartas[i].nomeCidade);
  printf("Populacao: %d\n", cartas[i].populacao);
  printf("Area: %.2f km²\n", cartas[i].area);
  printf("PIB: %.2f\n", cartas[i].pib);
  printf("Pontos Turisticos: %d\n", cartas[i].pontosTuristicos);
    }

    return 0;
}
