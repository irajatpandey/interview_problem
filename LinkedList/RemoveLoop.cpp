#include<bits/stdc++.h>
using namespace std;

class LinkedList{
	public:
		int data;
		LinkedList *next;
	LinkedList(int x){
		data = x;
	}	
};

void removeLoopLinkedList(LinkedList *head){
	
	LinkedList *slow = head;
	LinkedList *fast = head;
	while(slow and fast != NULL and fast -> next != NULL){
		 slow = slow -> next;
		 fast = fast -> next -> next;
		 if(slow == fast)
		 	break;
		 
	}

	if(slow != fast) return;

	else{
	slow = head;

	while(slow -> next != fast -> next ){	
		slow = slow -> next;
		fast = fast -> next;

	}
	fast -> next = NULL;
}

}
void printList(LinkedList *head){
	while(head){
		cout << head -> data << " ";
		head = head -> next;
	}
	cout << endl;
}

void insert(LinkedList **head, int x){
	 LinkedList *newNode = new LinkedList(x);
	 newNode -> next = (*head);
	 (*head) = newNode;
}

int main(){

	LinkedList *head = NULL;

	int arr[] = {10, 4, 15, 20, 50};
	for(int i = 0; i < 5; i++)
		insert(&head, arr[i]);
    head->next->next->next->next->next = head->next->next; 


	removeLoopLinkedList(head);

	printList(head);

	
	

}