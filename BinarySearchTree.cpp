#include "BinarySearchTree.h"

using namespace std;

// BinarySearchTree class
template<typename Comparable>
BinarySearchTree<Comparable>::BinarySearchTree() : root{nullptr} {
}

/**
 * Copy constructor
 */
template<typename Comparable>
BinarySearchTree<Comparable>::BinarySearchTree(const BinarySearchTree &rhs) : root{nullptr} {
    root = clone(rhs.root);
}

/**
 * Move constructor
 */
template<typename Comparable>
BinarySearchTree<Comparable>::BinarySearchTree(BinarySearchTree &&rhs) : root{rhs.root} {
    rhs.root = nullptr;
}

/**
 * Destructor for the tree
 */
template<typename Comparable>
BinarySearchTree<Comparable>::~BinarySearchTree() {
    makeEmpty();
}

/**
 * Internal method to clone subtree.
 */
template<typename Comparable>
typename BinarySearchTree<Comparable>::BinaryNode
*BinarySearchTree<Comparable>::clone(BinaryNode *t) const {
    if (t == nullptr)
        return nullptr;
    else
        return new BinaryNode{t->element, t->val, clone(t->left), clone(t->right)};
}

/**
 * Test if the tree is logically empty.
 * Return true if empty, false otherwise.
 */
template<typename Comparable>
bool BinarySearchTree<Comparable>::isEmpty() const {
    return root == nullptr;
}

/**
 * Make the tree logically empty.
 */
template<typename Comparable>
void BinarySearchTree<Comparable>::makeEmpty() {
    makeEmpty(root);
}

/**
 * Internal method to make subtree empty.
 */
template<typename Comparable>
void BinarySearchTree<Comparable>::makeEmpty(BinaryNode *&t) const {
    if (t != nullptr) {
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }
    t = nullptr;
}


/**
 * Find the smallest item in the tree.
 * Throw UnderflowException if empty.
 */
template<typename Comparable>
typename BinarySearchTree<Comparable>::BinaryNode
*BinarySearchTree<Comparable>::findMin() const {
    if (isEmpty()) {
        throw UnderflowException();
    }

    findMin(root);
}

/**
 * Internal method to find the smallest item in a subtree t.
 * Return node containing the smallest item.
 */
template<typename Comparable>
typename BinarySearchTree<Comparable>::BinaryNode
*BinarySearchTree<Comparable>::findMin(BinaryNode *t) const {
    BinaryNode *ptr = root;

    while (ptr->left != nullptr) {
        ptr = ptr->left;
    }

    return ptr;
}

/**
 * Find the largest item in the tree.
 * Throw UnderflowException if empty.
 * Return node containing the largest item.
 */
template<typename Comparable>
typename BinarySearchTree<Comparable>::BinaryNode
*BinarySearchTree<Comparable>::findMax() const {
    if (isEmpty()) {
        throw UnderflowException();
    }

    findMax(root);
}

/**
 * Internal method to find the largest item in a subtree t.
 * Return node containing the largest item.
 */
template<typename Comparable>
typename BinarySearchTree<Comparable>::BinaryNode
*BinarySearchTree<Comparable>::findMax(BinaryNode *t) const {
    BinaryNode *ptr = root;

    while (ptr->right != nullptr) {
        ptr = ptr->right;
    }

    return ptr;
}

/**
 * Returns true if x is found in the tree.
 */
template<typename Comparable>
bool BinarySearchTree<Comparable>::contains(const Comparable &x) const {
    return contains(x, root);
}

/**
 * Internal method to test if an item is in a subtree.
 * x is item to search for.
 * t is the node that roots the subtree.
 */
template<typename Comparable>
bool BinarySearchTree<Comparable>::contains(const Comparable &x, BinaryNode *t) const {
    if (t == nullptr) {
        return false;
    } else if (x < t->element) {
        return contains(x, t->left);
    } else if (t->element < x) {
        return contains(x, t->right);
    } else {
        return true;
    }
}

/**
 * Insert node (its id is x) into the BST tree; duplicates are ignored.
 * The inserted node will use the student information stored in val
 * to initialize its student information.
 */
template<typename Comparable>
void BinarySearchTree<Comparable>::insert(const Comparable &x, Student<string> &student) {
    insert(x, student, root);
}

