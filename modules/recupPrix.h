#include <stdio.h>
#include <stdlib.h>



float recupPrix(char code[], float *prix, char codeF[15][4], char codeL[15][4], char codeV[15][4], float prixF[], float prixL[], float prixV[])
{
    int i = 0;
		if(code[0] == 'F')
    	{	
        	for (i = 0; i < 15 ; i++)   
        	{
            	if (codeF[i] == code)
            	{
                *prix = prixF[i];
            	}
        }	}
		i =0;
    	if(code[0] == 'L')
    	{
        	for (i = 0; i < 15; i++)   
        	{
            	if (codeL[i] == code)
            	{
                *prix = prixL[i];
            	}
        	}
    	}
		i=0;
    	if(code[0] == 'V')
    	{
        	for (i = 0; i < 15; i++)   
        	{
            	if (codeV[i] == code)
            	{
                *prix = prixV[i];
            	}
            }
        }
    
    	else
    	{
        printf("erreur");
    	}
    
   
}