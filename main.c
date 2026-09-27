#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct QuestionNode
{
    int q_no;
    char questions[100];
    char options[4][30];
    char correct_option;
    struct QuestionNode *next;
} QuestionNode;

typedef struct ResponseNode
{
    int q_no;
    char correct_option;
    char user_option;
    int points_earned;
    struct ResponseNode *next;
} ResponseNode;

QuestionNode *start1 = NULL;
ResponseNode *start2 = NULL;

void insertQuestion()
{
    QuestionNode *ptr1 = (QuestionNode *)malloc(sizeof(QuestionNode));
    if (ptr1 == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    printf("Enter Question number: ");
    scanf("%d", &ptr1->q_no);
    getchar();

    printf("Enter Question: ");
    fgets(ptr1->questions, 100, stdin);

    ptr1->questions[strcspn(ptr1->questions, "\n")] = '\0';

    printf("Enter option A: ");
    fgets(ptr1->options[0], 30, stdin);
    ptr1->options[0][strcspn(ptr1->options[0], "\n")] = '\0';

    printf("Enter option B: ");
    fgets(ptr1->options[1], 30, stdin);
    ptr1->options[1][strcspn(ptr1->options[1], "\n")] = '\0';

    printf("Enter option C: ");
    fgets(ptr1->options[2], 30, stdin);
    ptr1->options[2][strcspn(ptr1->options[2], "\n")] = '\0';

    printf("Enter option D: ");
    fgets(ptr1->options[3], 30, stdin);
    ptr1->options[3][strcspn(ptr1->options[3], "\n")] = '\0';

    printf("Enter Correct option: ");
    scanf("%c", &ptr1->correct_option);
    getchar();
    ptr1->correct_option = toupper(ptr1->correct_option);
    ptr1->next = NULL;

    if (start1 == NULL)
    {
        start1 = ptr1;
    }
    else
    {
        QuestionNode *temp1 = start1;
        while (temp1->next != NULL)
        {
            temp1 = temp1->next;
        }
        temp1->next = ptr1;
    }
}

void takequiz()
{
    QuestionNode *temp1 = start1;
    int points_earned, current_score = 0;

    while (temp1 != NULL)
    {
        printf("\nQuestion No: %d\n", temp1->q_no);
        printf("%s\n", temp1->questions);
        printf("A. %s\n", temp1->options[0]);
        printf("B. %s\n", temp1->options[1]);
        printf("C. %s\n", temp1->options[2]);
        printf("D. %s\n", temp1->options[3]);
        printf("Enter your answer: ");

        char answer;
        scanf(" %c", &answer);
        getchar();
        answer = toupper(answer);

        ResponseNode *ptr2 = (ResponseNode *)malloc(sizeof(ResponseNode));
        if (ptr2 == NULL)
        {
            printf("Memory allocation failed!\n");
            exit(1);
        }

        ptr2->q_no = temp1->q_no;
        ptr2->correct_option = temp1->correct_option;
        ptr2->user_option = answer;
        ptr2->next = NULL;

        if (answer == temp1->correct_option)
        {
            printf("STATUS: CORRECT\n");
            points_earned = 1;
            current_score++;
        }
        else
        {
            printf("STATUS: INCORRECT\n");
            points_earned = 0;
        }

        ptr2->points_earned = points_earned;

        if (start2 == NULL)
        {
            start2 = ptr2;
        }
        else
        {
            ResponseNode *temp2 = start2;
            while (temp2->next != NULL)
            {
                temp2 = temp2->next;
            }
            temp2->next = ptr2;
        }

        temp1 = temp1->next;
    }

    printf("\n\n==========================================================================\n");
    printf(" FINAL PERFORMANCE REPORT\n");
    printf("==========================================================================\n\n");

    // Print table header
    printf("%-10s %-10s %-12s %-15s %-8s\n", "Q.No.", "Correct", "Your Ans", "Status", "Points");
    printf("--------------------------------------------------------------------------\n");

    ResponseNode *temp2 = start2;
    while (temp2 != NULL)
    {
        const char *status = (temp2->points_earned == 1) ? "CORRECT" : "WRONG";
        printf("%-10d %-10c %-12c %-15s %-8d\n",
               temp2->q_no,
               temp2->correct_option,
               temp2->user_option,
               status,
               temp2->points_earned);
        temp2 = temp2->next;
    }

    printf("--------------------------------------------------------------------------\n");
    printf("\nTOTAL SCORE : %d\n", current_score);
    printf("==========================================================================\n");
}

// Function to free allocated memory
void freeMemory()
{
    QuestionNode *temp1 = start1;
    while (temp1 != NULL)
    {
        QuestionNode *toFree = temp1;
        temp1 = temp1->next;
        free(toFree);
    }

    ResponseNode *temp2 = start2;
    while (temp2 != NULL)
    {
        ResponseNode *toFree = temp2;
        temp2 = temp2->next;
        free(toFree);
    }
}

int main()
{
    int n;
    printf("Enter number of questions: ");
    scanf("%d", &n);
    getchar(); // Consume newline

    for (int i = 0; i < n; i++)
    {
        insertQuestion();
    }

    takequiz();
    freeMemory();
    return 0;
}