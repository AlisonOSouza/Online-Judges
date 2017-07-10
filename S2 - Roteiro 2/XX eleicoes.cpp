#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

typedef struct voto
{
    int num_votos;
    int candidato;
} voto_t;

int main(void)
{
    int i, j, n, aux, eleito;
    
    std::cin >> n;
    std::vector<voto_t> votos(n);
    for(i = 0; i < n; i++)
    {
        votos[i].num_votos = 0;
        votos[i].candidato = 0;
    }
    
    for(i = 0; i < n; i++)
    {
        std::cin >> aux;
        for(j = 0; j < n; j++)
        {
            if(aux == votos[j].candidato)
            {
                votos[j].num_votos++;
                break;
            }
            if(votos[j].candidato == 0)
            {
                votos[j].candidato = aux;
                votos[j].num_votos++;
                break;
            }
        }
    }
    
    aux = 0;
    for(i = 0; i < n; i++)
    {
        if(votos[i].num_votos > aux) 
        {
            eleito = votos[i].candidato;
            aux = votos[i].num_votos;
        }
    }
    
    std::cout << eleito;
   
    return 0;
}