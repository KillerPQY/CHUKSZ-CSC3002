/*
 * File: buffer.cpp (list version without dummy cell)
 * --------------------------------------------------
 * This file implements the EditorBuffer class using a linked
 * list to represent the buffer.
 */

#include <iostream>
#include "buffer.h"
using namespace std;

/*
 * Implementation notes: EditorBuffer constructor
 * ----------------------------------------------
 * This function initializes an empty editor buffer, represented
 * as a doubly linked list.  In this implementation, the ends of
 * the linked list are joined to form a ring, with the dummy cell
 * at both the beginning and the end.  This representation makes
 * it possible to implement the moveCursorToEnd method in constant
 * time, and reduces the number of special cases in the code.
 */

EditorBuffer::EditorBuffer() {
   start = cursor = new Cell;
   start->next = start;
   start->prev = start;
}

/*
 * Implementation notes: EditorBuffer destructor
 * ---------------------------------------------
 * The destructor must delete every cell in the buffer.  Note
 * that the loop structure is not exactly the standard idiom for
 * processing every cell within a linked list, because it is not
 * legal to delete a cell and later look at its next field.
 */

EditorBuffer::~EditorBuffer() {

   //TODO
    Cell *tp = start;
    // if tp == NULL, no need to delete
    if (tp != NULL) {
        while (tp->next != start) {
            // copy the next pointer before delete
            Cell *next = tp->next;
            // free current pointer memory
            delete tp;
            // let tp point to next
            tp = next;
        }
        delete start;
    }
}

/*
 * Implementation notes: cursor movement
 * -------------------------------------
 * In a doubly linked list, each of these operations runs in
 * constant time.
 */

void EditorBuffer::moveCursorForward() {
    if (cursor->next != start) {
      cursor = cursor->next;
   }
}

void EditorBuffer::moveCursorBackward() {

   //TODO
    // if cursor == start, can't move it backwart any more
    if (cursor != start) {
        // let cursor point to first previous cell
        cursor = cursor->prev;
    }
}

void EditorBuffer::moveCursorToStart() {

   //TODO
    // let cursor = start
    cursor = start;
}

void EditorBuffer::moveCursorToEnd() {

   //TODO
    // because EditorBuffer is a ring, the end is the prev of start
    cursor = start -> prev;
}

/*
 * Implementation notes: insertCharacter, deleteCharacter
 * ------------------------------------------------------
 * This code is much like that used for the traditional linked
 * list except that more pointers need to be updated.
 */

void EditorBuffer::insertCharacter(char ch) {

    //TODO
    Cell *tp = new Cell;  // create a new cell
    // the current cursor points to the cell before tp
    tp->ch = ch;
    tp->prev = cursor;
    tp->next = cursor->next;
    (cursor->next)->prev = tp;
    cursor->next = tp;
    if (cursor->prev->prev == cursor) {
            cursor->prev->prev = tp;
        }
    cursor = tp;
}

void EditorBuffer::deleteCharacter() {

    //TODO
    // if cursor is at end, can't delete anything
    if (cursor->next != start) {
        Cell *oldCell = cursor->next;
        cursor->next = cursor->next->next;
        cursor->next->prev = cursor;
        delete oldCell;
    }
}

/*
 * Implementation notes: getText and getCursor
 * -------------------------------------------
 * The getText method uses the standard linked-list pattern to loop
 * through the cells in the linked list.  The getCursor method counts
 * the characters in the list until it reaches the cursor.
 */

string EditorBuffer::getText() const {

    //TODO
    string result = "";
    // start doesn't have char, start->next is the first char, start->prev is the last char
    for (Cell *p = start->next; p != start; p = p->next) {
        result += p->ch;
    }
    return result;
}

int EditorBuffer::getCursor() const {

   //TODO
    int n = 0;
    for (Cell *p = start; p != cursor; p = p->next) {
        n++;
    }
    return n;
}
