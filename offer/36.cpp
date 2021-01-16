#define NULL 0
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
        Node* treeToDoublyList(Node* root) {
                return _1(root);
        }
private:
        Node* _1(Node* root){
                Node* last_node = nullptr;
                if(root)
                        last_node = link(root, nullptr);
                else
                        return nullptr;
                Node* first_node = last_node;
                while(first_node->left)
                        first_node = first_node->left;
                first_node->left = last_node;
                last_node->right = first_node;
                return first_node;
        }
        /**
         * @brief 4ms, 98
         * 
         * @param root not null
         * @param prev previous visited node in in-order traverse
         * @return Node* the last node visited in sub-tree root
         */
        Node* link(Node* root, Node* prev){
                if(root->left)
                        prev = link(root->left, prev);
                root->left = prev;
                if(prev)
                        prev->right = root;
                if(root->right)
                        return link(root->right, root);
                else
                        return root;
        }
};
