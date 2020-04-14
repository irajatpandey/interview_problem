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

LinkedList* mergeList(LinkedList *head1, LinkedList *head2){

	if(head1 == NULL) return head2;
	if(head2 == NULL) return head1;

	 LinkedList *finalHead = NULL, *finalTail = NULL;


	 if(head1 -> data < head2 -> data){
	 	finalHead = head1;
	 	finalTail = head1;
	 	head1 =head1 -> next;
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

	LinkedList *head1 = NULL;
	LinkedList *head2 = NULL;


	int arr1[] = {5, 4, 3};
	int arr2[] = {2, 1};

	for(int i = 0; i < 3; i++){
		insert(&head1, arr1[i]);
	}

	for(int i = 0; i < 2; i++)
		insert(&head2, arr2[i]);

	LinkedList *finalHead = mergeList(head1, head2);
	printList(finalHead);
	

}