class arraystack:
  def __init__(self):
      self.S = []

  def LEN(self):
      i = sum(1 for n in self.S)
      return i
    
  def TOP(self):
        return self.S[0]
  	
  def POP(self):
        i = 1
        tempStack = arraystack()
        arr = []
        try:
            while i <= (self.LEN()):
                arr.append(self.S[i])
                i=i+1
        except IndexError:
            #print(arr)
            tempStack.S = arr
            #print(tempStack.S)
            self = tempStack
            return self
  
  def PUSH(self,x):
        self.S = [x] + self.S
        return self

        
  def EMPTY(self):
     if self.S[0] is None:
        return True
     else:
        return False
  
  def MAKENULL(self):
      newStack = arraystack()
      return newStack


