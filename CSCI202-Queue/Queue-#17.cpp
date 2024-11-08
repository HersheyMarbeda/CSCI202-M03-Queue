    /********************************************************************************************
     *        Programming Assignment 3.1: Queues                                                *
     *                                                                                          *
     *        Programmer: Hershey Marbeda                                                       *
     *        Instructor: Dr. Carver                                                            *
     *        Class: CSCI 202: Data Structures and Algorithms                                   *
     *        Due Date: 11.12.2024                                                              *
     *                                                                                          *
     *        Last Date Updated: 11.8.2024                                                      *
     *                                                                                          *
     *        Description: This program demonstrates the use of queues (FIFO)                   *
     *                                                                                          *
     *  Programming Exercise #17 - Ch. 17 (p. 1278) - Write the definition of the               *
     *  class linkedQueueType, which is derived from the class unorderedLinkedList, as          *
     *  explained in this chapter.  Also, write a program to test various operations of         *
     *  this class                                                                              *
     ********************************************************************************************/

#include <iostream>
#include <queue>
#include <iomanip>

using namespace std;

// Linked List Node
struct nodeType
{
    int info;
    nodeType* link;
};

class unorderedLinkedList
{
private:
    nodeType* first;
    nodeType* last;
    
public:
        // Constructor
    unorderedLinkedList(): first(nullptr), last(nullptr) {}
    
        // Destructor
    ~unorderedLinkedList()
    {
        while (first != nullptr)
        {
            nodeType* temp = first;
            first = first->link;
            delete temp;
        }
        last = nullptr;
    }
    
        // Check if the list is empty
    bool isEmptyList() const
    {
        if (first == nullptr)
        {
            cout << "\nQueue is Empty\n";
            return true;
        }
        return false;
    }
    
        // Insert node at the end of the queue (FIFO behavior)
    void insertLast(int newItem)
    {
        nodeType* newNode = new nodeType;
        newNode->info = newItem;
        newNode->link = nullptr;
        
        if (last != nullptr)
        {
            last->link = newNode;  // Make the current last node point to the new node
        }
        
        last = newNode;  // Set the new node as the last node
        
        if (first == nullptr)  // If the list was empty, set the first node to the new node
        {
            first = newNode;
        }
        
        cout << newItem << " has been added to the queue\n";
    }
    
    // Delete node from the front of the queue
    void deleteFirst()
    {
        if (isEmptyList())  // Check if the list is empty
        {
            cout << "\nQueue is Empty\n";
            return;  // Return immediately if the queue is empty
        }
        
        nodeType* temp = first;
        first = first->link;  // Move the first pointer to the next node
        
        if (first == nullptr)  // If the queue is now empty after deletion
        {
            last = nullptr;    // Set last to nullptr
        }
        
        delete temp;  // Delete the first node
        cout << "First node has been deleted\n";
    }
    
        // Display the front element of the queue
    void displayFront() const
    {
        if (first != nullptr)
        {
            cout << "Front Element: " << first->info << endl;
        }
        else
        {
            cout << "Queue is Empty\n";
        }
    }
    
        // Display the last element of the queue
    void displayLast() const
    {
        if (last != nullptr)
        {
            cout << "Last Element: " << last->info << endl;
        }
        else
        {
            cout << "Queue is Empty\n";
        }
    }
};

int main()
{
        // Table Headings
    cout << string(100, '*') << endl
    << "\t\t\t\t\t\t\tProgramming Assignment 3.1: Queues-#17\n"
    << "\t\t\t\t\t\t\t\t Programmer: Hershey Marbeda\n"
    << string(100, '*') << endl << endl;
    
        // Class Object
    unorderedLinkedList queue;
    
        // Test the insertLast function (FIFO behavior)
    queue.insertLast(5);
    queue.insertLast(10);
    queue.insertLast(15);
    queue.insertLast(20);
    queue.insertLast(25);
    
        // Test the insertLast function
    if (queue.isEmptyList())
    {
        cout << "Queue is empty\n";
    }
    else
    {
        cout << "Queue is not empty\n";
    }
    
        // Test dequeuing (FIFO order)
    cout << "\nTesting Dequeue Function:\n";
    cout << "Current ";
    queue.displayFront();  // Display the front element before deletion
    queue.deleteFirst();  // Dequeue one element (5)
    queue.displayFront();  // Display the front element after deletion
    
    cout << "\n";
    queue.deleteFirst();  // Dequeue another element (10)
    queue.displayFront();  // Display the front element after deletion
    
    cout << "\n";
    queue.deleteFirst();  // Dequeue another element (15)
    queue.displayFront();  // Display the front element after deletion
    
    cout << "\n";
    queue.deleteFirst();  // Dequeue another element (20)
    queue.displayFront();  // Display the front element after deletion
    
    cout << "\n";
    queue.deleteFirst();  // Dequeue another element (25)
    queue.displayFront();  // Display the front element after deletion
    
    cout << "\n\n";
    return 0;
}

