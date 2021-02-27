#Computer Algorithm 061 class
#Homework 1 sequence_alignment
#201524582 JeongHeeSeok

fileInput = open("input.txt", 'r') #file open read mode
fileOutput = open("output.txt", 'w') #file open write mode

sequence1 = fileInput.readline() #ATCCTAG-
sequence1 = sequence1[:-1] + '-' #last index not include
sequence2 = fileInput.readline() + '-' #TACGT-
fileInput.close()                      #result : -TAC-GT & penalty = 7

##Make 2-division Matrix##
matrix = [[0]*len(sequence2) for i in range(len(sequence1))]
##matrix initialization process##
matrix[-1][-1] = 0
for i in range(0,len(sequence2)-1):
    matrix[-1][i] = 2*(len(sequence2)-1-i)
for j in range(0,len(sequence1)-1):
    matrix[j][-1] = 2*(len(sequence1)-1-j)
##matrix filled with penalty##
for l in range(2,len(sequence1)+1):
    for m in range(2,len(sequence2)+1) :
        if(sequence1[-l]==sequence2[-m]) : 
            a = 0
        else : 
            a = 1
        matrix[-l][-m] = min([matrix[-l][-m+1]+2,matrix[-l+1][-m]+2,matrix[-l+1][-m+1] + a])

for k in range(0,len(sequence1)):
    print(matrix[k])
##find shortest path with down or below diagonal##
i = 0
j = 0
sequenceResult = ""
result = ""
while((i != len(sequence1)-1)&(j != len(sequence2)-1)):
    if(matrix[i][j] - 2 == matrix[i+1][j]):
        i += 1
        result += "%d" % 2
        sequenceResult += "-"
    elif(matrix[i][j] -2 == matrix[i][j+1]):
        pass
        #j += 1
        #sequenceResult += "-"
    else:
        sequenceResult += sequence2[j]
        result += "%d" % (matrix[i][j]-matrix[i+1][j+1]) 
        i += 1
        j += 1

##print, write to file##
out = "Sequence penalty score = %d" % matrix[0][0]
print(out)
out += "\n"
fileOutput.write(out)

sequence1 = sequence1[:-1]
print(sequence1)
sequence1 += "\n"
fileOutput.write(sequence1)

print(sequenceResult)
sequenceResult += "\n"
fileOutput.write(sequenceResult)

print(result)
result += "\n"
fileOutput.write(result)

fileOutput.close()