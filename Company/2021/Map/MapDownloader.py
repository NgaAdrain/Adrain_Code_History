# MAP GENERATOR FOR KAKAO
# By H.S.Jeong 2021/08/11

import requests
import os

import configparser

# READ CONFIG
config = configparser.ConfigParser()
config.read('Config.ini')

lateral_begin = int(config['AXIS']['BOTTOM'])     #아래   6
lateral_end = int(config['AXIS']['TOP'])          #위     7
longitudinal_begin = int(config['AXIS']['LEFT'])  #왼쪽   7
longitudinal_end = int(config['AXIS']['RIGHT'])   #오른쪽 8

min_level = int(config['LEVEL']['MIN']) 
max_level = int(config['LEVEL']['MAX']) 

# Prepare
base = 'https://map4.daumcdn.net/map_2d/2106wof/' #map0~4
# level = 10
# lateral_begin = 6       # 범위 찾기 #아래
# lateral_end = 7                     #위
# longitudinal_begin = 7  # 범위 찾기 #왼쪽
# longitudinal_end = 8                #오른쪽
# 다음 지도 특징은 폴더가 세로축 파일이 가로축이다.
# 이미지가 옆으로 이동.
ext = '.png'

# Download
print("Download Start...")
for level in reversed(range(min_level,max_level + 1)):
    if level == 10:
        print("CURRENT LEVEL = 10",end = '\r')
    else:
        print("CURRENT LEVEL =  {}".format(level),end = '\r')
    folder_base = 'L'+str(level)
    os.mkdir('L'+str(level))
    # print(folder_base)
    # Download
    for lateral in range(lateral_begin,lateral_end+1):
        folder = folder_base + "\\" + str(lateral)
        os.mkdir(folder)
        # print(folder)
        folder = folder_base + "\\" + str(lateral) + "\\"
        for longitudinal in range(longitudinal_begin,longitudinal_end+1):
            # print(folder + str(longitudinal) + ext)
            f = open(folder + str(longitudinal) + ext ,'wb')
            url = base + 'L' + str(level) + '/' + str(lateral) + '/' + str(longitudinal) + ext
            response = requests.get(url)
            f.write(response.content)
            f.close()

    # 다음 레벨로 이동
    lateral_begin = lateral_begin * 2
    lateral_end = lateral_end * 2 + 1
    longitudinal_begin = longitudinal_begin * 2
    longitudinal_end = longitudinal_end * 2 + 1

# Finish
print("Download End...")

# f = open(str(longitudinal) + '_4' + ext ,'wb')
# url = base + 'L' + str(level) + '/' + str(lateral) + '/' + str(longitudinal) + ext
# response = requests.get(url)
# print(response.status_code)
# f.write(response.content)
# f.close()
# #https://map0.daumcdn.net/map_2d/2106wof/L4/494/824.png
# print("download successful")
