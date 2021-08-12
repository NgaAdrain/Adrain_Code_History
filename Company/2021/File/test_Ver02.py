import os

print("좌측 번호 입력 : ", end = "")
left_name = input()
print("우측 번호 입력 : ", end = "")
right_name = input()
print("상단 번호 입력 : ", end = "")
top_name = input()
print("하단 번호 입력 : ", end = "")
bottom_name = input()

left = int(left_name)
right = int(right_name)
top = int(top_name)
bottom = int(bottom_name)

TARGET_LOCATION = '.\\todo_11\\' # 원하는 파일 존재하는 위치
for i in range(left,right + 1):
    TARGET = TARGET_LOCATION + str(i) #todo_15/27921
    if(os.path.isdir(TARGET)):
        TARGET_FILE = [file for file in os.listdir(TARGET) if file.endswith('.png')]
        for name in TARGET_FILE:
            num = int(name[:name.find('.')])
            if top > num or bottom < num:
                os.remove(TARGET + '\\' + name)
                # print()




    
