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

int lengthOfLoop(Node *fast, Node *slow){
    int count = 1;
    fast = fast -> next;
    while(slow != fast){
        fast = fast -> next;
        count++;
    }
    return count;
}

int countNodesinLoop(struct Node *head)
{
     // Code here
     Node *fast = head;
     Node *slow = head;
     
     
     while(fast != NULL and fast -> next != NULL){
        fast = fast -> next -> next;
        slow = slow -> next;
       
        if(slow == fast)
           return lengthOfLoop(slow, fast);
              
       
        
     }
     if(slow != fast)
        return 0;
     
    return 0;
     
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

	int arr[] = {100, 90, 80, 70, 60, 50, 40, 30, 20, 10};
	for(int i = 0; i < 10; i++)
		insert(&head, arr[i]);
	printList(head);

	

}