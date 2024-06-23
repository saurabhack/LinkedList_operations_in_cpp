class node:
    def __init__(self,data) :
        self.data=data
        self.next=None
class linkedLists:
    def __init__(self) :
        self.head=None

    def pushAtFront(self,data):
        newNode=node(data)
        newNode.next=self.head
        self.head=newNode
        return

    def push(self,data):
        newNode=node(data)
        if self.head==None:
            self.head=newNode
            return
        current=self.head
        while current.next!=None:
            current=current.next
        current.next=newNode
    def display(self):
        current=self.head
        while current!=None:
            print(current.data,end="->")
            current=current.next
        print("NULL")
    def reverse(self):
        pre=None
        current=self.head
        while current!=None:
            next=current.next
            current.next=pre
            pre=current
            current=next
        self.head=pre
        

ll=linkedLists()
ll.push(1)
ll.push(2)
ll.push(3)
ll.push(4)
ll.display()
ll.pushAtFront(5)
ll.display()
ll.reverse()
ll.display()