/*
Marquinhos é um aluno do IC.
Marquinhos sempre sonhou em ser um ninja, e ele conseguiu, com a ajuda de seu grande amigo Karuto.
(Quaisquer semelhanças com a realidade é pura coincidência... tô certo)
Karuto é o Mestre da Vila da Árvore, e deseja treinar Marquinhos para que este se torne o próximo mestre de sua vila. Para isso, Marquinhos terá que acumular uma quantidade de energia vital superior a 20000.
Para tal feito, a melhor forma de aprimorar suas habilidades e ao mesmo tempo adquirir mais energia vital é por meio de duelos com outros ninjas. Então, visto que, como Mestre da Vila, Karuto sabe a localização dos inimigos da Vila da Árvore no momento, decidiu passar para Marquinhos a localização desses.
Marquinhos domina a técnica de saber o nível de energia do inimigo só em observá-lo, e visto que ele só consegue derrotar um ninja que possui energia vital inferior ou até mesmo igual a dele, ao avistar alguém com nível acima, ele foge! (ou seja, não haverá luta contra tal ninja)
Marquinhos ganha a diferença de energia vital entre ele e o inimigo ao derrotá-lo (por exemplo: Marquinhos tem energia 200 e luta contra alguém com energia 198, ao derrotar, é acrescido a ele 200-198, ou seja, no final da luta, Marquinhos tem 202 de energia).
*/

#include <stdio.h>

double media(double quantidadeNinjas, double contador)
{

    return (contador * 100) / quantidadeNinjas;

}

void batalha(int arrayNinjas[], int arrayOrdemBatalha[], int inicio, int final, int nivelEnergiaMarquinhos, int contador)
{

    int ordem;
    int acrescimo;
    double resultadoMedia;
    if (inicio == final)
    {
        printf("N�vel de energia: %d\n", nivelEnergiaMarquinhos);
        resultadoMedia = media(final, contador);
        printf("%.2lf%%\n", resultadoMedia);
        if (nivelEnergiaMarquinhos > 20000)
        {
            printf("Marquinhos � o novo Mestre da Vila da �rvore!");
        }
        else
        {
            printf("Continue tentando!");
        }
        return;
    }
    else
    {
        ordem = arrayOrdemBatalha[inicio];
        if (nivelEnergiaMarquinhos >= arrayNinjas[ordem - 1])
        {
            contador = contador + 1;
            acrescimo = nivelEnergiaMarquinhos - arrayNinjas[ordem - 1];
            return batalha(arrayNinjas, arrayOrdemBatalha, inicio + 1, final, nivelEnergiaMarquinhos + acrescimo, contador);
        }
        else
        {
            return batalha(arrayNinjas, arrayOrdemBatalha, inicio + 1, final, nivelEnergiaMarquinhos, contador);
        }
    }

}

void registroOrdemBatalha(int arrayOrdemBatalha[], int inicio, int final)
{

    int posicao;
    if (inicio == final)
    {
        return;
    }
    else {
        scanf("%d", &posicao);
        arrayOrdemBatalha[inicio] = posicao;
        return registroOrdemBatalha(arrayOrdemBatalha, inicio + 1, final);
    }

}

void registroNivelEnergiaNinja(int arrayNinjas[], int inicio, int final)
{

    int nivelEnergiaNinja;
    if (inicio == final)
    {
        return;
    }
    else
    {
        scanf("%d", &nivelEnergiaNinja);
        arrayNinjas[inicio] = nivelEnergiaNinja;
        return registroNivelEnergiaNinja(arrayNinjas, inicio + 1, final);
    }

}

int main() {
    
    int nivelEnergiaMarquinhos, quantidadeNinjas;

    scanf("%d", &nivelEnergiaMarquinhos);
    scanf("%d", &quantidadeNinjas);
    
    int arrayNinjas[quantidadeNinjas];
    registroNivelEnergiaNinja(arrayNinjas, 0, quantidadeNinjas);

    int arrayOrdemBatalha[quantidadeNinjas];
    registroOrdemBatalha(arrayOrdemBatalha, 0, quantidadeNinjas);

    batalha(arrayNinjas, arrayOrdemBatalha, 0, quantidadeNinjas, nivelEnergiaMarquinhos, 0);

    return 0;

}