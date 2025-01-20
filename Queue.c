#include <stdio.h>
#define len 5
int f = -1, r = -1;
int Queue[len];
void equeue(int y)
{
    // check overflow condition
    if (r > len)
    {
        printf("Queue is overflow\n");
        return;
    }
    // logic of insert in Queue
    else
    {
        r += 1;
        Queue[r] = y;
        if (f == -1)
        {
            f += 1;
        }
        printf("insert element is:%d\n", y);
        return;
    }
}
int dqueue()
{
    // check underflow condition
    if (f == -1)
    {
        printf("Queue is underflow");
        return;
    }
    // logic of delete in Queue
    else
    {
        int p = Queue[f];
        if (f == r)
        {
            f = -1;
            r = -1;
        }
        else
        {
            f += 1;
        }
        return p;
    }
}
void display()
{
    if (f == -1)
    {
        printf("Queue is underflow\n");
    }
    else
    {
        int i = f;
        while(i<=r)
        {
          printf("%d\t",Queue[i]);
          i++;
        }
    }
}
void main()
{
    int choice;
    while (1)
    {
        printf("\nenter what you choice:\nSelect 1 for insert in Queue\nSelect 2 for delete in Queue\nSelect 3 for display Queue\nSelect 4 for Exit in Queue\n");
        scanf("%d", &choice);
        printf("--------------------------------------------------------------------------------------------------------------------------\n");
        switch (choice)
        {
            int ele;
        case 1:
            printf("enter a element\n");
            scanf("%d", &ele);
            equeue(ele);
            break;
        case 2:
            printf("delited element is:%d\n", dqueue());
            break;
        case 3:
            display();
            break;
        case 4:
            return;
            break;
        default:
           printf("invalid");
        }
    }
}