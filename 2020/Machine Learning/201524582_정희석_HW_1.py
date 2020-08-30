#문제 정의
#PNU CSE
#201524582 Jeong Hee Seok 
#주의! 메모장으로 작성되어서 서식이 안 맞을 수 있습니다.
'''
<n-queens problem>
ㅁㅁ...ㅁㅁ
ㅁ.......ㅁ
...........
...........
ㅁ.......ㅁ
ㅁㅁ...ㅁㅁ
NxN matrix에 n개의 queen을 놓았을 때 서로 공격을 하지 않도록 배치하는 방법을 찾는다.
<과제>
n=5일 때 이 해를 찾는 모델을 작성하라
=> genetic algorithm을 기반으로 작성.
<genetic algorithm>
1. Chromosome design(염색체 설계)
-> n-element 배열 사용 -> 10개 사용
2. Initialization(초기화)
-> random으로 chromosome에 값을 입력
3. Fitness evaluation
-> 알고리즘에 넣어서 중첩되는 값이 0이 되면(check값이 0) 선택.
4. Selection
-> check값이 가장 낮은 chromosome 2개 선택
5. Crossover
-> chromosome 2개는 보존 -> [ㅇㅇ][ㅁㅁㅁ]로 나눠서 crossover 진행
6. Mutation
-> 첫번째 random -> mutation 개수 설정
-> 두번째 random -> mutation 위치
-> 세번째 random -> 해당 위치에서의 값
-> 2-3 반복
7. Update generation  
-> goto 3. Fitness evaluation
'''
#===========Module Import============#
import random
import copy
from pprint import pprint
#===========Function Definition============#
#3. Fitness Evaluation
def FitEval(cList,chkList,n):
  #cList => chromosomeList
  #chkList => checkList
  #n => n_of_element
  check = 0;
  chkList.clear()
  temp = []
  if(len(cList[0])==0):
    return -1
  for x in cList:
    for i in range(0,n):
      for j in range(1,n-1):
        if((i+j)<n):#현재보다 다음의 element check
          if(x[i]==x[i+j]):#같은 직선상
            check += 1
          elif(x[i]==x[i+j]-j):#대각선 위
            check += 1
          elif(x[i]==x[i+j]+j):#대각선 아래
            check += 1
        if((i-j)>0): #현재보다 이전의 element check
          if(x[i]==x[i-j]):#같은 직선상
            check += 1
          elif(x[i]==x[i-j]-j):#대각선 위
            check += 1
          elif(x[i]==x[i-j]+j):#대각선 아래
            check += 1
    chkList.append(check)
    check = 0
  check = 0
  for x in range (0,n_of_chromosome):
    if (chkList[x] == 0):
      print("Answer : " + str(cList[x]))
      temp = copy.deepcopy(cList[x])
      cList.clear()
      chkList.clear()
      cList.append(copy.deepcopy(temp))
      check = 1
      break
    elif ((x == n_of_chromosome - 1) & (check < 1)):
      print("No answer! Go to Next Step")
  return check

#4. Selection
def Selection(cList,chkList,n):
  #cList => chromosomeList
  #chkList => checkList
  #n => n_of_select
  chk = 1 #check 
  temp = []
  check_num = 0
  while(check_num < n):
    for x in range(0,len(chkList)):
      if(chk==chkList[x]):
        temp.append(x)
        check_num += 1
        if(check_num==n):
          break
    chk += 1
  for y in range(0,n):
    temp.append(cList[temp[0]])
    temp.pop(0)
  cList.clear()
  for y in range(0,n):
    cList.append(temp[y])

#5. Crossover
def Crossover(cList):
  #cList => chromosomeList
  chk = 1
  temp = []
  n_of_cList = len(cList)#2
  n_of_cross = len(cList[0])#5
  for x in range(0,n_of_cList):
    for y in range(0,n_of_cross):
      if(y < int(n_of_cross/2)):
        temp.append(cList[x][y])
      else:
        temp.append(cList[n_of_cList-x-1][y])
    cList.append(copy.deepcopy(temp))
    temp.clear()

