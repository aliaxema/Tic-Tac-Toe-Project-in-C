#include <stdio.h>
#include <stdlib.h>

char arr[3][3]={'1','2','3','4','5','6','7','8','9'};
char player ='X';
void print();
void update();
int winner();
int main()
{

    while(winner()==0)
    {
        print();
        update();


    }
    print();
    if (winner()==1)
        printf("the winner is player X!");
   else if (winner()==2)
        printf("the winner is player O!");
        else if (winner()==3)
        printf("it's a draw!");


    return 0;
}

void print()
{
       // printf("\n");
        for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%c ",arr[i][j]);
        }
        printf("\n");
    }
}
int winner()
{
    int counterX=0,counterO=0,counter =0;

    for (int i =0;i<3;i++)
    {
         for (int j =0;j<3;j++)
         {
                if (arr[i][j]=='X'||arr[i][j]=='O')
                    counter++;
                 if(arr[j][i]=='X')
                    counterX++;
                 else if(arr[j][i]=='O')
                    counterO++;
            if(counterX==3||counterO==3)
        {
            if (counterX>counterO)
                return 1;
            else
                return 2;
        }

         }
         counterX=0;
         counterO=0;
    }
    for (int i =0;i<3;i++)
    {
         for (int j =0;j<3;j++)
         {
            if(arr[i][j]=='X')
                counterX++;
            else if(arr[i][j]=='O')
                counterO++;
            if(counterX==3||counterO==3)
        {
            if (counterX>counterO)
                return 1;
            else
                return 2;
        }

         }
         counterX=0;
         counterO=0;
    }

         for (int i =0;i<3;i++)
    {
         for (int j =0;j<3;j++)
         {
             /*1 2 3 4 5 6 7 8 9
             //1 5 9 , 3 5 7
             //i=0,j=2,  2-2 = 0 [0][2] =3
                */
              if (i==(2-j))
             {
                if(arr[i][j]=='X')
                    counterX++;
                else if(arr[i][j]=='O')
                    counterO++;
             }
             else if (i==j)
             {
                 if(arr[i][j]=='X')
                    counterX++;
                else if(arr[i][j]=='O')
                    counterO++;
             }

           if(counterX==3||counterO==3)
        {
            if (counterX>counterO)
                return 1;
            else
                return 2;
        }

         }
    }
     /*  if(arr[0][0]=='X'&&arr[1][1]=='X'&&arr[2][2]=='X')
    {
        return 1;
    }
    else if(arr[0][0]=='O'&&arr[1][1]=='O'&&arr[2][2]=='O')
    {
        return 2;
    }
    if(arr[0][2]=='X'&&arr[1][1]=='X'&&arr[2][0]=='X')
    {
        return 1;
    }
    else if(arr[0][2]=='O'&&arr[1][1]=='O'&&arr[2][0]=='O')
    {
        return 2;
    }*/

         if(counter ==9)
            return 3;

    return 0;
}
void update()
{
    //char x;
 /*   printf("\nEnter the number you want to set on it player(%c)>>",player);
    scanf(" %c",&x);*/
    int input;
    printf("\nEnter the number you want to set on it player(%c)>>",player);
    scanf(" %d",&input);

    if(input>9||input<0)
        printf("you must enter a valid value!\n");
    int row ;
    int col ;
    // 1 2 3 4 5 6 7 8 9
    //2-1 = 1 =1 9-1=8%3=2
    //9-1=8/3=2
     col  = (input-1) %3 ;
     row = (input-1)/ 3;
     arr[row][col]=player;

/*
    for (int i =0;i<3;i++)
    {
         for (int j =0;j<3;j++)
         {
             if (arr[i][j]==x)
             {
                 arr[i][j]=player;
                 break ;
             }
         }
    }*/
    //printf("%i", (player=='X'));
   if(player=='X'){
    player='O';
   }else{
    player='X';
   }
}