/**
 * Internal method to insert into a subtree.
 * x is the item to insert.
 * t is the node that roots the subtree.
 * Set the new root of the subtree.
 */
template<typename Comparable>
void BinarySearchTree<Comparable>::insert(const Comparable &x, Student<string> &student, BinaryNode *&t) {
    if (t == nullptr) {
        t = new BinaryNode(x, student, nullptr, nullptr);
    } else if (x < t->element) {
        insert(x, student, t->left);
    } else if (t->element < x) {
        insert(x, student, t->right);
    }

}

/**
 * Remove x from the tree. Nothing is done if x is not found.
 */
template<typename Comparable>
void BinarySearchTree<Comparable>::remove(const Comparable &x) {
    remove(x, root);
}

/**
 * Internal method to remove from a subtree.
 * x is the item to remove.
 * t is the node that roots the subtree.
 * Set the new root of the subtree.
 */
template<typename Comparable>
void BinarySearchTree<Comparable>::remove(const Comparable &x, BinaryNode *&t) {
    if (t == nullptr) {
        return; // Didn't find item, return out
    }

    if (x < t->element) {
        remove(x, t->left);
        return;
    } else if (x > t->element) {
        remove(x, t->right);
        return;
    } else if (t->left != nullptr && t->right != nullptr) {
        t->element = findMin(t->right)->element;
        remove(t->element, t->right);
        return;
    } else {
        BinaryNode *temp = t;

        t = t->left == nullptr ? t->right : t->left;
        delete temp;
    }

}

/**
 * Returns the node if x is found in the tree, otherwise, return nullptr.
 */
template<typename Comparable>
bool BinarySearchTree<Comparable>::update(const Comparable &x, Student<string> &student) {
    return update(x, student, root);
}

/**
 * Internal method to update a node whose element (id) equals x in a subtree.
 * If found, the node whole element is x is updated, i.e., the corresponding student information
 * stored in this node is updated with the information stored in val, and return true, otherwise return false
 * x is the item to be found.
 * t is the node that roots the subtree.
 * Set the new root of the subtree.
 */
template<typename Comparable>
bool BinarySearchTree<Comparable>::update(const Comparable &x, Student<string> &student, BinaryNode *&t) {
    if (t == nullptr) {
        cout << "Didn't find any student with ID " << x << "." << endl;
        return false;
    } else if (x < t->element) {
        return update(x, student, t->left);
    } else if (t->element < x) {
        return update(x, student, t->right);
    } else {
        t->student = student;
        return true;
    }
}

/**
 * Print out the node information (student information) if x is
 * found in the tree, and return true.
 * Otherwise, print "Node x was not found", and return false.
 */
template<typename Comparable>
bool BinarySearchTree<Comparable>::printNodeInfo(const Comparable &x) const {
    return printNodeInfo(x, root);
}

/**
 * Internal method used by public printNodeInfo method
 * Print out the node information (student information) if x is
 * found in the tree, and return true.
 * Otherwise, print "Node x was not found", and return false.
 */
template<typename Comparable>
bool BinarySearchTree<Comparable>::printNodeInfo(const Comparable &x, BinaryNode *t) const {
    if (t == nullptr) {
        cout << "The student with ID " << x << " wasn't found in the tree." << endl;
        return false;
    } else if (x < t->element) {
        return printNodeInfo(x, t->left);
    } else if (t->element < x) {
        return printNodeInfo(x, t->right);
    } else {
        cout << t->student.toString() << endl;
    }
}


/**
 * Print the tree contents in sorted order.
 */
template<typename Comparable>
void BinarySearchTree<Comparable>::printTree(ostream &out) {
    if (isEmpty()) {
        cout << "Empty tree" << endl;
    } else {
        printTree(root, out);
    }
}

/**
 * Internal method to print a subtree rooted at t in sorted order.
 * You must print out "->" between every two nodes and there is no "->"
 * after the last node in the BST
 * Please use the example output as a reference
 */
template<typename Comparable>
void BinarySearchTree<Comparable>::printTree(BinaryNode *t, ostream &out) {
    if (t != nullptr) {
        cout << t->student.toString() << endl;
        printTree(t->left, out);
        printTree(t->right, out);
    }
}
