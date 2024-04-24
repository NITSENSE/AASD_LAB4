#include"../include/SearchTree.h"



Node*set::find_min(Node* root_node) {
	if (!root_node) return nullptr;
	while (root_node->left_node) root_node = root_node->left_node;
	return root_node;
}

bool set::delete_node(Node*& root_node, int value) {
	if (!root_node) return false;
	if (root_node->data < value) return delete_node(root_node->left_node, value);
	else if (root_node->data > value) return delete_node(root_node->right_node, value);
	else {
		if (!root_node->left_node && !root_node->right_node) {
			delete root_node;
			root_node = nullptr;
		}
		else if (!root_node->left_node) {
			Node* temp = root_node;
			root_node = root_node->right_node;
			delete temp;
		}
		else if (!root_node->right_node) {
			Node* temp = root_node;
			root_node = root_node->left_node;
			delete temp;
		}
		else {
			Node* temp = find_min(root_node->right_node);
			root_node->data = temp->data;
			delete_node(root_node->right_node, temp->data);
		}
		--_size;
		return true;
	}
}


Node* set::copy(Node* node) {
	if (!node)
		return nullptr;
	Node* newNode = new Node(node->data);
	newNode->left_node = copy(node->left_node);
	newNode->right_node = copy(node->right_node);
	return newNode;
}

void set::delete_all(Node* node) {
	if (!node) {
		delete_all(node->left_node);
		delete_all(node->right_node);
		delete node;
	}
}

void set::pre_print(Node* node) {
	if (node != nullptr) {
		pre_print(node->left_node);
		std::cout << node->data << " ";
		pre_print(node->right_node);
	}
}

bool set::search(Node* root, int value) {
	if (!root) return false;
	else {
		if (root->data == value) return true;
		if (root->data < value) return search(root->left_node, value);
		else return search(root->right_node, value);
	}
}


set::set(int data) {
	_root = new Node(data);
	_size = 1;
}

set::set(const set& BST) {
	_root = copy(BST._root);
}

set::~set() {
	delete_all(_root);
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

set& set::operator=(const set& other) {
	if (this != &other) {
		delete_all(_root);
		_root = copy(other._root);
	}
	return *this;
}

bool set::erase(int value) {
	return delete_node(_root, value);
}

void set::print() {
	pre_print(_root);
	std::cout << std::endl;
}

bool set::contains(int value) {
	return search(_root, value);
}
