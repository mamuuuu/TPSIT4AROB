import random

class Node():
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None
    
    def insertNode(self, key):
        if self.key is not None:
            if key > self.key:
                if self.right is None:
                    self.right = Node(key)
                else:
                    self.right.insertNode(key)
            else:
                if key < self.key:
                    if self.left is None:
                        self.left = Node(key)
                    else:
                        self.left.insertNode(key)
        else:
            self.key = key

    def printTree(self, level = 0):
        if self.left is not None:
            self.left.printTree(level+1)
        print(f"Livello : {level}, key: {self.key}")
        if self.right is not None:
            self.right.printTree(level+1)
    
    def findNode(self, key):
        if key > self.key:
            if self.right is None:
                return f"Nodo non trovato"
            return self.right.findNode(key)
        elif key < self.key:
            if self.left is None:
                return f"Nodo non trovato"
            return self.left.findNode(key)
        else:
            return f"Nodo trovato"
    
    def tree_height(self):
        if self.left is None:
            heightL = 0
        else:
            heightL = self.left.tree_height()

        if self.right is None:
            heightR = 0
        else:
            heightR = self.right.tree_height()
        
        return max(heightR+1,heightL+1)
        
        
    def b_tree(self, lista_key):
        """
        nodes deve contenere valori ordinati crescenti
        """

        l = len(lista_key)
        if (l==0):
            return None

        lista_key.sort() # modifica l'oggetto su cui è operato
        m = l//2
        root = Node(lista_key[m])

        root.left = b_tree(lista_key[0:m])
        root.right = b_tree(lista_key[m+1:])

        return root


def b_tree(nodes):

    #nodes deve contenere valori ordinati crescenti

    l = len(nodes)
    if (l==0):
        return None

    nodes.sort() # modifica l'oggetto su cui è operato
    m = l//2
    root = Node(nodes[m])

    root.left = b_tree(nodes[0:m])
    root.right = b_tree(nodes[m+1:])

    return root
        
def main():

    lista_key = list(range(0,40,5))

    """
    root = Node(50)
    
    root.insertNode(20)
    root.insertNode(70)
    root.insertNode(90)
    root.insertNode(10)
    root.insertNode(65)
    """

    random.shuffle(lista_key)
    print(lista_key)
    
    albero = Node(lista_key[0])

    for key in lista_key[1:]:
        albero.insertNode(key)
    
    albero.printTree()
    print(albero.findNode(10))

    albero1 = b_tree(lista_key)
    albero1.printTree()
    print(albero1.tree_height()-1)

    #Puoi aggiungere metodi o attributi dinamicamente
    albero1.altezza = 5
    print(albero1.altezza)


if __name__=="__main__":
    main()