import math

class DynamicArray:
    arr = []
    newArr = []
    capacity = 0
    size = 0
    def __init__(self):
        self.capacity = 2
        self.size = 0
        self.arr = [0] * self.capacity
        print(self.arr)
    def increaseSize(self):
        self.newArr = [0] * self.capacity
        for i in range(len(self.arr)):
            self.newArr[i] = self.arr[i]
        self.capacity = self.capacity * 2
        self.arr = [0] * self.capacity
        for i in range(len(self.newArr)):
            self.arr[i] = self.newArr[i]
        self.newArr = []
    def getCapacity(self):
        return self.capacity
    def getValue(self, index):
        if index >=0 and index < self.size:
            return self.arr[index]
        else:
            print("Index out of bounds execption")
    def setValue(self, index, value):
        if index < 0:
            print("Index out of bounds execption")
        elif(index < self.capacity):
            self.arr[index] = value
            self.size = index
        else:
            self.increaseSize()
            self.arr[index] = value
            self.size = index
    def getSize(self):
        return self.size
    def pushBack(self, value):
        if self.size < self.capacity:
            self.arr[self.size] = value
            self.size += 1
        else:
            self.increaseSize()
            self.arr[self.size] = value
            self.size += 1
    def remove(self, index):
        for i in range(index-1, self.size - 1):
            self.arr[i] = self.arr[i+1]
        self.size -= 1
    def showElements(self):
        print(self.arr)
    def is_empty(self):
        if(self.size == 0):
            return True
        else:
            return False