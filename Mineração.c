/*
Um dos problemas encontrados para gerenciar os recursos de uma mina é ter controle de onde cada túnel pode levar, sabendo disso a Sociedade Brasileira de Mineiros pediu para você construir um programa que, dado a quantidade de túneis, onde cada túnel leva e o túnel que quer saber onde você vai sair imprima na tela o túnel de saída.
Um túnel é considerado um túnel de saída quando ele leva a -1.
Obs1: sempre existe pelo menos um túnel de saída.
Obs2: um túnel i sempre leva a exatamente um túnel de saída (ou seja, não existe interseções entre os túneis)
*/

#include <stdio.h>

void localizacao(int array[], int inicioProcura, int parametro) {
    if (array[inicioProcura] == -1) {
        printf("%d", inicioProcura);
        return;
    }
    else {
        if (inicioProcura == parametro) {
            inicioProcura = 0;
            return localizacao(array, inicioProcura, parametro);
        }
        localizacao(array, inicioProcura + 1, parametro);
    }
}

void entradaDeDados(int array[], int inicio, int final) {
    int numero;
    if (inicio < final) {
        scanf("%d", &numero);
        array[inicio] = numero;
        entradaDeDados(array, inicio + 1, final);
    }
    return;
}

int main() {

    int tamanhoArray, inicioProcura;
    scanf("%d", &tamanhoArray);
    int array[tamanhoArray];
    entradaDeDados(array, 0, tamanhoArray);
    scanf("%d", &inicioProcura);
    localizacao(array, inicioProcura, tamanhoArray);

    return 0;

}