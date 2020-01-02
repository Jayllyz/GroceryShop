#include <stdio.h>
#include <stdlib.h>



float recupPrix(char code[], char codeF[15], char codeL[15], char codeV[15], float prixF[15], float prixL[15], float prixV[15])
{
    if(code[0] == 'F')
    {
     int i;
        for (i = 0; codeF[i] !='\0'; i++)   
        {
            if (codeF[i] == *code)
            {
                return prixF[i];
            }
        }
    }
    if(code[0] == 'L')
    {
     int i;
        for (i = 0; codeL[i] !='\0'; i++)   
        {
            if (codeL[i] == *code)
            {
                return prixL[i];
            }
        }
    }
    if(code[0] == 'V')
    {
     int i;
        for (i = 0; codeV[i] !='\0'; i++)   
        {
            if (codeV[i] == *code)
            {
                return prixV[i];
            }
        }
    }
    
}