//projet bataille navale par NIZAR RAKIBI et HANANE ABID
//1APG3

#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<time.h>
#include <stdlib.h>

int i,j,k=0,x,y,chk=0,win=0,uposb[4][2];
char gridu[10][10],gridc[10][10],orin[2];

void gotoxy(int x,int y)
{
    printf("%c[%d;%df",0x1B,y,x);
}

void navire() // fonction pour placer les navire du joueur
{
    for(;;)
    {
        chk=0;
        printf("navire:\n");
        printf("Orientation: ");
        scanf("%s",&orin);
        printf("les cordonnee x et y: ");
        scanf("%d %d",&x,&y);
        if(strcmp(orin,"h")==0)
        {
            if(y>6 || y<0 || x>9 || x<0)
            {
                printf("Impossible de placer le navire. réessayer\n");
                continue;
            }
            else
            {

                for(i=y;i<y+4;i++)
                {
                    if(gridu[x][i]!='.')
                    {
                        printf("Impossible de placer le navire. réessayer\n");
                        chk=1;
                        break;
                    }
                }
                if(chk==1)
                    continue;
                else
                {
                    for(i=y;i<y+4;i++)
                    {
                        gridu[x][i]='B';
                        uposb[k][0]=x;
                        uposb[k][1]=i;
                        k++;
                    }
                    break;
                }
            }
        }
        if(strcmp(orin,"v")==0)
        {
            if(x>6 || x<0 || y>9 || y<0)
            {
                printf("Impossible de placer le navire. réessayer\n");
                continue;
            }
             else
            {
                 for(i=x;i<x+4;i++)
                {
                    if(gridu[i][y]!='.')
                    {
                        printf("Impossible de placer le navire. réessayer\n");
                        chk=1;
                        break;
                    }
                }
                if(chk==1)
                    continue;
                else
                {
                   for(i=x;i<x+4;i++)
                    {
                        gridu[i][y]='B';
                        uposb[k][0]=i;
                        uposb[k][1]=y;
                        k++;
                    }
                    break;
                }
            }
        }
    }
    k=0;
    system("cls");
    for(i=0;i<10;i++)
    {
        for(j=0;j<30;j++)
            printf(" ");
        if(i==0)
        {
            printf("  ");
            for(j=0;j<10;j++)
            printf("%d ",j);
            printf("\n");
            for(j=0;j<30;j++)
            printf(" ");
        }
        printf("%d ",i);
        for(j=0;j<10;j++)
            printf("%c ",gridu[i][j]);
        printf("\n");
    }
}

