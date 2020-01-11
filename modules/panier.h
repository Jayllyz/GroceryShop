#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int panierEmoji(char code[],char panier[10][2],char* eF[],char* eL[],char* eV[],int rang,int j,int y, int x)
{
	if(strcmp(panier[j+1],"o") ==0) //on verifie les cases libres du panier
		{
			if(code[0] == 'F')//on regarde la première lettre pour savoir dans quel tab chercher
			{
				printf("\033[%d;%dH",y,x);
				printf("%s", eF[rang]);//on print l'emoji avec le rang donné en parametre
				return 0;
			}
			if(code[0] == 'L') //même chose
			{
				printf("\033[%d;%dH",y,x);
				printf("%s", eL[rang]);
				return 0;
			}
			if(code[0] == 'V')//même chose
			{
				printf("\033[%d;%dH",y,x);
				printf("%s", eV[rang]);
				return 0;
			}
		}
	else
	{
		return 1;//Sinon le panier est plein
	}

}



void placementPanier(int j,int* y, int* x) //J correspond à la case du panier dans laquelle on doit placer l'emoji puis y et x les coordonnées
{
    if(j == 1)
    {
        *y=28; //En fonction de la case les coordonnées change (0 est directement place dans la fonction panierEmoji)
        *x=70;
    }
    if(j == 2)
    {
        *y=28;
        *x=74;
    }
    if(j==3)
    {
        *y=27;
        *x=66;
    }
    if(j==4)
    {
        *y=27;
        *x=70;
    }
    if(j==5)
    {
        *y=27;
        *x=75;
    }
    if(j ==6)
    {
        *y=26;
        *x=66;
    }
    if(j==7)
    {
        *y=26;
        *x=70;
    }
    if(j==8)
    {
        *y=26;
        *x=74;
    }
}
