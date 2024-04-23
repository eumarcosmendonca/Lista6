/*
Você encontrou um robô perdido pela rua e percebeu que o dever dele é de fazer somas matemáticas! Entretanto, esse robô funciona apenas com números binários na hora de fazer a soma e também retorna um número binário.
Para o robô funcionar você deve dar N que é o tamanho máximo de dígitos do número binário. Então você dará dois números binários de N dígitos e receberá um número binário também de N dígitos que é o resultado da soma. Note que se o resultado da soma ultrapassar um número binário de N dígitos (Exemplo: 1 0 0 + 1 0 0 = 1 0 0 0), o robô exibe a mensagem "OVERFLOW".
A soma de números binários ocorre da seguinte forma:
Número 1: 0 1 0 1 1
Número 2: 1 0 0 0 1
Resultado: 1 1 1 0 0
A soma ocorre com o número diretamente acima dele da seguinte forma: Se ambos forem 0 o resultado é 0, se tiver 1 e 0 o resultado é 1, se ambos forem 1 o resultado vai ser 0 mas a soma a esquerda vai receber mais 1.
Exemplo: Se N for 5, o número binário pode ser 1 0 1 0 0
Dica: Faça a matemática da direita para a esquerda.
*/

#include <stdio.h>

void print(int array[], int inicio, int final) {
    if (inicio == final) {
        return;
    }
    else {
        printf("%d ", array[inicio]);
        print(array, inicio + 1, final);
    }
}

void verificador(int array1[], int array2[], int arrayFinal[], int inicio, int final, int parametro) {
    if (final != 0) {
        if (array1[final - 1] == 0 && array2[final - 1] == 0) {
            arrayFinal[final  - 1] = 0;
        }
        if (array1[final - 1] == 1 && array2[final - 1] == 0) {
            arrayFinal[final  - 1] = 1;
        }
        if (array1[final - 1] == 0 && array2[final - 1] == 1) {
            arrayFinal[final  - 1] = 1;
        }
        if (array1[final - 1] == 1 && array2[final - 1] == 1) {
            arrayFinal[final - 1] = 0;
            if (array1[final - 2] == 0) {
                array1[final - 2] = 1;
            }
            else {
                array2[final - 2] = 1;
            }
        }
        verificador(array1, array2, arrayFinal, inicio, final - 1, parametro);
    }
    if (final == 0) {
        if (array1[final] == 1 && array2[final] == 1) {
            printf("OVERFLOW");
            return;
        }
        else {
            print(arrayFinal, 0, parametro);
            return;
        }
    }
}

void entradaDeDados(int array[], int inicio, int final) {
    if (inicio == final) {
        return;
    }
    else {
        int numero;
        scanf("%d", &numero);
        array[inicio] = numero;
        entradaDeDados(array, inicio + 1, final);
    }
}

int main() {

    int numero;
    scanf("%d", &numero);
    int array1[numero];
    int array2[numero];
    int arrayFinal[numero];
    entradaDeDados(array1, 0, numero);
    entradaDeDados(array2, 0, numero);
    verificador(array1, array2, arrayFinal, 0, numero, numero);

    return 0;

}