void nav_ale()
{
    for(;;)
    {
        chk=0;
        if(rand()%2 == 1)
            strcpy(orin,"h");
        else strcpy(orin,"v");
        x=rand()%10;
        y=rand()%10;
        if(strcmp(orin,"h")==0)
        {
            if(y>6 || y<0 || x>9 || x<0)
                continue;
            else
            {
                for(i=y;i<y+4;i++)
                {
                    if(gridc[x][i]!='.')
                    {
                        chk=1;
                        break;
                    }
                }
                if(chk==1)
                    continue;
                else
                {
                    for(i=y;i<y+4;i++)
                        gridc[x][i]='B';
                    break;
                }
            }
        }
        if(strcmp(orin,"v")==0)
        {
            if(x>6 || x<0 || y>9 || y<0)
            {
                continue;
            }
             else
            {
                 for(i=x;i<x+4;i++)
                {
                    if(gridc[i][y]!='.')
                    {
                        chk=1;
                        break;
                    }
                }
                if(chk==1)
                    continue;
                else
                {
                    for(i=x;i<x+4;i++)
                        gridc[i][y]='B';
                    break;
                }
            }
        }
    }
}
void delay(clock_t a)
{
    clock_t start;
    start  = clock();
    while(clock()-start<a)
    {

    }
}
int main()
{
    int probab,diff,b=0;
    char tempstr[10],str[20]="Bataille naval",str1[50]="By Nizar Rakibi et Hanane Abid",griduv[10][10],gridcv[10][10],ch;
    system("COLOR B4");
    
   for(i=0;i<10;i++)
    {
        printf("\n");
    }
    for(i=0;i<30;i++)
    {
        printf(" ");
    }
    for(i=0;str[i]!='\0';i++)
    {
        printf("%c",str[i]);
        delay(60);
    }
    printf("\n");
    for(i=0;i<30;i++)
    {
        printf(" ");
    }
    for(i=0;str1[i]!='\0';i++)
    {
        printf("%c",str1[i]);
        delay(60);
    }
    delay(1500);
    system("cls");
    for(;;)
    {
        system("cls");
        /*for(i=0;i<10;i++)
            printf("\n");
        for(i=0;i<30;i++)
            printf(" ");*/
        gotoxy(31, 10); printf("1.jouer\n");
        for(i=0;i<30;i++)
            printf(" ");
        printf("2.regles\n");
        ch=getch();
        if(ch==49)
            break;
        if(ch==50)
        {
            system("cls");
            printf("preparez vous pour une guerre   .\n");
            printf("1.You have to defeat your opponent by destroying all his war ships before he destroys yours.\n");
            printf("2.bataille navale est une grille 10x10 où vous placez vos navires\n");
            printf("3.Vous pouvez placer vos navires en entrant son orientation. Pour l'orientation horizontale, tapez 'h' dans l'option d'orientation et tapez 'v' pour vertical\n");
            printf("4.Et ses coordonnées x y (toutes deux séparées par un espace) où x est le numéro de ligne et y est le numéro de colonne\n");
            printf("4.Vous disposez d'une navire (4 unités de long)\n");
            printf("5.Après avoir placé vos navires, vous pouvez attaquer la zone ennemie. Pour attaquer une zone spécifique, entrez sa coordonnée x y (séparée par un espace)\n");
            printf("6.Si votre attaque touche le navire ennemi, elle sera signalée par un «H». Et tu as un tour supplémentaire\n");
            printf("7.Si votre attaque échoue, elle sera signalée par un '*' et votre tour se termine\n");
            printf("appuyez sur Entrée pour continuer.........");
            fflush(stdin);
            gets(tempstr);
            continue;
        }
    }
    system("cls");
    for(i=0;i<10;i++)
        printf("\n");
    for(i=0;i<30;i++)
        printf(" ");
    printf("Sélectionnez le niveau de difficulte:\n");
    for(i=0;i<30;i++)
        printf(" ");
    printf("1.facile\n");
    for(i=0;i<30;i++)
        printf(" ");
    printf("2.moyen\n");
    for(i=0;i<30;i++)
        printf(" ");
    printf("3.difficile\n");
    ch=getch();
    if(ch==49)
        diff=9;
    if(ch==50)
        diff=8;
    if(ch==51)
        diff=6;
    system("cls"); //clearing the screen 

    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            gridc[i][j]='.';
            gridu[i][j]='.';
            gridcv[i][j]='.';
        }
    }
    for(i=0;i<10;i++) // boucle pour afficher la grille 
    {
        for(j=0;j<30;j++)
            printf(" ");
        if(i==0)
        {
            printf("  ");
            for(j=0;j<10;j++)
            printf("%d ",j);
            printf("\n");
            for(j=0;j<30;j++)
            printf(" ");
        }
        printf("%d ",i);
        for(j=0;j<10;j++)
            printf("%c ",gridu[i][j]);
        printf("\n");
    }

    /* placement des navires du joueur */
        navire();
        navire();
        navire();
     /*navire - placement de navire ennemie d'une façon aleatoire*/
        nav_ale();
        nav_ale();
        nav_ale();
    
    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
            griduv[i][j]=gridu[i][j];
    }
    for(;;)
    {
        system("cls");
        for(i=0;i<10;i++)
        {
            for(j=0;j<30;j++)
            printf(" ");
            if(i==0)
            {
                printf("  ");
                for(j=0;j<10;j++)
                printf("%d ",j);
                printf("\n");
                for(j=0;j<30;j++)
                printf(" ");
            }
            printf("%d ",i);
            for(j=0;j<10;j++)
                printf("%c ",gridcv[i][j]);
            printf("\n");
        }
        printf("\n");
        for(i=0;i<10;i++)
        {
            for(j=0;j<30;j++)
            printf(" ");
            if(i==0)
            {
                printf("  ");
                for(j=0;j<10;j++)
                printf("%d ",j);
                printf("\n");
                for(j=0;j<30;j++)
                printf(" ");
            }
            printf("%d ",i);
            for(j=0;j<10;j++)
                printf("%c ",griduv[i][j]);
            printf("\n");
        }
        for(;;)
        {
            printf("Entrer x et y: ");
            scanf("%d %d", &x,&y);
            if(x>9 || x<0 || y>9 || y<0 || gridcv[x][y]=='T' || gridcv[x][y]=='*')
            {
                printf("Invalid input. Try again\n");
                continue;
            }
            else
            {
                if(gridc[x][y]=='B') // si cet emplacement contient une navire
                {
                    if(gridcv[x][y]!='T')
                    {
                        gridcv[x][y]='T'; //cet emplacement du matrice ennemie prend T "toucher"
                        system("cls");
                        for(i=0;i<10;i++)
                        {
                            for(j=0;j<30;j++)
                            printf(" ");
                            if(i==0)
                            {
                                printf("  ");
                                for(j=0;j<10;j++)
                                    printf("%d ",j);
                                printf("\n");
                                for(j=0;j<30;j++)
                                printf(" ");
                            }
                            printf("%d ",i);
                            for(j=0;j<10;j++)
                                printf("%c ",gridcv[i][j]);
                            printf("\n");
                        }
                        printf("\n");
                        for(i=0;i<10;i++)
                        {
                            for(j=0;j<30;j++)
                            printf(" ");
                            if(i==0)
                            {
                                printf("  ");
                                for(j=0;j<10;j++)
                                    printf("%d ",j);
                                printf("\n");
                                for(j=0;j<30;j++)
                                printf(" ");
                            }
                            printf("%d ",i);
                            for(j=0;j<10;j++)
                                printf("%c ",griduv[i][j]);
                            printf("\n");
                        }
                        for(i=0;i<10;i++)
                        {
                            for(j=0;j<10;j++)
                            {
                                if(gridcv[i][j]=='T')
                                    win++;
                            }
                        }
                        if(win==12)
                        {
                            printf("\nvous avez gagner!\n");
                            break;
                        }
                        win=0;
                        continue;
                    }
                    else
                    {
                        printf("Entrée invalide. Réessayer\n");
                        continue;
                    }
                }
                else
                {
                    gridcv[x][y]='*';
                    break;
                }
            }
        }
        for(;;)
        {
            probab=rand()%diff;
            if(probab==diff-2 && b<4)
            {
                x=uposb[b][0];
                y=uposb[b][1];
                b++;
            }
            else
            {
                x=rand()%10;
                y=rand()%10;
            }
            if(x>9 || x<0 || y>9 || y<0 || griduv[x][y]=='T' || griduv[x][y]=='*')
            {
                continue;
            }
            else
            {
                if(gridu[x][y]=='B')
                {
                    if(griduv[x][y]!='T')
                    {
                        griduv[x][y]='T';
                        system("cls");
                        for(i=0;i<10;i++)
                        {
                            for(j=0;j<30;j++)
                            printf(" ");
                            if(i==0)
                            {
                                printf("  ");
                                for(j=0;j<10;j++)
                                    printf("%d ",j);
                                printf("\n");
                                for(j=0;j<30;j++)
                                printf(" ");
                            }
                            printf("%d ",i);
                            for(j=0;j<10;j++)
                                printf("%c ",gridcv[i][j]);
                            printf("\n");
                        }
                        printf("\n");
                        for(i=0;i<10;i++)
                        {
                            for(j=0;j<30;j++)
                            printf(" ");
                            if(i==0)
                            {
                                printf("  ");
                                for(j=0;j<10;j++)
                                    printf("%d ",j);
                                printf("\n");
                                for(j=0;j<30;j++)
                                printf(" ");
                            }
                            printf("%d ",i);
                            for(j=0;j<10;j++)
                                printf("%c ",griduv[i][j]);
                            printf("\n");
                        }
                        delay(1000);
                        continue;
                    }
                    else
                    {
                        continue;
                    }
                }
                else
                {
                    griduv[x][y]='*';
                    break;
                }
            }

        }
        //tester si le joueur a toucher tous les navires ennemie 
        for(i=0;i<10;i++)
        {
            for(j=0;j<10;j++)
            {
                if(gridcv[i][j]=='T')
                    win++;
            }
        }
        if(win==12)
        {
            printf("\nvous avez gagner!\n");
            break;
        }
        win=0;

        //tester si l'ennemie a toucher tous les navire du joueur 
        for(i=0;i<10;i++)
        {
            for(j=0;j<10;j++)
            {
                if(griduv[i][j]=='T')
                    win++;
            }
        }
        if(win==12)
        {
            printf("\nvous avez perdu!\n");
            break;
        }
        win=0;
    }
    return 0;
}