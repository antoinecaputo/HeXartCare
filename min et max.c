#include <stdio.h>
#include <stdlib.h>

void min_et_max(int *tab, int sizetab)
{
    int i, a, b;
    int maxi =0;
    int mini =0;
    mini = tab[0];
    maxi = tab[0];
    for(i=0;i<sizetab;i++)
    {
        if (mini>tab[i])
        {
            mini = tab[i];
            a = i+1;
        }
        else if (maxi<tab[i])
        {
            maxi = tab[i];
            b = i+1;
        }
    }
    printf("La valeure minimale est %d a la seconde %d\n", mini, a);
    printf("La valeure maximale est %d a la seconde %d\n", maxi, b);
}
