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

int getCount(LinkedList *t){
	if(t == NULL) return 0;

	return 1 + getCount(t -> next);
}

/*Best Solution*/
int getIntersectionPoint(LinkedList *head1, LinkedList *head2){
	int c1 = getCount(head1);
	int c2 = getCount(head2);

	if(c1 > c2){
		for(int i = 0; i < abs(c1 - c2); i++)
			head1 = head1 -> next;
	}
	else{
		for(int i = 0; i < abs(c1 - c2); i++)
			head2 = head2 -> next;
	}
	while(head1 != NULL and head2 != NULL){
		if(head1 == head2)
			return head1 -> data;
		head1 = head1 -> next;
		head2 = head2 -> next;
	}
	return -1;
}


/* Hashing Solution */

int intersectionPoint(LinkedList *head1, LinkedList *head2){
	 unordered_set<LinkedList*> s;
     LinkedList *temp = head1;
	    while(temp){
	        s.insert(temp);
	        temp = temp -> next;
	    }
	 
	while(head2){
	    if(s.find(head2) != s.end()){
	        return head2 -> data;
	    }
	    head2 = head2 -> next;
	}
	return -1;
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

	 LinkedList* newNode; 
  
    // Addition of new nodes 
    LinkedList* head1 = new LinkedList(10); 
   
  
    LinkedList* head2 = new LinkedList(3); 
    
  
    newNode = new LinkedList(6); 
   
    head2->next = newNode; 
  
    newNode = new LinkedList(9); 
  
    head2->next->next = newNode; 
  
    newNode = new LinkedList(15); 
    
    head1->next = newNode; 
    head2->next->next->next = newNode; 
  
    newNode = new LinkedList(30); 
    
    head1->next->next = newNode; 
  
    head1->next->next->next = NULL; 
	
	cout << intersectionPoint(head1, head2);
	cout << getIntersectionPoint(head1, head2);

}