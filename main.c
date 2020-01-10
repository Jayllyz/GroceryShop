#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "modules/initTab.h"
#include "modules/recupPrix.h"
#include "modules/payement.h"
#include "modules/panier.h"

void cursorPosition(int YPos, int XPos) //Fonction pour déplacer le curseur
{
    printf("\033[%d;%dH",YPos,XPos);
}



int main()
{



	char* emojiF[] = //chaine pour stocker les emoji
    {
        "🍓",
        "🍇",
        "🍏",
        "🍎",
        "🍐",
        "🍊",
        "🍋",
        "🍌",
        "🍉",
        "🍈",
        "🍒",
        "🍑",
        "🥥",
        "🍍",
        "🥝",
    };

	float prixF[15]; // tab des prix init dans le fichier initTab
    char codeF[15][4] =  //chaine pour les codes
    { 
        "F00",
        "F01",
        "F02",
        "F03",
        "F04",
        "F05",
        "F06",
        "F07",
        "F08",
        "F09",
        "F10",
        "F11",
        "F12",
        "F13",
        "F14",
    };

	char* emojiL[] =
    {
        "🍅",
        "🍆",
        "🥦",
        "🌽",
        "🥒",
        "🌶",
        "🥕",
        "🥔",
        "🍠",
        "🥑",
        "🍀",
        "🥔",
        "🌱",
        "🌿",
        "🍄",
    };

	float prixL[15];
    char codeL[15][4] = 
    { 
        "L00",
        "L01",
        "L02",
        "L03",
        "L04",
        "L05",
        "L06",
        "L07",
        "L08",
        "L09",
        "L10",
        "L11",
        "L12",
        "L13",
        "L14",
    };

	char* emojiV[] =
    {
        "🍗",
        "🍖",
        "🥩",
        "🥓",
        "🍘",
        "🍔",
        "🍱",
        "🦐",
        "🐚",
        "🦀",
        "🐟",
        "🐠",
        "🍤",
        "🐡",
        "🐋",
    };
	float prixV[15];
    char codeV[15][4] = 
    { 
        "V00",
        "V01",
        "V02",
        "V03",
        "V04",
        "V05",
        "V06",
        "V07",
        "V08",
        "V09",
        "V10",
        "V11",
        "V12",
        "V13",
        "V14",
    };

    initPrixF(prixF); //initialisation des valeurs pour les tab 
    initPrixL(prixL);
    initPrixV(prixV);
    
    char panier[10][2]= 
    {
        "o",
        "o",
        "o",
        "o",
        "o",
        "o",
        "o",
        "o",
        "o",
        "o",
    };



    int caractereActuel = 0;
    FILE* fichier = NULL;
    fichier = fopen("vitrine.txt", "r"); //on ouvre le fichier en lecture
    do
    {
        caractereActuel = fgetc(fichier); // On lit le caractère
        printf("%c", caractereActuel);
    } while ( caractereActuel != EOF); //tant que le fichier n'est pas terminé


int j=0,rang;
int y =28;
int x =66;
char code[4]= {0};
char pay[4]="pay";
char fin[4]="fin";
float prixT; 
float prixA = 0;

    while((strcmp(code,fin)) !=0)
    {
            cursorPosition(29,27);
            printf("   ");
            cursorPosition(29,27);
            scanf("%3s", code);
            if ((strcmp(code,pay))==0)
            {
                cursorPosition(27,115); 
                printf("   ");
                cursorPosition(27,115);
                printf("%.2f", prixT); 
                cursorPosition(28,110);
                float recu = payement(prixT);
                if(recu < 0)
                {
                    cursorPosition(28,110); 
                    printf("erreur montant");
                }
                else
                {
                    cursorPosition(29,108);
                    printf("%f",recu);
                    cursorPosition(31,25);
                    printf("Merci à bientôt !");

                }
            }

            prixA = recupPrix(code,panier,codeF,codeL,codeV,prixF,prixL,prixV); 

                if(prixA == 0)
                {
                    cursorPosition(29,27);
                    printf("    ");
                    cursorPosition(31,25);
                    printf("article épuisé");
                    continue;
                }
                else
                {   
                     
                    prixT = prixT + prixA;
                    cursorPosition(27,115); 
                    printf("%.2f", prixT); 

                    rang = recupRang(code,codeF,codeL,codeV,prixF,prixL,prixV);
                       if(  (panierEmoji(code,panier,emojiF,emojiL,emojiV,rang,j,y,x)) ==1 )
                       {
                            cursorPosition(31,25);
                            printf("panier plein.");

                       }
                        strcpy(panier[j], code);
                        j+=1;
                }
            if(j == 1)
            {
                y=28;
                x=70;
            }
            if(j == 2)
            {
                y=28;
                x=74;
            }
            if(j==3)
            {
                y=27;
                x=66;
            }
            if(j==4)
            {
                y=27;
                x=70;
            }
            if(j==5)
            {
                y=27;
                x=75;
            }
            if(j ==6)
            {
                y=26;
                x=66;
            }
            if(j==7)
            {
                y=26;
                x=70;
            }
            if(j==8)
            {
                y=26;
                x=74;
            }
    }   
             if((strcmp(code,fin)) ==0)
            {
                cursorPosition(31,27);
                printf("Aurevoir");
                exit(-1);
            }        
        


    fclose(fichier);


    return 0;
}