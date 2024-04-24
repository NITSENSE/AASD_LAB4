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

	bool search(Node*, int);
	void pre_print(Node*);
	Node* find_min(Node*);
	Node* copy(Node*);
	void delete_all(Node*);
	bool delete_node(Node*&, int);
public:
	set() : _root(nullptr), _size(0) {};
	set(int);
	set(const set&);
	~set();
	set& operator=(const set&);
	bool insert(int);
	void print();
	bool contains(int);
	bool erase(int);
};
#endif