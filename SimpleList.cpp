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
    //cout << "SimpleList Constructor called" << endl;
    head = nullptr;
    tail = nullptr;
  }
  ~SimpleList(){
    //cout << "SimpleList Destructor called" << endl;
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
    //cout << "Node added" << endl;
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
    //cout << "delete" << endl;
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
            //cout << "nullptr" << endl;
        }
        else
        {
            cout << head->data << endl;
            display(head->next);
        }
  }
  virtual void pop() = 0;
  virtual void push(int) = 0;
};

class Stack : public SimpleList {
public:
  Stack() : SimpleList() {
    cout << "Stack Constructor" << endl;
  }
  void push(int n){
    add_start(n);
    //cout << "push" << endl;
  }
  void pop(){
     del_start();
     //cout << "pop" << endl;
  }
};

class Queue : public SimpleList {
public:
  Queue() : SimpleList() {
    cout << "Queue Constructor" << endl;
  }
  void push(int n){
    add_end(n);
    //cout << "push" << endl;
  }
  void pop(){
     del_start();
     //cout << "pop" << endl;
  }
};

int main(){
  //SimpleList a;
  Stack s;
  Queue q;
  cout << "Stack" << endl;
  s.push(1);
  s.push(2);
  s.pop();
  s.push(15);
  s.push(3);
  s.pop();
  s.display(s.gethead());
  cout << "\n" << "Queue" << endl;
  q.push(1);
  q.push(2);
  q.pop();
  q.push(15);
  q.push(3);
  q.pop();
  q.display(q.gethead());
  return 0;
}
