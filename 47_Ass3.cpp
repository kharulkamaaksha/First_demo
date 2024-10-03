#include<iostream>
using namespace std;

struct Song{
	string sTitle;
	string sArtist;
	float fDuration;
	Song *next;
};

class Playlist{
	Song *head;
	public:
		Playlist(){
			head = NULL;
		}
		
		void insert(string title, string artist, float duration){
			Song *nn = new Song;
			nn -> sTitle = title;
			nn -> sArtist = artist;
			nn -> fDuration = duration;
			nn -> next = NULL;
			if(head == NULL)
				head = nn;
			else{
				Song *temp = head;
				while(temp -> next)
					temp = temp -> next;
				temp -> next = nn;
			}
			return;
			
		}
		
		void removeASong(string title){
			Song *temp = head;
			Song *prev = NULL;
			if(head == NULL){
				cout << "Empty playlist!" << endl;
				return;
			}
			/*if(head -> sTitle == title){
				head = head -> next;
				delete temp;
			}*/
			//temp = head;//temp should point to new head
			while(temp){
				if(temp -> sTitle == title){
				    if(temp == head){
				        head = head -> next;
				        delete temp;
				        temp = head;
				    }
				    else{
					    prev -> next = temp -> next;
					    delete temp;
					    temp = temp -> next;
				    }
				}
				else{
				    prev = temp;
				    temp = temp -> next;
				}
			}
			return;
		}
		void removeASongByArtist(string artist){
			Song *temp = head;
			Song *prev = NULL;
			if(head == NULL){
				cout << "Empty playlist!" << endl;
				return;
			}
			if(head -> sArtist == artist){
				head = head -> next;
				delete temp;
			}
			temp = head;//temp should point to new head
			while(temp){
				if(temp -> sArtist == artist){
					prev -> next = temp -> next;
					delete temp;
				}
				prev = temp;
				temp = temp -> next;
			}
			return;
		}
		void printRecords(){
			Song *temp = head;
			while(temp){
				cout << temp -> sTitle << "\t" << temp -> sArtist << "\t"<< temp -> fDuration << endl;
				temp = temp -> next;
			}
			return;
		}
		void searchASong(string title){
			Song *temp = head;
			while(temp){
				if(temp -> sTitle == title){
					cout << temp -> sTitle << "\t" << temp -> sArtist << "\t"<< temp -> fDuration << endl;
					return;
				}
				else
					temp = temp -> next;
			}
			cout << title << " NOT FOUND!" << endl;
			return;
		}
		
		void searchSong(string artist){
			Song *temp = head;
			while(temp){
				if(temp -> sArtist == artist){
					cout << temp -> sTitle << "\t" << temp -> sArtist << "\t"<< temp -> fDuration << endl;
					return;
				}
				else
					temp = temp -> next;
			}
			cout << artist << " NOT FOUND!" << endl;
			return;
		}
};
	
int main(){
	Playlist myList;
	myList.insert("song1","artist1",3.05);
	myList.insert("song1","artist1",3.05);
	myList.insert("song1","artist1",3.05);
	myList.insert("song2","artist2",3.08);
	myList.insert("song3","artist3",4.02);
	myList.insert("song2","artist2",3.08);
	cout << "Insertion Done!"<< endl;
	myList.printRecords();
	myList.searchASong("title1");
	myList.searchSong("artist3");
	myList.removeASong("song1");
	cout << "After deletion by title!" << endl;
	myList.printRecords();
	myList.removeASongByArtist("artist2");
	cout << "After deletion by artist!" << endl;
	myList.printRecords();
	return 0;
}

