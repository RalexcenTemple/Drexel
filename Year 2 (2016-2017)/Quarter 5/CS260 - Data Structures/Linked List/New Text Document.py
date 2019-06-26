class Node:
 def __init__( self ):
     self.val = None
     self.next = None

class LinkedList:
    def __init__( self ):
        self.head = None
        self.tail = None


    def ADDONE(self, x):
        n = Node()
        n.val = x
        if self.head == None:
            self.head = n
        if self.tail != None:
            self.tail.next = n
            self.tail = n

    def FIRST(self):
        return self.head

    def END(self):
        tmp = self.head
        print(tmp.val)
        tmp = tmp.next
        while True:
            if tmp.next is None:
                return tmp.val

    def RETRIVE(self, p):
        tmp = self.head
        for i in range(0, p):
            tmp = tmp.next
            return tmp

    def LOCATE(self, x):
        tmp = self.FIRST()
        c = 0
        while True:
                tmp = tmp.next
                c = c + 1
                if tmp.val == x:
                    return c

    def NEXT(self, n):
        return n.next

    def PREVIOUS(self, n):
        tmp = self.FIRST()
        while True:
            tmp = tmp.next
            if tmp.next == n:
                return tmp

    def INSERT(self, p, x):
        n = Node()
        n.val = x #creat node with val x
        if p ==0:
            n.next = self.head
            self.head = n
        else:
            tmp = self.FIRST()
            for i in range(0, p-1):
                if tmp.next != None:
                    tmp = tmp.next #reach the desinted location
                    n.next = tmp.next
                    tmp.next = n
                    return

    def DELETE(self, p):
        tmp = self.FIRST()
        if p == 0:
            self.FIRST = tmp.next
        else:
            for i in range(0, p-1):
                if tmp.next != None:
                    tmp = tmp.next
                    #tmp.PREVIOUS(self.RETRIVE(p)) = tmp.next
                    return

    def MAKENULL(self):
        return

    def printList(self):
        n = self.head
        while n :
            print(n.val)
            n = n.next


a = LinkedList()
a.INSERT(0,0)
a.INSERT(1,1)
a.INSERT(2,2)
a.INSERT(3,3)
a.INSERT(4,4)
a.INSERT(5,5)
a.INSERT(6,6)

a.DELETE(0)

print("retrieve: " + str(a.RETRIVE(3)))
a.printList()
print("end is: " + str(a.END()))
print("3rd is at " + str (a.LOCATE(3)))
