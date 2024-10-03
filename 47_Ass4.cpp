//Kamaaksha Rajendra Kharul
// 123B1B047
#include<iostream>
using namespace std;

struct Node{
	string text;
	Node *prev;
	Node *next;
};

class DLL{
	Node *head;
	public:
		DLL(){
			head = NULL;
		}
		
		void insertAtEnd(string text){
			Node *nn = new Node;
			if(nn == NULL)
				return;
			nn -> text = text;
			nn -> next = nn -> prev = NULL;
			if(head == NULL)
				head = nn;
			else{
				Node *temp = head;
				while(temp -> next)
					temp = temp -> next;
				temp -> next = nn;
				nn -> prev = temp;
			}
			return ;
		}
		
		void insertAtHead(string text){
			Node *nn = new Node;
			if(nn == NULL)
				return;
			nn -> text = text;
			nn -> next = nn -> prev = NULL;
			if(head == NULL)
				head = nn;
			else{
				nn -> next = head;
				head -> prev = nn;
				head = nn;
			}
			return ;
		}
		
		void printRecords(){
			Node *temp = head;
			while(temp){
			    cout << temp -> text << "\t";
			    temp = temp -> next;
			}
			cout << endl;
		}
		
		void printReverse(){
		    Node *temp = head;
		    //temp ko tail pe lagaya
		    while(temp -> next)
		        temp = temp -> next;
		        
		    while(temp){
		        cout << temp -> text << "\t";
		        temp = temp -> prev;
		    }
		    cout << endl;
		    return;
		}
		
		void deleteRecord(string text){
            Node* temp = head;
            while (temp != NULL){
                if (temp->text == text){
                    //head data matches
                    if (temp == head){
                        head = temp->next;
                        if (head != NULL){
                            head->prev = NULL;
                        }
                    }
                    //Node is not head
                    else{
                        temp->prev->next = temp->next;
                        if (temp->next != NULL){
                            temp->next->prev = temp->prev;
                        }
                    }

                    delete temp;
                    cout << "Deleted record" << endl;
                    return;
                }
                temp = temp->next;
            }
            cout << "Record not found" << endl;
            return;
        }

		void searchRecord(string text){
		    Node *temp = head;
		    while(temp){
		        if(temp -> text == text){
		            cout << text << " FOUND" << endl;
		            return;
		        }
		        temp = temp -> next;
		    }
		    cout << text << " NOT FOUND" << endl;
		    return;
		}
};
int main(){
    DLL mylist;
    mylist.insertAtHead("Riya");
    mylist.insertAtHead("Siya");
    mylist.insertAtEnd("Kiya");
    cout << "Original list: ";
    mylist.printRecords();
    cout << "Reversed list: ";
    mylist.printReverse();
    mylist.deleteRecord("Ritika");
    mylist.deleteRecord("Kiya");
    mylist.printRecords();
    mylist.searchRecord("Riya");
    mylist.searchRecord("Geeta");
}