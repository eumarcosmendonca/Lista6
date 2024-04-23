/*
Balanceamento de parênteses é algo fundamental na computação e na matemática. Mas, e se no lugar de parênteses, tivéssmos números? Faça um programa que avalie se uma sequência de números está balanceada ou não.
Sendo '(' representado por 0 e ')' representado por 1, a sequência: 0 0 1 1 está balanceada, assim como: 0 1 0 1 está balanceada.
*/

#include <stdio.h>

int analiseDeDados(int array[], int abrirParenteses, int fecharParenteses, int inicio, int final, int resultado) {
    if (inicio == final) {
        return resultado;
    }
    else {
        if (array[0] == fecharParenteses) {
            resultado = 1;
            return resultado;
        }
        if (array[final - 1] == abrirParenteses) {
            resultado = 1;
            return resultado;
        }
        if (array[inicio] == abrirParenteses) {
            resultado = resultado + 1;
        }
        if (array[inicio] == fecharParenteses) {
            resultado = resultado - 1;
        }
        analiseDeDados(array, abrirParenteses, fecharParenteses, inicio + 1, final, resultado);
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

    int abrirParenteses, fecharParenteses, numero;

    scanf("%d %d %d", &abrirParenteses, &fecharParenteses, &numero);

    int array[numero];
    entradaDeDados(array, 0, numero);

    if (numero % 2 != 0) {
        printf("Desbalanceada!");
    }
    else {
        int resultado = analiseDeDados(array, abrirParenteses, fecharParenteses, 0, numero, 0);
        if (resultado == 0) {
            printf("Balanceada!");
        }
        else {
            printf("Desbalanceada!");
        }
    }

    return 0;

}