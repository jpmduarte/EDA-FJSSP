#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct operacao
{
    int num;
    int maq;
    int time;
    struct operacao* next;
} node;


void removenode(int pos, node* head)
{
    FILE* fp;
    node* temp = head; 
    int i;
    if (pos == 0)
    {
        head = head->next; 
        temp->next = NULL;
        free(temp); 
    }
    else
    {
        for (i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        
        node* del = temp->next; 
        temp->next = temp->next->next;
        del->next = NULL;
        free(del); 
    }
}

void insertnode(node** head)
{
    node* newnode = (node*)malloc(sizeof(node));
    int num;
    int NumMaq;
    int numaux, i;
    int time;
    FILE* fp;
    fp = fopen("job.txt", "a+");
    system("cls");
    printf("Qual o numero da operacao?\n");
    scanf("%d", &num);
    newnode->num = num;
    fprintf(fp, "Operacao %d: ", num);
    printf("Qual o numero(s) da(s) maquina(s)?\n\ninsira um de cada vez no caso de multiplas maquinas\n");
    scanf("%d", &NumMaq);
    fprintf(fp, "(%d) ", NumMaq);
    newnode->maq = NumMaq;
    fprintf(fp, "\n             ");
    printf("Qual e o tempo da(s) maquina(s)?\n");
    scanf("%d", &time);
    newnode->time = time;
    fprintf(fp, "[%d] ", time);
    fprintf(fp, "\n ");
    if (*head == NULL) 
    {
        *head = newnode;
    }
    else
    {
        node* lastNode = *head;

      
        while (lastNode->next != NULL)
        {
            lastNode = lastNode->next;
        }

        
        lastNode->next = newnode;
    }
    system("cls");
}


void lerficheiro()
{
    char aux[150];
    FILE* fp;
    fp = fopen("job.txt", "r");
    if (fp == NULL) {
        printf("\nFicheiro vazio\n");
    }
    while (!feof(fp))
    {
        fgets(aux, 150, fp);
        puts(aux);
    }
    fclose(fp);
    printf("Any key to continue.");
    getchar();
    getchar();
}



void printlist(node* head)
{
    node* temp;    
    temp = head;          
    while (temp != NULL)
    {
        printf("operacao %d\n", temp->num);
        printf("(%d)", temp->maq);
        printf("[%d]", temp->time);
        printf("\n");
        temp = temp->next;
    }
    printf("\n");
}

int sizeoflist(node* node) {
    int size = 0;

    while (node != NULL) {
        node = node->next;
        size++;
    }
    return size;
}

void insertAfterNthNode(int n, node** head)
{
    int size = sizeoflist(*head);
    int num;
    int NumMaq;
    int time;
    node* newnode = (node*)malloc(sizeof(node));
    FILE* fp;
    fp = fopen("job.txt", "a");
    system("cls");
    printf("Qual o numero da operacao?\n");
    scanf("%d", &num);
    newnode->num = num;
    fprintf(fp, "Operacao %d: ", num);
    printf("Qual o numero(s) da(s) maquina(s)?\n");
    scanf("%d", &NumMaq);
    fprintf(fp, "(%d) ", NumMaq);
    newnode->maq = NumMaq;
    fprintf(fp, "\n             ");
    printf("Qual e o tempo da(s) maquina(s)?\n");
    scanf("%d", &time);
    newnode->time = time;
    fprintf(fp, "[%d] ", time);
    fprintf(fp, "\n ");
    newnode->next = NULL;

  
    if (n < 0 || n > size)
        printf("Erro\n");

    
    else if (n == 0) {
        newnode->next = *head;
        *head = newnode;
    }

    else
    {
        node* temp = *head;

   
        while (--n)
            temp = temp->next;

        
        newnode->next = temp->next;
       
        temp->next = newnode;
        
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
    node* head = NULL;
    int choice = 1;
    int x;
    do
    {
        menu();
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printlist(head);
            getchar();
            getchar();
            break;
        case 2:

            lerficheiro();
            getchar();
            getchar();
            break;
        case 3: remove("job.txt");
            getchar();
            getchar();
            break;
        case 4:
            insertnode(&head);
            getchar();
            getchar();
            break;
        case 5:
            printf("\nQue operacao deseja remover?\n");
            scanf("%d", &x);
            x = x + 1;
            removenode(x, head);
            getchar();
            getchar();
            break;
        case 6:printf("\nQue operacao deseja alterar\n");
            scanf("%d", &x);
            x = x - 1;
            removenode(x, head);
            insertAfterNthNode(x, &head);
            break;
        default:
            break;
        }
    } while (choice != 0);
}