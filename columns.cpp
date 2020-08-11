/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 */

#include <stdio.h>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// constraints
#define MAXN 1000000
#define unita 10

// input data
int N, M, T, i, j;
int L[MAXN];
int massimo=0;

vector <int> possibili_somme;

int verifica(int mas, int massimo)
{
    int value=0;
    queue <int> va;
    queue <int> vb;
    for(i=0; i<N; i++)
    {
        for(j=0; j<mas/2; j+=unita)
        {
            if(L[i]==mas)
            {
                va.push(i);
            }
            if(L[i]==mas-j)
            {
                vb.push(i);
            }
        }
    }
    while(!va.empty() || !vb.empty())
    {
        L[va.front()]=0;
        L[vb.front()]=0;
        va.pop();
        vb.pop();
        value++;
    }
    return value;
}

int main()
{
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(3 == scanf("%d %d %d", &N, &M, &T));
    for(i=0; i<N; i++)
    {
        assert(1 == scanf("%d", &L[i]));
        if(L[i]>massimo)
            massimo=L[i];
    }
    sort(L,L+N);
    possibili_somme.resize(2*massimo,0);
    for(i=0; i<N; i++)
    {
        possibili_somme[L[i]]++;
    }
    /*for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
        {
            if(j<i)
            {
                possibili_somme[L[i]+L[j]]++;
            }
        }
    }*/

    for(int mas=massimo*2; mas<0; mas-=unita)
    {
        possibili_somme[mas]+=verifica(mas, massimo);
    }

    for(i=0; i<2*massimo; i+=unita)
    {
        printf("%d", i);
        printf("%d\n", possibili_somme[i]);
    }
    int provo=T;
    i=0;
    bool verifica=true;
    while(verifica)
    {
        if(provo<massimo*2)
        {
            if(possibili_somme[provo]>M-1)
                verifica=false;
            else
                provo+=unita;
        }
        else
        {
            printf("IMPOSSIBLE\n");
            return 0;
        }
    }

// 4 2 10 10 20 30 40
    printf("%d\n", provo); // change 42 with actual answer
//  printf("IMPOSSIBLE\n"); // uncomment if needed
    return 0;
}
