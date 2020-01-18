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

    system("clear"); //on clear le terminale avant

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
    
    char panier[10][4]= 
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



int caractere = 0;
FILE* fichier = NULL;
fichier = fopen("vitrine.txt", "r"); //on ouvre le fichier en lecture
if( fichier != NULL) //on verifie que le fichier existe bien 
{ 
    while ( caractere != EOF) //
    {   
        caractere = fgetc(fichier);// On lit le caractère
            if( caractere == EOF) //si c'est la fin il stop
            {
                break;            
            } 
        printf("%c", caractere); //on print le caractere récupéré
    } 

}
else
{
    printf("Fichier manquant ! ");//si le fichier existe pas on informe l'utilisateur

}
fclose(fichier);            
short int j=0,rang =0;   // création de toutes les variables utiles et chaine de caractere, j correspond aux article du panier
int y =27;      
int x =66;
char code[5]= {0}; //code entrée par l'utilisateur (on prend une taille de 5 car on prend 4 caractere dans le scanf tout est expliqué pourquoi à coté du scanf)
char pay[4]="pay";
char fin[4]="fin";
float prixT=0;
float prixA;

    while((strcmp(code,fin)) !=0)
    {
        cursorPosition(28,27); //on se place à l'endroit  du code et on efface bien ce qu'il y a avant
        printf("               ");
        cursorPosition(28,27);
        scanf("%4s", code); //on scan puis on le mets dans code (on prend 4 élément pour eviter une faille si l'utilisateur rentre F001 et que l'on récupere F00 cela va foncctionner alors que le code est faux)
        //donc on prend 4 caractéres pour etre sur d'avoir le bon code
        cursorPosition(30,25);
        printf("                   ");
            if ((strcmp(code,pay))==0 && j >= 1) //on rentre dans cette boucle une fois que l'utilisateur tape "pay"
            {

                cursorPosition(27,110);
                float recu = 0;
                recu = payement(prixT);

                while(recu < 0) //si le recu est négatif alors l'utilisateur n'a pas donné suffisament
                {
                    cursorPosition(24,108); 
                    printf("erreur montant ⛔");
                    cursorPosition(27,110);
                    printf("    ");
                    cursorPosition(27,110);
                    recu = payement(prixT);
                }
                if(recu >=0)
                {
                    cursorPosition(24,108);
                    printf("                  "); //on efface une possible erreur de montant réalisé avant
                    cursorPosition(28,108); //sinon on print le recu et le prix 
                    printf("%.2f €",recu); 
                    cursorPosition(30,25); 
                    printf("Merci à bientôt ! 👋");
                    cursorPosition(79,0); 
                    printf(" ");
                    break; //puis on ferme la boucle

                }
            }

            prixA = recupPrix(code,panier,codeF,codeL,codeV,prixF,prixL,prixV,j); 

            if(prixA == 0)//si l'article vaut 0 c'est car c'est un article déjà payé donc on rentre dans une boucle spécifique
            {
                cursorPosition(30,25);
                printf("              "); //On efface une possible erreur print avant
                cursorPosition(30,25);
                printf("⛔ article épuisé ⛔");
                 continue;//puis on relance la boucle pour le prochain produit
            }
            if(prixA > 0) //Si le prix est bien supérieur à 0
            {   
                     
                prixT = prixT + prixA; //on calcule le prix 
                cursorPosition(26,115); 
                printf("%.2f €", prixT); // et on print
                rang = recupRang(code,codeF,codeL,codeV,prixF,prixL,prixV);//on recupére le rang de l'article acheté dans le tableau pour l'utiliser dans une fonction
                    if( (panierEmoji(code,panier,emojiF,emojiL,emojiV,rang,j,y,x)) ==1 ) //panierEmoji renvoi 1  car aucune case du panier n'est vide
                    {
                        cursorPosition(30,25);
                        printf("                ");
                        cursorPosition(30,25);
                        printf("⛔ panier plein ⛔");
                        j-=1; //si le panier est plein il ne faut pas augmenter le nombre d'article donc on fait -1 car juste après il s'incrémente
                    }

                strcpy(panier[j], code);//on mets le code du produit dans panier pour ne pas pouvoir payer deux fois le même article
                j+=1; //on incrémente le nombre d'article payé
                cursorPosition(30,62);
                if(j > 1)
                {
                    printf("Vous avez %d articles", j); //compteur d'articles
                }
                else
                {
                    printf("Vous avez %d article", j);
                }
            }
            else //sinon le code est faux car en cas d'erreur la fonction qui cherche le prix ne return rien
            {
                if(j == 0 && (strcmp(code,pay))==0 ) //si le panier et vide et que l'utilisateur tape "pay" on rentre dans ce if
                {
                    cursorPosition(28,27);
                    printf("    ");
                    cursorPosition(30,25);
                    printf("panier vide ⛔");
                    continue;
                }
                cursorPosition(28,27); //sinon c'est simplement un code  faux
                printf("    ");
                cursorPosition(30,25);
                printf("code faux ⛔");

            } 
        placementPanier(j,&y,&x); //cette fonction place l'emoji en fonction du nombre d'artcile déjà payé
    }

/*une fois sorti de la boucle principale on vérifie si la boucle est fermé car l'utilisateur à terminé de payer alorson ne fait rien
mais si l'utilisateur à écrit fin on lance un boucle spécifique */

if((strcmp(code,fin)) ==0)   
{
    cursorPosition(26,115);
    printf("0   "); 
    cursorPosition(30,25);
    printf("Aurevoir 👋");
    cursorPosition(79,0); 
    printf(" ");
    exit(-1);   
} 
        



    return 0;
}