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

// Naive Solution
void eliminateDuplicateList(LinkedList *head){
	
	LinkedList *ptr1 = head;
	LinkedList *ptr2 = NULL;
	LinkedList *dup = NULL;

	while(ptr1 and ptr1 -> next){
		ptr2 = ptr1;
		while(ptr2 -> next != NULL){
			if(ptr1 -> data == ptr2 -> next -> data){
				dup = ptr2->next; 
                ptr2->next = ptr2->next->next; 
                delete(dup); 
			}
			else
			ptr2 = ptr2 -> next;
		}
		ptr1 = ptr1 -> next;

	}


}

void eliminateDuplicate(LinkedList *head){
	if(head == NULL) return;
	unordered_set<int> s;
	LinkedList *prev = NULL;
	while(head != NULL){
		if(s.find(head -> data) != s.end()){
			prev -> next = head -> next;
		}
		else{
		s.insert(head -> data);
		prev = head;
		}
		head = prev -> next;
	}
}
int main(){

	LinkedList *head = NULL;

	int arr[] = {21, 43, 41, 21, 12, 11, 12};
	for(int i = 0; i < 7; i++)
		insert(&head, arr[i]);

	// eliminateDuplicate(head);
	// printList(head);

	eliminateDuplicateList(head);
	printList(head);


	

}