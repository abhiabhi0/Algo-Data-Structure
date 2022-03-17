//Given sorted Doubly LL of unique integers. Count number of 
//pairs of node whose sum of value is equal to k.

#include <iostream>

class DoublyLinkedList
{
    struct Node
    {
        int data;
        Node* next;
        Node* prev;
        Node(int val): data(val), next(nullptr), prev(nullptr) {}
    };
    Node *head, *tail;

  public:
      DoublyLinkedList(): head(nullptr), tail(nullptr) {}

     ~DoublyLinkedList()
      {
          Node *tmp = nullptr;
          while (head)
          {
              tmp = head;
              head = head->next;
              delete tmp;
          }
          head = nullptr;
      }

      void insertFront(int val)
      {
          Node *node = new Node(val);
          Node *tmp = head;
          if (head == nullptr)
          {
              head = node;
              tail = node;
          }
          else
          {
              node->next = head;
              head = node;
              node->next->prev = node;
          }
      }

      void insertBack(int val)
      {
          Node *node = new Node(val);
          if(tail->next == nullptr)
          {
              tail->next = node;
              node->prev = tail;
              tail = node;
          }
      }

      void display() 
      {
          Node *node = head;
          while(node != nullptr)
          {
              std::cout << node->data << " ";
              node = node->next;
          }
      } 

      int count_pairs(int k)
      {
          Node *p1 = head;
          Node *p2 = tail;
          int count = 0;

          while (p1 != p2 && p2->next != p1)
          {
              if ((p1->data + p2->data) < k)
              {
                  p1 = p1->next;
              }
              else if ((p1->data + p2->data) > k)
              {
                  p2 = p2->prev;
              }
              else  
              {
                  count++;
                  p1 = p1->next;
                  p2 = p2->prev;
              }
          }
          return count;
      }
};

int main(){
  #ifndef FILE_INOUT
 
      freopen("in.txt", "r", stdin);
  
      freopen("out.txt", "w", stdout);
   
  #endif

  DoublyLinkedList l1;
  l1.insertFront(-3);
  l1.insertBack(0);
  l1.insertBack(3);
  l1.insertBack(6);
  l1.insertBack(14);
  l1.insertBack(25);
  l1.display();
  std::cout << "\n" << l1.count_pairs(17) << "\n";
  return 0;
}
