////////////////////////////////////////////////////////////////////////////////
// INCLUDES
#include "include.h";

////////////////////////////////////////////////////////////////////////////////
// GLOBAL VARIABLES
int count;

////////////////////////////////////////////////////////////////////////////////
// MAIN ENTRY POINT

int main(int argc, char const *argv[])
{
    create();
    enque(5);

    return 0;
}

void create()
{
    head = NULL;
    tail = NULL;
}

/**
 * Puts an item into the Queue.
 */
void enque(int x)
{
    if (head == NULL)
    {
        head = (struct node *)malloc(sizeof(struct node));
        head->data = x;
        head->next = NULL;
        tail = head;
    }
    else
    {
        tmp = (struct node *)malloc(sizeof(struct node));
        tmp->data = x;
        tmp->next = NULL;
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        tail->next = tmp;
    }
}

/**
 * Takes the next item from the Queue.
 */
int deque()
{
    int returnData = 0;
    if (head == NULL)
    {
        printf("ERROR: Deque from empty queue.\n");
        exit(1);
    }
    else
    {
        returnData = head->data;
        struct node* p = head;
        head = head->next;
        free(p);
    }
    return returnData;
}

/**
 * Returns the size of the Queue.
 */
int size() { return count; }
