/*
 * File: reversequeue.cpp
 * ----------------------
 * This file implements the reversequeue.h interface
 * You need "include" the proper header file and write the function definition.
 */

// TODO
#include <iostream>
#include <string>
#include "queue.h"
#include "stack.h"
using namespace std;

void reverseQueue(Queue<string> & queue)
{
    // Checks whether the queue is empty.
    if (!queue.isEmpty())
    {
        // Reverse the queue by stack.
        Stack<string> stack;
        int l = queue.size();
        // Stack last in first out, queue first in first out.
        for (int i = 0; i < l; i++)
        {
            stack.push(queue.dequeue());
        }
        for (int j = 0; j < l; j++)
        {
            queue.enqueue(stack.pop());
        }
    }
    else
    {
        cout << "The input queue is empty!" << endl;
    }
}

void listQueue(Queue<string> & queue)
{
    // Checks whether the queue is empty.
    if (!queue.isEmpty())
    {
        // Create a copy of the queue so that doesn't change the original queue.
        Queue<string> copy_queue(queue);
        cout << "The queue contains:";
        while (!copy_queue.isEmpty())
        {
            cout << " " << copy_queue.front();  // Print the first one in the copy queue.
            copy_queue.dequeue();  // Pop up the first one.
        }
        cout << endl;
    }
    else
    {
        cout << "The input queue is empty!" << endl;
    }
}
