#include<stdio.h>
#include<string.h>
int chkwin = 0;
int xwins = 0;
int owins = 0;
int turn = 0;
char xo = '~';
char pos[3] = "";

char row1[4] = "";
char row2[4] = "";
char row3[4] = "";

char col1[4] = "";
char col2[4] = "";
char col3[4] = "";

char dia1[4] = "";
char dia2[4] = "";

// char cmpre
char _11[3] = "11";
char _12[3] = "12";
char _13[3] = "13";

char _21[3] = "21";
char _22[3] = "22";
char _23[3] = "23";

char _31[3] = "31";
char _32[3] = "32";
char _33[3] = "33";

// display
char row1d[4] = "~~~";
char row2d[4] = "~~~";
char row3d[4] = "~~~";

void graphics()
{
    printf("%s\n%s\n%s", row1d, row2d, row3d);
}

int logic()
{
    while(chkwin==0)
    {
        // x or o
        if (turn%2 == 0)
        {
            xo = 'X';
            turn++;
        } else 
        {
            xo = 'O';
            turn++;
        }

        fgets(pos, 3, stdin);
        printf("\n%d",turn);

        // check where to put xo
        if(strcmp(pos, _11)==0)
        {
            row1[0] = xo;
            col1[0] = xo;
            dia1[0] = xo; 
        } else if (strcmp(pos, _12)==0)
        {
            row1[1] = xo;
            col2[0] = xo;
        } else if (strcmp(pos, _13)==0)
        {
            row1[2] = xo;
            col3[0] = xo;
            dia2[0] = xo;
        } else if(strcmp(pos, _21)==0)
        {
            row2[0] = xo;
            col1[1] = xo; 
        } else if (strcmp(pos, _22)==0)
        {
            row2[1] = xo;
            col2[1] = xo;
            dia1[1] = xo;
            dia2[1] = xo;
        } else if (strcmp(pos, _23)==0)
        {
            row2[2] = xo;
            col3[1] = xo;
        } else if(strcmp(pos, _31)==0)
        {
            row3[0] = xo;
            col1[2] = xo;
            dia2[2] = xo; 
        } else if (strcmp(pos, _32)==0)
        {
            row3[1] = xo;
            col2[2] = xo;
        } else if (strcmp(pos, _33)==0)
        {
            row3[2] = xo;
            col3[2] = xo;
            dia1[2] = xo;
        } else {
            printf("turn error");
        }

        // graphics
        graphics();

        // check win
        if (strcmp(row1, "XXX")==0 || strcmp(row2,"XXX")==0 || strcmp(row3, "XXX")==0 || strcmp(col1, "XXX")==0 || strcmp(col2, "XXX")==0 || strcmp(col3, "XXX")==0 || strcmp(dia1, "XXX")==0 || strcmp(dia2, "XXX")==0)
        {
            printf("x wins");
            xwins++;
            chkwin = 1;
        }

        if (strcmp(row1, "OOO")==0 || strcmp(row2,"OOO")==0 || strcmp(row3, "OOO")==0 || strcmp(col1, "OOO")==0 || strcmp(col2, "OOO")==0 || strcmp(col3, "OOO")==0 || strcmp(dia1, "OOO")==0 || strcmp(dia2, "OOO")==0)
        {
            printf("x wins");
            owins++;
            chkwin = 1;
        }
        
    }
    return(0);
}



int main()
{
    logic();
    return(0);
}