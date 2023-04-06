#include <iostream>

using std::cout;
using std::endl;

struct Node
{
int key = 0;
Node* next = nullptr;
};

void push_back(Node*& head_ref, int new_key) 
{
    Node* new_node = new Node{new_key, nullptr};
    if (head_ref == nullptr) 
    {
        head_ref = new_node;
        return;
    }
    Node* ptr = head_ref;
    while (ptr->next != nullptr) 
    {
        ptr = ptr->next;
    }
    ptr->next = new_node;
}
void print_list(Node* head_ref)
{
    Node* current = new Node;
    current = head_ref;
    while(current != nullptr)
    {
        cout << " " << current->key;
        current = current->next;
    }
    cout  << endl;
}


int main() {
  Node* HEAD = nullptr;
  push_back(HEAD, 0);
  push_back(HEAD, 1);
  push_back(HEAD, 2);
  print_list(HEAD);
  return 0;
}