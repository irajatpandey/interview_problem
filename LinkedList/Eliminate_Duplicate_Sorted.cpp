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
void eliminateDuplicate(LinkedList *head){
	LinkedList *p1 = head;
	LinkedList *p2 = NULL;

	while(p1 -> next != NULL){
		if(p1 -> data == p1 -> next -> data){
			p2 = p1 -> next;
			p1 -> next = p2 -> next;
			delete(p2);
		}
		else
			p1 = p1 -> next;
	}

}

void insert(LinkedList **head, int x){
	 LinkedList *newNode = new LinkedList(x);
	 newNode -> next = (*head);
	 (*head) = newNode;
}

void printList(LinkedList *head){
	while(head){
		cout << head -> data << " ";
		head = head -> next;
	}
	cout << endl;
}

int main(){

	LinkedList *head = NULL;

	int arr[] = {100, 90, 90, 80, 70, 60, 60, 50, 40, 40};
	for(int i = 0; i < 10; i++)
		insert(&head, arr[i]);
	eliminateDuplicate(head);
	printList(head);

	

}