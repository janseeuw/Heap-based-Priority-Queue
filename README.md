#Heap-based Priority Queue

##What is a heap?

A heap is a complete heap-ordered binary tree where the records are stored in an array.


A tree is heap-ordered if the key in each node is larger than or equal to the keys in all of that node's children (if any).
Equivalently, the key in each node of a heap-ordered tree is smaller than of equal to the key in that node's parent (if any).

Complete binary trees provide us with the advantage to use a compact array instead of a linked representation. We can easily get from a node to its parant and children without needing to maintain explicit links. We put the root at position 1, its children at positions 2 and 3, the nodes at the next level in positions 4, 5, 6 and 7, and so on.

##Algorithms on heaps
A heap is an important data structure. Most operations are efficiënt because they are limited to the height of the tree.

The algorithms all work by first making a modification to the tree that could violate the heap condition, then traveling throught the heap, modifying the heap as required to ensure that the heap condition is satisfied. There are two cases where we need to _fix the heap_.

###Priority of a node increases
When a new node is added at the bottom for example, we need to travel _up_ the heap to restore the heap condition.

If a node's key becomes larger than its parent's key we exchange the node's and travel up the tree until we reach a node with a larger key, or the root. It is similar to insertion sort except exchanging items isn't in a linear serie of elements, but on a way up in the heap between the new node and the root.

We move up the heap, exchanging the node with its parent if necessary, continuing as long as the parent is greater than the child or until we reach the top of the heap.

###Priority of a node decreases
If the heap property is violated because a node's key becomes smaller than one of that node's childrens' keys, we have to fix it in a way down to the bottom of the heap.

While the node has children and one of the children has a larger key, we exchange the new node with the child who has the largest key. 

Here we have two distinct exits: one for the case that the bottom is hit and another one for the case that the heap condition is satisfied somewhere in between.

##Create a heap-based priority queue
Now we have all the ingredients to build our own priority queue class which uses a heap data structure.

We want our priority queue to implements the following operations:

* push: add an element
* pop: remove the top element
* top: access the top element
* size: number of elements
* empty: test wether the priority queue is empty or not