#include <stdio.h>
#include <string.h>

struct Carta {
    char nomePais[50];
    unsigned long int populacao;
    double area;
    double pib;
    int pontosTuristicos;
    double densidadeDemografica;
    double pibPerCapita;
};

void lerDadosCarta(struct Carta *carta) {
    printf("Digite o nome do país: ");
    scanf(" %[^\n]", carta->nomePais);

    printf("Digite a população: ");
    scanf("%lu", &carta->populacao);

    printf("Digite a área (em km²): ");
    scanf("%lf", &carta->area);

    printf("Digite o PIB (em reais): ");
    scanf("%lf", &carta->pib);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta->pontosTuristicos);

    carta->densidadeDemografica = (double)carta->populacao / carta->area;
    carta->pibPerCapita = carta->pib / carta->populacao;
}

void exibirDadosCalculados(struct Carta c) {
    printf("Densidade Populacional de %s: %.2f hab/km²\n", c.nomePais, c.densidadeDemografica);
    printf("PIB per Capita de %s: R$ %.2f\n", c.nomePais, c.pibPerCapita);
}

void exibirMenu() {
    printf("\nEscolha o atributo para comparação:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Digite a opção desejada: ");
}

int main() {
    struct Carta carta1, carta2;

    printf("Cadastro da Carta 1:\n");
    lerDadosCarta(&carta1);

    printf("\nCadastro da Carta 2:\n");
    lerDadosCarta(&carta2);

    printf("\n--- Dados Calculados ---\n");
    exibirDadosCalculados(carta1);
    exibirDadosCalculados(carta2);

    int opcao;
    exibirMenu();
    scanf("%d", &opcao);

    printf("\nComparação entre %s e %s\n", carta1.nomePais, carta2.nomePais);

    switch (opcao) {
        case 1:
            printf("\nPopulação:\n");
            printf("%s: %lu\n", carta1.nomePais, carta1.populacao);
            printf("%s: %lu\n", carta2.nomePais, carta2.populacao);

            if (carta1.populacao > carta2.populacao)
                printf("\nResultado: %s venceu!\n", carta1.nomePais);
            else if (carta1.populacao < carta2.populacao)
                printf("\nResultado: %s venceu!\n", carta2.nomePais);
            else
                printf("\nResultado: Empate!\n");
            break;

        case 2:
            printf("\nÁrea (km²):\n");
            printf("%s: %.2lf\n", carta1.nomePais, carta1.area);
            printf("%s: %.2lf\n", carta2.nomePais, carta2.area);

            if (carta1.area > carta2.area)
                printf("\nResultado: %s venceu!\n", carta1.nomePais);
            else if (carta1.area < carta2.area)
                printf("\nResultado: %s venceu!\n", carta2.nomePais);
            else
                printf("\nResultado: Empate!\n");
            break;

        case 3:
            printf("\nPIB (R$):\n");
            printf("%s: %.2lf\n", carta1.nomePais, carta1.pib);
            printf("%s: %.2lf\n", carta2.nomePais, carta2.pib);

            if (carta1.pib > carta2.pib)
                printf("\nResultado: %s venceu!\n", carta1.nomePais);
            else if (carta1.pib < carta2.pib)
                printf("\nResultado: %s venceu!\n", carta2.nomePais);
            else
                printf("\nResultado: Empate!\n");
            break;

        case 4:
            printf("\nPontos Turísticos:\n");
            printf("%s: %d\n", carta1.nomePais, carta1.pontosTuristicos);
            printf("%s: %d\n", carta2.nomePais, carta2.pontosTuristicos);

            if (carta1.pontosTuristicos > carta2.pontosTuristicos)
                printf("\nResultado: %s venceu!\n", carta1.nomePais);
            else if (carta1.pontosTuristicos < carta2.pontosTuristicos)
                printf("\nResultado: %s venceu!\n", carta2.nomePais);
            else
                printf("\nResultado: Empate!\n");
            break;

        case 5:
            printf("\nDensidade Demográfica (hab/km²):\n");
            printf("%s: %.2lf\n", carta1.nomePais, carta1.densidadeDemografica);
            printf("%s: %.2lf\n", carta2.nomePais, carta2.densidadeDemografica);

            if (carta1.densidadeDemografica < carta2.densidadeDemografica)
                printf("\nResultado: %s venceu!\n", carta1.nomePais);
            else if (carta1.densidadeDemografica > carta2.densidadeDemografica)
                printf("\nResultado: %s venceu!\n", carta2.nomePais);
            else
                printf("\nResultado: Empate!\n");
            break;

        default:
            printf("\nOpção inválida. Por favor, escolha um número de 1 a 5.\n");
            break;
    }

    return 0;
}
