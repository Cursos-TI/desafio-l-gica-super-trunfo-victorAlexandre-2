

    #include <stdio.h>
    #include <string.h>
    
    // Definindo a estrutura Carta
    typedef struct {
        char estado[50];
        char codigo[20];
        char cidade[50];
        int populacao;
        float area;
        float pib;
        int pontos_turisticos;
    } Carta;
    
    // Função para calcular a densidade populacional
    float calcular_densidade_populacional(Carta carta) {
        return carta.populacao / carta.area;
    }
    
    // Função para calcular o PIB per capita
    float calcular_pib_per_capita(Carta carta) {
        return carta.pib / carta.populacao;
    }
    
    // Função para comparar duas cartas com base no atributo escolhido
    void comparar_cartas(Carta carta1, Carta carta2) {
        // Atributo para comparação, escolhido diretamente no código (exemplo: "populacao")
        char atributo[] = "populacao"; // Mude esse valor para comparar outros atributos
    
        printf("\nComparação de cartas (Atributo: %s):\n", atributo);
        printf("Carta 1 - %s (%s): %d\n", carta1.cidade, carta1.estado, carta1.populacao);
        printf("Carta 2 - %s (%s): %d\n", carta2.cidade, carta2.estado, carta2.populacao);
    
        if (strcmp(atributo, "populacao") == 0) {
            if (carta1.populacao > carta2.populacao) {
                printf("Resultado: Carta 1 (%s) venceu!\n", carta1.cidade);
            } else {
                printf("Resultado: Carta 2 (%s) venceu!\n", carta2.cidade);
            }
        } else if (strcmp(atributo, "area") == 0) {
            if (carta1.area > carta2.area) {
                printf("Resultado: Carta 1 (%s) venceu!\n", carta1.cidade);
            } else {
                printf("Resultado: Carta 2 (%s) venceu!\n", carta2.cidade);
            }
        } else if (strcmp(atributo, "pib") == 0) {
            if (carta1.pib > carta2.pib) {
                printf("Resultado: Carta 1 (%s) venceu!\n", carta1.cidade);
            } else {
                printf("Resultado: Carta 2 (%s) venceu!\n", carta2.cidade);
            }
        } else if (strcmp(atributo, "densidade_populacional") == 0) {
            float densidade1 = calcular_densidade_populacional(carta1);
            float densidade2 = calcular_densidade_populacional(carta2);
            printf("Densidade populacional Carta 1: %.2f\n", densidade1);
            printf("Densidade populacional Carta 2: %.2f\n", densidade2);
    
            if (densidade1 < densidade2) {
                printf("Resultado: Carta 1 (%s) venceu! (Menor densidade populacional)\n", carta1.cidade);
            } else {
                printf("Resultado: Carta 2 (%s) venceu! (Menor densidade populacional)\n", carta2.cidade);
            }
        } else if (strcmp(atributo, "pib_per_capita") == 0) {
            float pib1 = calcular_pib_per_capita(carta1);
            float pib2 = calcular_pib_per_capita(carta2);
            printf("PIB per capita Carta 1: %.2f\n", pib1);
            printf("PIB per capita Carta 2: %.2f\n", pib2);
    
            if (pib1 > pib2) {
                printf("Resultado: Carta 1 (%s) venceu!\n", carta1.cidade);
            } else {
                printf("Resultado: Carta 2 (%s) venceu!\n", carta2.cidade);
            }
        }
    }
    
    int main() {
        // Definindo duas cartas para comparação
        Carta carta1 = {"SP", "001", "São Paulo", 12300000, 1521.11, 500000, 50};
        Carta carta2 = {"RJ", "002", "Rio de Janeiro", 6000000, 1182.3, 300000, 30};
    
        // Exibindo as informações das cartas
        printf("Carta 1 - %s (%s): %d habitantes, %.2f km², PIB: %.2f milhões, %d pontos turísticos\n", 
               carta1.cidade, carta1.estado, carta1.populacao, carta1.area, carta1.pib, carta1.pontos_turisticos);
        printf("Carta 2 - %s (%s): %d habitantes, %.2f km², PIB: %.2f milhões, %d pontos turísticos\n", 
               carta2.cidade, carta2.estado, carta2.populacao, carta2.area, carta2.pib, carta2.pontos_turisticos);
    
        // Comparando as cartas
        comparar_cartas(carta1, carta2);
    
        return 0;
    }
    