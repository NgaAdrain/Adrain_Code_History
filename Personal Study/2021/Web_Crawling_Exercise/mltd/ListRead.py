#-*- coding:utf-8 -*-

from datetime import date

def readData(File_Name):
	result_List = []
	File = open( File_Name+'.csv','rt',encoding='utf-8')
	lines = File.readlines()
	tag = True
	for line in lines:
		if tag == True:
			tag = False
		else:
			line = line.replace('\n','')
			list = line.split('|')
			result_List.append(list)
	return result_List

def idolSSRInfo(Card_List,Idol_Name):
	print(Idol_Name + '의 카드 정보')
	index = len(Card_List) - 1
	idol_List = []
	for i in range(0, index):
		if Card_List[i][3] == Idol_Name:
			idol_List.append(Card_List[i])
	if idol_List == []:
		print("아이돌 이름 재입력")
		return None
	return idol_List

def calculateDay(Card_List,Idol_Name):
	index = len(Card_List) - 1
	Date = ''
	idol_Card = []
	for i in range(index, 0, -1):
		if Card_List[i][3] == Idol_Name:
			Date = Card_List[i][6]
			idol_Card = Card_List[i][:] #swallow copy but different
			break
	if idol_Card == []:
		print("아이돌 이름 재입력")
		return None
	target = date.fromisoformat(Date)
	today = date.today()
	if len(idol_Card) == 7:
		idol_Card.append(str((today-target).days) + '일')
	else : #update
		del idol_Card[7]
		idol_Card.append(str((today-target).days) + '일')
	return idol_Card

