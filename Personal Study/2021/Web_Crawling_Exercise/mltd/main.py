import ListRead as lread

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

def main():
	L1 = lread.readData('통상목록')
	L2 = lread.readData('페스목록')
	CL = lread.readData('카드목록')
	order = 0
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
				for cd in lread.idolSSRInfo(CL,idol):
					print(cd)
		elif(order == '6'):
			idol = ' '
			while idol != '나가기':
				print("메인으로 나가려면 나가기 를 입력해 주세요")
				idol = input("아이돌 이름을 입력해주세요: ")
				if(idol == '나가기'):
					break
				print(lread.calculateDay(CL,idol))
		elif(order == '7'):
			break
		else:
			print("잘못된 입력입니다")
	'''
	for card in L1:
		print(card)
	for card in L2:
		print(card)
	for card in CL:
		print(card)
	'''
if __name__ == "__main__":
	main()