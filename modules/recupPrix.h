#include <stdio.h>
#include <stdlib.h>


int recupPrix(char code[], char codeF[15][4], char codeL[15][4], char codeV[15][4], float prixF[], float prixL[], float prixV[])
{
    int i = 0;
	int j=0;
	int k=0;
		if(code[0] == 'F')
    	{	
        	for (i = 0; i <= 15 ; i++)   
        	{
            	if ((strcmp(code,codeF[i]) == 0))
            	{
					return i;
        	  	}
			}
		}
	
    	if(code[0] == 'L')
    	{
        	for (j = 0; j <= 15; i++)   
        	{
            	if ((strcmp(code,codeL[i]) == 0))
            	{
					return j;
            	}
        	}
    	}

    	if(code[0] == 'V')
    	{
        	for (k = 0; k <= 15; i++)   
        	{
            	if ((strcmp(code,codeV[i]) == 0))
            	{
					return k;
            	}
            }
        }

}