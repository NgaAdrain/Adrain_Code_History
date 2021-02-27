#-*- coding:utf-8 -*-
#Version 2는 상단의 통-페-한 0XX을 사용하는 방법을 써보자.
#indexing이 들어간다.

from datetime import date
import re
'''
Tong_Han_Fes = ''
Card_Name = ''
Idol_Name = ''
Card_Skill = ''
Main_Skill = ''
Gasha_Name = ''
Date = ''
Gasha_List = []
Fes_List = []
'''

#가챠 종류 체크
#찾아야 하는 것)
#1) n차 ... 가샤 -> 일반/페스 구분
#2) 개최 시작 일자(start : year, end : '일(')
def Read_Gasha():
	#[가챠 이름][개최 날짜]
	count = 1
	fes_count = 1
	Gasha_List = []
	Fes_List = []
	file = open("data.txt",'rt',encoding='utf-8') 		#가샤 체크
	lines = file.readlines()
	Gasha_Name = ''
	Date = ''
	Gasha_List.append(['0차 어서오세요! 프로듀서 가샤','2017-06-29'])
	for line in lines:
		start = line.find('>'+ str(count) +'차 ')
		if start == -1  : #연도
			continue
		else :
			#일반 가샤
			while (line.find('>'+ str(count) +'차 ')) != -1:
				n_start = line.find('>'+ str(count) +'차 ')
				end = line.find('<sp',n_start)
				Gasha_Name = line[n_start+1:end]
				Date = line[line.find('년 ',end)-4:line.find('일(',end)+1]
				y_m_d = re.findall("\d+",Date)
				if (int(y_m_d[1])<10) & (y_m_d[1][0]!='0'):
					y_m_d[1] = '0' + y_m_d[1] 
				if (int(y_m_d[2])<10) & (y_m_d[2][0] != '0'):
					y_m_d[2] = '0' + y_m_d[2] 
				Date = y_m_d[0] + '-' + y_m_d[1] + '-' + y_m_d[2]
				count = count + 1
				next = line.find('>'+ str(count) +'차 ')
				end = line.find('일(',end)
				#===
				Gasha_Info = []
				Gasha_Info.append(Gasha_Name)
				Gasha_Info.append(Date)
				#print(Gasha_Info[0])
				#print(Gasha_Info[1])
				Gasha_List.append(Gasha_Info)
				#===
			#페스 가샤
			while (line.find('>' + str(fes_count) + '차 밀리언 페스')) != -1:
				n_start = line.find('>'+ str(fes_count) +'차 밀리언 페스')
				end = line.find('<sp',n_start)
				Gasha_Name = line[n_start+1:end]
				Date = line[line.find('년 ',end)-4:line.find('일(',end)+1]
				y_m_d = re.findall("\d+",Date)
				if (int(y_m_d[1])<10) & (y_m_d[1][0] != '0'):
					y_m_d[1] = '0' + y_m_d[1] 
				if (int(y_m_d[2])<10) & (y_m_d[2][0] != '0'):
					y_m_d[2] = '0' + y_m_d[2] 
				Date = str(y_m_d[0]) + '-' + str(y_m_d[1]) + '-' + str(y_m_d[2])
				fes_count = fes_count + 1
				next = line.find('>'+ str(fes_count) +'차 밀리언 페스')
				end = line.find('일(',end)
				#===
				Fes_Info = []
				Fes_Info.append(Gasha_Name)
				Fes_Info.append(Date)
				#print(Fes_Info[0])
				#print(Fes_Info[1])
				Fes_List.append(Fes_Info)
				#===
	file.close()
	return Gasha_List, Fes_List
	
def Read_Card():
	#[통/한/페][가챠번호][카드 이름][아이돌 이름][개인 스킬][센터 스킬]
	Tong_Han_Fes = ''
	Gasha_Number = ''
	Card_Name = ''
	Idol_Name = ''
	Main_Skill = ''
	Card_List = []
	file = open("data_2.txt",'rt',encoding='utf-8')	#카드 종류들
	lines = file.readlines()
	for line in lines:
		start = line.find('<strong>센터 효과</strong>') + 20
		if start == -1  : #연도
			continue
		else :
			n_start = line.find('<st',start)
			while n_start != -1:
				card = []
				end = line.find('</st',n_start)
				Tong_Han_Fes = line[n_start+8:n_start+9]
				if(Tong_Han_Fes == '통'):
					Tong_Han_Fes = '통상'
				elif(Tong_Han_Fes == '한'):
					Tong_Han_Fes = '한정'
				else:
					Tong_Han_Fes = '페스'
				card.append(Tong_Han_Fes) #OK
				#print(Tong_Han_Fes)
				Gasha_Number = line[n_start+9:end]
				card.append(Gasha_Number) #OK
				#print(Gasha_Number)
				end = line.find('>[',end)
				Card_Name = line[end + 2:line.find('] ',end)]
				card.append(Card_Name)
				#print(Card_Name)
				end = line.find('] ',end)
				Idol_Name = line[end + 2:line.find('</a',end)]
				card.append(Idol_Name)
				#print(Idol_Name)
				end = line.find('</a',end)
				end = line.find('ph',end)
				Card_Skill = line[end+4:line.find('</d',end)]
				card.append(Card_Skill)
				#print(Card_Skill)
				end = line.find('</d',end)
				end = line.find('ph',end)
				Main_Skill = line[end+4:line.find('</d',end)]
				if((Main_Skill[0]=='<')):
					Main_Skill = Main_Skill[Main_Skill.find('>')+1:Main_Skill.find('<',1)]
					if(Main_Skill[Main_Skill.find('<',1)]=='+'):
						Main_Skill = Main_Skill + '15%(Type)'
				card.append(Main_Skill)
				#print(Main_Skill)
				Card_List.append(card)
				end = line.find('</d',end)
				n_start = line.find('<st',end)
	return Card_List			
	file.close()

