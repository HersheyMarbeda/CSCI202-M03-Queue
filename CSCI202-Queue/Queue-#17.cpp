    /********************************************************************************************
     *        Programming Assignment 3.1: Queues                                                *
     *                                                                                          *
     *        Programmer: Hershey Marbeda                                                       *
     *        Instructor: Dr. Carver                                                            *
     *        Class: CSCI 202: Data Sturctures and Algorithms                                   *
     *        Due Date: 11.12.2024                                                              *
     *                                                                                          *
     *        Last Date Updated: 11.8.2024                                                      *
     *                                                                                          *
     *        Description: This program demonstrates the use of queues                          *
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
        while (first == nullptr)
        {
            cout << "\nQueue is Empty\n";
            return true;
        }
        return false;
    }
    
    // Insert node at the beginning of the queue
    void insertFirst(int newItem)
    {
        nodeType* newNode = new nodeType;
        newNode->info = newItem;
        newNode->link = first;
        first = newNode;
        
        if (last == nullptr)
        {
            last = newNode;
        }
        
        cout << newItem << " has been added to the queue\n";
    }
    
    // Insert node at the end of the queue
    void insertLast(int newItem)
    {
        nodeType* newNode = new nodeType;
        newNode->info = newItem;
        newNode->link = nullptr;
        last->link = newNode;
        last = newNode;
        
        if (first == nullptr)
        {
            first = newNode;
        }
        
        cout << newItem << " has been added to the queue\n";
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
   
    // Test the insertFirst function
    queue.insertFirst(5);
    queue.insertFirst(10);
    queue.insertFirst(15);
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

    cout << "\n\n";
    return 0;
}

/************* Expected Output          *
 * 5 has been added to the queue   *
 * 10 has been added to the queue  *
 * 15 has been added to the queue  *
 * 20 has been added to the queue  *
 * 25 has been added to the queue  *
 * Queue is not empty              *
*/
