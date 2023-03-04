#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char player1[20], player2[20];
    int coins1 = 200, coins2 = 200, bet1, bet2, guess1, guess2, random_num, winner;
    srand(time(NULL));
    printf("Welcome to the Betting Game!\nRules:\n1.Both the players have 200 coins in the starting\n2.The players will bet from the amount of coins they have\n3.After betting the users will guess a number from 1-100\n4.The player having the closest to the Number generated wins the Round\n5.Winner of Each round will get an advantage to play first in the next round\n\n");
    printf("Enter name of player 1: ");
    scanf("%s", player1);
    printf("Enter name of player 2: ");
    scanf("%s", player2);

    while (coins1 > 0 && coins2 > 0) {
        printf("%s, you have %d coins. Enter your bet: ", player1, coins1);
        scanf("%d", &bet1);
        coins1 -= bet1;

        printf("%s, you have %d coins. Enter your bet: ", player2, coins2);
        scanf("%d", &bet2);
        coins2 -= bet2;

        int turn = rand() % 2;
        if (turn == 0) {
            printf("%s goes first.\n", player1);
        } else {
            printf("%s goes first.\n", player2);
        }

        random_num = rand() % 100 + 1;
      

        if (turn == 0) {
            printf("%s, enter your guess: ", player1);
            scanf("%d", &guess1);

            printf("%s, enter your guess: ", player2);
            scanf("%d", &guess2);

            if (abs(guess1 - random_num) < abs(guess2 - random_num)) {
                  printf("THE NUMBER WAS................  %d.\n", random_num);
                printf("%s wins the round!\n", player1);
                coins1 += (bet1 + bet2);
                winner = 1;
            } else if (abs(guess2 - random_num) < abs(guess1 - random_num)) {
                  printf("THE NUMBER WAS................  %d.\n", random_num);
                printf("%s wins the round!\n", player2);
                coins2 += (bet1 + bet2);
                winner = 2;
            } else {
                  printf("THE NUMBER WAS................  %d.\n", random_num);
                printf("It's a draw!\n");
                coins1 += bet1;
                coins2 += bet2;
                winner = 0;
            }
        } else {
            printf("%s, enter your guess: ", player2);
            scanf("%d", &guess2);

            printf("%s, enter your guess: ", player1);
            scanf("%d", &guess1);

            if (abs(guess2 - random_num) < abs(guess1 - random_num)) {
                  printf("THE NUMBER WAS................  %d.\n", random_num);
                printf("%s wins the round!\n", player2);
                coins2 += (bet1 + bet2);
                winner = 2;
            } else if (abs(guess1 - random_num) < abs(guess2 - random_num)) {
                  printf("THE NUMBER WAS................  %d.\n", random_num);
                printf("%s wins the round!\n", player1);
                coins1 += (bet1 + bet2);
                winner = 1;
            } else {
                  printf("THE NUMBER WAS................  %d.\n", random_num);
                printf("It's a draw!\n");
                coins1 += bet1;
                coins2 += bet2;
                winner = 0;
            }
        }

        if (winner == 1) {
            printf("%s, it's your turn to bet and guess.\n", player1);
        } else if (winner == 2) {
            printf("%s, it's your turn to bet and guess.\n", player2);
        }
    }

     // Determine winner of the game
    if (coins1 == 0)
    {
        printf("\n%s has no coins left. %s wins the game!", player1, player2);
    }
    else
    {
        printf("\n%s has no coins left. %s wins the game!", player2, player1);
    }

    return 0;
}

