#-*- coding:utf-8 -*-
#information#
"""
2019 Spring Semester 
Computer Algorithm 061 class
Homework2
201524582 JeongHeeSeok

"""
###use sys.argv[1] for > .py input.txt###
import sys

try:
    inpFile = open(sys.argv[1],'r')
except:
    inpFile = open('input.txt','r')

INF = sys.maxsize-1 #for using on best-first branch-and bound
###introduction of this program###
print('this program solve Traveling Salesperson Problem with three algorithms')
print('that greedy search, backtracking and branch-and-bound')
print('this problem is start from one vertex, traveling all vertex only once,')
print('finally arrive to start vertex with smallest cost')
###initialization from file###
numOfVertex = int(inpFile.readline())
print('this graph\'s number of vertex is ',numOfVertex)
graph = [[0]*numOfVertex for i in range(numOfVertex)] #make empty 2-division graph
for x in range(numOfVertex):
    templine = inpFile.readline();
    templine = templine.replace("\n","")
    templine = templine.split(" ")
    ### print(templine); #check for fileread
    for y in range(numOfVertex):
        graph[x][y] = int(templine[y])

inpFile.close();
#"""
#check for graph
for x in range(numOfVertex):
    for y in range(numOfVertex):
        print(graph[x][y],end=' ');
    print();
#"""
###greedy search algorithm###
print('<first : greedy search algorithm>') #35
print('start from 1')
count_gree = 0
listPointer = [0]*numOfVertex
path_gree = []
path_gree.append(0)
for i in range(numOfVertex):
    listPointer[i] = i
listPointer.remove(0)
length = 0
start = 0
tempIndex = listPointer[0]
while(1):   #Modify!
    temp = graph[start][listPointer[0]]
    tempIndex = listPointer[0]
    for j in listPointer:#select minimum of graph => modify to pointer no check
         if(temp>graph[start][j]):
             temp = graph[start][j]
             tempIndex = j
         count_gree = count_gree+1    

    path_gree.append(tempIndex)
    start = tempIndex
    length += temp
    listPointer.remove(tempIndex)
    if not listPointer:
        break

length += graph[start][0]
print('Path : ', end = '')
for x in path_gree :
    print(x+1,end = ' -> ')
path_gree.append(0)
print(path_gree[-1]+1)

print('length : ' ,end = '')
print(length)

print('calculate count = ' , end = '')
print(count_gree)

###Node and Linked-List for BackTracking###
class Node_Back:
    def __init__(self, vertex, path):
        self.deadEnd = [False]*numOfVertex
        self.vertex = vertex
        #self.next = None
        for i in path:
            self.deadEnd[i]=True

    def dead(self,vertex):
        self.deadEnd[vertex] = True

    def isDead(self):
        result = True
        for i in range(numOfVertex):
            result = result & self.deadEnd[i]
        return result

class LinkedList_Back():
    def __init__(self,vertex,path,point,minimum,min_list):
        self.head = Node_Back(vertex,path)
        self.path = path
        self.point = point
        self.minimum = minimum
        self.mins = min_list
        self.min_path = None
        self.count = 0
    def promising(self,vertex):
        x = 0
        leng = 0
        for y in self.path:
            leng += graph[x][y]
            x = y
        for y in self.point:
            leng += self.mins[y]
        return leng
    def search(self):
        for x in range(1,numOfVertex):
            self.count = self.count+1
            if(self.head.deadEnd[x] == True):
                continue
            else:
                check = self.promising(x)
                if(check>=minimum):
                    self.head.dead(x)
                    continue
                else:
                    self.down(x,self.point)
                    if(self.min_path==[]):
                        self.head.dead(x)
    def down(self,vertex,point):
        self.path.append(vertex)
        self.point.remove(vertex)
        check = self.promising(vertex)
        temp = Node_Back(vertex,self.path)
        for x in point:
            if(temp.deadEnd[x]==True):
                continue
            else:
                check = self.promising(x)
                if(check>=self.minimum):
                    temp.dead(x)
                    continue
                else:
                    self.down(x,self.point)
        if(self.point == []):
            check = check + graph[self.path[-1]][0]
            if(check<self.minimum):
                self.minimum = check
                i = 0
                if(self.min_path == None):
                    self.min_path = []
                    for j in self.path:
                        self.min_path.append(j)
                else:
                    for j in self.path:
                        self.min_path[i] = j
                        i = i + 1

        self.path.remove(vertex)
        self.point.append(vertex)
        self.count = self.count + 1
    def printPath(self):
        print('Path : ',end='')
        for x in self.min_path:
            print(x+1,end=' -> ')
        print(1)
        print('length : ', end = '')
        print(self.minimum)
        print('count : ', end = '')
        print(self.count)
#finished at 19/06/02 20:00
###===========###
###backtracking###
print('<second : backtracking algorithm>') #33
print('Initialize minimum from greedy search\'s result : ', end = '')
###
visit = [0]*numOfVertex
count = 0
count_back = 0
path_back = path_gree
lower_bound = 0
mins = []
minimum = length
print(minimum)
for x in range(numOfVertex):
    temp = 10000
    for y in graph[x]:
        if(y!=0) :
            if(temp>y):
                temp = y

    mins.append(temp)
    lower_bound += temp

