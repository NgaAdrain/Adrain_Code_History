#-*- coding:utf-8 -*-
#Version 1

#Version 2는 상단의 통-페-한 0XX을 사용하는 방법을 써보자.
#indexing이 들어간다. 
#아까 한거 무슨 가샤만 들어간다 라는 것을 먼저 데이터화시키고 index로 매칭

f = open("data.txt",'rt',encoding='utf-8') 		#가샤 체크
f2 = open("data_2.txt",'rt',encoding='utf-8')	#카드 종류들
lines_2 = f2.readlines()
lines = f.readlines()
count = 1
fes_count = 1


#Tong_Han_Fes = ''
#Card_Name = ''
#Idol_Name = ''
#Main_Skill = ''
Gasha_Name = ''
Date = ''
Gasha_List = []
Fes_List = []
#가챠 종류 체크
for line in lines:
	start = line.find('>'+ str(count) +'차 ')
	if start == -1  : #연도
		continue
	else :
		#기간 한정 카드
		#신규 추가 카드
		#찾아야 하는 것)
		#1) n차 ... 가샤
		#2) 개최 시작 일자(start : year, end : '일(')
		#3) 기간 한정 vs 신규 추가
		#4) SSR (find 'SSR', end : +3)
		#5) 카드 이름 (start : '[', end : ']')
		#6) 아이돌 이름 (start : ']', end : '<')
		while (line.find('>'+ str(count) +'차 ')) != -1:
			n_start = line.find('>'+ str(count) +'차 ')
			end = line.find('<sp',n_start)
			Gasha_Name = line[n_start+1:end]
			Date = line[line.find('년 ',end)-4:line.find('일(',end)+1]
			count = count + 1
			next = line.find('>'+ str(count) +'차 ')
			end = line.find('일(',end)
			#===
			Gasha_Info = []
			Gasha_Info.append(Gasha_Name)
			Gasha_Info.append(Date)
			print(Gasha_Info[0])
			print(Gasha_Info[1])
			Gasha_List.append(Gasha_Info)
			#===
			'''
			if line.find('기간 한정 ',end,next) != -1:
				end = line.find('기간 한정',line.find('일(',end,next))
				next = line.find('신규 추가',end)
				#===
				while line.find('SSR [' ,end,next) != -1:
					Tong_Han_Fes = 'H'
					Main_Skill = '콤보'
					#print('기간 한정')
					end = line.find('SSR [',end,next)
					print(line[end: end + 3])	#SSR
					Card_Name = line[end+5: line.find('] ',end,next)]
					print(Card_Name)		#카드 이름
					Idol_Name = line[line.find('] ',end)+2:line.find('<',end,next)]
					print(Idol_Name)		#아이돌 이름
					end = line.find('] ',end)
					print(Gasha_Name)
					print(Date)
					#여기에 csv파일이나 DB로 나가도록 구현#
				#===
			next = line.find('>'+ str(count) +'차 ')
			if next == -1:
				next = line.find('>' + str(fes_count) + '차 밀리언 페스')
			if line.find('신규 추가',end,next) != -1:
				end = line.find('신규 추가',end,next)
				#===
				while line.find('SSR [' ,end,next) != -1:
					Tong_Han_Fes = 'T'
					Main_Skill = '스코어업'
					print('신규 통상')
					end = line.find('SSR [',end,next)
					print(line[end: end + 3])	#SSR
					Card_Name = line[end+5: line.find('] ',end,next)]
					print(Card_Name)		#카드 이름
					Idol_Name = line[line.find('] ',end)+2:line.find('<',end,next)]
					print(Idol_Name)		#아이돌 이름
					end = line.find('] ',end)
					print(Gasha_Name)
					print(Date)
					#여기에 csv파일이나 DB로 나가도록 구현#
				#===
			'''
		#페스 추가
		while (line.find('>' + str(fes_count) + '차 밀리언 페스')) != -1:
			n_start = line.find('>'+ str(fes_count) +'차 밀리언 페스')
			print(n_start)
			end = line.find('<sp',n_start)
			Gasha_Name = line[n_start+1:end]
			Date = line[line.find('년 ',end)-4:line.find('일(',end)+1]
			fes_count = fes_count + 1
			next = line.find('>'+ str(fes_count) +'차 밀리언 페스')
			end = line.find('일(',end)
			#===
			Fes_Info = []
			Fes_Info.append(Gasha_Name)
			Fes_Info.append(Date)
			print(Fes_Info[0])
			print(Fes_Info[1])
			Fes_List.append(Fes_Info)
			#===
			'''
			while line.find('SSR [' ,end,next) != -1:
				Tong_Han_Fes = 'Fes'
				Main_Skill = '콤보'
				#print('기간 한정')
				end = line.find('SSR [',end,next)
				print(line[end: end + 3])	#SSR
				Card_Name = line[end+5: line.find('] ',end,next)]
				print(Card_Name)		#카드 이름
				Idol_Name = line[line.find('] ',end)+2:line.find('<',end,next)]
				print(Idol_Name)		#아이돌 이름
				end = line.find('] ',end)
				print(Gasha_Name)
				print(date)
			'''
f.close()