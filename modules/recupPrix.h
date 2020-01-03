#include <stdio.h>
#include <stdlib.h>


int recupPrix(char code[], char codeF[15][4], char codeL[15][4], char codeV[15][4], float prixF[], float prixL[], float prixV[])
{
    int i = 0;
		if(code[0] == 'F')
    	{	
        	for (i = 0; i < 15 ; i++)   
        	{
            	if (codeF[i] == code)
            	{
					return i;
        	  	}
			}
		}
	i=0;
    	if(code[0] == 'L')
    	{
        	for (i = 0; i < 15; i++)   
        	{
            	if (codeL[i] == code)
            	{
					return i;
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
					return i;
            	}
            }
        }

}