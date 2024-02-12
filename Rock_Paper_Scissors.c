/**
 * @file Rock_Paper_Scissors.c
 * @author Rachit Mittal
 * @date 2022-07-26
 */
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

// Function to check whether a string is in array of string or not.
int In(char (*arr)[10], char *choice, int len)
{
    for (int i = 0; i < len; i++)
    {
        if (strcmp(*(arr + i), choice) == 0)
        {
            return 1;
        }
    }
    return 0;
}

// Function to ask whether user wants to play further or not
int play_fwd()
{
    int fwd;
    fflush(stdin);
    printf("Would You Like to play further?(0 for No/ 1 for Yes): ");
    scanf("%d", &fwd);
    return fwd;
}

// Main Function
int main()
{
    char choice[10], choices[3][10], comp_choice[10];
    int cont_fwd = 1;
    strcpy(choices[0], "Rock");
    strcpy(choices[1], "Paper");
    strcpy(choices[2], "Scissor");

    printf("!!!Welcome!!!\n");

    do
    {
        // Generate Random Choice for Computer
        srand(time(NULL));
        int index = rand() % 3;
        strcpy(comp_choice, choices[index]);

        fflush(stdin);
        printf("Enter Your Choice: ");
        scanf("%s", choice);

        // Checking whether user had entered correct Input or Not
        if (In(choices, choice, 3) == 0)
        {
            printf("Wrong Input\n");
            continue;
        }

        // Game Conditions
        if (strcmp(choice, "Rock") && strcmp(comp_choice, "Paper"))
        {
            printf("Lose\n");
        }
        else if (strcmp(choice, "Rock") && strcmp(comp_choice, "Scissor"))
        {
            printf("Win\n");
        }
        else if (strcmp(choice, "Scissor") && strcmp(comp_choice, "Paper"))
        {
            printf("Win\n");
        }
        else if (strcmp(choice, "Scissor") && strcmp(comp_choice, "Rock"))
        {
            printf("Lose\n");
        }
        else if (strcmp(choice, "Paper") && strcmp(comp_choice, "Rock"))
        {
            printf("Win\n");
        }
        else if (strcmp(choice, "Paper") && strcmp(comp_choice, "Scissor"))
        {
            printf("Lose\n");
        }
        else
        {
            printf("Draw\n");
        }
        cont_fwd = play_fwd();
    } while (cont_fwd == 1);

    return 0;
}