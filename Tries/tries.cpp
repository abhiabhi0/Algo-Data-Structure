class TrieNode
{
  public:
	unordered_map<char, TrieNode> um;
	bool end;

	TrieNode()
	{
		end = false;
	}
};

class Trie  
{
	TrieNode root;
};


//TC : O(l), l = length of word
void insert(string word)
{
	TrieNode curr = root;
	for (int i = 0; i < word.length(); ++i)
	{
		char ch = word[i];

		if (!curr.um[ch])
		{
			curr.um.insert({ch, new TrieNode()});
		}
		curr = curr.um[ch];
	}
}

//TC : O(l), l = length of word
bool search(string word)
{
	TrieNode curr = root;
	for (int i = 0; i < word.length(); ++i)
	{
		char ch = word[i];

		if (!curr.um[ch])
		{
			return false;
		}
		return curr.end;
	}
}

