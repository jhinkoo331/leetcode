
class Node{
public:
	int val;
	Node* next;
	Node(): val(0), next(nullptr) {};
	Node(int _val): val(_val), next(nullptr) {};
	Node(int _val, Node* _next): val(_val), next(_next) {};
};

/**
 * * perf: [5, 55]
 * TODO: discuss
 */
class MyLinkedList {
public:
	int length;
	Node* head;
	Node* tail;
	/** Initialize your data structure here. */
	MyLinkedList() {
		length = 0;
		head = new Node();
		tail = head;
	}

	/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
	int get(int index) {
		//* index in valid in range [0, length)
		if(index < 0 || index >= length)
			return -1;
		Node* cur = head->next;
		while(index--)
			cur = cur->next;
		return cur->val;
	}

	/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
	void addAtHead(int val) {
		Node* cur = new Node(val, head->next);
		head->next = cur;
		length++;
		if(head == tail)
			tail = cur;
	}

	/** Append a node of value val to the last element of the linked list. */
	void addAtTail(int val) {
		tail->next = new Node(val);
		tail = tail->next;
		length++;
	}

	/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
	void addAtIndex(int index, int val) {
		if(index == length){
			tail->next = new Node(val);
			tail = tail->next;
			length++;
		}else if(0 <= index && index < length){
			Node* prev = head;
			while(index--)
				prev = prev->next;
			Node* _new = new Node(val, prev->next);
			prev->next = _new;
			length++;
		}
	}

	/** Delete the index-th node in the linked list, if the index is valid. */
	void deleteAtIndex(int index) {
		if(index < 0 || index >= length)
			return;
		Node* prev = head;
		for(int i = 0; i < index; ++i)
			prev = prev->next;
		Node* temp = prev->next;
		prev->next = temp->next;
		delete temp;
		if(index == length - 1)
			tail = prev;
		length--;
	}
};


/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

int main(){
	MyLinkedList mll;
	mll.addAtIndex(0, 10);
	mll.addAtIndex(0, 20);
	mll.addAtIndex(1, 30);
	mll.get(0);
	return 0;
}

