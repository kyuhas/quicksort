#include <stdio.h>
#include <stdlib.h>
#include "node.h"

//this method takes in the head node of a linked list and performs a quick sort on it
struct mynode *quicksort(struct mynode *head){
	theHead = head;
	theTail = getLast(head);
	quick(theHead, theTail);
	return theHead; 
}

//this method gets the last node and returns that pointer
struct mynode *getLast(struct mynode *theNode) {
	struct mynode *temp = theNode;
	int boolean = 1;
	while(boolean) {
		//if you are at the last node
		if(temp->next == NULL) {
			boolean = 0;
		}
		//if you are not at the last node
		else {
			temp = temp->next;
		}
	}
	return temp;
} 

//this method prints the value of each node in the linked list 
void printlist(struct mynode *head){
	struct mynode *temp = head;
	//if you've reached the last node in the linked list
	if(temp->next == NULL){
		printf("%d\n", (int)temp->value);
		return;
	}
	//if you are not yet at the last node
	else {
		printf("%d\n", (int)temp->value);
		printlist(temp->next);
	}
}

int getIndexOf(struct mynode *node) {
	struct mynode *head = theHead;
	int index = 0;
	//do this until you get to the node
	while(head != node && head != NULL) {
		index = index + 1;
		head = head->next;
	}
	return index;
}

struct mynode *getNodeAt(int index) {
	struct mynode *temp = theHead;
	int i = 0;
	while(i < index) {
		temp = temp->next;
		i = i + 1;
	}
	return temp;
}

//this recursive method takes two pointers, l and r, which point to nodes, and puts
//them in ascending order
void quick(struct mynode *l, struct mynode *r) {
	int indexL = getIndexOf(l);
	int indexR = getIndexOf(r);
	if(indexL < indexR) {
		//make the pivot node -- this is the location where the pivot gets its permanent place
		struct mynode *pivot = partition(l, r);
		//if the pivot's previous value is not null
		if(pivot->prev != NULL) {
			quick(getNodeAt(indexL), pivot->prev);
		}
		//if the pivot's next value is not NULL
		if(pivot->next != NULL) {
			quick(pivot->next, getNodeAt(indexR));
		}
	}
}

//this method takes a left and right pointer (which point to addresses of nodes) and then
//assigns the first one to be the pivot. After every item in the node has been checked, 
//the pivot will be moved to its correct place  
struct mynode *partition(struct mynode *left, struct mynode *right) {
	struct mynode *l = left;
	struct mynode *r = right; 
	//give the pivot the first value in the list
	struct mynode *pivot = l;
	//make a wall -- this wall will eventually point to the final location of the pivot
	struct mynode *leftWall = l;
	//this i pointer points to each element in the linked list to see if it is less than the pivot
	//i initially gets the value of pivot->next
	struct mynode *i = l->next;
	
	int indexI = getIndexOf(i);
	int indexR = getIndexOf(r);
	int indexPivot = getIndexOf(pivot);
	
	int indexSwap = indexI;
	int indexWall = indexI - 1;
	//while you are not past the right pointer
	while(indexI <= indexR) {
		//if(i->value < pivot->value) {
		if(getNodeAt(indexI)->value < pivot->value) {
			//move the wall forward one step
			leftWall = leftWall->next;
			indexWall = indexWall + 1;
			//swap the nodes i and leftWall -- i will always be >= leftWall
			//swap(leftWall, i);
			swap(getNodeAt(indexWall), getNodeAt(indexI));
		}
		if(indexI != indexR) {
			i = i->next;
			indexI = indexI + 1;
		}
		else {
			break;
		}
	}
	//at this point, the pivot is ready to be placed in its correct spot, which is at leftWall
	//remember: the pivot is at location l
	//swap(pivot, i);
	swap(getNodeAt(indexPivot), getNodeAt(indexWall)); 
	//return leftWall;
	return getNodeAt(indexWall);
}

