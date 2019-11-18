#include <iostream>
#include <string>
using namespace std;

template <typename Object>
class SimpleList {
private:
  string name = "memememme";
  class Node {
  public:
    Object data;
    Node *next;
  };
protected:
  void add_end(Object n){
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
  void add_start(Object n){
    Node *tmp = new Node;
    tmp -> data = n;
    tmp -> next = head;
    head = tmp;
  }
  void del_start() {
    Node *tmp = head;
    head = head->next;
    delete tmp;
    //cout << "delete" << endl;
  }
public:
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
  virtual void push(Object) = 0;
};

template <typename Object>
class Stack : public SimpleList<Object> {
public:
  Stack() : SimpleList<Object>() {
    cout << "Stack Constructor" << endl;
  }
  void push(Object n){
    this->add_start(n);
    //cout << "push" << endl;
  }
  void pop(){
     this->del_start();
     //cout << "pop" << endl;
  }
};

template <typename Object>
class Queue : public SimpleList<Object> {
public:
  Queue() : SimpleList<Object>() {
    cout << "Queue Constructor" << endl;
  }
  void push(Object n){
    this->add_end(n);
    //cout << "push" << endl;
  }
  void pop(){
     this->del_start();
     //cout << "pop" << endl;
  }
};

int main(){
  //SimpleList a;
  Stack<string> s;
  Queue<int> q;
  cout << "Stack" << endl;
  s.push("Really is a string!");
  s.push("2");
  s.pop();
  s.push("15");
  s.push("3");
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
