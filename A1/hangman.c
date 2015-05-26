/*
 * ASSIGNMENT:  CIS*1500  Assignment  Number 5
 * Author: Nathan Reymer
 * Date Created: November 3rd
 * Date Modified: November 21st
 * DESCRIPTION:
 * This program plays the game of Hangman. Letters are input to guess a word
 * KNOWN  BUGS: Weird spacing after 7 characters, set it to the limit anyways
 */
//Function prototype
void drawhang();
void drawnoose();
//Declare Libraries
#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main(void) {
    //Declare variables
    int x = 0;
    int glen = 0;
    int tries = 0;
    int round = 0;
    int ground = 0;
    char hword[400] = {""};
    char guessed[100] = "";
    int r = 0;
    //Bank of random words
    char random[21][8] = {"alumni", "pencil", "button", "leaves", "claude", "piano", "alison", "foxy",
        "table", "weekend", "stupid", "sock", "earth", "love",
        "lamp", "brick", "delight", "classy", "vitamin", "racecar"};
    int corr = 0;
    char choice;
    char word[200] = "";
    char ch[100] = "";
    int letters = 0;
    char guess;
    int len;
    //Get random number
    srand(time(NULL));
    r = (rand() % 20) + 1;

    printf("Welcome to Nathan Reymer's: \n");
    //Print ASCI art
    drawhang();
    printf(" \n");
    printf(" \n");
    //Give player a choice on how to play
    printf("Do you want to randomly select a word, or enter one? \n");
    printf("1. For random 2. For Manual \n");
    //Get players choice
    scanf("%c%*c", &choice);
    //Choice 1 is from random word bank
    if (choice == '1') {
        strcat(word, random[r]);
        len = strlen(word);
        letters = len;
    } else {
        //Other is create your own
        printf("Enter a lowercase word (Max 7 Characters) \n");
        fgets(word, 20, stdin);
        len = strlen(word);
        letters = len - 1;
        //Take input work
        //Check to see if under 7 letters
        while (x != 99) {
            if (letters >= 8) {
                printf("Try that again, you have %d letters \n", len - 1);
                fgets(word, 20, stdin);
                len = strlen(word);
                letters = len - 1;

            } else if (letters <= 7) {
                break;
            }
        }
        len = strlen(word);
        letters = len - 1;
        //Convert input to lowercase
        for (x = 0; word[x] != '\0'; x++) {
            word[x] = (char) tolower(word[x]);
        }
    }
    x = 0;
    //Draw blank spaces for guesses
    while (x != letters) {
        strcat(&hword[x], "_");
        strcat(hword, " ");
        x++;
    }
    printf(" \n");
    x = 0;
    tries = 0;
    //Display blank word _
    printf("%s \n", hword);

    //Draw graphical representation of bad guesses
    drawnoose(tries);
    printf(" \n");

    //Start the game
    printf("You have guessed %d wrong letters! \n", tries);
    printf("What is the next letter?: ");
    //Start main loop
    while (x != 99) {
        //Set counters for string check to default
        round = 0;
        ground = 0;
        x = 0;
        //Get single character
        guess = getchar();
        while (getchar() != '\n');
        while (isupper(guess)) {
            if (isupper(guess)) {
                printf("Thats uppercase, please put in lowercase \n");
                printf("What is the next letter?: ");
                guess = getchar();
                while (getchar() != '\n');
            } else {
            }
        }
        //Check to see if character is letter
        while (x != 99) {
            if (isalpha((int) (guess))) {
                break;
                //If character is not a letter, check again
            } else {
                printf("Thats not a letter! \n");
                printf("What is the next letter?: ");
                guess = getchar();
                while (getchar() != '\n');
            }
        }
        //Check to see if letter has already been guessed
        for (x = 0; x < glen; x++) {
            if (guess == guessed[x]) {
                ground++;
            }
        }
        //Forgive the player, doesn't count as another try
        if (ground >= 1) {
            guess = ch[1];
            printf("You guessed that already! \n");
            tries--;
        } else {

            //Do Nothing
        }
        //Copy guess to guessed array
        strcat(guessed, &guess);
        //Get length of guessed array for loop
        glen = strlen(guessed);
        //Set loop values back to 0
        ground = 0;
        round = 0;
        x = 0;
        //Check to see if guess is in word
        for (x = 0; x < letters; x++) {
            if (guess == word[x]) {
                //Add letter to blank word
                hword[x * 2] = guess;
                corr++;
                //Added for multiple same letters
                round++;
            }
        }
        //If not in the word, fail
        if (round == 0) {
            tries++;
        }
        //If not in the word, and it has checked all of the word, fail
        if (round >= 0 && guess != word[x] && x == letters - 1) {
            tries++;
        }
        x = 0;
        //Display stats
        printf("Guessed: %s \n", guessed);
        printf(" \n");
        printf("%s \n", hword);
        printf(" \n");
        //End game is word is guessed
        if (corr == letters) {
            printf("You guessed the word! Congrats! \n");
            printf("The word was: ");
            printf("%s", word);
            printf(" \n");
            drawhang();
            break;
        }
        //End game is wrong guesses are 10
        if (tries == 10) {
            printf("You failed, the word was: ");
            printf("%s", word);
            drawhang();
            break;
        }
        //Drawings or fail #
        //Draw noose for tries
        drawnoose(tries);
        //Display prompt again
        printf(" \n");
        printf("You have guessed %d wrong letters! \n", tries);
        printf("What is the next letter?: ");
    }
    return 0;
}
//ASCI Art for Start/Finish
//Generated characters from a website
//enter printf and align manually

