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

/* Using Hashing*/
bool detectLoopHash(LinkedList *head){
	if(head == NULL) return false;

	unordered_set<LinkedList *> s;
	while(head != NULL){
	if(s.find(head) != s.end()){
		return true;
	}
		s.insert(head);
		head = head -> next;
	}
	return false;
}

/* Best Solution */
bool detectLoop(LinkedList *head){
	if(head == NULL) return false;

	LinkedList *slow = head;
	LinkedList *fast = head;

	while(fast != NULL and fast -> next != NULL){
		slow = slow -> next;
		fast = fast -> next -> next;

		if(fast == slow)
			return true;

	}
	return false;

}
void insert(LinkedList **head, int x){
	 LinkedList *newNode = new LinkedList(x);
	 newNode -> next = (*head);
	 (*head) = newNode;
}

int main(){

	LinkedList *head = NULL;

	int arr[] = {20, 4, 15, 10};
	for(int i = 0; i < 10; i++)
		insert(&head, arr[i]);
	head->next->next->next->next = head; 

	if(detectLoop(head)) cout << "true\n";
	else cout << "false\n";
	

	if(detectLoopHash(head)) cout << "true\n";
	else cout << "false\n";
	

}