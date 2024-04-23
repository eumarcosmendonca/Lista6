/*
Faça um programa que lê uma Lista de números inteiros, depois encontra e imprime:
a) a lista dos números lidos na ordem inversa;
b) primeiro os números que estiverem nas posições com índices pares, seguidos pelos que estão nas posições com índices ímpares;
c) a soma dos elementos, de mesma posição, tomando dois a dois, considerando os valores resultantes das listas dos itens a) e b).
*/

#include <stdio.h>

void printSoma(int arraySoma[], int inicio, int final) {
    if (inicio == (final - 1)) {
        printf("%d", arraySoma[inicio]);
        return;
    }
    else {
        printf("%d ", arraySoma[inicio]);
        printSoma(arraySoma, inicio + 1, final);
    }
}

void printParImp(int arrayParImp[], int inicio, int final) {
    if (inicio == (final - 1)) {
        printf("%d", arrayParImp[inicio]);
        return;
    }
    else {
        printf("%d ", arrayParImp[inicio]);
        printParImp(arrayParImp, inicio + 1, final);
    }
}

void printInversa(int arrayInversa[], int inicio, int final) {
    if (inicio == (final - 1)) {
        printf("%d", arrayInversa[inicio]);
        return;
    }
    else {
        printf("%d ", arrayInversa[inicio]);
        printInversa(arrayInversa, inicio + 1, final);
    }
}

void entradaDeDadosArraySoma(int arrayInversa[], int arrayParImp[], int arraySoma[], int inicio, int final) {
    if (inicio < final) {
        arraySoma[inicio] = arrayInversa[inicio] + arrayParImp[inicio];
        return entradaDeDadosArraySoma(arrayInversa, arrayParImp, arraySoma, inicio + 1, final);
    }
    return;
}

void complementarEntradaDeDadosArrayParImp(int array[], int arrayParImp[], int inicio, int final, int contador) {
    if (inicio == final) {
        return;
    }
    else {
        if (inicio % 2 != 0) {
            arrayParImp[contador] = array[inicio];
            contador++;
        }
        return complementarEntradaDeDadosArrayParImp(array, arrayParImp, inicio + 1, final, contador);
    }
}

void entradaDeDadosArrayParImp(int array[], int arrayParImp[], int inicio, int final, int contador) {
    if (inicio == final) {
        complementarEntradaDeDadosArrayParImp(array, arrayParImp, 0, final, contador);
        return;
    }
    else {
        if (inicio % 2 == 0) {
            arrayParImp[contador] = array[inicio];
            contador++;
        }
        return entradaDeDadosArrayParImp(array, arrayParImp, inicio + 1, final, contador);  
    }
}

void entradaDeDadosArrayInversa(int array[], int arrayInversa[], int inicio, int final) {
    if (inicio <= final) {
        arrayInversa[inicio] = array[final - inicio - 1];
        return entradaDeDadosArrayInversa(array, arrayInversa, inicio + 1, final);
    }
    return;
}

int entradaDeDados(int array[], int indice) {
    if (scanf("%d", &array[indice]) == EOF){
        return indice;
    }
    return entradaDeDados(array, indice + 1);
}

int main() {
    
    int array[999];
    int arrayInversa[999];
    int arrayParImp[999];
    int arraySoma[999];
    int indice = entradaDeDados(array, 0);
    entradaDeDadosArrayInversa(array, arrayInversa, 0, indice);
    entradaDeDadosArrayParImp(array, arrayParImp, 0, indice, 0);
    entradaDeDadosArraySoma(arrayInversa, arrayParImp, arraySoma, 0, indice);
    printf("Invert: ");
    printInversa(arrayInversa, 0, indice);
    printf("\n");
    printf("ParImp: ");
    printParImp(arrayParImp, 0, indice);
    printf("\n");
    printf("Soma: ");
    printSoma(arraySoma, 0, indice);

    return 0;

}