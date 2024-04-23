/*
Yuto adora jogar RPG com seus amigos, mas tem muito dificuldade na criação de ficha de personagem. No Dungeon and Dragons, que é o seu sistema favorito, há 6 atributos: Força, Destreza, Constituição, Sabedoria, Inteligência e Carisma, e seus valores são determinados pela seguinte regra: São jogados 4d6 (4 dados de 6 faces) e os três maiores valores são somados.
Yuto está desesperado, hoje a noite terá a primeira sessão e ele ainda não determinou os atributos de seu guerreiro, Kayn. Você, como um bom amigo e programador, decidiu ajudá-lo criando um programa para determinar esses atributos. Dado os dados rolados por ele e a ordem dos atributes, retorne os valores de cada atributo.
*/

#include <stdio.h>

void ordemDePrioridade(int array[], int inicio, int final) {

    int numero;
    if (inicio < final) {
        scanf("%d", &numero);
        array[inicio] = numero;
        return ordemDePrioridade(array, inicio + 1, final);
    }
    else {
        return;
    }
    
}

void bubble(int array[], int i, int tamanho) {

    if (i == tamanho - 1) {
        return;
    }
    else {
        if (array[i] < array[i + 1]) {
            int aux = array[i];
            array[i] = array[i + 1];
            array[i + 1] = aux;
        }
        bubble(array, i + 1, tamanho);
    }
    
}

void bubbleSort(int array[], int tamanho) {

    if (tamanho == 0) {
        return;
    }
    else {
        bubble(array, 0, tamanho);
        bubbleSort(array, tamanho - 1);
    }

}

int soma(int array[], int somaArray, int inicio, int final) {

    if (inicio == final) {
        return somaArray;
    }
    else {
        int numero = array[inicio];
        somaArray = somaArray + numero;
        return soma(array, somaArray, inicio + 1, final);
    }
}

void entradaDeDados(int array[], int inicio, int final) {

    int numero;
    if (inicio < final) {
        scanf("%d", &numero);
        array[inicio] = numero;
        return entradaDeDados(array, inicio + 1, final);
    }
    return;

}

int main() {

    int array1[4], array2[4], array3[4], array4[4], array5[4], array6[4];
    int somaArray1, somaArray2, somaArray3, somaArray4, somaArray5, somaArray6;
    int arrayOrdemDePrioridade[6];

    entradaDeDados(array1, 0, 4);
    bubbleSort(array1, 4);
    entradaDeDados(array2, 0, 4);
    bubbleSort(array2, 4);
    entradaDeDados(array3, 0, 4);
    bubbleSort(array3, 4);
    entradaDeDados(array4, 0, 4);
    bubbleSort(array4, 4);
    entradaDeDados(array5, 0, 4);
    bubbleSort(array5, 4);
    entradaDeDados(array6, 0, 4);
    bubbleSort(array6, 4);

    int resultadoSomaArray1 = soma(array1, 0, 0, 3);
    int resultadoSomaArray2 = soma(array2, 0, 0, 3);
    int resultadoSomaArray3 = soma(array3, 0, 0, 3);
    int resultadoSomaArray4 = soma(array4, 0, 0, 3);
    int resultadoSomaArray5 = soma(array5, 0, 0, 3);
    int resultadoSomaArray6 = soma(array6, 0, 0, 3);

    int arrayFinal[6];
    arrayFinal[0] = resultadoSomaArray1;
    arrayFinal[1] = resultadoSomaArray2;
    arrayFinal[2] = resultadoSomaArray3;
    arrayFinal[3] = resultadoSomaArray4;
    arrayFinal[4] = resultadoSomaArray5;
    arrayFinal[5] = resultadoSomaArray6;
    bubbleSort(arrayFinal, 6);

    ordemDePrioridade(arrayOrdemDePrioridade, 0, 6);
    int ordem1 = arrayOrdemDePrioridade[0];
    int ordem2 = arrayOrdemDePrioridade[1];
    int ordem3 = arrayOrdemDePrioridade[2];
    int ordem4 = arrayOrdemDePrioridade[3];
    int ordem5 = arrayOrdemDePrioridade[4];
    int ordem6 = arrayOrdemDePrioridade[5];

    printf("For = %d\n", arrayFinal[ordem1 - 1]);
    printf("Des = %d\n", arrayFinal[ordem2 - 1]);
    printf("Con = %d\n", arrayFinal[ordem3 - 1]);
    printf("Sab = %d\n", arrayFinal[ordem4 - 1]);
    printf("Int = %d\n", arrayFinal[ordem5 - 1]);
    printf("Car = %d\n", arrayFinal[ordem6 - 1]);
    
    return 0;

}