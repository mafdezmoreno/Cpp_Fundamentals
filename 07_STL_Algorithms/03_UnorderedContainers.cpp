#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//TODO: Implement Hash Table with unordered multiset

/* ////! Unordered Containers

    * Unordered Set: Element are unsorted and with distinct values.
    * Unordered Multiset: Element duplicated are allowed.
    * Unordered Map: Mapped by key values. Unordered keys-value (which can't be repeated)
    * Unordered Multimap: Keys can be duplicated

    ////! Principal characteristic:
    * Implementing unordered containers using a hash table allows us to find an element 
    * with a specific value in constant time complexity, which translates to an even 
    * faster lookup when compared to associative containers
*/

//! Examples:

//  Hash table:
//  https://www.tutorialspoint.com/data_structures_algorithms/hash_data_structure.htm

//  Program (in this code):
//  https://www.geeksforgeeks.org/unordered_set-in-cpp-stl/

// C++ program to find duplicate from an array using
// unordered_set
// Print duplicates in arr[0..n-1] using unordered_set
void printDuplicates(int arr[], int n)
{

	unordered_set<int> intSet;
	unordered_set<int> duplicate;

	for (int i = 0; i < n; i++)
	{
		// if element is not there then insert that
		if (intSet.find(arr[i]) == intSet.end())
			intSet.insert(arr[i]);

		else
			duplicate.insert(arr[i]);
	}

	cout << "Duplicate item are : ";
	unordered_set<int> :: iterator itr;

	for (itr = duplicate.begin(); itr != duplicate.end(); itr++)
		cout << *itr << " ";
    cout<<endl;
}

// Driver code
int main()
{
	int arr[] = {1, 5, 2, 1, 4, 3, 1, 7, 2, 8, 9, 5};
	int n = sizeof(arr) / sizeof(int);

	printDuplicates(arr, n);
	return 0;
}

