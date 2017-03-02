#include <stdio.h>
#include <stdlib.h>
#include "node.h"

struct mynode *createNode(struct mynode *thenode, int thenumber);

int main() {
	int boolean = 1;
	int counter = 0;
	struct mynode *this;
	struct mynode *head = (struct mynode *)malloc(sizeof(struct mynode));
	
	while(boolean) {
		//get value from user
		int number;
		scanf("%d", &number);

		//stop taking input if you get to 
		if(number == 0) {
			boolean = 0;
		}
		//if it's first number, make head node and initialize it
		else if(counter == 0) {
			*(int*)&head->value = number;
 			head->prev = NULL;
 			head->next = NULL;
			this = head;
			counter = counter + 1;
		}
		//else, create a new node and call a function to initialize it
		else {
			struct mynode *newNode = (struct mynode *)malloc(sizeof(struct mynode));
			*(int*)&newNode->value = number;
 			newNode->prev = this;
 			newNode->next = NULL;
			this->next = newNode;
			this = newNode;
			counter = counter + 1;
		}
	
	}
	//they entered in something
	if(counter != 0) {
		//at this point, the linked list has been created
		printf("unsorted linked list:\n");
		printlist(head);
	
		//sort it here
		printf("sorted linked list:\n");
		printlist(quicksort(head));
	}
	
	//they did not enter in any numbers other than 0
	else {
		printf("You did not give the linked list any nodes!\n");
	}

	return 0;
}