void drawhang() {
    printf(" \n");
    printf("$$ |  $$ | \n");
    printf("$$ |  $$ | $$$$$$\\  $$$$$$$\\   $$$$$$\\  $$$$$$\\$$$$\\   $$$$$$\\  $$$$$$$\\ \n");
    printf("$$$$$$$$ | \\____$$\\ $$  __$$\\ $$  __$$\\ $$  _$$  _$$\\  \\____$$\\ $$  __$$\\ \n");
    printf("$$  __$$ | $$$$$$$ |$$ |  $$ |$$ /  $$ |$$ / $$ / $$ | $$$$$$$ |$$ |  $$ | \n");
    printf("$$ |  $$ |$$  __$$ |$$ |  $$ |$$ |  $$ |$$ | $$ | $$ |$$  __$$ |$$ |  $$ | \n");
    printf("$$ |  $$ |\\$$$$$$$ |$$ |  $$ |\\$$$$$$$ |$$ | $$ | $$ |\\$$$$$$$ |$$ |  $$ | \n");
    printf("\\__|  \\__| \\_______|\\__|  \\__| \\____$$ |\\__| \\__| \\__| \\_______|\\__|  \\__| \n");
    printf("                              $$\\   $$ |   \n");
    printf("                              \\$$$$$$  | \n");
    printf("                               \\______/ \n");
}
//Graphical state of bad guesses

void drawnoose(int tries) {
    switch (tries) {
        case 0:
            printf("\n");
            printf("    _______ \n");
            printf("  |/      | \n");
            printf("  |\n");
            printf("  |\n");
            printf("  |\n");
            printf("  |\n");
            printf("  |\n");
            printf("__|__\n");
            break;
        case 1:
            printf("\n");
            printf("    _______ \n");
            printf("  |/      | \n");
            printf("  |      (\n");
            printf("  |\n");
            printf("  |\n");
            printf("  |\n");
            printf("  |\n");
            printf("__|__\n");
            break;
        case 2:
            printf("\n");
            printf("    _______ \n");
            printf("  |/      | \n");
            printf("  |      (_\n");
            printf("  |\n");
            printf("  |\n");
            printf("  |\n");
            printf("  |\n");
            printf("__|__\n");
            break;
        case 3:
            printf("\n");
            printf("    _______ \n");
            printf("  |/      | \n");
            printf("  |      (_)\n");
            printf("  |\n");
            printf("  |\n");
            printf("  |\n");
            printf("  |\n");
            printf("__|__\n");
            break;
        case 4:
            printf("\n");
            printf("    _______ \n");
            printf("  |/      | \n");
            printf("  |      (_)\n");
            printf("  |       |\n");
            printf("  |\n");
            printf("  |\n");
            printf("  |\n");
            printf("__|__\n");
            break;
        case 5:
            printf("\n");
            printf("    _______ \n");
            printf("  |/      | \n");
            printf("  |      (_)\n");
            printf("  |       | \n");
            printf("  |       | \n");
            printf("  |\n");
            printf("  |\n");
            printf("__|__\n");
            break;
        case 6:
            printf("\n");
            printf("    _______ \n");
            printf("  |/      | \n");
            printf("  |      (_)\n");
            printf("  |       | \n");
            printf("  |       | \n");
            printf("  |      /  \n");
            printf("  |\n");
            printf("__|__\n");
            break;
        case 7:
            printf("\n");
            printf("    _______ \n");
            printf("  |/      | \n");
            printf("  |      (_)\n");
            printf("  |       | \n");
            printf("  |       | \n");
            printf("  |      / \\ \n");
            printf("  |\n");
            printf("__|__\n");
            break;
        case 8:
            printf("\n");
            printf("    _______ \n");
            printf("  |/      | \n");
            printf("  |      (_)\n");
            printf("  |      /| \n");
            printf("  |       | \n");
            printf("  |      / \\  \n");
            printf("  |\n");
            printf("__|__\n");
            break;
        case 9:
            printf("\n");
            printf("    _______ \n");
            printf("  |/      | \n");
            printf("  |      (_)\n");
            printf("  |      /|\\ \n");
            printf("  |       | \n");
            printf("  |      / \\ \n");
            printf("  |\n");
            printf("__|__\n");
            break;
    }
}
