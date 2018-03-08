#include <iostream>
#include <vector>
#include <queue>

class HuffmanCodes
{
 struct Node
 {
  char data;
  size_t freq;
  Node* left;
  Node* right;

  Node()
  {
    data = '\0';
    freq = 0;
  }
  Node(char data, size_t freq) : data(data),
                                 freq(freq),
                                 left(nullptr),
                                 right(nullptr)
                                 {}
 ~Node()
 {
   delete left;
   delete right;
 }
 };

 struct compare
 {
  bool operator()(Node* l, Node* r)
  {
    return (l->freq > r->freq);
  }
};

Node* top;

void printCode(Node* root, std::string str)
{
  if(root == nullptr)
   return;

 if(root->data != '$')
 {
   std::cout << root->data << " : " << str << "\n";
 }
 printCode(root->left, str + "0");
 printCode(root->right, str + "1");
}

public:
  HuffmanCodes() {}
  ~HuffmanCodes()
  {
    delete top;
  }
  void GenerateCode(const std::vector<char>& data, const std::vector<size_t>& freq)
  {
   Node* left;
   Node* right;

   std::priority_queue<Node*, std::vector<Node*>, compare > minHeap;

   for(size_t i = 0; i < data.size(); ++i)
   {
      minHeap.push(new Node(data[i], freq[i]));
   }

    while(minHeap.size() != 1)
    {
      left = minHeap.top();
      minHeap.pop();

      right = minHeap.top();
      minHeap.pop();

      top = new Node('$', left->freq + right->freq);
      top->left  = left;
      top->right = right;
      minHeap.push(top);
     }
    printCode(minHeap.top(), "");
 }
};

 int main()
 {
  HuffmanCodes set1;
  std::vector<char> data({'d', 'e', 'b', 'c', 'a', 'f'});
  std::vector<size_t> freq({16, 9, 13, 12, 45, 5});
  size_t size = data.size();
  set1.GenerateCode(data, freq);

  return 0;
}
