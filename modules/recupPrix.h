#include <stdio.h>
#include <stdlib.h>
#include <string.h>


float recupPrix(char code[], char codeF[15][4], char codeL[15][4], char codeV[15][4], float prixF[], float prixL[], float prixV[])
{
    int i = 0;
	
		if(code[0] == 'F')
    	{	
        	for (i = 0; i <= 15 ; i++)   
        	{
            	if ((strcmp(code,codeF[i])) == 0)
            	{
					return prixF[i];
        	  	}
			}
		}
	
    	if(code[0] == 'L')
    	{
        	for (i = 0; i <= 15; i++)   
        	{
            	if ((strcmp(code,codeL[i])) == 0)
            	{
					return prixL[i];
            	}
        	}
    	}

    	if(code[0] == 'V')
    	{
        	for (i = 0; i <= 15; i++)   
        	{
            	if ((strcmp(code,codeV[i])) == 0)
            	{
				    return prixV[i];
            	}
            }
        }
}

int recupRang(char code[], char codeF[15][4], char codeL[15][4], char codeV[15][4], float prixF[], float prixL[], float prixV[])
{
    int i = 0;
    
        if(code[0] == 'F')
        {   
            for (i = 0; i <= 15 ; i++)   
            {
                if ((strcmp(code,codeF[i])) == 0)
                {
                    return i;
                }
            }
        }
    
        if(code[0] == 'L')
        {
            for (i = 0; i <= 15; i++)   
            {
                if ((strcmp(code,codeL[i])) == 0)
                {
                    return i;
                }
            }
        }

        if(code[0] == 'V')
        {
            for (i = 0; i <= 15; i++)   
            {
                if ((strcmp(code,codeV[i])) == 0)
                {
                    return i;
                }
            }
        }
}