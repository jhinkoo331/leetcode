#include <string>
#include <vector>
using std::string;
using std::vector;

/**
 * @brief 
 * @perf: [40, 23]
 */
class Trie {
public:
	/** Initialize your data structure here. */
	Trie() {
		is_tail = false;
		children.resize(26, nullptr);
	}

	/** Inserts a word into the trie. */
	void insert(const string& word) {
		Trie* cur = this;
		for(int i = 0; i < word.size(); ++i){
			int index = word[i] - 'a';
			if(cur->children[index] == nullptr){
				cur->children[index] = new Trie();
			}
			cur = cur->children[index];
		}
		cur->is_tail = true;
	}

	/** Returns if the word is in the trie. */
	bool search(const string& word) {
		Trie* cur = this;
		for(int i = 0; i < word.size(); ++i){
			cur = cur->children[word[i] - 'a'];
			if(cur == nullptr)
				return false;
		}
		return cur->is_tail;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(const string& prefix) {
		Trie* cur = this;
		for(int i = 0; i < prefix.size(); ++i){
			cur = cur->children[prefix[i] - 'a'];
			if(cur == nullptr)
				return false;
		}
		return true;
	}
private:
	bool is_tail;
	vector<Trie*> children;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */