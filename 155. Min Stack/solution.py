class MinStack:

    def __init__(self):
        self.stack = []
        self.currentMin = 9223372036854775807
        self.minstack = []

    def push(self, val: int) -> None:
        self.stack.append(val)
        if val <= self.currentMin and self.currentMin == 9223372036854775807:
            self.currentMin = val
        elif val <=self.currentMin and self.currentMin != 9223372036854775807:
            self.minstack.append(self.currentMin)
            self.currentMin = val


    def pop(self) -> None:
        if self.stack[len(self.stack) - 1] == self.currentMin and len(self.minstack) != 0:
            self.currentMin = self.minstack.pop()
        elif self.stack[len(self.stack) - 1] == self.currentMin and len(self.minstack) == 0:
            self.currentMin = 9223372036854775807
        self.stack.pop()
        
    def top(self) -> int:
        return self.stack[len(self.stack) - 1]
    
    def getMin(self) -> int:
        return self.currentMin
        


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()