// { Driver Code Starts
//Initial Template for C

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
 
// A structure to represent a queue
struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};
 
// function to create a queue
// of given capacity.
// It initializes size of queue as 0
struct Queue* createQueue(unsigned capacity)
{
    struct Queue* queue = (struct Queue*)malloc(
        sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
 
    // This is important, see the enqueue
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(
        queue->capacity * sizeof(int));
    return queue;
}
 
// Queue is empty when size is 0
int isEmpty(struct Queue* queue)
{
    return (queue->size == 0);
}
 
// Function to add an item to the queue.
// It changes rear and size
void enqueue(struct Queue* queue, int item)
{
    queue->rear = (queue->rear + 1)
                  % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}
 
// Function to remove an item from queue.
// It changes front and size
void dequeue(struct Queue* queue)
{
    if (isEmpty(queue))
        return ;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1)
                   % queue->capacity;
    queue->size = queue->size - 1;
}
 
// Function to get front of queue
int front(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->front];
}

// Function to get size of queue
int size(struct Queue* queue)
{
    return queue->size;
}


 // } Driver Code Ends
//User function Template for C

/*
// A structure to represent a queue
struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};
 
// function to create a queue
// of given capacity.
// It initializes size of queue as 0
struct Queue* createQueue(unsigned capacity);

// Queue is empty when size is 0
int isEmpty(struct Queue* queue);
 
// Function to add an item to the queue.
void enqueue(struct Queue* queue, int item);

// Function to remove an item from queue.
void dequeue(struct Queue* queue);
 
// Function to get front of queue
int front(struct Queue* queue);

// Function to get size of queue
int size(struct Queue* queue);
*/


// Function to push an element into stack using two queues.
// 2 Queues q1 and q2 where q1 should be used as stack and q2 as helping queue
// num: number to be inserted 
void QueueStack :: push(int x)
{
    q1.push(x);
    int sz=q1.size()-1;
    while(sz--)
    {
        q1.push(q1.front());
        q1.pop();
    }
}


//Function to pop an element from stack using two queues. 
int QueueStack :: pop()
{
    int ans;
    if(q1.empty())
    {
        ans=-1;
    }
    else
    {
        ans=q1.front();
        q1.pop();
    }
    return ans;
}

// { Driver Code Starts.

int main() {
	
	int t;
	scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        struct Queue* q1 = createQueue(n);
        struct Queue* q2 = createQueue(n);
        while(n--)
        {
            int opt;
            scanf("%d",&opt);
            if(opt==1)
            {
                int x;
                scanf("%d",&x);
                push(q1,q2,x);
            }
            else
            {
                printf("%d ",pop(q1));
            }
        }
        printf("\n");
    }
	return 0;
}
  // } Driver Code Ends
