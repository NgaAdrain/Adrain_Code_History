# MAP GENERATOR FOR VWORLD
# By H.S.Jeong 2021/08/12

import requests
import os

import configparser

# READ CONFIG
config = configparser.ConfigParser()
config.read('Config.ini')

lateral_begin = int(config['AXIS']['TOP'])        #위     404
lateral_end = int(config['AXIS']['BOTTOM'])       #아래   405
longitudinal_begin = int(config['AXIS']['LEFT'])  #왼쪽   874
longitudinal_end = int(config['AXIS']['RIGHT'])   #오른쪽 875

min_level = int(config['LEVEL']['MIN']) # 11
max_level = int(config['LEVEL']['MAX']) # 18

# Prepare
# base = 'https://map4.daumcdn.net/map_2d/2106wof/' #map0~4
base = 'https://xdworld.vworld.kr/2d/Base/service/'#7/110/48.png
# level = 10
# lateral_begin = 6       # 범위 찾기 #아래
# lateral_end = 7                     #위
# longitudinal_begin = 7  # 범위 찾기 #왼쪽
# longitudinal_end = 8                #오른쪽
# 브이월드 지도 특징은 폴더가 가로축 파일이 세로축이다.
# 이미지가 옆으로 이동.
ext = '.png'

os.mkdir('Base')

# Download
print("Download Start...")
for level in range(min_level,max_level + 1): # 11~ 18
    if level >= 10:
        print("CURRENT LEVEL = {}".format(level),end = '\r')
    else:
        print("CURRENT LEVEL =  {}".format(level),end = '\r')
    folder_base = 'Base' + "\\" +str(level)
    os.mkdir(folder_base)
    # print(folder_base)
    # Download
    for longitudinal in range(longitudinal_begin,longitudinal_end+1):
        folder = folder_base + "\\" + str(longitudinal)
        os.mkdir(folder)
        # print(folder)
        folder = folder_base + "\\" + str(longitudinal) + "\\"
        for lateral in range(lateral_begin,lateral_end+1):
            # print(folder + str(longitudinal) + ext)
            f = open(folder + str(lateral) + ext ,'wb')
            url = base + str(level) + '/' + str(longitudinal) + '/' + str(lateral) + ext
            response = requests.get(url)
            f.write(response.content)
            f.close()

    # 다음 레벨로 이동
    longitudinal_begin = longitudinal_begin * 2
    longitudinal_end = longitudinal_end * 2 + 1
    lateral_begin = lateral_begin * 2
    lateral_end = lateral_end * 2 + 1

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
