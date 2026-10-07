#include "student.h"

void addRecord(SLL **ptr)
{
    SLL *new, *pos, *temp;
    int roll = 1;

    new = malloc(sizeof(SLL));

    if(new == 0)
    {
        printf("Memory allocation failed\n");
        return;
    }

    while(1)
    {
        temp = *ptr;

        while(temp && temp->rollno != roll)
            temp = temp->next;

        if(temp == 0)
            break;

        roll++;
    }

    new->rollno = roll;

    printf("Enter name and percentage: ");
    scanf("%s %f", new->name, &new->percentage);

    if(new->percentage < 0 || new->percentage > 100)
    {
        printf("Invalid percentage\n");
        free(new);
        return;
    }

    if(*ptr == 0)
    {
        new->next = 0;
        *ptr = new;
    }
    else
    {
        pos = *ptr;

        while(pos->next != 0)
            pos = pos->next;

        new->next = 0;
        pos->next = new;
    }

    printf("Record added successfully\n");
}


void deleteNode(SLL **ptr)
{
    SLL *del, *prev;
    char ch;
    int roll;
    char name[50];

    if(*ptr == 0)
    {
        printf("No student records available\n");
        return;
    }

    printf("R/r : Delete by roll number\n");
    printf("N/n : Delete by name\n");
    scanf(" %c", &ch);

    if(ch == 'R' || ch == 'r')
    {
        printf("Enter roll number: ");
        scanf("%d", &roll);
    }
    else if(ch == 'N' || ch == 'n')
    {
        printf("Enter name: ");
        scanf("%s", name);

        del = *ptr;

        while(del)
        {
            if(strcmp(del->name, name) == 0)
                printf("Roll No: %d  Name: %s  Percentage: %f\n",del->rollno, del->name, del->percentage);

            del = del->next;
        }

        printf("Enter roll number to delete: ");
        scanf("%d", &roll);
 }
    else
    {
        printf("Invalid choice\n");
        return;
    }

    del = *ptr;
    prev = 0;

    while(del && del->rollno != roll)
    {
        prev = del;
        del = del->next;
    }

    if(del == 0)
    {
        printf("Record not found\n");
        return;
    }

    if(prev == 0)
        *ptr = del->next;
    else
        prev->next = del->next;

    free(del);

    printf("Record deleted successfully\n");
}
void printNode(SLL *ptr)
{
    if(ptr == 0)
    {
        printf("No student records available\n");
        return;
    }

    printf("\n---------------------------------------------\n");
    printf("Roll No\tName\t\tPercentage\n");
    printf("---------------------------------------------\n");

    while(ptr)
    {
        printf("%d\t%s\t\t%f\n",
               ptr->rollno, ptr->name, ptr->percentage);

        ptr = ptr->next;
    }

    printf("---------------------------------------------\n");
}
void modifyNode(SLL *ptr)
{
    SLL *temp;
    char ch, name[50];
    int roll;
    float percentage;

    if(ptr == 0)
    {
        printf("No student records available\n");
        return;
    }

    printf("R/r : Search by roll number\n");
    printf("N/n : Search by name\n");
    printf("P/p : Search by percentage\n");
    printf("Enter your choice: ");
    scanf(" %c", &ch);

    if(ch == 'R' || ch == 'r')
    {
        printf("Enter roll number: ");
        scanf("%d", &roll);
    }
    else if(ch == 'N' || ch == 'n')
    {
        printf("Enter name: ");
        scanf("%s", name);

        temp = ptr;
        while(temp)
        {
            if(strcmp(temp->name, name) == 0)
                printf("Roll No: %d  Name: %s  Percentage: %f\n",
                       temp->rollno, temp->name, temp->percentage);

            temp = temp->next;
        }

        printf("Enter roll number to modify: ");
        scanf("%d", &roll);
    }else if(ch == 'P' || ch == 'p')
    {
        printf("Enter percentage: ");
        scanf("%f", &percentage);

        temp = ptr;
        while(temp)
        {
            if(temp->percentage == percentage)
                printf("Roll No: %d  Name: %s  Percentage: %f\n",
                       temp->rollno, temp->name, temp->percentage);

            temp = temp->next;
        }

        printf("Enter roll number to modify: ");
        scanf("%d", &roll);
    }
    else
    {
        printf("Invalid choice\n");
        return;
    }

    temp = ptr;

    while(temp && temp->rollno != roll)
        temp = temp->next;

    if(temp == 0)
    {
        printf("Record not found\n");
        return;
    }
    printf("Enter new name and percentage: ");
    scanf("%s %f", temp->name, &temp->percentage);

    if(temp->percentage < 0 || temp->percentage > 100)
    {
        printf("Invalid percentage\n");
        return;
} 
printf("Record modified successfully\n");
}


