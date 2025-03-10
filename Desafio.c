#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    unsigned long int populacao;
    float area;
    double pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
    float super_poder;
} Carta;

void calcular_atributos(Carta *carta) {
    if (carta->area > 0) {
        carta->densidade_populacional = (float)carta->populacao / carta->area;
    } else {
        carta->densidade_populacional = 0;
    }
    carta->pib_per_capita = carta->pib / carta->populacao;
    float inverso_densidade = (carta->densidade_populacional > 0) ? (1.0f / carta->densidade_populacional) : 0;
    carta->super_poder = (float)carta->populacao + carta->area + (float)carta->pib + 
                          carta->pontos_turisticos + carta->pib_per_capita + inverso_densidade;
}

void ler_carta(Carta *carta, int numero) {
    printf("\nDigite os dados da Carta %d:\n", numero);
    
    printf("Nome: ");
    getchar(); 
    fgets(carta->nome, sizeof(carta->nome), stdin);
    carta->nome[strcspn(carta->nome, "\n")] = '\0'; 
    
    printf("População: ");
    scanf("%lu", &carta->populacao);
    
    printf("Área (km²): ");
    scanf("%f", &carta->area);
    
    printf("PIB (em bilhões): ");
    scanf("%lf", &carta->pib);
    
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta->pontos_turisticos);
    
    calcular_atributos(carta);
}

void comparar_cartas(Carta c1, Carta c2) {
    printf("\nComparação de Cartas:\n");

    // Comparaçao População
    printf("População: Carta %d venceu (%d)\n", c1.populacao > c2.populacao ? 1 : 2, c1.populacao > c2.populacao);

    // Comparação Área
    printf("Área: Carta %d venceu (%d)\n", c1.area > c2.area ? 1 : 2, c1.area > c2.area);

    // Comparação PIB
    printf("PIB: Carta %d venceu (%d)\n", c1.pib > c2.pib ? 1 : 2, c1.pib > c2.pib);

    // Comparação Pontos Turísticos
    printf("Pontos Turísticos: Carta %d venceu (%d)\n", c1.pontos_turisticos > c2.pontos_turisticos ? 1 : 2, c1.pontos_turisticos > c2.pontos_turisticos);

    // Comparação Densidade Populacionala
    printf("Densidade Populacional: Carta %d venceu (%d)\n", c1.densidade_populacional < c2.densidade_populacional ? 1 : 2, c1.densidade_populacional < c2.densidade_populacional);

    // Comparação PIB per Capita
    printf("PIB per Capita: Carta %d venceu (%d)\n", c1.pib_per_capita > c2.pib_per_capita ? 1 : 2, c1.pib_per_capita > c2.pib_per_capita);

    // Comparação Super Poder
    printf("Super Poder: Carta %d venceu (%d)\n", c1.super_poder > c2.super_poder ? 1 : 2, c1.super_poder > c2.super_poder);
}

int main() {
    Carta carta1, carta2;
    
    ler_carta(&carta1, 1);
    ler_carta(&carta2, 2);
    
    comparar_cartas(carta1, carta2);
    
    return 0;
}
