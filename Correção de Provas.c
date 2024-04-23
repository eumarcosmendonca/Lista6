/*
Faça um programa para corrigir provas de múltipla escolha. Cada prova tem 10 questões, cada questão valendo um ponto. O primeiro conjunto de dados a ser lido é o gabarito para a correção da prova. Depois serão dados os números dos alunos e suas respectivas respostas. O programa encerra a entrada quando o número de um aluno dado for igual a 9999
*/

#include <stdio.h>

double maiorIndice(double array[], int inicio, int final, double indice, int contador, int auxiliar, double resultadoIndice) {

    if (inicio == final) {
        return resultadoIndice;
    }
    if (array[inicio] == array[inicio - 1]) {
        contador = contador + 1;
    }
    else {
        contador = 1;
    }
    if (contador > auxiliar) {
        resultadoIndice = array[inicio];
        auxiliar = contador;
    }
    else if (contador == auxiliar && array[inicio] > resultadoIndice) {
        resultadoIndice = array[inicio];
    }
    return maiorIndice(array, inicio + 1, final, indice, contador, auxiliar, resultadoIndice);

}

int comparativo(char respostas[], char gabarito[], int inicio, int final, double contador, int alunoParametro) {
    if (inicio < final) {
        if (respostas[inicio] == gabarito[inicio]) {
            contador = contador + 1;
        }
        return comparativo(respostas, gabarito, inicio + 1, final, contador, alunoParametro);
    }
    else {
        printf("%d %.1lf\n", alunoParametro, contador);
        return contador;
    }
}

void respostaAluno(char respostas[], int inicio, int final) {
    if (inicio < final) {
        char resposta;
        scanf(" %c", &resposta);
        respostas[inicio] = resposta;
        return respostaAluno(respostas, inicio + 1, final);
    }
    return;
}

void entradaAlunos(int aluno, char gabarito[], int qtdAcimaMedia, int qtdAlunos, double indices[], int aux) {
    scanf("%d", &aluno);
    if (aluno == 9999) {
        double media = (qtdAcimaMedia * 100.0) / qtdAlunos;
        printf("%.1lf%%\n", media);
        double resultadoMaiorIndice = maiorIndice(indices, 1, qtdAlunos, indices[0], 1, 1, indices[0]);
        printf("%.1lf", resultadoMaiorIndice);
        return;
    }
    else {
        char respostas[10];
        respostaAluno(respostas, 0, 10);
        int rsp = comparativo(respostas, gabarito, 0, 10, 0, aluno);
        indices[aux] = rsp;
        if (rsp >= 6) {
            return entradaAlunos(aluno, gabarito, qtdAcimaMedia + 1, qtdAlunos + 1, indices, aux + 1);
        }
        else {
            return entradaAlunos(aluno, gabarito, qtdAcimaMedia, qtdAlunos + 1, indices, aux + 1);
        }
    }
}

void entradaGabarito(char gabarito[], int inicio, int final) {
    if (inicio < final) {
        char resposta;
        scanf(" %c", &resposta);
        gabarito[inicio] = resposta;
        return entradaGabarito(gabarito, inicio + 1, final);
    }
    return;
}

int main() {

    char gabarito[10];
    double indices[999];
    entradaGabarito(gabarito, 0, 10);
    entradaAlunos(0, gabarito, 0, 0, indices, 0);

    return 0;

}