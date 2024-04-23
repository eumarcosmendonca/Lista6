/*
Após observar padrões interessantes com seu telescópio, Corneana ficou obcecada com alguns grupos de bits observados pelo espaço. Ela notou que, algumas vezes, os bits alternavam seus valores entre 1 e 0 (ou entre 0 e 1).
Foi definido que o "tamanho de uma sequência" é o tamanho da maior sequência que tem seus bits alternando entre 1 e 0 (ou 0 e 1).
Por exemplo, dado o grupo de bits 1 0 0 1 0 1 0 0, o tamanho da sequência é 5 (1 0 0 1 0 1 0 0).
Aqui estão alguns exemplos:
0 1 1 0 1 -> tamanho da sequência é 3 (0 1 1 0 1)
0 0 0 0 0 -> tamanho da sequência é 1 (0 0 0 0 0)
1 1 1 1 1 1 1 -> tamanho da sequência é 1 (1 1 1 1 1 1 1)
0 1 0 0 1 0 1 0 0 1 -> tamanho da sequência é 5 (0 1 0 0 1 0 1 0 0 1)
Serão dados N grupos de bits. Printe o tamanho da maior sequência.
*/

#include <stdio.h>

int verificador(int array[], int inicio, int final, int quantidadeSequencia, int maiorSequencia) {
    
    if (inicio <= final) {
        if (array[inicio] != array[inicio - 1]) {
            quantidadeSequencia++;
            return verificador(array, inicio + 1, final, quantidadeSequencia, maiorSequencia);
        }
        if (array[inicio] == array[inicio - 1]) {
            if (quantidadeSequencia + 1 >= maiorSequencia) {
                maiorSequencia = quantidadeSequencia + 1;
            }
            quantidadeSequencia = 0;
            return verificador(array, inicio + 1, final, quantidadeSequencia, maiorSequencia);
        }
    }
    if (quantidadeSequencia >= maiorSequencia) {
       maiorSequencia = quantidadeSequencia; 
       return maiorSequencia;
    }
    return maiorSequencia;
}

void entradaLista(int arrayDigitos[], int inicio, int final) {

    int numero;
    if (inicio < final) {
        scanf("%d", &numero);
        arrayDigitos[inicio] = numero;
        entradaLista(arrayDigitos, inicio + 1, final);
    }
    return;

}

int entradaDados(int arrayGrupos[], int inicio, int final, int resultadoSequencia) {

    int quantidadeDigitos, sequencia = 1;
    if (inicio < final) {
        scanf("%d", &quantidadeDigitos);
        
        int arrayDigitos[quantidadeDigitos];
        if (quantidadeDigitos == 1) {
            int teste;
            scanf("%d", &teste);
        }
        else {
            entradaLista(arrayDigitos, 0, quantidadeDigitos);
            sequencia = verificador(arrayDigitos, 1, quantidadeDigitos, 0, 0);
        }
        if (sequencia >= resultadoSequencia) {
            resultadoSequencia = sequencia;
        }
        return entradaDados(arrayGrupos, inicio + 1, final, resultadoSequencia);
    }
    return resultadoSequencia;

}

int main() {

    int quantidadeGrupos;
    scanf("%d", &quantidadeGrupos);
    if(quantidadeGrupos == 0) printf("0");
    else 
    {
        int arrayGrupos[quantidadeGrupos];
        int resultadoFinal = entradaDados(arrayGrupos, 0, quantidadeGrupos, 1);
        printf("%d\n", resultadoFinal);
    }

    return 0;

}