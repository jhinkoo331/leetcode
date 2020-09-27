#include <string>
#include <vector>
using std::string, std::vector;

const int sz = 'z' - 'A' + 1;

class WordDictionary {
public:
        /** Initialize your data structure here. */
        WordDictionary() {
                _1_constructor();
        }

        /** Adds a word into the data structure. */
        void addWord(string word) {
                _1_add_word(word);
        }

        /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
        bool search(string word) {
                return _1_search(word, 0);
        }
private:
        vector<WordDictionary*> children;
        bool this_is_a_word;

        /**
         * @brief 
         * @perf: 80, 27
         */
        void _1_constructor(){
                children.resize(sz, nullptr);
                this_is_a_word = false;
        }
        void _1_add_word(string& word){
                WordDictionary* cur = this;
                for(int i = 0; i < word.size(); ++i){
                        if(cur->children[word[i] - 'A'] == nullptr)
                                cur->children[word[i] - 'A'] = new WordDictionary();
                        cur = cur->children[word[i] - 'A'];
                }
                cur->this_is_a_word = true;
        }
        bool _1_search(string& word, int index){
                if(index == word.size())
                        return this->this_is_a_word;
                if(word[index] == '.'){
                        for(const auto& e: this->children)
                                if(e != nullptr && e->_1_search(word, index + 1))
                                        return true;
                        return false;
                }else{
                        WordDictionary* child = this->children[word[index] - 'A'];
                        if(child == nullptr)
                                return false;
                        else
                                return child->_1_search(word, index + 1);
                }
        }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

int main(){
        WordDictionary wd;
        wd.addWord("bad");
        wd.addWord("dad");
        wd.addWord("mad");
        wd.search("pad");
        wd.search("bad");
        wd.search(".ad");
        wd.search("b..");
        return 0;
}
