# Trees

Trees represent hierarchical structures and can also serve as a more efficient data structure for certain operations on linear structures.

Maximal number of children of any node in the tree is called the **degree** of the tree.

Two main representations of trees:
- an **implicit** representation
  - an array is used to store all the nodes of the tree
  - no pointers are used

- an **explicit** representation
  - the connection of one tree node to another is done by a pointer

---

undirected graph: edges have no orientation. The edge (u, v) is identical to the edge (v, u)

directed graph or digraph: edges have orientations. The edge (u, v) is the edge _from_ node u _to_ node v

weighted graphs: edges contain a certain weight to represent an arbitrary value (such as cost, distance, quantity, etc.)

directed acyclic graphs (DAGs): directed graphs with no cycles. These graphs play an important role in representing structures with dependencies

tree:
- special kind of graph where no node has more than one parent
- an undirected graph with no cycles
- a connected graph with N nodes and N-1 edges (each node has 1 incoming edge except the root node which has none)

linked list: special kind of tree where no node has more than one child

---

Trees are recursive data structures.

depth of node x = number of edges in path from root to x (i.e. length of path from root to x)
  - depth of node 1 = 0
  - depth of nodes 2, 3 = 1
  - depth of nodes 4, 5, 6, 7, 8 = 2
  - depth of nodes 9, 10, 11 = 3

height of node x = number of edges in longest path from x to a leaf node
  - height of node 3 = 2
  - height of leaf nodes (4, 6, 8, 9, 10, 11) = 0
  - height of node 1 = 3

height of tree = height of root node

```
       1
     /   \
   2       3
 / | \    / \
4  5  6  7   8
  / \    |
 9  10   11
```

# Binary trees

Binary tree: a tree in which each node can have at most 2 children

Tree traversal: process of visiting each node in the tree, exactly once

- breadth-first traversal
  - level-order

- depth-first traversal
  - preorder: **root** -> left -> right
  - inorder: left -> **root** -> right
  - postorder: left -> right -> **root**


In the following tree..

level-order: F D J B E G K A C I H

preorder (data, left, right): F D B A C E J G I H K

inorder (left, data, right): A B C D E F G H I J K

postorder (left, right, data): A C B E D H I G K J F

this tree is a binary search tree, and an inorder traversal of a binary search tree gives you a sorted list

```
       F
     /   \
    D      J
   / \    / \
  B   E  G   K
 / \      \
A   C      I
          /
         H
```

level-order traversal
- algorithm:
  1. maintain a queue and enqueue the address of the node being visited (aka "discovered node")
  2. as a discovered node is being visited (eg. printing out its value) and dequeued, enqueue its children nodes to be visited later
- time complexity (assume n nodes): O(n) for best/worst/avg case
- space complexity: O(1) for best case and O(n) for worst/avg case

preorder/inorder/postorder traversal
- time complexity (assume n nodes): O(n) for best/worst/avg case
- space complexity: O(h) where h is tree height
  - O(n) for worst case because h = n -1
  - O(log n) for best/avg case because h = log n

# AVL trees

a self-balancing binary search tree.

only 3 nodes are used when rotating, regardless of the number of nodes in the entire BST.

a balance factor is used to to balance the height of a BST:
- balance factor = height of left subtree - height of right subtree = { -1, 0, 1 }

when a node's balance factor is:
-  positive -> tree is heavy on the left side
-  negative -> tree is heavy on the right side
