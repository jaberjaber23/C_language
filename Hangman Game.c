#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include "foc_fa22.h"
void startGuessTheNumberGame();
void startHangmanGame();

int main()
{
    int choose;
    char name[25];
 printf("Enter your name :\t");
 scanf("%s", name);
 printf("\n Welcome %s! \n", name);
 do{
printf("Please enter the number of the game you wish to play, or choose Exit.\n");
printf("1. Guess the Number.\n");
printf("2. Hangman.\n");
printf("3. Exit.\n");
printf(">> \t");
scanf("%d", &choose);
if(choose <= 3 && choose > 0)
{
    switch(choose)
    {
case 1:
startGuessTheNumberGame();
break;

case 2:
startHangmanGame();
break;

default:
printf("The program has been exited !");
return 0;
break;
    }
}
else
{
    printf("Wrong entry!! Enter again\n");
}
 }while(choose < 3 || choose > 0);
    return 0;
}

void startGuessTheNumberGame()
{
    int usernum = 0 , choose, num_of_guesses = 0, low = 0 ,high = 10000, mid;
mid = (low + high)/2;
printf("\n***Welcome to guess the number game***\n");
printf("Enter a secret number between 1 and 10000 : ");
scanf("%d", &usernum);
do{
printf("My guess is : %d\n", mid);
printf("Please choose one of the following 3 options: \n");
printf("1. My guess is correct.\n");
printf("2. The secret number is larger than %d.\n", mid);
printf("3. The secret number is smaller than %d.\n >>", mid);
scanf("%d", &choose);
if(choose == 2)
{
    low = mid;
    mid = (low + high)/2;
}
else if(choose == 3)
{
    high = mid;
    mid = (low + high)/2;
}
else if(choose != 1)
{
    printf("Invalid choice!\n");
}
num_of_guesses++;
}while(choose != 1);
if(choose == 1)
   printf("End game :) \nNumber of guess = %d \n", num_of_guesses);
   num_of_guesses = num_of_guesses *10;
num_of_guesses = 150 - num_of_guesses;
int col[150][150];
for(int i = 0; i < 150; i++)
{
for(int j = 0; j < 150; j++)
{
col[i][j]=255;
if(j > 65 && j < 85 && i > num_of_guesses)
{
col[i][j]=0;
}
}
}
showArray(150,150,col);
printf("\nMain Menu:\n");
}

void startHangmanGame()
{
 FILE *food1;
 FILE *objects1;
 FILE *names1;
 FILE *colors1;
             food1 = fopen("food.txt","r");
             objects1 =fopen("objects.txt","r");
             colors1 = fopen("colors.txt","r");
             names1 =fopen("names.txt","r");
    int choose, random_num , num_of_characters, attempts = 5, letterguess[10]={0,0,0,0,0,0,0,0,0,0}, once, finish = 0, add = 0, test, one = 1, fir;
    char word[15], letter, test2[15];
    char *co_[15]={"_","_","_","_","_","_","_","_","_","_","_","_","_","_","_"};
    srand(time(0));
     printf("\n***Welcome to Hangman game***\n");
do{
printf("Choose a category: \n");
printf("1. Food.\n");
printf("2. Objects.\n");
printf("3. Names.\n");
printf("4. Colors.\n >> \t");
scanf("%d", &choose);
    if(choose > 4 || choose < 0)
    {
        printf("Invalid choice!!\n");
    }
}while(choose > 4 || choose < 0);
random_num = rand() % (15);
switch(choose)
{
case 1:
if(food1 == NULL)
  {
    printf("\nCannot open food.txt file ! \n");
    return;
  }
test = fscanf(food1, "%s ", test2);
while(test == 1)
{
if(random_num == add)
{
fscanf(food1, "%s ", word);
}
test = fscanf(food1, "%s ", test2);
add++;
}
        fclose(food1);
break;

case 2:
if(objects1 == NULL)
  {
    printf("\nCannot open objects.txt file ! \n");
    return;
  }
test = fscanf(objects1, "%s ", test2);
while(test == 1)
{
if(random_num == add)
{
fscanf(objects1, "%s ", word);
}
test = fscanf(objects1, "%s ", test2);
add++;
}
        fclose(objects1);
break;

case 3:
if(names1 == NULL)
  {
    printf("\nCannot open names.txt file ! \n");
    return;
  }
test = fscanf(names1, "%s ", test2);
while(test == 1)
{
if(random_num == add)
{
fscanf(names1, "%s ", word);
}
test = fscanf(names1, "%s ", test2);
add++;
}
        fclose(names1);
break;

case 4:
if(colors1 == NULL)
  {
    printf("\nCannot open colors.txt file ! \n");
    return;
  }
test = fscanf(colors1, "%s ", test2);
while(test == 1)
{
if(random_num == add)
{
fscanf(colors1, "%s ", word);
}
test = fscanf(colors1, "%s ", test2);
add++;
}
        fclose(colors1);
break;

default:
printf("Erorr!");
break;
}
printf("For test! The word is... %s \n", word);
num_of_characters = strlen(word);
while(attempts != 0)
{
 printf("The word so far is: ");
    for(int j = 0; j < num_of_characters; j++)
    {
        if(letterguess[j]==1)
        {
            printf(" %c", word[j]);
        }
        else
        {
            printf(" %s", co_[j]);
        }
    }
 printf(". \nYou have %d remaining attempts.\n", attempts);
 printf("Enter the letter:\n>>\t");
 scanf(" %c",&letter);
            once = 0;
            one = 1;
            fir = 0;
    for(int i = 0; i < num_of_characters; i++)
    {
        if(letter == word[i] && letterguess[i] != 1)
        {
            letterguess[i]=1;
            if(one == 1)
            {
            printf("Correct! Keep going!\n");
             finish++;
             one++;
            }
             once = i;
             fir  = 1;
        }
    }
        if(letterguess[once] == 0 || fir == 0)
        {
            printf("Not quite! Try again!\n");
            attempts--;

        }
        if(finish == num_of_characters)
        {
            break;
        }
  }
  if(attempts > 0)
  {
       printf("Congratulations! You find the word!\n\n");
  }
  else
  {
       printf("Hard luck! you were not able to find the word. :(\n\n");
  }
  
}

