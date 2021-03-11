#-*- coding='utf-8' -*-
from datetime import datetime
import mouse as MS
import keyboard as KB
import pyautogui as PA
#from PyQt5.QtWidgets import QWidget ,QPushButton

def setting():
    print("Click Left Upper Side")
    request = False
    while(1):
        if MS.is_pressed():
            left_upper = MS.get_position();
            break
    print("Click Right Lower Side")
    while(1):
        if MS.is_pressed(MS.RIGHT):
            right_lower = MS.get_position();
            break
    hotkey = 'hotkey = ctrl+alt'
    conf = open('settings.conf','wt',encoding='utf-8')
    conf.write('Left_Upper = ' + str(left_upper[0]) + ',' + str(left_upper[1])+'\n')
    conf.write('Right_Lower = '+ str(right_lower[0]) + ',' + str(right_lower[1])+'\n')
    conf.write(hotkey)
    '''
    print("If You want to set hotkey Press S, or Not Press Q")
    while(1):
        if KB.is_pressed('s'):
            request = True
            break
        if KB.is_pressed('q'):
            request = False
            break
    if request:
    '''

def loading():
    loc = []
    hotkey = ''
    conf = open('settings.conf','rt',encoding='utf-8')
    for line in conf:
        if line[0] == 'L' or line[0] == 'R':
            x = int(line[line.find('= ') + 2:line.find(',')])
            y = int(line[line.find(',') + 1:line.find('\n')])
            loc.append(x)
            loc.append(y)
        else:
            hotkey = line[line.find('= ') + 2:]
    return tuple(loc), hotkey

def capture(loc):
    now = str(datetime.now().year) + '_' + str(datetime.now().month) + '_' + str(datetime.now().day) + '_' + str(datetime.now().hour)+'_' + str(datetime.now().minute) + '_' + str(datetime.now().second)
    path = './screenshot/' + now + '.png'
    PA.screenshot(path,region=loc)


def main():
    setting()
    location , hotkey = loading()
    print(hotkey)
    print('If You Want Exit, press CTRL+Q')
    while(1):
        if KB.is_pressed(hotkey):
            capture(location)
        if KB.is_pressed('ctrl+q'):
            break

if __name__ == "__main__":
	main()




