class Jar:
    def __init__(self, capacity=12):
        if capacity < 0
            raise ValueError("Invalid capacity")
        self.capacity = capacity
        self.size = 0

    def __str__(self):
        return "🍪" * self.size

    def deposit(self, n):
        ...

    def withdraw(self, n):
        ...

    @property
    def capacity(self):
        ...

    @property
    def size(self):
        ...