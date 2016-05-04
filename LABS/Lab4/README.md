# Lab 4
*You will start this lab by creating a composite pattern for representing an expression tree. The first expression to be executed will be at the deepest level. The result of that calculation then becomes an input to the next level up, and that result becomes an input to the next level up. The tree is evaluated recursively from the bottom to the top, and is constructed in this particular way because of order of operations.*

*You will write a composite pattern for representing these expression trees.*

_You will have one type of leaf node which will represent a number (class Op), and two types of composite nodes. There will be four types of nodes that have two children, capable of expressing the operations multiply (class Mult), divide (class Div), add (class Add), and subtract (class Sub). There also be one type of node that only has one child, which expresses squaring a value (class Sqr). Notice that any parentheses that would be in the expression can be implemented in the trees structure rather than explicitly with a node. Now that you have created your expression tree classes, we will create a strategy pattern for sorting these trees by their evaluate()value. You will start this by creating two containers, one that uses a vector to hold your trees (class VectorContainer), and one that uses a list (class ListContainer). Both of these classes hold the top node pointers of the trees, so the list or vector would be of the type <Base*>. You will implement them both using the following Container base class._

_You will also implement two sort functions for sorting these containers, one that uses the selection sort algorithm and one that uses the bubble sort algorithm (you may directly adapt this code when writing your sort functions)._

