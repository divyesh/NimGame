//
//  main.c
//  NimGame
//
//  Created by divyesh konkani on 2015-03-25.
//  Copyright (c) 2015 divyesh konkani. All rights reserved.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include<string.h>

//#define PileLength 3
void PrintSticks(int *l,int length);
void ComputerMove(int *l,int length);
void PlayerMove(int *ppiles,int length);
static int computercount=0;
int CheckWin(int *ppiles,int length);
int Random(int max);
int pause_sec(int x);
static int Win=0;
int main(int argc, const char * argv[])
{
    srand((unsigned)time(NULL));
    char ppiles[100];
    //int piles[PileLength]={4,3,5};
    printf("Enter your Pile :");
    scanf("%s",ppiles);
    
    int length=(unsigned)strlen(ppiles);
    //printf("length =%d\n",length);
    int piles[length];
    //free(piles);
    int n=0;
    for (int k=0; k<length; k++) {
        n=ppiles[k]-'0';
        piles[k]=n;
    }
   
    
    int *p;
    
    p=piles;

   PrintSticks(p,length);
    

   do {
       
        PlayerMove(p,length);
        PrintSticks(p,length);
        ComputerMove(p,length);
        PrintSticks(p,length);
       
       if(Win==1) break;
        //printf("\n%d\n",win);
        
   } while (1);
    printf("\nGame Over\n");
    return 0;
}

void PlayerMove(int *ppiles,int length)
{
    int from=0;
    int stick=0;
    printf("\nPlayer Turn : ");
    scanf("%d %d",&from,&stick);
    
    printf("From pile# %d , remove %d Stick \n",from,stick);
    
    if (from<=length) {
        from=from>0?from-1:from;
        int sticksinpile=*(ppiles+from);
        if (stick>sticksinpile) {
            printf("There are only %d sticks, you want %d\n",sticksinpile,stick);
            PlayerMove(ppiles,length);
        }
        *(ppiles+from)=*(ppiles+from)-stick;
    }
    Win=CheckWin(ppiles,length);
    
    if(Win==1){
        printf("Hurrray You win.");
    }
}


void PrintSticks(int *l,int length)
{
    
    for (int i=0; i<length; i++) {
        for (int j=*(l+i); j>0; j--) {
            printf("I");
        }
        printf("     ");
    }
    printf("\n");
}

void ComputerMove(int *l,int length)
{
    //Allow computer only when someone not Win/lost
    if(Win==0)
    {
        int selectPile =Random(length);
        
        if (*(l+selectPile)==0) {
           
            ComputerMove(l,length);
        }else
        {
           
            int removeStick=Random(*(l+selectPile));
            
            if (removeStick==0) {
                ++computercount;
                ComputerMove(l,length);
            }else {
            printf("Computer Turn :%d \n",(++computercount));
            printf("Selected pile# %d, Remove stick %d\n",selectPile+1, removeStick);
            *(l+selectPile)=*(l+selectPile)-removeStick;
            //printf("After %d\n", *(l+selectPile));
            Win=CheckWin(l,length);
            
            if(Win==1)
                printf("Computer win, you lost.");
            }
        }
    }
}

int CheckWin(int *l,int lenght)
{
    int zerostickcount=0;
    //printf("\nCheck win\n");
    for (int i=0; i<3; i++) {
        //printf("%d",*(l+i));
        if(*(l+i)==0)
        {
            ++zerostickcount;
        }
    }
    
    if(zerostickcount==lenght)
        return 1;
    return 0;
}

int Random(int max)
    {
       /* Seed is usually taken from the current time, which are the seconds, as in time(NULL), so if you always set the seed before taking the random number, you will get the same number as long as you call the srand/rand combo multiple times in the same second.
            
            To avoid this problem, srand is set only once per application, because it is doubtful that two of the application instances will be run in the same second, so each instance will then have a different sequence of random numbers.*/
        //srand((unsigned)time(NULL));
         pause_sec(1);
        int r =rand()%max;
        
        return r;
    }
int pause_sec(int x)
{
    /* In the program random number is generating corretly sometime, but some time crash.
     As we know random number are generated from time and our programme is very fast that it can loop more than 100,000
     times in mili second, so it will crash.
     We need to puse for a second and then generate, so we can get next available number
     */
    
    for (int t=0; t>1000*x; t++) {
        //continue;
    }
    return(x);
}
