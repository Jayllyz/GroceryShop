#include <stdio.h>
#include <stdlib.h>
#include <string.h>


float recupPrix(char code[],char panier[10][2], char codeF[15][4], char codeL[15][4], char codeV[15][4], float prixF[], float prixL[], float prixV[])
{
    int i = 0;
	for(i=0; i <9;i++ ) //on parcourt la chaine panier 
    {    
        if((strcmp(panier[i],code)) !=0 ) //et on verifie que l'utilisateur tape un code qui n'a pas déjà été payé !
        {

		   if(code[0] == 'F')//on regarde la première lettre pour connaitre le tableau
    	   {	
        	   for (i = 0; i <= 15 ; i++)   
        	   {
            	    if ((strcmp(code,codeF[i])) == 0)//on cherche le bon code (strcmp compare deux chaines de caractere)
            	    {
					   return prixF[i]; //on return le prix avec le même i car les deux tableaux sont de la même tailles
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
           else
           {
             break;
           }

        }
        else
        {
            return 0; //si l'article est déjà dans le panier on return 0 puis dans le main on affiche l'erreur
        }
    }
}




//même fonction que au dessus sauf qu'on return le rang  et pas le prix, qu'on a besoin dans la fonction panierEmoji
int recupRang(char code[], char codeF[15][4], char codeL[15][4], char codeV[15][4], float prixF[], float prixL[], float prixV[])
{
    short int i = 0;
     
        if(code[0] == 'F')
        {   
            for (i = 0; i <= 15; i++)   
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