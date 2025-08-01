#include <stdio.h>
#include <string.h>

struct Carta {
    char estado[3];
    char codigo[10];
    char cidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
};

int main() {
    struct Carta carta1 = {"SP", "001", "São Paulo", 12300000, 1521.0, 750000000.0, 12};
    struct Carta carta2 = {"RJ", "002", "Rio de Janeiro", 6000000, 1182.3, 360000000.0, 8};

    carta1.densidadePopulacional = carta1.populacao / carta1.area;
    carta1.pibPerCapita = carta1.pib / carta1.populacao;

    carta2.densidadePopulacional = carta2.populacao / carta2.area;
    carta2.pibPerCapita = carta2.pib / carta2.populacao;

    char atributoEscolhido[] = "po
