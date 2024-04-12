#ifndef ST
#define ST

#include<iostream>

struct Node {
	int  data;
	Node* left_node, * right_node;

	explicit Node(int value) : data(value), left_node(nullptr), right_node(nullptr) {};
};

class set {
	Node* _root;
	size_t _size;
public:
	set() : _root(nullptr), _size(0) {};
	set(int);
	//set(const set& copy);
	//~set();
	//set& operator=(set& copy);
	bool insert(int);
	//bool contains(int key);
	//bool erase(int key);
};
#endif