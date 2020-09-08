from string import ascii_lowercase
from string import ascii_uppercase
class Node:
    def __init__(self, name=None, data=None):
        self.name = name
        self.data = data
        self.children = dict()

    def ADDCHILD(self, key, data=None):
        if not isinstance(key, Node):
            self.children[key] = Node(key, data)
        else:
            self.children[key.label] = key

    def __getitem__(self, key):
        return self.children[key]


class Trie:
    def __init__(self):
        self.head = Node()

    def __getitem__(self, key):
        return self.head.children[key]

    def ADD(self, word):
        temp = self.head
        wordend = True
        for i in range(len(word)):
            if word[i] in temp.children:
                temp = temp.children[word[i]]
            else:
                wordend = False
                break

        if not wordend:
            while i < len(word):
                temp.ADDCHILD(word[i])
                temp = temp.children[word[i]]
                i += 1
        temp.data = word

    def CHECKWORD(self, word):
        if word == '':
            return False
        if word == None:
            raise ValueError('Trie.has_word requires a not-Null string')

        temp = self.head
        bool = True
        for letter in word:
            if letter in temp.children:
                temp = temp.children[letter]
            else:
                bool = False
                break
        if bool:
            if temp.data == None:
                bool = False
        return bool

    def STARTPRE(self, pre):
        sentance = list()
        if pre == None:
            raise ValueError('Requires not-Null prefix')

        headNode = self.head
        for letter in pre:
            if letter in headNode.children:
                headNode = headNode.children[letter]
            else:
                return sentance

        if headNode == self.head:
            queue = [node for key, node in headNode.children.items()]
        else:
            queue = [headNode]

        while queue:
            popped = queue.pop()
            if popped.data != None:
                sentance.append(popped.data)
            queue = [node for key, node in popped.children.items()] + queue
        return sentance

    def getData(self, word):
        if not self.has_word(word):
            raise ValueError('{} not found in trie'.format(word))
        temp = self.head
        for letter in word:
            temp = temp[letter]

        return temp.data


if __name__ == '__main__':
    trie = Trie()
    with open('alice.txt','r') as alice:
        aliceFile = alice.read().replace('\n',' ')
    for word in aliceFile.split():
        trie.ADD(word)
    #print("'end' in alice in wonderland: ", trie.CHECKWORD('end'))
    size = 0
    for i in ascii_lowercase:
        if(size < len(trie.STARTPRE(i))):
            size = len(trie.STARTPRE(i))

    for j in ascii_uppercase:
        if(size < len(trie.STARTPRE(j))):
            size = len(trie.STARTPRE(j))
    #print(trie.STARTPRE('d'))
    print("largest size prefix trie: " , size)