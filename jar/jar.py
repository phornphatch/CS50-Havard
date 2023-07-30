class Jar:
    def __init__(self, capacity=12):
        if capacity < 0:
            raise ValueError("Invalid capacity")
        self._capacity = capacity
        self._size = 0

    def __str__(self):
        return "🍪" * self.size

    def deposit(self, n):
        if n > self.capacity:
            raise ValueError("Exceed")
        if self.size + n > self.capacity:
            raise ValueError("Exceed")
        self.size += n


    def withdraw(self, n):
          if n > self.size:
            raise ValueError("Not enough")
          self.size -= n

    @property
    def capacity(self):
        return self._capacity

    @property
    def size(self):
        return self._size


jar = Jar()
jar.deposit(2)
jar.withdraw(1)
jar.capacity()
jar.size()
print(jar)