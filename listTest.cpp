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

void parse(){
  list<SimpleList<int> *> listSLi; // all integer stacks and queues
  list<SimpleList<double> *> listSLd; // all double stacks and queues
  list<SimpleList<string> *> listSLs; // all string stacks and queues

  string listName;
  SimpleList<int> *pSLi;
  pSLi = new Stack<int>(listName);
  listSLi.push_front(pSLi);//list of pointers to integer stacks and queues. built in c++ function
}

void open(ifstream file){

}

void input(){
  ifstream file ("test.txt");
  string str;
  string word_one = "";
  string word_two = "";
  string word_three = "";
  int word_counter = 0;
  while (getline(file,str)){ // for every line
      for (auto x : str){
          if (word_counter == 0){
              if (x == ' '){
                cout << word_one << endl;
                word_one = "";
                word_counter++;
              }
              else{
                word_one = word_one + x;
              }
          }
          else if (word_counter > 0){
              if (x == ' '){
                cout << word_two << endl;
                word_two = "";
                word_counter++;
              }
              else{
                word_two = word_two + x;
              }
          }
          // else if (word_counter == 2){
          //
          //     if (x == '\0'){
          //       //cout << "test" << endl;
          //       word_three = word_three + x;
          //     }
          //     else{
          //       //cout << "test" << endl;
          //       cout << word_three << endl;
          //       word_three = "";
          //       word_counter++;
          //     }
          // }

      }
      cout << word_two << endl;
      word_counter = 0;
    //cout << word_one << ". Word count is " << word_counter << endl;
    //   for (int i = 0; i < str.length(); i++){ // loop through the line
    //     if (word_counter == 0){
    //       if (str[i] != ' '){ // if not space
    //         word_one[i] = str[i]; // store the word into word_one
    //         // cout << word_one[i];
    //         // cout << i << endl;
    //         //cout << word_one[4];
    //       }
    //       else {
    //         if (word_one == "create"){
    //           cout << "oh" << endl;
    //         }
    //         //cout << word_one << i << endl;
    //         word_counter++;
    //         //cout << "\n";
    //         //cout << word_one << endl;;
    //       }
    //     }
    //   }
    //   cout << "\n";
    //
    //     // for (int j = 0; str[i] != ' '; i++){
    //     //   word_one[i] = str[i];
    //     //   //cout << str[i];
    //     //   if ( word_one == "create" ){
    //     //     cout << "Make a stack!" << endl;
    //     //   }
    //     //   if (str[i] == ' '){
    //     //     break;
    //     //   }
    //   //}
    //
    // //cout << word_one << "\n";
  }

}
void input2(){
  ifstream file ("test.txt");
  string str;
  while (getline(file,str)){
    for(int i = 0; i < str.length() ; i++){
      if (str[i] != ' ' && str[i] != '\n'){
          cout << "test" << endl;
      }
      else {
        cout << "bob" << endl;
      }
    }
  }
}
int main(){
  //SimpleList a;
  ifstream file("test.txt");
  string str;
  while (getline(file,str)){
    //cout << str << endl;
    if (str.compare("Stack<string> s;")){
      // Stack<string> s("BOB");
      // Queue<int> q;
      // cout << "Stack" << endl;
      // s.push("Really is a string!");
      // s.push("2");
      // s.pop();
      // s.push("15");
      // s.push("3");
      // s.pop();
      // s.display(s.gethead());
      // cout << "\n" << "Queue" << endl;
      // q.push(1);
      // q.push(2);
      // q.pop();
      // q.push(15);
      // q.push(3);
      // q.pop();
      // q.display(q.gethead());
    }
  }
  parse();
  //input();
  input2();

  return 0;
}
