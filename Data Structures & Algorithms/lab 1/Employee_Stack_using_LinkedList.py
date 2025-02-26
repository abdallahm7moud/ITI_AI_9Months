class node:
    def __init__(self, id, name, position):
        self.id = id
        self.name = name
        self.position = position
        self.next = None
        


class Stack:
    def __init__(self):
        self.TOS = None
        
    def Push(self, id, name, position):
        new_node = node(id, name, position)
        if self.TOS == None:
            self.TOS = new_node
        else:
            new_node.next = self.TOS
            self.TOS = new_node
            
    def Pop(self):
        if self.TOS == None:
            print("Stack is empty")
            return None
        else:
            nd = self.TOS
            self.TOS = self.TOS.next
            return nd
        
if __name__ == "__main__":
    s = Stack()
    s.Push(1, "Abdallah", "Manager")
    s.Push(2, "Ahmed", "Assistant Manager")
    s.Push(3, "Amr", "Staff")
    
    emp1 = s.Pop()
    print(f"emp name: {emp1.name} - emp id: {emp1.id} - emp position: {emp1.position}")
    
    emp2 = s.Pop()
    print(f"emp name: {emp2.name} - emp id: {emp2.id} - emp position: {emp2.position}")
    
    s.Pop()
    s.Pop()

    
