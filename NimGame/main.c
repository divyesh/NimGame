//
//  main.c
//  NimGame
//
//  Created by divyesh konkani on 2015-03-25.
//  Copyright (c) 2015 divyesh konkani. All rights reserved.
//

#include <stdio.h>
#include <time.h>
#include "stdlib.h"
#include<string.h>
//#define PileLength 3
void PrintSticks(int *l,int length);
void ComputerMove(int *l,int length);
void PlayerMove(int *ppiles,int length);
static computercount=0;
void CheclWin(int *ppiles,int length);

void main(int argc, const char * argv[])
{
    srand((unsigned)time(NULL));
    char ppiles[100];
    //int piles[PileLength]={4,3,5};
    printf("Enter your Pile :");
    scanf("%s",ppiles);
    
    int length=strlen(ppiles);
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
     //printf("\n %d \n",sizeof(*p));
   PrintSticks(p,length);
    
    int win=1;
   do {
       
        PlayerMove(p,length);
        PrintSticks(p,length);
        ComputerMove(p,length);
        PrintSticks(p,length);
       
        
        //printf("\n%d\n",win);
        
   } while (1);
    
    //return 0;
}

void PlayerMove(int *ppiles,int length)
{
    int from=0;
    int stick=0;
    printf("\nPlayer Turn : ");
    scanf("%d %d",&from,&stick);
    
    printf("From pile# %d , remove %d Stick \n",from,stick);
    
    if (from<length) {
        from=from>0?from-1:from;
        int sticksinpile=*(ppiles+from);
        if (stick>sticksinpile) {
            printf("There are only %d sticks, you want %d\n",sticksinpile,stick);
            PlayerMove(ppiles,length);
        }
        *(ppiles+from)=*(ppiles+from)-stick;
    }
    int win=CheckWin(ppiles,length);
    
    if(win==1)
        printf("Hurrray You win.");
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
    
    int selectPile =Random(length);

    if (*(l+selectPile)==0) {
        ComputerMove(l,length);
    }else
    {
        printf("Computer Turn :%d \n",(++computercount));
        int removeStick=Random(*(l+selectPile));
        if (removeStick==0) {
            ComputerMove(l,length);
        }
        printf("Selected pile# %d, Remove stick %d\n",selectPile, removeStick);
        *(l+selectPile)=*(l+selectPile)-removeStick;
        //printf("After %d\n", *(l+selectPile));
        int win=CheckWin(l,length);
        
        if(win==1)
            printf("Computer win, you lost.");
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
        srand((unsigned)time(NULL));
        int r =rand()%max;
        //printf("\nRandom# %d\n",r);
        //if(r==0) return Random(max);
        return r;
    }

