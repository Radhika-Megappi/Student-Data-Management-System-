#include "student.h"

int main()
{
    SLL *headptr = 0;
    char ch, op;

    readFile(&headptr);

    while(1)
    {
        printf("\n******** STUDENT RECORD MENU ********\n");
        printf("a/A : Add new record\n");
        printf("d/D : Delete a record\n");
        printf("s/S : Show the list\n");
        printf("m/M : Modify a record\n");
        printf("v/V : Save records\n");
        printf("e/E : Exit\n");
        printf("t/T : Sort the list\n");
        printf("l/L : Delete all the records\n");
        printf("r/R : Reverse the list\n");

        printf("Enter your choice: ");
        scanf(" %c", &ch);

        switch(ch)
        {
            case 'a':
            case 'A':
                addRecord(&headptr);
                break;

            case 'd':
            case 'D':
                deleteNode(&headptr);
                break;

            case 's':
            case 'S':
                printNode(headptr);
                break;
            case 'm':
            case 'M':
                modifyNode(headptr);
                break;

            case 'v':
            case 'V':
                saveFile(headptr);
                break;

            case 't':
            case 'T':
                sortData(headptr);
                break;

            case 'l':
            case 'L':
                deleteAll(&headptr);
                break;

            case 'r':
            case 'R':
                reverseLinks(&headptr);
                break;

            case 'e':
            case 'E':
                printf("S/s : Save and exit\n");
                printf("E/e : Exit without saving\n");
                printf("Enter your choice: ");
                scanf(" %c", &op);

                if(op == 'S' || op == 's'){
                    saveFile(headptr);
                    deleteAll(&headptr);
                    return 0;
                }
                else if(op == 'E' || op == 'e')
                {
                    deleteAll(&headptr);
                    return 0;
                }
                else
                    printf("Invalid choice\n");

                break;

            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}


                                          



                                                                                                                                                                   1,0-1         Top
