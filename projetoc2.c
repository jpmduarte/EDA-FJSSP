#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct operacao
{
    int num;
    int nummaqavail;
    int maq;
    int time;
    struct operacao *next;
} node;

node *head = NULL;
node *tail = NULL;

void *removenode(int pos)
{
    FILE *infile;
    node *temp = head; // Creating a temporary variable pointing to head
    int i;
    if (pos == 0)
    {
        head = head->next; // Advancing the head pointer
        temp->next = NULL;
        free(temp); // Node is deleted
    }
    else
    {
        for (i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        // Now temp pointer points to the previous node of the node to be deleted
        node *del = temp->next; // del pointer points to the node to be deleted
        temp->next = temp->next->next;
        del->next = NULL;
        free(del); // Node is deleted
    }
}

void *insertnode()
{
    node *newnode = malloc(sizeof(node));
    node *tail = head;
    int num;
    int NumMaq;
    int numaux, i;
    int time;
    FILE *infile;
    infile = fopen("Operacao.txt", "a+");
    system("cls");
    printf("Qual o numero da operacao?\n");
    scanf("%d", &num);
    newnode->num = num;
    fprintf(infile, "Operacao %d: ", num);
    newnode->nummaqavail = numaux;
    printf("Qual o numero(s) da(s) maquina(s)?\n\ninsira um de cada vez no caso de multiplas maquinas\n");
    scanf("%d", &NumMaq);
    fprintf(infile, "(%d) ", NumMaq);
    newnode->maq = NumMaq;
    fprintf(infile, "\n             ");
    printf("Qual e o tempo da(s) maquina(s)?\n");
    scanf("%d", &time);
    newnode->time = time;
    fprintf(infile, "[%d] ", time);
    fprintf(infile, "\n ");
    newnode->next = NULL;
    if (head == NULL) // Checking if List is empty
    {
        head = newnode;
        tail = newnode;
    }
    else // If not empty then...
    {
        tail->next = newnode;
        tail = newnode; // Updating the tail node with each insertion
    }
    system("cls");
}

void lerficheiro()
{
    char ler[150];
    FILE *infile;
    infile = fopen("Operacao.txt", "r");
    if (sizeof(infile) == 0)
    {
        printf("\nficheiro vazio");
    }
    while (!feof(infile))
    {
        fgets(ler, 150, infile);
        puts(ler);
    }
    fclose(infile);

    printf("Any key to continue.");
    getchar();
    getchar();
}

void printlist()
{
    int i = 0;
    node *tmp = head;
    int aux = tmp->nummaqavail;
    while (tmp != NULL)
    {
        printf("operacao %d\n", tmp->num);
        printf("(%d)", tmp->maq);
        printf("[%d]", tmp->time);
        printf("\n");
        tmp = tmp->next;
    }
}

void menu()
{
    printf("*********************************************\n");
    printf("*                  FJSSP                    *\n");
    printf("*********************************************\n");
    printf("*  1 - listar o job atual                   *\n");
    printf("*  2 - ler o ficheiro                       *\n");
    printf("*  3 - apagar ficheiro                      *\n");
    printf("*  4 - inserir  operacao                    *\n");
    printf("*  5 - remover  operacao                    *\n");
    printf("*  6 - alterar  operacao                    *\n");
    printf("*  7 - Calculo do tempo minimo              *\n");
    printf("*  8 - Calculo do tempo maximo              *\n");
    printf("*  0 - sair                                 *\n");
    printf("*********************************************\n");
}

int main()
{
    int choice = 1;
    int x;
    do
    {
        menu();
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printlist();
            break;
        case 2:
            lerficheiro();
            break;
        case 3:
            break;
        case 4:
            insertnode();
            break;
        case 5:
            printf("\nQue operacao deseja remover?\n");
            scanf("%d", &x);
            removenode(x);
            break;
        case 6:

            break;
        default:
            break;
        }
    } while (choice != 0);
}