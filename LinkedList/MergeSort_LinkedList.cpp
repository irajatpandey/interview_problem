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

LinkedList* middle(LinkedList *head){
	if(head == NULL)
		return head;

	LinkedList *slow = head;
	LinkedList *fast = head;

	while(fast -> next != NULL and fast -> next -> next != NULL){
		slow = slow -> next;
		fast = fast -> next -> next;
	}
	return slow;
}
LinkedList* merge(LinkedList *head1, LinkedList *head2){

	if(head1 == NULL) return head2;
	if(head2 == NULL) return head1;

	 LinkedList *finalHead = NULL, *finalTail = NULL;


	 if(head1 -> data < head2 -> data){
	 	finalHead = head1;
	 	finalTail = head1;
	 	head1 = head1 -> next;
	 }
	 else{
	 	finalHead = head2;
	 	finalTail = head2;
	 	head2 = head2 -> next;
	 }


    while(head1 != NULL and head2 != NULL){
    if(head1 -> data > head2 -> data){    
            finalTail -> next = head2;
            finalTail = head2; 
        	head2 = head2 -> next;
    }
    else
    {   
            finalTail -> next = head1;
            finalTail = head1;
        	head1 = head1 -> next;
    }
}
	if(head1 != NULL) finalTail -> next = head1;
	if(head2 != NULL) finalTail -> next = head2;

	return finalHead;
}

LinkedList* mergeSort(LinkedList *head){

	if(head == NULL or head -> next == NULL)
		return head;

	LinkedList *mid = middle(head);
	LinkedList *h1 = head;
	LinkedList *h2 = mid -> next;
	mid -> next = NULL;

	h1 = mergeSort(h1);
	h2 = mergeSort(h2);
	LinkedList *finalHead = merge(h1, h2);
	return finalHead;
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

	int arr[] = {1, 2, 3, 4, 5};
	for(int i = 0; i < 5; i++)
		insert(&head, arr[i]);
	printList(head);

	head = mergeSort(head);
	printList(head);
	

}