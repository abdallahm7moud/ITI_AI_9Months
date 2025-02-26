import json

class Queue:
    def __init__(self):
        self.queue = []

    def insert(self, value):
        self.queue.append(value)

    def pop(self):
        if self.is_empty():
            print("Warning: Attempted to pop from an empty queue!")
            return None
        return self.queue.pop(0)

    def is_empty(self):
        return len(self.queue) == 0



class QueueOutOfRangeException(Exception):
    # def __init__(self, message):
    #     super().__init__(message)
    pass



class AdvancedQueue(Queue):    
    instances = {}

    def __init__(self, name, size):
        super().__init__()  
        self.name = name
        self.size = size

        # if name in AdvancedQueue.instances:
        #     raise ValueError(f"A queue with the name '{name}' already exists.")
        AdvancedQueue.instances[name] = { "size" : self.size,"queue": self.queue }

    def insert(self, value):
        if len(self.queue) >= self.size:
            raise QueueOutOfRangeException("Queue is full. Cannot insert more values.")
        self.queue.append(value)

 
    @classmethod
    def save(cls):
        try:
            with open("queue.json", 'w') as file:
                json.dump(cls.instances, file, indent=4)
        except Exception as e:
            print(e)

    @classmethod
    def load(cls):
        try:
            with open("queue.json", 'r') as file:
                cls.instances = json.load(file)
        except FileNotFoundError:
            return {}

    @classmethod
    def get_queue_by_name(cls, name):
        if name not in cls.instances:
            print(f"Warning: Queue with name '{name}' does not exist.")
        else:
            return cls.instances[name]

    
if __name__ == "__main__":
    AdvancedQueue.load()
    queue4 = AdvancedQueue("queue4", 6)
    queue4.insert(1)
    queue4.insert(2)
    queue4.insert(3)
    queue4.insert(4)
    queue4.insert(5)
    queue4.insert(5)

    AdvancedQueue.save()
    print(AdvancedQueue.get_queue_by_name("queue3"))
    queue4.pop()
    print(AdvancedQueue.get_queue_by_name("queue3"))