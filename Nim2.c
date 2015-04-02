    #include<stdio.h>
    #include<stdlib.h>
    #include <string.h>
    #include <time.h>



    void endingGame(int winner);
    void displayGame(int *totalpiles, int numbers[]);
    int arrayShift(int *piles,int pile,int *totalPiles);
    void arrayChange(int *piles,int pile,int sticks,int* totalPiles);
    int userTurn (int *piles,int *totalPiles);
    int computerTurn(int *piles,int *totalPiles);
    int turn(int piles[], int *totalPiles);


    int main(void)
    {
        
        int totalPile, piles[100]={0}, i;
        
        //Prints title
        
        printf("***************\n* - - NIM - - *\n***************\n");
        
        //Ask user for input
        
        printf("Please enter number of pile: ");
        scanf("%d",&totalPile);
        
        //printf("Please enter how many sticks are in each pile: ");
        for(i=0; i<totalPile; i++){
            printf("Enter sticks for Pile #%d :",i+1);
            scanf("%d", &piles[i]);
        }
        
        //Call functions in loop
        while(totalPile!=0)
        {
            displayGame(&totalPile,piles);
            totalPile = turn(piles,&totalPile);
           
        }
        
        return 0;
    }



    void endingGame(int winner)
    {
        if(winner == 1)
            printf("\n\nCongratulations you just BEAT a machine!\n");
        else
            printf("\n\nSorry about that!\n");
        
        printf("WANT TO PLAY AGAIN?");
    }
    void displayGame(int *totalpiles, int numbers[])
    {
        int i;
        for(i=0; i<*(totalpiles); i++){
            for (int j=numbers[i]; j>0; j--) {
                printf("I");
            }
            printf("     ");
        }
        
            printf("\n");
    }
               
    int arrayShift(int *piles,int pile,int *totalPiles)
    {
            int i,temp;
            for(i=pile-1;i < *(totalPiles-1);i++)
            {
                temp = piles[i];
                piles[i] = piles[i+1];
                piles[i+1] = temp;
            }
            return *(totalPiles - 1);
    }
               
    void arrayChange(int *piles,int pile,int sticks,int *totalPiles)
    {
            //printf("ArrayChange Total pile %d \t Selected pile# %d \n",*totalPiles, sticks);
            piles[pile-1] = piles[pile-1] - sticks;
            if(piles[pile-1] <=0)
                *totalPiles = arrayShift(piles, pile, totalPiles);
        
    }
               
    int userTurn (int *piles,int *totalPiles)
    {
            int pile, stick;
            printf("What pile would you like to take from :");
            scanf("%d",&pile);
            printf("how many sticks would you like to take :");
            scanf("%d",&stick);
            arrayChange(piles,pile,stick, totalPiles);
            
            return *totalPiles;
    }

    int computerTurn(int *piles,int *totalPiles)
    {
        int selectPile =rand()%(*totalPiles);
        //printf("ComputerTurn Total pile %d \t Selected pile# %d \n",*totalPiles, selectPile);
        if (*(piles+selectPile)!=0)
        {
            
            int removeStick=*(piles+selectPile)==1?1: rand()%(*(piles+selectPile));
            
            if (removeStick==0) {
                computerTurn(piles,totalPiles);
            }else {
                
                printf("Selected pile# %d, Remove stick %d\n",selectPile+1, removeStick);
                *(piles+selectPile)=*(piles+selectPile)-removeStick;
                //printf("After %d\n", *(l+selectPile));
               // CheckWin(l);
                
                //if(Win==1)
                  //  printf("Computer win, you lost.");
            }
        }else
        {
            
            computerTurn(piles,totalPiles);
        }
        
        return *totalPiles;
    }
               
    int turn(int piles[], int *totalPiles)
    {
            //printf("Total piles :%d",*totalPiles);
        
            *totalPiles = userTurn(piles,totalPiles);
            displayGame(totalPiles,piles);
            if(totalPiles == 0)
                endingGame(0);
            else
            {
                *totalPiles = computerTurn(piles,totalPiles);
                if(totalPiles == 0)
                    endingGame(1);
            }
            return *totalPiles;
    }