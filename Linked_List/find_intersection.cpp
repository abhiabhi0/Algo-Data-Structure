/** Find intersection point of two LLs **/


Node* find_intersection(Node* head1, Node* head2)
{
	int len1 = 0, len2 = 0;

	Node *node1 = head1, *node2 = head2;

	while (node1 != NULL)
	{
		len1++;
		node1 = node1->next;
	}

	while (node2 != NULL)
	{
		len2++;
		node2 = node2->next;
	}
	node1 = head1;
	node2 = head2;

	if (len1 > len2)
	{
		int diff = len1 - len2;

		while (diff > 0)
		{
			node1 = node1->next;
			diff--;
		}
	}
	else if (len1 < len2)
	{
		int diff = len2 - len1;

		while (diff > 0)
		{
			node2 = node2->next;
			diff--;
		}
	}

	while (node1 != node2)
	{
		node1 = node1-next;
		node2 = node2->next;
	}
	return node1;
}
