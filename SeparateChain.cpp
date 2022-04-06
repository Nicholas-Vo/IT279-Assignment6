#include "SeparateChain.h"

using namespace std;

template<typename HashedObj>
HashTable<HashedObj>::HashTable(int size) : currentSize{0} {
    theLists.resize(size);
}

/**
 * return (input key) % (bucket size)
 */
template<typename HashedObj>
size_t HashTable<HashedObj>::myHash(const HashedObj &x) const {
    return hash(x) % theLists.size();
}

/**
 * A hash routine for ints. Return the key
 */
template<typename HashedObj>
size_t HashTable<HashedObj>::hash(const HashedObj &key) const {
    return key;
}

/**
 * Insert a node whose id == x (all student information stored
 * in s): if the node is found, do nothing and return false
 * Otherwise, insert the node to the BST tree (including student information
 * stored in s), and return true
 */
template<typename HashedObj>
bool HashTable<HashedObj>::insert(const HashedObj &x, Student<string> &student) {
    BinarySearchTree<HashedObj> &bst = theLists[myHash(x)];
    if (bst.contains(x)) {
        return false;
    }

    bst.insert(x, student);

//    if (++currentSize > theLists.size() / 2) {
//        // rehash()?
//    }
    return true;
}

/**
 * Find whether id == x is in the database, if found, update the student information
 * and return true. Otherwise, return false
 */
template<typename HashedObj>
bool HashTable<HashedObj>::update(const HashedObj &x, Student<string> &s) {
    BinarySearchTree<HashedObj> &bst = theLists[myHash(x)];
    if (!bst.contains(x)) {
        cout << x << " was not found." << endl;
        return false;
    }

    bst.update(x, s);
    return true;
}

/**
 * Find whether id == x is in the database, if found, remove the node and return true
 * Otherwise, return false
 */
template<typename HashedObj>
bool HashTable<HashedObj>::remove(const HashedObj &x) {
    BinarySearchTree<HashedObj> &bst = theLists[myHash(x)];
    if (!bst.contains(x)) {
        return false;
    }

    bst.remove(x);
    --currentSize;
    return true;
}

/**
 * If the x (student id) is found, print out student information whose id == x
 * return true.
 * Otherwise, print out "x was not found" and return false
 * You should use bool printNodeInfo(const Comparable &x)
 * in BinarySearchTree class
 */
template<typename HashedObj>
bool HashTable<HashedObj>::printNodeInfo(const HashedObj &x) {
    BinarySearchTree<HashedObj> &bst = theLists[myHash(x)];
    if (!bst.contains(x)) {
        cout << x << " was not found." << endl;
        return false;
    }

    bst.printNodeInfo(x);
    return true;
}

/**
 * Display the content of the hash table
 */
template<typename HashedObj>
void HashTable<HashedObj>::displayHash() {
    for (int i = 0; i < theLists.size(); i++) {
        cout << i + 1<< " ";
        theLists[i].printTree();
    }
}

/**
 * Make the hash table empty
 */
template<typename HashedObj>
void HashTable<HashedObj>::makeEmpty() {
    for (auto &bst: theLists) {
        bst.makeEmpty();
    }
}