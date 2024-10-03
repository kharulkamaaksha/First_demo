#include<iostream>
using namespace std;

struct Node{
    string source;
    string destination;
    float distance;
    Node *next;
};

class scll {
    Node *tail;
    
    public:
        scll() {
            tail = NULL;
        }

        void insertAtTail(string source, string dest, float dist) {
            Node *nn = new Node;
            nn -> source = source;
            nn -> destination = dest;
            nn -> distance = dist;
            nn -> next = NULL;
            if (tail == NULL) {
                // When the list is empty, the new node should point to itself
                tail = nn;
                nn->next = nn;
            } 
            else {
                // Insert the new node into the circular linked list
                nn->next = tail->next;
                tail->next = nn;
                tail = nn;
            }
        }
        
        void insertAtHead(string source, string dest, float dist) {
            Node *nn = new Node;
            nn -> source = source;
            nn -> destination = dest;
            nn -> distance = dist;
            nn -> next = NULL;
            if (tail == NULL) {
                // When the list is empty, the new node should point to itself
                tail = nn;
                nn->next = nn;
            } 
            else {
                // Insert the new node into the circular linked list
                nn->next = tail->next;
                tail->next = nn;
            }
        }

        void printRoutes() {
            if (tail == NULL) {
                cout << "List is empty!" << endl;
                return;
            }
            Node *temp = tail->next;
            do {
                cout << temp->source << " -> " << temp->destination << " : " << temp->distance << endl;
                temp = temp->next;
            } 
            while (temp != tail->next);
            cout << endl;
        }
        
        void deleteRoute(string src, string dest){
			if(tail == NULL){
				cout << "Empty list" << endl;
				return;
			}
			Node *temp = tail -> next;
			Node *prev = tail;

			do{
				if(temp -> source == src && temp -> destination == dest){
					prev -> next = temp -> next;
					Node *curr = temp;
					
					//single node
					if(tail == tail->next){
						tail = NULL;
						return;
					}
					
					if(temp == tail -> next){
					    //head hai
					    prev -> next = temp -> next;
					    delete curr;
					    temp = temp -> next;
					}
					
					//tail hai
					if(temp == tail){
						tail = prev;
						temp = temp -> next;
						delete curr;
					}
					
					//else anywhere
					else{
					    prev -> next = temp -> next;
					    delete curr;
					    temp = temp -> next;
					}
				}
				else{
				    prev = temp;
				    temp = temp -> next;
				}
			}
			while(temp != tail -> next);
			return;
		}
        
        	
};

int main() {
    scll mylist;
    mylist.insertAtTail("a","b",100);
    mylist.insertAtTail("c","d",70);
    mylist.insertAtHead("g","l",88);
    mylist.insertAtHead("a","d",85);
    mylist.insertAtHead("a","d",85);
    mylist.insertAtTail("a","b",100);
    
    mylist.printRoutes();
    mylist.deleteRoute("a","b");
    cout << "After deletion" << endl;
    mylist.printRoutes();
    mylist.deleteRoute("a","d");
    cout << "After deletion" << endl;
    mylist.printRoutes();
    return 0;
}
