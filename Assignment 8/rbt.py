import sys
class Color:
    RED = 0
    BLACK = 1

class Node:
    def __init__(self):
        #initialize pointers for nodes and elements with none
        self.data = None
        self.color = Color.RED
        #color as red
        self.left = None
        self.right = None
        self.parent = None
        
#to print the tree
def printTree(tree):
    #add all elements into a new list
    init_tree = [tree]
    a = '                               '
    while init_tree:
        next_level = list() #create a new list for child nodes
        #divide the list into half
        a = a[:len(a)//2]
        s = '  ' 
        for n in init_tree:
            color = 'B'
            if n != None and (n.color == Color.RED):
                color = 'R'
            s = s + a + str(n.data) + color
            if n != None and n != RedBlackTree.NIL:
                next_level.append(n.left)
                next_level.append(n.right)
        print(s)
        init_tree = next_level
        #set elements in the next level as parent elements for following level


class RedBlackTree:
    NIL = Node()
    #set the color NIL nodes
    NIL.color = Color.BLACK

    def __init__(self):
        self.root = RedBlackTree.NIL

    def rotateLeft(self, x):
        y = x.right #set y
        x.right = y.left #turn y's left subtree into x's right subtree
        if y.left != RedBlackTree.NIL:
            y.left.parent = x
        y.parent = x.parent
        if x.parent == RedBlackTree.NIL:
            self.root = y
        elif x == x.parent.left:
            x.parent.left = y
        else:
            x.parent.right = y

        y.left = x   #put x on y's left
        x.parent = y

    def rotateRight(self, y):
        x = y.left 
        y.left = x.right # turn x's right subtree into y's left subtree
        if x.right != RedBlackTree.NIL:
            x.right.parent = y
        x.parent = y.parent 
        if y.parent == RedBlackTree.NIL:
            #fix the root
            self.root = x
        elif y == y.parent.left:
            y.parent.left = x
        else:
            y.pasrent.right = x
        x.right = y    #put y on x's right
        y.parent = x

    def transplant(self, u, v):
        if u.parent == RedBlackTree.NIL:
            self.root = v
        elif u == u.parent.left:
            u.parent.left = v
        else:
            u.parent.right = v
        if v != RedBlackTree.NIL:
            v.parent = u.parent

    #fix the tree after insertion
    def rbInsertFixup(self, z):
        while z.parent.color == Color.RED:
            if z.parent == z.parent.parent.left:
                y = z.parent.parent.right
                #Case 1
                if y.color == Color.RED:
                    z.parent.color = Color.BLACK
                    y.color = Color.BLACK
                    z.parent.parent.color = Color.RED
                    z = z.parent.parent
                #Case 2
                elif z == z.parent.right:
                    z = z.parent
                    self.rotateLeft(z)
                    #Case 3
                    z.parent.color = Color.BLACK
                    z.parent.parent.color = Color.RED
                    self.rotateRight(z.parent.parent)
                else:
                    z.parent.color = Color.BLACK
                    z.parent.parent.color = Color.RED
                    self.rotateRight(z.parent.parent)
            else:
                y = z.parent.parent.left
                if y.color == Color.RED:
                    z.parent.color = Color.BLACK
                    y.color = Color.BLACK
                    z.parent.parent.color = Color.RED
                    z = z.parent.parent
                else:
                    if z == z.parent.left:
                        z = z.parent
                        self.rotateRight(z)
                    z.parent.color = Color.BLACK
                    z.parent.parent.color = Color.RED
                    self.rotateLeft(z.parent.parent)
        self.root.color = Color.BLACK
        printTree(self.root)

    #add a new node to the tree
    def rbInsert(self, z):
        y = RedBlackTree.NIL
        x = self.root

        #locate where to insert the node
        while x != RedBlackTree.NIL:
            y = x
            if z.data < x.data:
                x = x.left
            else:
                x = x.right
        z.parent = y
        if y == RedBlackTree.NIL:
            self.root = z
        elif z.data < y.data:
            y.left = z
        else:
            y.right = z

        z.left = RedBlackTree.NIL
        z.right = RedBlackTree.NIL
        z.color = Color.RED
        self.rbInsertFixup(z)
        #to fix level and color of each node according to properties of RBT

    def insert(self,data):
        node = Node()
        node.data = data
        self.rbInsert(node)

    #fix the tree after deletion
    def rbDeleteFixup(self, x):
        while x != self.root and x.color == Color.BLACK:
            if x == x.parent.left:
                b = x.parent.right
                if b.color == Color.RED:
                    b.color = Color.BLACK
                    x.parent.color = Color.RED
                    self.rotateLeft(x.parent)
                    b = x.parent.right
                if b.left.color == Color.BLACK and w.right.color == Color.BLACK:
                    b.color = Color.RED
                    x = x.parent
                else:
                    if b.right.color == Color.BLACK:
                        b.left.color = Color.BLACK
                        b.color = Color.RED
                        self.rotateRight(b)
                        b = x.parent.right
                    b.color = x.parent.color
                    x.parent.color = Color.BLACK
                    b.right.color = Color.BLACK
                    self.rotateLeft(x.parent)
                    x = self.root
            else:
                b = x.parent.left
                if b.color == Color.RED:
                    b.color = Color.BLACK
                    x.parent.color = Color.RED
                    self.rotateRight(x.parent)
                    b = x.parent.left
                if b.right.color == Color.BLACK and b.left.color == Color.BLACK:
                    b.color = Color.RED
                    x = x.parent
                else:
                    if w.left.color == Color.BLACK:
                        w.right.color = Color.BLACK
                        w.color = Color.RED
                        self.rotateLeft(w)
                        b = x.parent.left
                    b.color = x.parent.color
                    x.parent.color = Color.BLACK
                    b.left.color = Color.BLACK
                    self.rotateRight(x.parent)
                    x = self.root
            x.color = Color.BLACK
    
    #delete a node from the tree
    def delete(self, z):
        #check whether the nodes is still there
        if (z.parent == None):
            print("Tree deleted!")
            return
        y = z
        y_org_color = y.color
        if (z.left == RedBlackTree.NIL):
            x = z.right # will move into y's  position
            self.transplant(z, z.right)
        elif (z.right == RedBlackTree.NIL):
            x = z.left   # will move into y's  position
            self.transplant(z, z.left)
        else:
            y = treeMinimum(z.right)
            y_org_color = y.color
            x = y.right
            if (y.parent == z):
                x.parent = y
            else:
                self.transplant(y, y.right)
                y.right = z.right
                y.right.parent = y
            
            self.transplant(z, y)
            y.left = z.left
            y.left.parent = y
            y.color = z.color
        if y_org_color == Color.BLACK:
            self.rbDeleteFixup(x)
            #fix the tree to avoid violations of 2,4 and 5
            
        #print the updated result after deleting
        printTree(self.root)

    #find minimum with parameter called 
    def treeMinimum(self,x):
        while x.left != RedBlackTree.NIL:
            x = x.left
        return x

    #find maximum with parameter called
    def treeMaximum(self,x):
        while x.right != RedBlackTree.NIL:
            x = x.right
        return x

    
    #return the predecessor of a given node
    def predecessor(self, x):
        if (x.parent == None):
           print("There is no node in the tree")
        #if left subtree is NIL, the predecessor
        #is the maximum value of left subtree
        if x.left != RedBlackTree.NIL:
            return treeMaximum(x.left)
        y = x.parent
        while y != RedBlackTree.NIL and x == y.left:
            x = y
            y = y.parent
        return y
    
    #return the successor of a given node
    def successor(self, x):
        if (x.parent == None):
            print("There is no node in the tree")
        #if the  right subtree is NIL, the successor is the
        #minimum value of the left subtree
        if x.right != RedBlackTree.NIL:
            return treeMinimum(x.right)
        y = x.parent
        while y != RedBlackTree.NIL and x == y.right:
            x = y
            y = y.parent
        return y

    def getMinimum(self):
        x = self.root
        #call overwrite function with parameter
        return self.treeMinimum(x)

    def getMaximum(self):
        x = self.root
        #call overwrite function with parameter
        return self.treeMaximum(x)
        
    #search an element in the tree
    def search(self, element):
        node = self.root
        while node != RedBlackTree.NIL:
            if element == node.data:
                print("Found "+str(node.data))
                return node
            elif element < node.data:
                node = node.left
            else:
                node = node.right
        #if the integer searched is not found
        print("No element found")
        return RedBlackTree.NIL


def main():
    #testcase
    newTree = RedBlackTree()
    treelist = [7,12,18,17,25,36,3] 
    #check if all elements in the list are integers
    for i in treelist:
        if (type(i) != int):
            print("The elements should be integers!")
            sys.exit(0)
    for i in treelist:
        newTree.insert(i)
    newTree.search(12) #search testing
    print("Min Value: "+str(newTree.getMinimum().data))
    print("Max Value: "+str(newTree.getMaximum().data))
    newTree.delete(newTree.getMaximum()) #delete testing
    newTree.delete(newTree.getMinimum())
    print("Min Value: "+str(newTree.getMinimum().data))
    print("Max Value: "+str(newTree.getMaximum().data))

if __name__ == '__main__':
    main()
