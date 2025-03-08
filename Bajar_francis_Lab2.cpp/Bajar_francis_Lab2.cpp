#include <iostream>
using namespace std;
 
 typedef struct Node{
     string songName;
     Node *link;

 }Node;
 
 Node *createNode(string data){
     Node *newNode = new Node;
     newNode->songName = data;
     newNode->link = NULL;
     
     return newNode;
 }
  void traverse(Node *head){
      Node *temp = new Node;
      temp = head;
      
      cout << "My Playlist" <<endl;
      while(temp != NULL){
          cout << temp->songName<< "->"<<endl;
          if(temp->link == NULL){
              cout << "NULL"<<endl;
          }
          temp = temp->link;
      }
  }
 Node *insertAtEnd(string data, Node *head){
     if(head == NULL){
         Node *newNode = createNode(data);
         head = newNode;
         cout << "A new node has been inserted at the end \n" << endl;
         return head;
     }
     Node *temp = new Node;
     temp = head;
     
     while(temp->link != NULL){
         temp = temp->link;
     }
     Node *newNode = createNode(data);
     temp->link = newNode;
     
     cout << "A new has been inserted at the end \n" <<endl;
     return head;
 }
 Node *insertAtBeginning(string data, Node *head){
     Node *newNode = createNode(data);
     newNode->link = head;
     
     head = newNode;
     cout << "A new node has beed inserted at the beginning \n" <<endl;
     
     return head;
 }
 string insertAfter(string after, string data, Node *head){
     Node * temp = new Node;
     temp = head;
     while(temp->songName.compare(after) != 0){
         if(temp == NULL){
             return "No such song exist, please try again later.";
         }
         temp = temp->link;
     }
     Node *newNode = createNode(data);
     newNode->link = temp->link;
     temp->link = newNode;
     
     return "An new mode has been added after" + after + "\n";
 }
 string deleteAtEnd(Node *head){
     if(head == NULL){
         return "The linked list is empty \n";
     }
     if(head->link == NULL){
         delete head;
         return "The head has beed deleted \n";
     }
     Node *temp = new Node;
     temp = head;
     
     while(temp->link->link != NULL){
         temp = temp->link;

     }
     temp->link = NULL;
     
     return "A node has been deleted at the end \n";
 }
    Node *deleteFromBeginning(Node *head){
        if(head == NULL){
            cout << "The linked is empty \n" <<endl;
            return NULL;
        }
        if(head->link == NULL){
            delete head;
        }
        head = head->link;
        cout <<" A node has been delete from the beginning \n" << endl;
        
        return head;
    }
    Node *deleteFromGivenNode(string givenNode, Node *head){
        if(head == NULL){
            cout << "The linked list is empty. \n" << endl;
            return NULL;
        }
        if(head->songName.compare(givenNode) == 0){
            head = deleteFromBeginning(head);
            cout << "The Node " + givenNode + "has been deleted. \n" <<endl;
            return head;
        }
        Node *temp = new Node;
        Node*next = new Node;
        temp = head;
        next = temp->link;
        
        while(next->songName.compare(givenNode) != 0){
            if(temp == NULL){
                cout << "No such node exist. \n" << endl;
                return head;
            }
            next = next->link;
            temp = temp->link;
        }
        temp->link = next->link;
        cout << "The Node " + givenNode + " has been deleted. \n" <<endl;
        return head;
    }
 
int main(){
     Node *head = createNode("Sanctuary by Joji");
     
     head = insertAtEnd("Sugar By Maroon 5", head);
     head = insertAtEnd("Beautiful Girl By Sean Kingston", head);
     head = insertAtEnd("Dont Matter By Akon", head);
     head = insertAtEnd("You Got It By Vedo", head);
     traverse (head);
     head = insertAtBeginning("Rodeo By Lah Pat", head);
     head = insertAtBeginning("679 By Fetty Wap", head);
     head = insertAtBeginning("Trap Queen By Fetty Wap", head);
     head = insertAtBeginning("Mask off By Future", head);
     traverse (head);
     insertAfter ("Dilaw By Maki", "Trap Queen By Fetty Wap", head);
     insertAfter ("Gusto By  Zack Tabudlo ", "Mask off By Future", head);
     insertAfter ("When I was your Man By Bruno Mars", "Trap Queen By Fetty Wap", head);
     traverse (head);
     
     cout << deleteAtEnd(head);
     traverse (head);
     head = deleteFromBeginning(head);
     traverse (head);
     head = deleteFromGivenNode( "When I was your Man By Bruno Mars", head);
     traverse (head);
     return 0;
     
}