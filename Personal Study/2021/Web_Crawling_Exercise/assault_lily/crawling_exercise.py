import requests
from bs4 import BeautifulSoup

def crawling(web_addr ,tag ,specification):
	#web_addr = https://altema.jp/assaultlily/memorialist
	res = requests.get(web_addr)
	soup = BeautifulSoup(res.content, 'html.parser')
	#tag = 'tr'
	data = soup.find_all(tag)
	mem_list = []
	#specifictaion = 'data-obj'
	for dat in data:
		if dat.get(specification) != None:
			mem_list.append(dat.get(specification))
	return mem_list

def extract(data):
	information = []
	#1. id
	front = data.find('id')
	end = data.find(',')
	information.append(data[front+4:end])
	#2. name
	front = data.find('name')
	end = data.find('",',front)
	information.append(data[front+7:end])
	#3. rare
	front = data.find('rea":')
	end = data.find(',',front)
	information.append(data[front+5:end])
	#4. feature
	front = data.find('zokusei":')
	end = data.find(',',front)
	information.append(data[front+9:end])
	#5. mem_type
	front = data.find('"memoria_type":')
	end = data.find(',',front)
	information.append(data[front+15:end])
	#6. status(0: atk, 1: sp_atk, 2: def, 3: sp_atk)
	status = []
	front = data.find('"atk":')
	end = data.find(',',front)
	status.append(data[front+6:end])
	front = data.find('"sp_atk":')
	end = data.find(',',front)
	status.append(data[front+9:end])
	front = data.find('"def":')
	end = data.find(',',front)
	status.append(data[front+6:end])
	front = data.find('"sp_atk":')
	end = data.find(',',front)
	status.append(data[front+9:end])
	information.append(status)
	#7. skill_types(0: huge_type, 1: legion_type, 2: legion_support_type)
	skills = []	
	front = data.find('"huge_type":')
	end = data.find(',',front)
	skills.append(data[front+12:end])
	front = data.find('"legion_type":')
	end = data.find(',',front)
	skills.append(data[front+14:end])
	front = data.find('"legion_hojo_type":')
	end = data.find('}',front)
	skills.append(data[front+19:end])
	information.append(skills)
	print(information)
	return information
#id":200,
#"name":"\u653e\u8ab2\u5f8c\u30d5\u30a1\u30f3\u30bf\u30ba\u30e0",
#"furigana":"\u307b\u3046\u304b\u3054\u3075\u3041\u3093\u305f\u305a\u3080",
#"ichiran_name":"\u653e\u8ab2\u5f8c\u30d5\u30a1\u30f3\u30bf\u30ba\u30e0",
#"chara_name":"","chara_furigana":"",
#"rea":5,"zokusei":1,"memoria_type":2,"hyoka":85,
#"saikyo_rank_id":3,"huge_rank_id":3,"legion_rank_id":4,
#"atk":1970,"sp_atk":1338,"def":1904,"sp_def":1337,
#"huge_type":1,"legion_type":1,"legion_hojo_type":4}
#rea>
#=>rarelity(5성,4성,3성)
#zokusei>
#=> 1: 화속, 2: 수속 3: 풍속
#memoria_type >
#=>1. 통상단일공격 2. 통상복수공격 3. 특수단일공격 4. 특수복수공격
#=>5. 아군 버프 6. 적 디버프 7. 회복
#huge_type>
#legion_type>
#legion_hojo_type>
#name: 메모리아 이름, rea: 별, zokusei: 속성, memoria_type: 메모리얼 타입,
#atk: 일공, sp_atk: 특공, def: 일방, sp_def: 특방
#huge_type: 휴지 스킬, legion_type: 레기온 스킬, legion_hojo_type: 레기온 보조 스킬
'''
def translate(information):
	
'''	

def main():
	web_addr = 'https://altema.jp/assaultlily/memorialist'
	tag = 'tr'
	specifictaion = 'data-obj'
	#필요 tag: name, rea, zokusei, memoria_type, atk, sp_atk, def, sp_def
	mem_list = crawling(web_addr ,tag ,specifictaion)
	data_list = []
	for memorial in mem_list:
		data_list.append(extract(memorial))

if __name__ == "__main__":
	main()
	