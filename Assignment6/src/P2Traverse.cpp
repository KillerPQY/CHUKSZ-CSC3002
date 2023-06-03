/*
 * File: TraverseTest.cpp
 * ------------------
 * This program reimplements the depth-first search algorithm using an
 * explicit stack
 * or
 * reimplements the breadth-first search algorithm using an
 * explicit queue.
 */

#include <iostream>
#include <fstream>
#include <string>
#include "set.h"
#include "simplegraph.h"
#include "stack.h"
#include "queue.h"
#include "foreach.h"

using namespace std;

/* Main program */
void dfs(Node *start);
void bfs(Node *start);

int TraverseTest() {
   SimpleGraph airline;
   ifstream infile("AirlineGraph.txt");
   readGraph(airline, infile);
   dfs(airline.nodeMap.get("Portland"));
   bfs(airline.nodeMap.get("Portland"));
   return 0;
}

void dfs(Node *start) {

    cout<<"dfs:"<<endl;
    Set<Node*>visited;
    Stack<Node*>mystack;
    mystack.add(start);
    while(!mystack.isEmpty()){
        start=mystack.pop();
        if(!visited.contains(start)){
            cout<<start->name<<endl;
            visited.add(start);
            for(Arc*arc:start->arcs){
                mystack.add(arc->finish);
            }
        }
    }
}

void bfs(Node *start) {
    /* TODO */
   /* make sure that your implemantation is based on an explicit Queue */
    cout << "bfs: " << endl;
    Queue<Node*> myqueue;
    Set<Node*> visited; // to record whether the node has been visited

    myqueue.enqueue(start);
    visited.add(start);

    while (!myqueue.isEmpty()) {
        Node* f = myqueue.dequeue();
        cout << f->name <<endl;  // print the node name
        foreach (Arc* arc in f->arcs) {
            if (!visited.contains(arc->finish)) {  // search the node which hasn't been visited
                visited.add(arc->finish);
                myqueue.enqueue(arc->finish);
            }
        }
    }

}
