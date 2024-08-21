#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int chkwin = 0; // check win
int xwins = 0; // # of x wins
int owins = 0; // # of o wins
int turn = 0; // turn #
char xo = '~'; // x or o character
char pos[3]; // current coordinate

char row1[3];
char row2[3];
char row3[3];

char col1[3];
char col2[3];
char col3[3];

char dia1[3];
char dia2[3];

// display
char row1d[4] = "~~~";
char row2d[4] = "~~~";
char row3d[4] = "~~~";

void graphics()
{
    printf("\n%s", row1d);
    printf("\n%s", row2d);
    printf("\n%s", row3d);
}

int logic()
{
    while(chkwin==0)
    {
        // x or o
        if((turn%2) == 0)
        {
            xo = 'X';
            turn++;
        } else 
        {
            xo = 'O';
            turn++;
        }
        
        // input
        // convert str to int
        fgets(pos, 4, stdin);
        int posi = strtol(pos, NULL, 10);

        // check where to put xo
        if(posi==11)
        {
            row1[0] = xo;
            col1[0] = xo;
            dia1[0] = xo;

            row1d[0] = xo; 
        } else if(posi==12)
        {
            row1[1] = xo;
            col2[0] = xo;

            row1d[1] = xo;
        } else if(posi==13)
        {
            row1[2] = xo;
            col3[0] = xo;
            dia2[0] = xo;

            row1d[2] = xo;
        } else if(posi==21)
        {
            row2[0] = xo;
            col1[1] = xo;

            row2d[0]= xo; 
        } else if(posi==22)
        {
            row2[1] = xo;
            col2[1] = xo;
            dia1[1] = xo;
            dia2[1] = xo;

            row2d[1] = xo;
        } else if(posi==23)
        {
            row2[2] = xo;
            col3[1] = xo;

            row2d[2] = xo;
        } else if(posi==31)
        {
            row3[0] = xo;
            col1[2] = xo;
            dia2[2] = xo; 

            row3d[0] = xo;
        } else if(posi==32)
        {
            row3[1] = xo;
            col2[2] = xo;

            row3d[1] = xo;
        } else if(posi==33)
        {
            row3[2] = xo;
            col3[2] = xo;
            dia1[2] = xo;
            
            row3d[2] = xo;
        } else {
            printf("\nturn error\n");
        }

        // graphics
        graphics();

        // check win
        if(strcmp(row1,"XXX")==0 || strcmp(row2,"XXX")==0 || strcmp(row3,"XXX")==0 || strcmp(col1,"XXX")==0 || strcmp(col2,"XXX")==0 || strcmp(col3,"XXX")==0 || strcmp(dia1,"XXX")==0 || strcmp(dia2,"XXX")==0)
        {
            printf("\nx wins");
            xwins++;
            chkwin = 1;
        }

        if(strcmp(row1,"OOO")==0 || strcmp(row2,"OOO")==0 || strcmp(row3,"OOO")==0 || strcmp(col1,"OOO")==0 || strcmp(col2,"OOO")==0 || strcmp(col3,"OOO")==0 || strcmp(dia1,"OOO")==0 || strcmp(dia2,"OOO")==0)
        {
            printf("\no wins");
            owins++;
            chkwin = 1;
        }
    }
    return(0);
}

// int test() {}

int main()
{
    logic();
    //test();
    //graphics();
    return(0);
}