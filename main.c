#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "initialize.h"
#include "logic.h"
#include "output.h"

int main()
{
    srand(time(NULL));
    int n;
    printf("Podaj wielkosc labiryntu\n");
    scanf("%d",&n);
    if(n<=0)
    {
        fprintf(stderr,"Wielkosc labiryntu musi byc wieksza od 0");
        return 1;
    }
    n=n*2+1;
    char **tab=createMatrix(n);

    int **visited=createVisited(n);

    double **con=createConnection(tab,n);
    
    int start,end;
    printf("Podaj wspolrzedne startowe oraz koncowe labirynu(ideksowanie od 1), np 1 3\n");
    scanf("%d %d",&start,&end);
    if(start<=0 || start>(n-1)/2 || end<=0 || end>(n-1)/2)
    {
        fprintf(stderr,"Podano zle wartosci poczatku/konca labiryntu");
        return 1;
    }
    addConnections(con,start*2-1,n+start*2-1);//dodanie polacznie pomiedzy startem labiryntu a kratka pod nim
    addConnections(con,n*(n-1)+end*2-1,n*(n-2)+end*2-1);//dodanie polacznie pomiedzy koncem labiryntu a kratka nad nim
    setStart(tab,start);//graficznie ustawia start labiryntu
    setEnd(tab,end,n);//graficznie ustawia koniec labiryntu
    dfs(tab,visited,con,n,1,start*2-1);
    printMatrix(tab,n);
    printf("\n");
    printConnection(con,n);

    freeMemory(tab,visited,con,n);
    return 0;


    return 0;
}