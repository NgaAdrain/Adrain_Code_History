import sys

import ListRead as lread

from PyQt5.QtWidgets import QApplication, QWidget ,QPushButton ,QToolTip, QDesktopWidget
from PyQt5.QtGui import QIcon, QFont
from PyQt5.QtWidgets import QMainWindow, QAction, qApp
from PyQt5.QtCore import QCoreApplication
from PyQt5.QtCore import QDate, Qt

###QMainWindow > QWidget

class MyApp(QWidget):
	
	def __init__(self):
		super().__init__()
		self.initUI()
	
	def initUI(self):
		#Title, Icon
		#self.setWindowTitle('Application Test')
		#self.setWindowIcon(QIcon('test.png'))

		#Button
		btn = []
		for i in range (0,7):
			btn.append(QPushButton('기능' + str(i+1), self))
			btn[i].move(200,50 + 50 * i)
		btn[0].clicked.connect(QCoreApplication.instance().quit)
		btn[0].setText('W♂NDER')
		btn[1].setText('$L♂T ')
		btn[2].setText('♂♂♂')
		#self.move(300,300) 	#위치 이동
		#self.resize(400,200) 	#크기 조절
		#=> 한번에 하는 것 self.setGeometry(x,y,w,h)
		# button object : QPushButton(문자열,대상)
		# 버튼.clicked.connect(클릭시 실행할 함수) => 시그널 & 슬롯

		#Tool tip
		QToolTip.setFont(QFont('SansSerif',10))
		self.setToolTip('This is a <b>QWidget</b> widget')
		btn[0].setToolTip('This is a <b>QPushButton</b> widget')
		#object.setToolTip('텍스트')로 object에 툴팁 첨부 가능

		#Status bar #Widget에서는 사용 불가!!!
		#self.statusBar().showMessage('Ready')
		
		#UI show
		self.setGeometry(700,250,500,500)
		self.show()	#UI표시


	'''
	def dataLoad(self):
		gasha_list = lread.readData('통상목록')
		fes_list = lread.readData('페스목록')
		card_list = lread.readData('카드목록')
		return gacha_list, fes_list, card_list
	'''

class MainLayer(QMainWindow):
	def __init__(self):
		super().__init__()
		self.date = QDate.currentDate() #현재 날짜
		self.initUI()
		
	def initUI(self):
		self.setWindowTitle('ASS We Can♂')
		self.setWindowIcon(QIcon('test.png'))
		#Status bar
		self.statusBar().showMessage('Ready')
		widget = MyApp() #위젯 불러오는 방식으로 사용
		self.setCentralWidget(widget) #위젯 위치 설정(Center)
		#Status bar Date 표시
		self.statusBar().showMessage(self.date.toString(Qt.DefaultLocaleLongDate))
		#단축키 & Action 설정
		exitAction = QAction(QIcon('exit.png'), 'Exit', self)
		exitAction.setShortcut('Ctrl+Q')
		exitAction.setStatusTip('Exit appliation')
		exitAction.triggered.connect(qApp.quit)

		#Menu bar
		menubar = self.menuBar()
		menubar.setNativeMenuBar(False)
		filemenu = menubar.addMenu('&File')
		filemenu.addAction(exitAction)

		#self.setGeometry(700,250,500,500)
		self.resize(500,500)
		self.center()
		self.show()
	
	def center(self): #UI를 화면의 가운데에 띄우기
		rectangle = self.frameGeometry()
		center_position = QDesktopWidget().availableGeometry().center()
		rectangle.moveCenter(center_position)
		self.move(rectangle.topLeft())

if __name__ == '__main__':
	app = QApplication(sys.argv)
	ex = MainLayer()
	sys.exit(app.exec_())