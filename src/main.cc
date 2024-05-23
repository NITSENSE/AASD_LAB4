#include"../include/experiment.h"
const std::vector<size_t> lengths = { 1000, 10000, 100000 };
using namespace std;

int main() {
	cout << "Average Fill Time BST " << endl;
	for (size_t i = 0; i < lengths.size(); ++i) {
		cout << lengths[i] << " unique numbers:"
			<< average_fill_time(generate_random_tree, lengths[i]) << "sec." << endl;
		}
		cout << endl;
	

	cout << "Average Fill Time Vector " << endl;
	for (size_t i = 0; i < lengths.size(); ++i) {
		cout << lengths[i] << " unique numbers: "
			<< std::fixed << std::setprecision(10) << average_fill_time(generate_random_vector, lengths[i]) << "sec." << endl;
	}
	cout << endl;
	


	cout << "Average Search element Time in BST " << endl;
	for (size_t i = 0; i < lengths.size(); ++i) {
		set tree = generate_random_tree(lengths[i]);
		cout << lengths[i] << " unique numbers: " << std::fixed << std::setprecision(10) << average_time_search_in_tree(tree) << "sec." << endl;
		tree.clear();
	}
	cout << endl;
	


	cout << "Average Search element Time in vector" << endl;
	for (size_t i = 0; i < lengths.size(); ++i) {
		vector<int> arr = generate_random_vector(lengths[i]);
		cout << lengths[i] << " unique numbers: " << std::fixed << std::setprecision(10) << average_time_search_in_vector(arr) << "sec." << endl;
		arr.clear();
	}
	cout << endl;
	


	cout << "average insert element time in BST " << endl;
	for (size_t i = 0; i < lengths.size(); ++i) {
		set tree = generate_random_tree(lengths[i]);
		cout << lengths[i] << " unique numbers: " << std::fixed << std::setprecision(10) << average_time_insert_tree(tree) << "sec." << endl;
		tree.clear();
	}
	cout << endl;
	


	cout << "average insert element time in vector" << endl;
	for (size_t i = 0; i < lengths.size(); ++i) {
		vector<int> arr = generate_random_vector(lengths[i]);
		cout << lengths[i] << " unique numbers: " << std::fixed << std::setprecision(10) << average_time_insert_vector(arr) << "sec." << endl;
		arr.clear();
	}
	cout << endl;
	


	cout << "average delete element time in BST " << endl;
	for (size_t i = 0; i < lengths.size(); ++i) {
		set tree = generate_random_tree(lengths[i]);
		cout << lengths[i] << " unique numbers: " << std::fixed << std::setprecision(10) << average_time_erase_tree(tree) << "sec." << endl;
		tree.clear();
	}
	cout << endl;
	


	cout << "average delete element time in vector " << endl;
	for (size_t i = 0; i < lengths.size(); ++i) {
		vector<int> arr = generate_random_vector(lengths[i]);
		cout << lengths[i] << " unique numbers: " << std::fixed << std::setprecision(10) << average_time_erase_vector(arr) << "sec." << endl;
		arr.clear();
	}
	cout << endl;

}
