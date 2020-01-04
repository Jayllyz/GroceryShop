#include <stdio.h>
#include <stdlib.h>


float recupPrix(char code[], char codeF[15][4], char codeL[15][4], char codeV[15][4], float prixF[], float prixL[], float prixV[])
{
    unsigned short int i = 0;
		if(code[0] == 'F') //si le code commence par F alors c'est un fruit
    	{	
        	for (i = 0; i <= 15 ; i++)   //la boucle parcourt tout les codes des fruits
        	{
            	if ((strcmp(code,codeF[i]) == 0)) /*si il trouve le code qui correspond alors
													 il return le prix correspondant au rang du code */
            	{
					return prixF[i];
        	  	}
				else
				{
					exit(-1);
				}
				
			}
		}
		//même chose pour les autres
    	if(code[0] == 'L')
    	{
        	for (i = 0; i <= 15; i++)   
        	{
            	if ((strcmp(code,codeL[i]) == 0))
            	{
					return prixL[i];
            	}
				else
				{
					exit(-1);
				}
				
        	}
    	}

    	if(code[0] == 'V')
    	{
        	for (i = 0; i <= 15; i++)   
        	{
            	if ((strcmp(code,codeV[i]) == 0))
            	{
					return prixV[i];
            	}
				else
				{
					exit(-1);
				}
				
            }
        }

}