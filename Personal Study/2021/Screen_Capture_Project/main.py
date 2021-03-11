#-*- coding='utf-8' -*-
from datetime import datetime
import mouse as MS
import keyboard as KB
import pyautogui as PA
#from PyQt5.QtWidgets import QWidget ,QPushButton

def file_test():
    try:
        file = open('settings.conf','rt',encoding='utf-8')
    except FileNotFoundError:
        file = open('settings.conf','wt',encoding='utf-8')
        file.write(' ')
        file.close()
        return False
    line = file.readline()
    if line == ' ':
        return False
    else:
        return True


def setting():
    conf = open('settings.conf','wt',encoding='utf-8')
    print("Left Click on Left Upper Side")
    request = False
    while(1):
        if MS.is_pressed():
            left_upper = MS.get_position();
            break
    print("Right Click on Right Lower Side")
    while(1):
        if MS.is_pressed(MS.RIGHT):
            right_lower = MS.get_position();
            break
    hotkey = 'Hotkey = ctrl+alt'

    conf.write('Left_Upper = ' + str(left_upper[0]) + ',' + str(left_upper[1])+'\n')
    conf.write('Size = '+ str(right_lower[0]-left_upper[0]) + ',' + str(right_lower[1]-left_upper[1])+'\n')
    conf.write(hotkey)
    conf.close()
    print('Setting Complete')
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
        if line[0] == 'L' or line[0] == 'S':
            x = int(line[line.find('= ') + 2:line.find(',')])
            y = int(line[line.find(',') + 1:line.find('\n')])
            loc.append(x)
            loc.append(y)
        else:
            hotkey = line[line.find('= ') + 2:]
    conf.close()
    return tuple(loc), hotkey

def capture(loc):
    now = str(datetime.now().year) + '_' + str(datetime.now().month) + '_' + str(datetime.now().day) + '_' + str(datetime.now().hour)+'_' + str(datetime.now().minute) + '_' + str(datetime.now().second)
    path = './screenshot/' + now + '.png'
    PA.screenshot(path,region=loc)

def show_info():
    print('If You Want Capture, press CTRL+ALT')
    print('If You Want Exit, press CTRL+Q')
    print('If You Want to change Setting, press CTRL+SHIFT')

def main():
    if file_test() is False:
        setting()
    location , hotkey = loading()
    show_info()
    while(1):
        if KB.is_pressed(hotkey):
            capture(location)
        if KB.is_pressed('ctrl+shift'):
            setting()
            location , hotkey = loading()
            show_info()
        if KB.is_pressed('ctrl+q'):
            break

if __name__ == "__main__":
	main()




