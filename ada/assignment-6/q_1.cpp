#include <iostream>
#include <cstdlib>
using namespace std;

struct node{
    
        int data;
        node *next;
    
        };

class CircList {
    
        public:     
        void add_node( struct node **head, int item ){
            struct node *t = *head;
            struct node *N = ( struct node * )malloc( sizeof( struct node ) );

            if( t == NULL ){

                *head = N;
                N -> data = item;
                N -> next = *head;
                return;         
            }

            else {
                while ( t -> next != *head ){
                    
                    t = t -> next;
                }

                t -> next = N;
                N->data = item;
                N->next = *head;
                
            }
            
        }

        void delete_item_node( struct node *head, int item ){
        
            struct node *t = head;

            while ( t -> next -> data != item){
                    t = t -> next;
            }

            struct node * temp = NULL;
            
            temp = t -> next;
            t -> next = t -> next -> next;
            free(temp);

        }

        void is_empty(struct node * head){
            if (head == NULL){
                cout<<"\nLinklist is empty\n";
            } else {
                cout<<"\nLinklist not empty\n";
            }

        }

        void search_node(struct node *head, int item){
                struct node *t = head;

                while ( t -> next != head ){   
                        if (t->data == item){
                            cout<<"\nElement found\n";
                            return;
                        }
                        t = t -> next;
                }
                cout<<"\nElement not found\n";
        }                

        void print_cir_list( struct node *head ){
            
            struct node *t = head;
            cout<<"\nCircular Linklist\n";
            
            while( t -> next != head ){
                cout<< t -> data<<"\t";
                t = t -> next;
            }

            cout<< t -> data<<"\t";
            cout<<"\n";
        }
    
};


int main(){
struct node *head = NULL;
CircList C;

int t = 1;

while(t){

        cout<<"\nEnter 1 to add node to linklist\n";
        cout<<"\nEnter 2 to delete node\n";
        cout<<"\nEnter 3 to search node\n";
        cout<<"\nEnter 4 to print linklist\n";
        cout<<"\nEnter 5 to exit\n\n";

        int c;
        cin>>c;

            switch(c){
                int item;
                case 1: cout<<"\nEnter item to add\n";
                        cin>>item;
                        C.add_node(&head, item);
                        break;

                case 2: cout<<"\nEnter item to delete\n";
                        cin>>item; 
                        C.delete_item_node(head, item);
                        break;

                case 3: cout<<"\nEnter item to search\n";
                        cin>>item; 
                        C.search_node(head, item);
                        break;

                case 4: C.print_cir_list(head);
                        break;

                case 5: t = 0;
            }
        }

}

