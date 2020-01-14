#include <stdio.h>
#include <stdlib.h>


float payement(float prix)
{
    float sommeClient;
    float sommeRendre;
    scanf("%f", &sommeClient);
    printf("\033[%d;%dH",27,115);
    printf("€");
    if ( (sommeClient - prix) == 0) //Le payement est bon rien à rendre
    {
        return 0; 
    }
    if( (sommeClient - prix) <  0) //Le mec à pas suffisament d'argent 
    {
        return -1;

    }
    if((sommeClient - prix) > 0) 
    {
        sommeRendre = sommeClient - prix; //On calcul la monnaie à rendre
        return sommeRendre;
    }
}
