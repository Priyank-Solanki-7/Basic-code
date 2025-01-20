#include <stdio.h>
#define len 5
int CQueue[len];
int f = -1, r = -1;

void enqueue(int ele)
{
    // condition for reset pointer
    if (r == len - 1)
    {
        r = 0;
    }
    else
    {
        r += 1;
    }
    // condition for overflow
    if (f == r)
    {
        printf("=>Queue is overflow\n");
        if (r == 0)
        {
            r = len - 1;
        }
        else
        {
            r -= 1;
        }
        return; // Stop further execution
    }
    // insert an element
    CQueue[r] = ele;
    // set front pointer
    if (f == -1)
    {
        f = 0;
    }
    printf("=>inserted element is: %d\n", ele);
    printf("------------------------------------------------------------\n");
}

int dequeue()
{
    // underflow condition
    if (f == -1)
    {
        printf("=>Queue is underflow\n");
        return -1; // Return an invalid value to indicate underflow
    }
    // Extract element in y
    int y = CQueue[f];
    // reset pointer
    if (f == r)
    {
        f = r = -1;
    }
    else if (f == len - 1)
    {
        f = 0;
    }
    else
    {
        f += 1;
    }
    return y;
}

void display()
{
    if (f == -1)
    {
        printf("=>Queue is underflow\n");
        return;
    }
    printf("Queue elements: ");
    int i = f;
    if (i <= r)
    {
        for (; i <= r; i++)
        {
            printf("%d ", CQueue[i]);
        }
    }
    else
    {
        for (; i < len; i++)
        {
            printf("%d ", CQueue[i]);
        }
        i = 0;
        for (; i <= r; i++)
        {
            printf("%d ", CQueue[i]);
        }
    }
    printf("\n------------------------------------------------------------\n");
}

void main()
{
    while (1)
    {
        printf("=>enter 0 for exit\n=>enter 1 for insert\n=>enter 2 for delete\n=>enter 3 for display\n");
        int c;
        printf("=>select::");
        scanf("%d", &c);
        int e;
        switch (c)
        {
        case 0:
            return;
            break;
        case 1:
            printf("=>enter an element:::");
            scanf("%d", &e);
            enqueue(e);
            break;
        case 2:
            printf("Deleted element is: %d\n", dequeue());
            break;
        case 3:
            display();
            break;
        default:
            printf("::::::::::::::::invalid input:::::::::::::\n");
            break;
        }
    }
}