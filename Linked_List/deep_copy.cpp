/** Clone (Deep copy) a LL with random pointer **/

/**
* class Node
* {
* 		int val;
* 		Node* next;
* 		Node* random;
* };
**/

#include <unordered_map>

Node* deep_copy(Node* head)
{
	std::unordered_map<Node*, Node*> nodes_map;

	Node* new_head = new Node(head->val);
	nodes_map.insert({head, new_head});

	Node* curr = head->next;
	Node* prev = new_head;

	while (curr != NULL)
	{
		Node* node = new Node(curr->val);
		nodes_map.insert({curr, node});

		prev->next = node;
		prev = node;

		curr = curr->next;
	}

	curr = head;
	Node* curr_copy = new_head;

	while (curr != NULL)
	{
		curr_copy->random = nodes_map[curr->random];
		curr = curr->next;
		curr_copy = curr_copy->next;
	}

	return new_head;
}
