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
        if self._size + n > self.capacity:
            raise ValueError("Exceed")
        self._size += n


    def withdraw(self, n):
          if n > self._size:
            raise ValueError("Not enough")
          self._size -= n

    @property
    def capacity(self):
        return self._capacity

    @property
    def size(self):
        return self._size

# test
jar = Jar()
print(str(jar.capacity))
print(str(jar.size))
jar.deposit(2)
print(str(jar))
jar.withdraw(1)
print(str(jar))