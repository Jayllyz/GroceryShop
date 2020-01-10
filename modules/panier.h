#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int panierVide(char tab[10][2])
{
    char test[] = "o";
    int i, place = 1;
    for(i=0; i <=9; i++)
    {
    	 if((strcmp(tab[i],test)) == 0)
         {
            place +=1;
         }
   
    }
    return place;
}

void panierEmoji(char code[],char panier[10][2],char* eF[],char* eL[],char* eV[],int rang,int y, int x)
{
	if(strcmp(panier[rang],"o") ==0)
		{
			if(code[0] == 'F')
			{
				printf("\033[%d;%dH",y,x);
				printf("%s", eF[rang]);
			}
			if(code[0] == 'L')
			{
				printf("\033[%d;%dH",y,x);
				printf("%s", eL[rang]);
			}
			if(code[0] == 'V')
			{
				printf("\033[%d;%dH",y,x);
				printf("%s", eV[rang]);
			}
		}

}