print('lower bound is : ', end = '')
print(lower_bound)
for i in range(numOfVertex):
    listPointer.append(i)
listPointer.remove(0)
path = []
path.append(0)
###implement###
node_start = LinkedList_Back(0,path,listPointer,minimum,mins)
node_start.search()                 #backtracking process
node_start.printPath()              #backtracking information
path_back = node_start.min_path     #path of backtracking
count_back = node_start.count       #count of backtracking
length_back = node_start.minimum    #length of backtracking path
#finished at 19/06/05 19:50
###Linked-List for Branch-and bound###
class Node_Bran:
    def __init__(self, vertex, path, r_graph = graph, parent_b = 0):
        self.vertex = vertex
        self.path = []
        for x in path:
            self.path.append(x)
        #self.path.append(vertex)
        self.reduced = [[0]*numOfVertex for i in range(numOfVertex)] #reduced_graph for calculate bound
        for x in range(numOfVertex):
            for y in range(numOfVertex):
                self.reduced[x][y] = r_graph[x][y]
        self.level = len(path)
        self.bound = parent_b
        min_col = []
        min_row = []
    ###setting for diagonal infinite###
        if(self.reduced[0][0]!=INF):
            for i in range(numOfVertex):
                self.reduced[i][i]=INF #setting infinite.
        if(self.path!=[]):
            self.bound += self.reduced[self.path[-1]][self.vertex]
            for x in range(numOfVertex):
                self.reduced[path[-1]][x] = INF
                self.reduced[x][vertex] = INF
                
    ###setting reduce graph###
        for x in range(numOfVertex):
            temp = INF
            for y in self.reduced[x]:
                if(y!=INF) :
                    if(temp>y):
                        temp = y
            if(temp==INF): temp = 0
            min_col.append(temp)
            self.bound+=temp
            for y in range(numOfVertex):
                if(self.reduced[x][y]!=INF) :
                    self.reduced[x][y] -= temp

        for x in range(numOfVertex):
            temp = INF
            for y in range(numOfVertex):
                if(self.reduced[y][x]!=INF):    
                    if(temp > self.reduced[y][x]):
                        temp = self.reduced[y][x]
            if(temp==INF): temp = 0
            min_row.append(temp)
            self.bound+=temp
            for y in range(numOfVertex):
                if(self.reduced[y][x]!=INF): 
                    self.reduced[y][x]-=temp
        self.path.append(vertex)

    def print(self):
        print('Path : ',end='')
        for x in self.path:
            print(x+1,end=' -> ')
        print(1)
        print('length : ', end = '')
        print(self.bound)
class LinkedList_Bran:
    def __init__(self):
        self.queue = []
        self.parent_node = Node_Bran(0,[],graph)
        self.min_node = None
        self.min = INF
        self.point = []
        self.count_br = 0
        for i in range(1,numOfVertex):
            self.point.append(i)
    def search(self):
        #first initialize
        result = None
        for i in range(1,numOfVertex):
            temp = Node_Bran(i,[0],self.parent_node.reduced,self.parent_node.bound)
            self.queue.append(temp) 
        while(self.queue!=[]):
            temp = self.queue[0]
            for a in self.queue: ##Compare node's
                if(a==None) : break;
                if (len(a.path) == 5): #check for completion.
                    temp = a #expected to minimum
                    self.queue.remove(a)
                    for b in self.queue:
                        self.count_br+=1
                        if(temp.bound<=b.bound):#another bound less than expected minimums bound
                            self.queue.remove(b) #useless! -> not expect better than temporary minimums
                        else : #expect possibility
                            if(len(b.path) == 5): #already full path! => it is better than expected path!
                                temp = b #replace!
                                self.queue.remove(b)
                else : #not complete
                    self.count_br+=1
                    if (temp.bound>a.bound):
                        temp = a           
            
            for x in temp.path: ##for navigate
                if(x!=0):
                    self.point.remove(x)
            for y in self.point: ##append node to queue
                if(len(temp.path)== 5) : break #no addition branch on maximum
                self.queue.append(Node_Bran(y,temp.path,temp.reduced,temp.bound))         
            for z in temp.path: ##point restore
                if(z!=0):
                    self.point.append(z)
            c = 0 #check for another answer => already deleted => after one comparation cycle
            for a in self.queue:
                if(a==temp): #
                    self.queue.remove(a)
                    c = 1 #Oh this is not yet
                    break
            if(len(temp.path) == 5):
                if(c == 0 ): #=> this is minimum path!
                    break
        self.min_node = temp
        self.min_node.print()
        self.min =  temp.bound
        print('count : ',self.count_br)
#finished at 19/06/06 20:00 ..TT
            
###branch-and bound algorithm###
print('<last : branch-and bound algorithm>') #33
#visit = [0]*numOfVertex
count = 0
count_bran = 0
path_bran = [0]
minimum = 0

###implement###
bran_node_start = LinkedList_Bran()
bran_node_start.search();
path_bran = bran_node_start.min_node.path
minimum = bran_node_start.min_node.bound

