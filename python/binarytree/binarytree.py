class BinaryTree():

    def __init__(self,rootid):
        self.left = None
        self.right = None
        self.rootid = rootid

    def getLeftChild(self):
        return self.left
    def getRightChild(self):
        return self.right
    def setNodeValue(self,value):
        self.rootid = value
    def getNodeValue(self):
        return self.rootid
    
    def insertLeft(self,node):
       # print ("insertion gauche de : " + node)
        if self.left == None:
            self.left = BinaryTree(node)
        else:
            tree = BinaryTree(node)
            self.left = tree
            tree.seft = self.left
    def insertRight(self,node):
       # print ("insertion droite de : "+node)
        if self.right == None:
            self.right = BinaryTree(node)
        else:
            tree = BinaryTree(node)
            tree.right = self.right
            tree.right = tree

def printTree(tree):
    if tree != None:
        printTree(tree.getLeftChild())
        print(tree.getNodeValue())
        printTree(tree.getRightChild())



#Test 
def test (tree):
    tree = BinaryTree("1")
    tree.insertLeft("2")
    tree.insertRight("3")
    tree.insertRight("4")
    printTree(tree)

tree = BinaryTree("0")
test (tree)
