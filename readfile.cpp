#include <iostream>
#include <string>
#include <list>
using namespace std;
#include <fstream>

template <typename Object>
class SimpleList {
private:
  string name;
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
  SimpleList(string name) {
    //cout << "SimpleList Constructor called" << endl;
    this->name = name;
    head = nullptr;
    tail = nullptr;
    //cout << "Name is " << name << endl;
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
  Stack(): SimpleList<Object>() {}
  Stack(string listName) : SimpleList<Object>(listName) {
    //cout << "Stack Constructor" << endl;
    //cout << listName << endl;
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
  Queue() : SimpleList<Object>() {}
  Queue(string listName) : SimpleList<Object>(listName) {
    //cout << "Stack Constructor" << endl;
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

void input(){
  list<SimpleList<int> *> listSLi; // all integer stacks and queues
  list<SimpleList<double> *> listSLd; // all double stacks and queues
  list<SimpleList<string> *> listSLs; // all string stacks and queues
  ifstream file ("test.txt");
  string str;
  string word0= "";
  string word1 = "";
  string word2 = "";
  int word_counter = 0;
  bool two_words = 0;
  while (getline(file,str)){ // for every line
        word0 = "";
        word1 = "";
        word2 = "";
        for (int i = 0; i < str.length(); i++){
            //first word
            if(word_counter == 0){
                if (str[i] != ' '){
                  word0 = word0 + str[i];
                }
                else{
                  word_counter++;
                }
            }
            else if (word_counter == 1){
                if (str[i] != ' ' && i != str.length()){
                  word1 = word1 + str[i];
                }
                else if (str[i] == ' '){
                  word_counter++;
                }
                else if (i == str.length()){
                  word2 = "";
                }
            }
            else if (word_counter == 2){
                if (i != str.length()){
                  word2 = word2 + str[i];
                }
            }
        }
        word_counter = 0;
        //cout << word0 << " " << word1 << " " << word2 << endl;



    if (word0 == "create"){
      if (word1[0] == 'i'){
        //integers
        string intListName = word1;
        SimpleList<int> *pSLi;
        if (word2 == "stack"){
          pSLi = new Stack<int>(intListName);
          listSLi.push_front(pSLi);
          //cout << word0 << " " << word1 << " " << word2 << endl;
        }
        if (word2 == "queue"){
          pSLi = new Queue<int>(intListName);
          listSLi.push_front(pSLi);
          //cout << word0 << " " << word1 << " " << word2 << endl;
        }
      }
      else if(word1[0] == 'd'){
        //doubles
        string doubleListName = word1;
        SimpleList<double> *pSLd;
        if (word2 == "stack"){
          pSLd = new Stack<double>(doubleListName);
          listSLd.push_front(pSLd);
          //cout << word0 << " " << word1 << " " << word2 << endl;
        }
        if (word2 == "queue"){
          pSLd = new Queue<double>(doubleListName);
          listSLd.push_front(pSLd);
          //cout << word0 << " " << word1 << " " << word2 << endl;
        }
      }
      else if(word1[0] == 's'){
        //strings
        string stringListName = word1;
        SimpleList<string> *pSLs;
        if (word2 == "stack"){
          pSLs = new Stack<string>(stringListName);
          listSLs.push_front(pSLs);
          //cout << word0 << " " << word1 << " " << word2 << endl;
        }
        if (word2 == "queue"){
          pSLs = new Queue<string>(stringListName);
          listSLs.push_front(pSLs);
          //cout << word0 << " " << word1 << " " << word2 << endl;
        }
      }
    }
    if (word0 == "push"){
      //cout << "pushing" << endl;
    }
  }
}
// void input2(){
//   ifstream file ("test.txt");
//   string str;
//   while (getline(file,str)){
//     for(int i = 0; i < str.length() ; i++){
//       if (str[i] != ' ' && str[i] != '\n'){
//           //cout << "test" << endl;
//       }
//       else {
//         //cout << "bob" << endl;
//       }
//     }
//   }
// }
int main(){
  //SimpleList a;
  //   if (str.compare("Stack<string> s;")){
  //     // Stack<string> s("BOB");
  //     // Queue<int> q;
  //     // cout << "Stack" << endl;
  //     // s.push("Really is a string!");
  //     // s.push("2");
  //     // s.pop();
  //     // s.push("15");
  //     // s.push("3");
  //     // s.pop();
  //     // s.display(s.gethead());
  //     // cout << "\n" << "Queue" << endl;
  //     // q.push(1);
  //     // q.push(2);
  //     // q.pop();
  //     // q.push(15);
  //     // q.push(3);
  //     // q.pop();
  //     // q.display(q.gethead());
  //   }
  input();

  return 0;
}
