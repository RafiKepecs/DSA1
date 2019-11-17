#include <iostream>
#include <string>
using namespace std;

class SimpleList {
private:
  string name = "memememme";
public:
  class Node {
  public:
    int data;
    Node *next;
  };
  Node *head, *tail;
  SimpleList() {
    cout << "SimpleList Constructor called" << endl;
    head = nullptr;
    tail = nullptr;
  }
  ~SimpleList(){
    cout << "SimpleList Destructor called" << endl;
    //clear();
    //delete head;
    //delete tail;
  }
  void add_end(int n){
    Node *tmp = new Node;
    tmp->data = n;
    tmp->next = nullptr;
    if(head == nullptr)
    {
        head = tmp;
        tail = tmp;
    }
    else
    {
        tail->next = tmp;
        tail = tail->next;
    }
    cout << "Node added" << endl;
  }
  void add_start(int n){
    Node *tmp = new Node;
    tmp -> data = n;
    tmp -> next = head;
    head = tmp;
  }
  void del_start(){
    Node *tmp = head;
    head = head->next;
    delete tmp;
    cout << "delete" << endl;
  }
  Node* gethead(){
    return head;
  }
  string getname(){
    cout << name << endl;
    return name;
  }
  void display(Node *head){
        if(head == nullptr)
        {
            cout << "nullptr" << endl;
        }
        else
        {
            cout << head->data << endl;
            display(head->next);
        }
  }

};

int main(){
  SimpleList a;
//  a.name = "mememem";
  a.add_end(1);
  a.add_end(2);
  a.add_end(15);
  a.add_start(3);
  a.del_start();
  a.del_start();
  a.display(a.gethead());
  a.getname();
  return 0;
}
