#include <iostream>
#include <algorithm>

template<typename T>
class BinaryTree
{
  struct Node
  {
    T data;
    Node* parent;
    Node* leftChild;
    Node* rightChild;
    Node(T const& value) : data(value),
                           parent(nullptr),
                           leftChild(nullptr),
                           rightChild(nullptr)
                           {}
    //move constructor
    //It  moves the content of 'value' into the node
    Node(T&& value) : data(std::move(value)),
                      parent(nullptr),
                      leftChild(nullptr),
                      rightChild(nullptr)
                      {}
    //to enter any number and type of arguments
    template<typename... Args>
    Node(Args&&... args) : data(std::forward<Args>(args)...),
                           parent(nullptr),
                           leftChild(nullptr),
                           rightChild(nullptr)
                           {}

    ~Node()
    {
      delete leftChild;
      delete rightChild;
    }
  };

public:
  Node* root;
  BinaryTree() : root(nullptr) {}
  BinaryTree(BinaryTree const&)            = delete;
  BinaryTree& operator=(BinaryTree const&) = delete;
  ~BinaryTree()
  {
    delete root;
  }

  bool isEmpty() const
  {
    return root == nullptr;
  }

  void insertValue(T const& value)
  {
    Node* node = new Node(value);
    Node* tmp;

    if(isEmpty())
    {
      root = node;
      return;
    }
    else
    {
      Node* current = root;
      while(current)
      {
        tmp = current;
        if(node->data > current->data)
          current = current->rightChild;
        else current = current->leftChild;
      }

      if(node->data < tmp->data)
        tmp->leftChild = node;
      else tmp->rightChild = node;

      node->parent = tmp;
    }
  }

  void insertValue(T&& value)
  {
    Node* node = new Node(std::move(value));
    Node* tmp;

    if(isEmpty())
    {
       root = node;
       return;
    }
    else
    {
      Node* current = root;
      while(current)
      {
        tmp = current;
        if(node->data > current->data)
          current = current->rightChild;
        else current = current->leftChild;
      }

      if(node->data < tmp->data)
        tmp->leftChild = node;
      else tmp->rightChild = node;

      node->parent = tmp;
    }
  }

  template<typename... Args>
  void insertValue(Args&&... args)
  {
    Node* tmp;
    Node* node = new Node(std::forward<Args>(args)...);

    if(isEmpty())
    {
      root = node;
      return;
    }
    else
    {
      Node* current = root;
      while(current)
      {
        tmp = current;
        if(node->data > current->data)
          current = current->rightChild;
        else current = current->leftChild;
      }

      if(node->data < tmp->data)
        tmp->leftChild = node;
      else tmp->rightChild = node;

      node->parent = tmp;
    }
  }

    void deleteValue(T value, Node* node)
    {
      if(!node)
        return;
      if(node->data < value)
        deleteValue(value, node->rightChild);
      else if(node->data > value)
        deleteValue(value, node->leftChild);
      else
      {
        if(node->leftChild == nullptr && node->rightChild == nullptr)
        {
          if(node->parent == nullptr)
          {
            root = nullptr;
            delete node;
            return;
          }
          else if(node->parent->leftChild  == node)
          {
            node->parent->leftChild = nullptr;
            delete node;
            return;
          }
          else
          {
            node->parent->rightChild = nullptr;
            delete node;
            return;
          }
        }

        if(node->rightChild != nullptr)
        {
          T temp = node->data;
          node->data = node->rightChild->data;
          node->rightChild->data = temp;
          deleteValue(value, node->rightChild);
          return;
        }
        if(node->leftChild != nullptr)
        {
          T temp = node->data;
          node->data = node->leftChild->data;
          node->leftChild->data = temp;
          deleteValue(value, node->leftChild);
          return;
        }
      }
    }

    void deleteValue(T value)
    {
      deleteValue(value, root);
    }
    void inOrder(Node* node)
    {
      if(node != nullptr)
      {
        inOrder(node->leftChild);
        std::cout << " " << node->data;
        inOrder(node->rightChild);
      }
      else return;
    }

    void preOrder(Node* node)
    {
      if(node != nullptr)
      {
        std::cout << " " << node->data;
        if(node->leftChild) preOrder(node->leftChild);
        if(node->rightChild) preOrder(node->rightChild);
      }
      else return;
    }

    void postOrder(Node* node)
    {
      if(node != nullptr)
      {
        if(node->leftChild) postOrder(node->leftChild);
        if(node->rightChild) postOrder(node->rightChild);
        std::cout << " " << node->data;
      }
      else return;
    }

  void print_inOrder()
  {
    inOrder(root);
  }

  void print_preOrder()
  {
    preOrder(root);
  }

  void print_postOrder()
  {
    postOrder(root);
  }

private:

  Node* search(Node* root, T value) const
  {
    if(root == nullptr || value == root->data)
      return root;

    if(value < root->data)
      return search(root->leftChild, value);

    else
      return search(root->rightChild, value);
  }

  Node* minimum(Node* root)
  {
      while(root->leftChild != nullptr)
          root = root->leftChild;
      return root;
  }

  Node* maximum(Node* root)
  {
      while(root->rightChild != nullptr)
          root = root->rightChild;
      return root;
  }

  //Successor - a node which has the next higher key
  Node* successor(Node* node)
  {
      if(node->rightChild != nullptr)
        return minimum(node->rightChild);

      Node* temp = node->parent;

      while(temp != nullptr && node == temp->rightChild)
      {
          node = temp;
          temp = temp->parent;
      }
      return temp;
  }

  //Predecessor - a node which has the next lower key
  Node* predecessor(Node* node)
  {
      if(node->leftChild != nullptr)
        return maximum(node->leftChild);

      Node* temp = node->parent;

      while(temp != nullptr && node == temp->leftChild)
      {
          node = temp;
          temp = temp->parent;
      }
      return temp;
  }

};

int main()
{
  BinaryTree<int> bt1;
  bt1.insertValue(100);
  bt1.insertValue(20);
  bt1.insertValue(30);
  bt1.insertValue(400);
  bt1.insertValue(50);
  std::cout << "In Order: ";
  bt1.print_inOrder();
  std::cout<<"\n";
  std::cout << "Pre Order: ";
  bt1.print_preOrder();
  std::cout<<"\n";
  std::cout << "Post Order: ";
  bt1.print_postOrder();
  std::cout << "\nDeleting 20 ";
  bt1.deleteValue(20);
  std::cout<<"\n";
  std::cout << "In Order: ";
  bt1.print_inOrder();
  std::cout<<"\n";
  std::cout << "Pre Order: ";
  bt1.print_preOrder();
  std::cout<<"\n";
  std::cout << "Post Order: ";
  bt1.print_postOrder();
  std::cout << "\n";
}