def Data_Match(Gasha_List,Fes_List,Card_List):
	#[통/한/페][가챠번호][카드 이름][아이돌 이름][개인 스킬][센터 스킬][등장 날짜]
	tag = ''
	number = 0
	for card in Card_List:
		tag = card[0]
		number = int(card[1])
		if(tag == '페스'):
			#print(Fes_List[number-1][1])
			card.append(Fes_List[number-1][1])
		else:
			#print(Gasha_List[number][1])	
			card.append(Gasha_List[number][1])
	return Card_List

def Calculate(Card_List,Idol_Name):
	index = len(Card_List) - 1
	Date = ''
	card = []
	for i in range(index, 0, -1):
		if Card_List[i][3] == Idol_Name:
			Date = Card_List[i][6]
			card = Card_List[i]
			break
	if card == []:
		print("아이돌 이름 재입력")
		return None
	target = date.fromisoformat(Date)
	today = date.today()
	card.append(str((today-target).days) + '일')
	return card

def Idol_SSR_Info(Card_List,Idol_Name):
	print(Idol_Name + '의 카드 정보')
	index = len(Card_List) - 1
	card = []
	for i in range(0, index):
		if Card_List[i][3] == Idol_Name:
			card.append(Card_List[i])
	if card == []:
		print("아이돌 이름 재입력")
		return None
	return card
def UI_Print():
	print("=========================================================")
	print("= 							=")
	print("= 1. 일반 가샤 목록 보기 				=")
	print("= 2. 페스 가샤 목록 보기				=")
	print("= 3. 가샤 전체 목록 보기				=")
	print("= 4. 출시 SSR  목록 보기				=")
	print("= 5. 원하는 아이돌 SSR 출시 리스트 보기 		=")
	print("= 6. 원하는 아이돌 SSR 마지막 출시 이후 일 수 확인 	=")
	print("= 7. 종료						=")
	print("=							=")
	print("=========================================================")

def output(List,file_Name):
	file = open(file_Name + '.csv', 'wt' , encoding='utf-8')
	if(len(List[0]) == 2):
		file.write('가샤 이름| 시작 날짜\n')
		for inner in List:
			file.write(inner[0] + '|' + inner[1] + '\n')
	else:	
		file.write('통/한/페|회차|')
		file.write('카드이름|아이돌이름|')
		file.write('스킬|센터스킬|')
		file.write('출시 날짜\n')
		for inner in List:
			file.write(inner[0] + '|' + inner[1] + '|' )
			file.write(inner[2] + '|' + inner[3] + '|' )
			file.write(inner[4] + '|' + inner[5] + '|' )
			file.write(inner[6] + '\n')
	file.close()

def main():
	# 기능 1: 보통 가챠 vs 페스 가챠 구분
	# 기능 2: 가챠 진행 정리
	# 기능 3: 카드들 출시 순으로 정리
	# 기능 4: 원하는 아이돌 이름 입력하면 마지막 출시로 부터 지난 날 계산
	# 기능 5: 원하는 아이돌의 SSR 출시 리스트
	L1, L2 = Read_Gasha()
	CL = Read_Card()
	CL = Data_Match(L1,L2,CL)
	order = 0
	'''
	output(L1,'통상목록')
	output(L2,'페스목록')
	output(CL,'카드목록')
	'''
	while (order != 7):
		UI_Print()
		order = input("기능을 선택 해주세요 : ")
		if(order == '1'):
			for info in L1:
				print(info)
		elif(order == '2'):
			for info in L2:
				print(info)
		elif(order == '3'):
			for info in L1:
				print(info)
			for info in L2:
				print(info)
		elif(order == '4'):
			for info in CL:
				print(info)
		elif(order == '5'):
			idol = ' '
			while idol != '나가기':
				print("메인으로 나가려면 나가기 를 입력해 주세요")
				idol = input("아이돌 이름을 입력해주세요: ")
				if(idol == '나가기'):
					break
				for cd in Idol_SSR_Info(CL,idol):
					print(cd)
		elif(order == '6'):
			idol = ' '
			while idol != '나가기':
				print("메인으로 나가려면 나가기 를 입력해 주세요")
				idol = input("아이돌 이름을 입력해주세요: ")
				if(idol == '나가기'):
					break
				print(Calculate(CL,idol))
		elif(order == '7'):
			break
		else:
			print("잘못된 입력입니다")
	

if __name__ == "__main__":
	main()