void saveFile(SLL *ptr)
{
    FILE *fp;

    fp = fopen("student.dat", "w");

    if(fp == 0)
    {
        printf("File opening failed\n");
        return;
    }

    while(ptr)
    {
        fprintf(fp, "%d %s %f\n",
                ptr->rollno, ptr->name, ptr->percentage);

        ptr = ptr->next;
    }

    fclose(fp);

    printf("Records saved successfully\n");
}
void readFile(SLL **ptr)
{
    FILE *fp;
    SLL *new, *last = 0;

    fp = fopen("student.dat", "r");

    if(fp == 0)
        return;

    while(1)
    {
        new = malloc(sizeof(SLL));

        if(new == 0)
            break;

        if(fscanf(fp, "%d %s %f",
                  &new->rollno, new->name, &new->percentage) != 3)
        {
            free(new);
            break;
        }

        new->next = 0;

        if(*ptr == 0)
            *ptr = new;
        else
            last->next = new;

        last = new;
    }

    fclose(fp);
}
void deleteAll(SLL **ptr)
{
    SLL *del;

    while(*ptr)
    {
        del = *ptr;
        *ptr = (*ptr)->next;
        free(del);
    }

    printf("All records deleted successfully\n");
}
void reverseLinks(SLL **ptr)
{
    SLL *t = *ptr, *temp;
    SLL **a;
    int c = 0, i;

    if(*ptr == 0)
    {
        printf("No records found\n");
        return;
    }

    while(t)
    {
        c++;
        t = t->next;
    }

    a = malloc(sizeof(SLL *) * c);

    t = *ptr;

    for(i = 0; i < c; i++)
    {
        a[i] = t;
        t = t->next;
    }

    for(i = c - 1; i > 0; i--)
        a[i]->next = a[i - 1];

    a[0]->next = 0;

    *ptr = a[c - 1];

    free(a);

    printf("List reversed successfully\n");
}


void sortData(SLL *ptr)
{
    if(ptr == 0)
    {
        printf("No records found\n");
        return;
    }

    SLL *p1 = ptr, *p2, t;
    int i, j, c = 0;
    char ch;

    while(ptr)
    {
        c++;
        ptr = ptr->next;
    }

    printf("N/n : Sort by name\n");
    printf("P/p : Sort by percentage\n");
    printf("Enter your choice: ");
    scanf(" %c", &ch);

    for(i = 0; i < c - 1; i++)
    {
        p2 = p1->next;

        for(j = 0; j < c - 1 - i; j++)
        {
            if((ch == 'N' || ch == 'n') &&
               strcmp(p1->name, p2->name) > 0)
            {
                t.rollno = p1->rollno;
                strcpy(t.name, p1->name);
                t.percentage = p1->percentage;

                p1->rollno = p2->rollno;
                strcpy(p1->name, p2->name);
                p1->percentage = p2->percentage;

                p2->rollno = t.rollno;strcpy(p2->name, t.name);
                p2->percentage = t.percentage;
            }

            if((ch == 'P' || ch == 'p') &&
               p1->percentage < p2->percentage)
            {
                t.rollno = p1->rollno;
                strcpy(t.name, p1->name);
                t.percentage = p1->percentage;

                p1->rollno = p2->rollno;
                strcpy(p1->name, p2->name);
                p1->percentage = p2->percentage;

                p2->rollno = t.rollno;
                strcpy(p2->name, t.name);
                p2->percentage = t.percentage;
            }

            p2 = p2->next;
        }

        p1 = p1->next;
    }

    if(ch == 'N' || ch == 'n' || ch == 'P' || ch == 'p')
        printf("List sorted successfully\n");
    else
        printf("Invalid choice\n");
}


                                              





                                                                          
                                                                                                                                                                   1,1           Top
