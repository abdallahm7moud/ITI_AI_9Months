class node:
    def __init__(self, id, name, position):
        self.id = id
        self.name = name
        self.position = position
        self.next = None
    
class Queue:
    def __init__(self, s):
        self.Head = None
        self.Tail = None
        self.Size = s
        self.idx = 0
        
    def Enqueue(self, id, name, position):
        new_node = node(id, name, position)
        if self.idx < self.Size:
            if self.Head == None:
                self.Head = new_node
                self.Tail = new_node
            else:
                self.Tail.next = new_node
                self.Tail = new_node
            self.idx += 1
        else:
            print("Queue is full")
            
    def Dequeue(self):
        if self.Head == None:
            print("Queue is empty")
            return None
        else:
            nd = self.Head
            self.Head = self.Head.next
            self.idx -= 1
            return nd   
        
    
        

if __name__ == "__main__":
    q = Queue(3)
    q.Enqueue(1, "Abdallah", "Manager")
    q.Enqueue(2, "Ahmed", "Assistant Manager")
    q.Enqueue(3, "Amr", "Staff")
   
   
    print(q.Dequeue().name)
  
    
        