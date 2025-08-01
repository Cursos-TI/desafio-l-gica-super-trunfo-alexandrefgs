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

double obterValorAtributo(struct Carta c, int atributo) {
    switch (atributo) {
        case 1: return (double)c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return (double)c.pontosTuristicos;
        case 5: return c.densidadeDemografica;
        default: return -1.0; // inválido
    }
}

const char* nomeAtributo(int atributo) {
    switch (atributo) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Demográfica";
        default: return "Inválido";
    }
}

void exibirMenu(int ocultar) {
    printf("\nEscolha um atributo para comparação:\n");
    if (ocultar != 1) printf("1 - População\n");
    if (ocultar != 2) printf("2 - Área\n");
    if (ocultar != 3) printf("3 - PIB\n");
    if (ocultar != 4) printf("4 - Pontos Turísticos\n");
    if (ocultar != 5) printf("5 - Densidade Demográfica\n");
    printf("Digite a opção desejada: ");
}

int compararAtributo(struct Carta c1, struct Carta c2, int atributo) {
    double val1 = obterValorAtributo(c1, atributo);
    double val2 = obterValorAtributo(c2, atributo);

    if (atributo == 5) { // Densidade: menor vence
        if (val1 < val2) return 1;
        else if (val1 > val2) return 2;
        else return 0;
    } else { // Outros: maior vence
        if (val1 > val2) return 1;
        else if (val1 < val2) return 2;
        else return 0;
    }
}

double valorParaSoma(struct Carta c, int atributo) {
    double val = obterValorAtributo(c, atributo);
    if (atributo == 5) { 
        return 1.0 / val;
    } else {
        return val;
    }
}

int main() {
    struct Carta carta1 = {"Brasil", 211000000, 8515767.0, 2200000000000.0, 25};
    struct Carta carta2 = {"Canadá", 38000000, 9984670.0, 1800000000000.0, 18};

    carta1.densidadeDemografica = (double)carta1.populacao / carta1.area;
    carta1.pibPerCapita = carta1.pib / carta1.populacao;

    carta2.densidadeDemografica = (double)carta2.populacao / carta2.area;
    carta2.pibPerCapita = carta2.pib / carta2.populacao;

    int atributo1 = 0, atributo2 = 0;

    do {
        exibirMenu(0);
        scanf("%d", &atributo1);
        if (atributo1 < 1 || atributo1 > 5) {
            printf("Opção inválida. Tente novamente.\n");
        }
    } while (atributo1 < 1 || atributo1 > 5);

    do {
        exibirMenu(atributo1);
        scanf("%d", &atributo2);
        if (atributo2 < 1 || atributo2 > 5 || atributo2 == atributo1) {
            printf("Opção inválida ou já escolhida anteriormente. Tente novamente.\n");
        }
    } while (atributo2 < 1 || atributo2 > 5 || atributo2 == atributo1);

    printf("\nComparação entre %s e %s\n", carta1.nomePais, carta2.nomePais);

    printf("\nAtributo 1: %s\n", nomeAtributo(atributo1));
    printf("%s: %.2lf\n", carta1.nomePais, obterValorAtributo(carta1, atributo1));
    printf("%s: %.2lf\n", carta2.nomePais, obterValorAtributo(carta2, atributo1));

    printf("\nAtributo 2: %s\n", nomeAtributo(atributo2));
    printf("%s: %.2lf\n", carta1.nomePais, obterValorAtributo(carta1, atributo2));
    printf("%s: %.2lf\n", carta2.nomePais, obterValorAtributo(carta2, atributo2));

    int vencedorA1 = compararAtributo(carta1, carta2, atributo1);
    int vencedorA2 = compararAtributo(carta1, carta2, atributo2);

    double somaCarta1 = valorParaSoma(carta1, atributo1) + valorParaSoma(carta1, atributo2);
    double somaCarta2 = valorParaSoma(carta2, atributo1) + valorParaSoma(carta2, atributo2);

    printf("\nSoma dos valores para %s: %.4lf\n", carta1.nomePais, somaCarta1);
    printf("Soma dos valores para %s: %.4lf\n", carta2.nomePais, somaCarta2);

    printf("\nResultado final: ");
    (somaCarta1 > somaCarta2) ? printf("%s venceu!\n", carta1.nomePais) :
    (somaCarta1 < somaCarta2) ? printf("%s venceu!\n", carta2.nomePais) :
    printf("Empate!\n");

    return 0;
}
