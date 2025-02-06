/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"

/* Add a prototype for a helper function here if you need */
// void append(Node*& head, int v); //must also be recursive 

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE
//first, step through the in list + determine which values are odd/even
//once you find out it's odd/even append that value to the corresponding list
//set that value to NULL in the original list?
  // Node* oddHead = nullptr;
  // Node* evenHead = nullptr;
  // Node* inHead = nullptr; 

  if(in == nullptr){
    return;
  }

  Node* temp = in->next;
  if(in->value % 2 == 0){ //if the value
    in->next = evens; 
    evens = in;
  }
  else{
    in->next = odds;
    odds = in;
  }
  in = nullptr; 
  split(temp, odds, evens);

  //need to do this recursively until I reach NULL 
  //have to iterate through list until you reach NULL;
  
  
  












  //odds points to the head of a linked list containing all items
  //where value is an odd integer 

  //evens points to the head of a linked list containing all items 
  //where value is an even integer 


  
}

/* If you needed a helper function, write it here */
// void append(Node*& head, int v){
  //if(head == NULL){
    //   Node* newptr = new Node;
    //   newptr->val = v; 
    //   newptr->next = NULL;
  //}

// }