//this method swaps the next and previous pointers for the variables
void swap(struct mynode *node1, struct mynode *node2) {
	
	//if the two nodes are the same
	if(node1 == node2) {
		return;
	}
	
	//the following TWO situations can occur if node1 is HEAD and node2 is TAIL:
	
	//if node2 is TAIL and node1 is HEAD and there is nothing between them
	else if(node2->next == NULL && node1->prev == NULL && node1->next == node2) {
		node1->next = NULL;
		node2->prev = NULL;
		node1->prev = node2;
		node2->next = node1;
		
		theHead = node2;
		theTail = node1;
	}
	//if node2 is TAIL and node1 is HEAD, but they are not next to each other
	else if(node2->next == NULL && node1->prev == NULL && node1->next != node2) {
		node1->next->prev = node2;
		node2->prev->next = node1;
		node1->prev = node2->prev;
		node2->next = node1->next;
		node2->prev = NULL;
		node1->next = NULL;
		
		theHead = node2;
		theTail = node1;
	}
	
	//the following TWO situations occur if node1 is NOT HEAD and node2 is TAIL
	
	//if node2 is the tail and node1 is directly behind it and node1 is not the head
	else if(node2->next == NULL && node2->prev == node1 && node1->prev != NULL){
		node1->prev->next = node2;
		node2->prev = node1->prev;
		node2->next = node1;
		node1->next = NULL;
		node1->prev = node2;
		
		theTail = node1;
	}
	//if node2 is the tail and node1 is not the head and they are not next to each other
	else if(node2->next == NULL && node2->prev != node1 && node1->prev != NULL) {
		node1->prev->next = node2;
		node1->next->prev = node2;
		node2->prev->next = node1;
		struct mynode *tempPrev = node1->prev;
		struct mynode *tempNext = node1->next;
		node1->next = NULL;
		node1->prev = node2->prev;
		node2->prev = tempPrev;
		node2->next = tempNext;
		
		theTail = node1;
	}
	
	//the following TWO situations occur if node1 is HEAD and node2 is NOT TAIL
	
	//if node1 is the head and node2 is not the tail and node2 is directly next to node1
	else if(node1->prev == NULL && node2->next != NULL && node1->next == node2) {
		node2->next->prev = node1;
		node1->next = node2->next;
		node2->next = node1;
		node2->prev = NULL;
		node1->prev = node2;
	
		theHead = node2;
	}
	//if node1 is the head and node2 is not the tail and they are not next to each other
	else if(node1->prev == NULL && node2->next != NULL && node1->next != node2) {
		node1->next->prev = node2;
		node2->prev->next = node1;
		node2->next->prev = node1;
		struct mynode *tempPrev = node2->prev;
		struct mynode *tempNext = node2->next;
		node2->prev = NULL;
		node2->next = node1->next;
		node1->prev = tempPrev;
		node1->next = tempNext;
	
		theHead = node2;
	}
	
	//The following TWO situations occur if node1 is NOT HEAD and node2 is NOT TAIL
	
	//if node1 is not head and node2 is not tail and node2 is directly next to node1
	else if(node1->prev != NULL && node2->next != NULL && node1->next == node2) {
		node1->prev->next = node2;
		node2->next->prev = node1;
		node2->prev = node1->prev;
		node1->next = node2->next;
		node1->prev = node2;
		node2->next = node1;
	}
	//if node1 is not head and node2 is not tail and they are not next to each other
	else if(node1->prev != NULL && node2->next != NULL && node1->next != node2) {
		node1->prev->next = node2;
		node1->next->prev = node2;
		node2->prev->next = node1;
		node2->next->prev = node1;
		struct mynode *tempPrev = node1->prev;
		struct mynode *tempNext = node1->next;
		node1->next = node2->next;
		node1->prev = node2->prev;
		node2->prev = tempPrev;
		node2->next = tempNext;
	}
}