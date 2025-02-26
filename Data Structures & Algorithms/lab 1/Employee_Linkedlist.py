class node:
    def __init__(self, id, name, position):
        self.id = id
        self.name = name
        self.position = position
        self.next = None
        self.prev = None
        
class linkedlist:
    def __init__(self):
        self.head = None
        self.tail = None
    
    def Insert(self, id, name, position, loc):
        new_node = node(id, name, position)
        if self.head == None:
            self.head = new_node
            self.tail = new_node
        elif loc == 0:
            self.head.prev = new_node
            new_node.next = self.head
            self.head = new_node
        else:
            idx = 0
            curr = self.head
            while idx < loc - 1 and curr != None:
                curr = curr.next
                idx += 1
            if curr == self.tail or curr == None:
                new_node.prev = self.tail
                self.tail.next = new_node
                self.tail = new_node
            else:
                curr.next.prev =new_node
                new_node.next = curr.next
                new_node.prev = curr
                curr.next = new_node
    
    
    def Update_data_byid(self, id, new_name=None, new_position=None):
        if self.head == None:
            return False
        nd = self.head
        while nd != None:
            if nd.id == id:
                nd.name = new_name
                nd.position = new_position
                return True
            nd = nd.next
        return False
    
              
    def Delete_by_id(self, id):
        if self.head == None:
            return False
        
        if self.head == self.tail:
            if self.head.id == id:
                self.head = None
                self.tail = None
                return True
            else:
                return False
        
        if self.head.id == id:
            self.head = self.head.next
            return True
        
        if self.tail.id == id:
            self.tail = self.tail.prev
            return True
        
        nd = self.head
        while nd != None:
            if nd.id == id:
                nd.prev.next = nd.next
                nd.next.prev = nd.prev
                return True
            nd = nd.next
        return False
            
    def Display_all(self):
        if self.head == None:
            return False
        nd = self.head
        i=1
        while nd != None:
            print(f"Emp{i} -> Id: {nd.id} - Name: {nd.name} - Position: {nd.position}")
            nd = nd.next
            i += 1
            
    def Delete_all(self):
        if self.head == None:
            return False
        else:
            self.head = None
            self.tail = None
            return True            
                                
if __name__=="__main__":
    Employees = linkedlist()
    Employees.Insert(1, 'Abdallah', 'CEO', 0)
    Employees.Insert(2, 'Mohamed', 'CFO', 1)
    Employees.Insert(3, 'Ali', 'CTO', 2)
    Employees.Insert(4, 'Omar', 'COO', 1)
    Employees.Display_all()
    print("\n")
    Employees.Update_data_byid(3, 'Ali', 'CIO')
    Employees.Display_all()
    print("\n")
    Employees.Delete_by_id(2)
    Employees.Display_all()
    print("\n")


    
    