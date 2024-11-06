/**************************************************************
 *        Programming Assignment 3.1: Queues                                                      *
 *                                                            *
 *        Programmer: Hershey Marbeda                                                                 *
 *        Instructor: Dr. Carver                                                                                  *
 *        Class: CSCI 202: Data Sturctures and Algorithms                                     *
 *        Due Date: 11.12.2024                                                                                *
 *                                                            *
 *        Last Date Updated: 11.6.2024                                                                   *
 *                                                          *
 *        Description: This program demonstrates the use of queues                    *
 **************************************************************/
/*
   Programming Exercise #13 Ch. 17 (p. 1277) - This chapter describes the array implementation of queues that use a special array slot,
   called the reserved slot, to distinguish between an empty and a full queue. Write the definition of the class and the definitions
   of the function members of this queue design. Also, write a test program to test various operations on a queue
*/


#include <iostream>
#include <queue>
#include <string>
#include <cstdlib>

using namespace std;

class ReservedSlotQueue
{
private:
    int* queueArray;   // Array to store queue elements
    int front, rear, size;
    unsigned capacity; // Total capacity including reserved slot
    
public:
        // Constructor
    ReservedSlotQueue(unsigned capacity)
    {
        this->capacity = capacity + 1;  // Allocate an extra slot
        queueArray = new int[this->capacity];
        front = 0;
        size = 0;
        rear = capacity;  // Initial rear position
    }
    
        // Destructor
    ~ReservedSlotQueue()
    {
        delete[] queueArray;
    }
    
        // Check if the queue is full
    bool isFull()
    {
        return size == capacity - 1;
    }
    
        // Check if the queue is empty
    bool isEmpty()
    {
        return size == 0;
    }
    
        // Add an item to the queue
    void enqueue(int item)
    {
        if (isFull())
        {
            cout << "Queue is full\n";
            return;
        }
        rear = (rear + 1) % capacity;
        queueArray[rear] = item;
        size++;
        cout << item << " enqueued to queue\n";
    }
    
        // Remove an item from the queue
    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return -1;  // Return -1 to indicate the queue is empty
        }
        
        int item = queueArray[front];
        front = (front + 1) % capacity;
        size--;
        cout << item << " dequeued from queue\n";
        return item;
    }
    
        // Get the front item
    int getFront()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return -1;
        }
        return queueArray[front];
    }
    
        // Get the rear item
    int getRear()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return -1;
        }
        return queueArray[rear];
    }
};

    // Test the ReservedSlotQueue
int main()
{
        // Table Heading
    cout << string(100, '-') << endl
    << "\t\t\t\t\t\t\tProgram Name: Reserved Slot Queue Program\n"
    << "\t\t\t\t\t\t\t\t\t\t\tM03.1: Queues\n"
    << string(100, '-') << endl;
    
        // Declaration of Variables
    int QUEUE_CAPACITY, numElements, element;
    char choiceDequeue;
    
    cout << "Enter the capacity of the queue: ";
    cin >> QUEUE_CAPACITY;
    
        // Input Validation
    while (cin.fail() || QUEUE_CAPACITY <= 0)
    {
        cin.clear();
        cin.ignore();
        cout << "\nInvalid input. Please enter a positive integer: ";
        cin >> QUEUE_CAPACITY;
    }
    
        // Create a queue with the given capacity
    ReservedSlotQueue queue(QUEUE_CAPACITY);
    
    
    cout << "\nEnter the number of elements to add (enqueue): ";
    cin >> numElements;
    
    for (int i = 0; i < numElements; i++)
    {
        cout << "\nEnter element #" << i + 1 << ": ";
        cin >> element;
        queue.enqueue(element);
    }
    
    cout << "\nFront element is: " << queue.getFront() << endl
    << "Rear element is: " << queue.getRear() << endl;
    
    do
    {
        cout << "\nDo you want to remove (dequeue) an element? (Y/N): ";
        cin >> choiceDequeue;
        
            // To transform the input to uppercase
        choiceDequeue = toupper(choiceDequeue);
        
            // Input Validation
        while (choiceDequeue != 'Y' && choiceDequeue != 'N')
        {
            cin.clear();
            cin.ignore();
            cout << "\nInvalid input. Please enter Y or N: ";
            cin >> choiceDequeue;
            
                // to transform the input to uppercase
            choiceDequeue = toupper(choiceDequeue);
        }
        
        if (choiceDequeue == 'Y')
        {
            queue.dequeue();
            cout << "\nFront element is: " << queue.getFront() << endl
            << "Rear element is: " << queue.getRear() << endl;
        }
        
    } while (choiceDequeue != 'N' && !queue.isEmpty());
    
    cout << "\nThank you for using the Reserved Slot Queue program!\n"
    << "Programmed by Hershey Marbeda\n";
    
        // To make it readable to screen
    cout << endl << endl;
    return 0;
}