#6. Mutation
def Mutation(cList,n):
  #cList => chromosomeList
  #n => num_of_chromosome
  temp = []
  for x in range(0,n-len(cList)):
    seed_1 = random.randint(1,5)  #seed_1 => mutation 개수
    if(x>=len(cList)):
      temp = copy.deepcopy(cList[(x-len(cList))])
    else:
      temp = copy.deepcopy(cList[x])
    for y in range(0,seed_1):
      seed_2 = random.randint(0,(len(cList[0])-1))#seed_2 => mutation 위치
      seed_3 = random.randint(1,len(cList[0]))#seed_3 => 바꿀숫자
      temp[seed_2] = seed_3
    cList.append(copy.deepcopy(temp))#뒤에 추가
    temp.clear()

#===========Execution============#
#표를 위한 matplotlib module import#
import matplotlib.pyplot as plt 
##chromosome design
checkList = []     #check점수를 담을 리스트
chromosome = []    #chromosome 기본
chromosomeList = []         #chromosome을 담을 리스트
n_of_element = 5 # 1~5 #element의 범위(n)
n_of_chromosome = 10  #chromosome 10개
n_of_select = 2 #selection에서 고를 chromosome의 개수 2개
count_of_gen = 0
for x in range(0,n_of_element):
  chromosome.append(x+1)
##chromosome initialization
for x in range(0,n_of_chromosome):       #1~5 안겹치게 shuffle => 10개 생성
  random.shuffle(chromosome)     #chromosome random으로 chromosome내부 요소들을 섞음
  chromosomeList.append(copy.deepcopy(chromosome)) #deepcopy를 사용 List에 chromosme을 추가
##Fitness Evaluation
check_a = 0
while(check_a==0): #check_a = 0 => Answer
  print(count_of_gen)
  check_a = FitEval(chromosomeList,checkList,n_of_element)
  if(check_a==1):
    break
  elif(len(chromosomeList)<n_of_chromosome):
    break
  ##Selection
  Selection(chromosomeList,checkList,n_of_select)
  print("[seleted] ")
  pprint(chromosomeList)
  ##Crossover
  Crossover(chromosomeList)
  print("[crossovered]")
  pprint(chromosomeList)
  ##Mutation
  Mutation(chromosomeList,n_of_chromosome)
  #Mutation의 결과를 확인하기 위해서는 아래의 주석에서 
  #pprint(chromosomeList) ##을 제거하면 확인 가능.
  count_of_gen+=1
#결과 출력용 list 생성
chess_board = []
chess_line = []
for x in range(0,n_of_element): #맨 첫 줄 생성 및 2차원 배열 생성
  if(chromosomeList[0][0]==(x+1)):
    chess_line.append("Q")
  else:
    chess_line.append(" ")
  chess_board.append(copy.deepcopy(chess_line))
  chess_line.clear()
for x in range(1,n_of_element): #생성된 2차원 배열에 배치
  for y in range(0,n_of_element):
    if(chromosomeList[0][x]==(y+1)):
      chess_board[y].append("Q")
    else:
      chess_board[y].append(" ")
pprint(chess_board) #최종 결과 체스판 배열
#위의 방식으로 한 이유는 위에서 나온 chromosome을 기반으로 배열을 배치하면
#y=-x를 기준으로 대칭이동한 결과가 나오기 때문이다.
#물론 대칭이동한 결과 역시 정답이다.
##matplotlib로 체스판을 그려서 보여주기
fig = plt.figure()#default(100dpi)
fig_axes = fig.add_subplot()#default(1,1,1)
fig_table = fig_axes.table(cellText=chess_board,cellLoc='center')
fig_table.scale(int(n_of_element/3),n_of_element)#column scale x1,row scale x5 => balance
fig_table.set_fontsize(30)#font Size 25pt
fig_axes.axis('off')  #remove axis 그래프
plt.subplots_adjust(left=0,bottom=0.55,right=0.55,top=1.0) #5-queens를 나타내는 것을 기준
plt.savefig("201524582_정희석.png")
plt.show()	#표를 출력