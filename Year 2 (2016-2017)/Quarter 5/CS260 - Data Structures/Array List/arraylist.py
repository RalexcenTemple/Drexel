class arraylist():
	def __init__(self):
		self.L = []

	def LEN(self):
		i = sum(1 for n in self.L)
		#print("i: " + str(i))
		return i


	def FIRST(self):
		if not self.L:
			return self.END()
		else:
			return 0

	def END(self):
		#print(self.LEN() + 1)
		return (self.LEN() + 1)
	
	def RETRIEVE(self, p):
		if p >= self.END():
			return None
		else:
			return self.L[p-1]
	
	def LOCATE(self, x):
		for i in range(self.LEN()):
			if self.L[i] is x:
				return i+1
		return self.END()
	
	def NEXT(self,p):
		if p >= self.END():
			return None
		return (p+1)
		
	def PREVIOUS(self, p):
		if p >= self.END():
			return None
		if p is 0:
			return None
		else:
			return (p-1)
		
	def INSERT(self , x, p):
		if p is self.END():
			self.L.append(x)
			return self.L
		else:
			if (p > self.END())or(p <=0) :
				return None
			else:
				temp=self.L[p-1]
				self.L[p-1] = x
				self.INSERT(temp,(p+1))
		return self

	def DELETE(self, p):
		if (p >= self.END()):
			return self
		else:
			try:
				if self.L[p] is None:
					return self
			except IndexError:
					list = []
					tempL = arraylist()
					for i in range(self.LEN()-1):
						#print("i: " + str(i))
						list.append(self.L[i])
					#print(list)
					self.L = list
					return self
			else:
				self.L[p-1] = self.L[p]
				self.DELETE(p + 1)
	
	def MAKENULL(self):
		newList = arraylist()
		return newList


