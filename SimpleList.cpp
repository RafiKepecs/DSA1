#include <iostream>
#include <string>
#include <list>
#include <fstream>
using namespace std;

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
  Object del_start() {
    string error = "ERROR: This list is empty!";
    Node *tmp = head;
    if(tmp == nullptr) throw error;
    head = head->next;
    Object value = tmp->data;
    delete tmp;
    return value;
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
    //cout << "SimpleList Destructor called" << "\n";
    //clear();
    //delete head;
    //delete tail;
  }
  Node* gethead(){
    return head;
  }
  string getname(){
    //cout << name << endl;
    return name;
  }
  void display(Node *head){
        if(head == nullptr)
        {
            //cout << "nullptr" << endl;
        }
        else
        {
            cout << head->data << "\n";
            display(head->next);
        }
  }
  virtual Object pop() = 0;
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
  Object pop(){
     Object temp;
     temp = this->del_start();
     return temp;
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
  Object pop(){
     Object temp;
     temp = this->del_start();
     return temp;
  }
};

template <typename Object>
SimpleList<Object>* search(list<SimpleList<Object> *> listpointers, string name1){
  typename list<SimpleList<Object> *>::iterator it;
  for (it = listpointers.begin();
      it != listpointers.end();
      it++){
        if ((*it)->getname() == name1){
          return *it;
        }
        else{
        }
  }
  return nullptr;
}

void parse(string input, string output){
  list<SimpleList<int> *> listSLi; // all integer stacks and queues
  list<SimpleList<double> *> listSLd; // all double stacks and queues
  list<SimpleList<string> *> listSLs; // all string stacks and queues
  ifstream file (input);
  ofstream file2 (output);
  string str;
  string search1;
  string name1 = "";
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

    file2 << "PROCESSING COMMAND: ";
    if (word0 == "create"){
      file2 << word0 << " " << word1 << " " << word2 << "\n";

      if (word1[0] == 'i'){
        //integers
        string intListName = word1;
        SimpleList<int> *pSLi;
        if (search(listSLi, word1) == nullptr){
          if (word2 == "stack"){
            pSLi = new Stack<int>(intListName);
            listSLi.push_front(pSLi);
            //cout << pSLi->getname() << " stack" << "\n";
            //cout << word0 << " " << word1 << " " << word2 << endl;
          }
          else if (word2 == "queue"){
            pSLi = new Queue<int>(intListName);
            listSLi.push_front(pSLi);
            //cout << pSLi->getname() << " queue" << "\n";
            //cout << word0 << " " << word1 << " " << word2 << endl;
          }
        }
        else{
          file2 << "ERROR: This name already exists!" << "\n";
        }
      }
      else if(word1[0] == 'd'){
        //doubles
        string doubleListName = word1;
        SimpleList<double> *pSLd;
        if (word2 == "stack"){
          pSLd = new Stack<double>(doubleListName);
          listSLd.push_front(pSLd);
          //cout << pSLd->getname() << " stack" << "\n";
          //cout << word0 << " " << word1 << " " << word2 << endl;
        }
        if (word2 == "queue"){
          pSLd = new Queue<double>(doubleListName);
          listSLd.push_front(pSLd);
          //cout << pSLd->getname() << " queue" << "\n";
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
          //cout << pSLs->getname() << " stack" << "\n";
          //cout << word0 << " " << word1 << " " << word2 << endl;
        }
        if (word2 == "queue"){
          pSLs = new Queue<string>(stringListName);
          listSLs.push_front(pSLs);
          //cout << pSLs->getname() << " queue" << "\n";
          //cout << word0 << " " << word1 << " " << word2 << endl;
        }
      }
    }
    else if (word0 == "push"){
      file2 << word0 << " " << word1 << " " << word2 << "\n";
      if (word1[0] == 'i'){
        SimpleList<int>* result = search <int> (listSLi, word1);
        if (result == nullptr){
          file2 << "ERROR: This name does not exist!" << "\n";
        }
        else{
          result->push(stoi(word2));
        }
      }
      if (word1[0] == 'd'){
        SimpleList<double>* result = search <double> (listSLd, word1);
        if (result == nullptr){
          file2 << "ERROR: This name does not exist!" << "\n";
        }
        else{
          result->push(stod(word2));
        }
      }
      if (word1[0] == 's'){
        SimpleList<string>* result = search <string> (listSLs, word1);
        if (result == nullptr){
          file2 << "ERROR: This name does not exist!" << "\n";
        }
        else{
          result->push(word2);
        }
      }
    }
    else if (word0 == "pop"){
      file2 << word0 << " " << word1 << "\n";
      if (word1[0] == 'i'){
        SimpleList<int>* result = search <int> (listSLi, word1);
        if (result == nullptr){
          file2 << "ERROR: This name does not exist!" << "\n";
        }
        else{
          try { // useful to use exception handling when the error is under several layers of functions and when returning abstract type
            int value = result->pop();
            file2 << "Value popped: " << value << "\n";
          }
          catch(string msg) {
            file2 << msg << "\n";
          }
        }
      }
      if (word1[0] == 'd'){
        SimpleList<double>* result = search <double> (listSLd, word1);
        if (result == nullptr){
          file2 << "ERROR: This name does not exist!" << "\n";
        }
        else{
          try {
            double value = result->pop();
            file2 << "Value popped: " << value << "\n";
          }
          catch(string msg) {
            file2 << msg << "\n";
          }
        }
      }
      if (word1[0] == 's'){
        SimpleList<string>* result = search <string> (listSLs, word1);
        if (result == nullptr){
          file2 << "ERROR: This name does not exist!" << "\n";
        }
        else{
          try {
            string value = result->pop();
            file2 << "Value popped: " << value << "\n";
          }
          catch(string msg) {
            file2 << msg << "\n";
          }
        }
      }
    }
  }
  file.close();
  file2.close();
}

int main(){
  string input, output;
  cout << "Enter name of input file: ";
  cin >> input;

  cout << "Enter name of output file: ";
  cin >> output;
  parse(input, output);
  return 0;
}
