#include"../include/SearchTree.h"

set::set(int data) {
	_root = new Node(data);
	_size = 1;
}

bool set::insert(int key) {
	if (!_root) {
		_root = new Node(key);
		_size = 1;
		return true;
	}

	bool flag = false;
	Node* temp = _root;
	while (!flag) {
		if (!temp->left_node && temp->data > key) {
			temp->left_node = new Node(key);
			flag = true;
		}
		if (!temp->right_node && temp->data < key) {
			temp->right_node = new Node(key);
			flag = true;
		}
		if (temp->data == key)
			return false;
		if (temp->data > key)
			temp = temp->left_node;
		else 
			temp = temp->right_node;
	}
	++_size;
	return true;
}