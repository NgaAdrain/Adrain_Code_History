2020 컴퓨터응용설계및실험 
6주차 보드 WIFI모듈을 사용하여 장치 조작 작성
전기컴퓨터공학부 정보컴퓨터공학전공
201524582 정희석

main코드는 SERVER폴더의 server.c이며 socket통신 관련해서는 지난학기 컴퓨터네트워크 BSD socket programming의
예제코드(텀프로젝트에서 서버프로그램 작성했던 것)를 응용.
SERVER를 보드에 올리고 이를 host에서 CLIENT 프로그램을 작성하여 소켓 통신을 통해 문자열을 주고
받게 동작하도록 함.(DOT-> 도트 출력, SEG-> 7-SEGx4 출력 LCD -> LCD출력, QUIT -> 연결종료)
compile용 Makefile은 새로 작성하였으며 링커 사용을 최소화 하기 위해 server.c파일에 필요한 부분을
모두 구현.
※소켓관련 코드 중 유사한 코드가 있을 수 있습니다. 이는 같이 컴퓨터 네트워크 
텀프로젝트를 진행했던 조원(클라이언트 프로그램 작성) 
역시 이 실험 과목을 같이 듣고있어서 같은 자료를 기반으로 작성할 가능성이 있습니다.
헤더 파일로는 fpga_dot_font.h를 사용함.

동작전 해야하는 것
insmod fpga_fnd_driver.ko
mknod /dev/fpga_fnd c 261 0
insmod fpga_dot_driver.ko
mknod /dev/fpga_dot c 262 0
insmod fpga_text_lcd_driver.ko
mknod /dev/fpga_text_lcd c 263 0

wifi설정.

문제점 -> 공유기를 사용 => 포트포워딩으로 25555포트를 보드에 할당한 192.168.10.115
(마지막에는 125로 변경)에 하여 113.131.100.18의 25555포트로 클라이언트를 접근 시켰는데
제대로 동작하지 않아서 DMZ를 사용하여 해결하였다.(이것 때문에 3일을 잡아먹었습니다...)

제출물은 CLIENT폴더의 client.c, SERVER폴더의 server.c fpga_dot_font.h, inet.h, Makefile
(make는 *.o 명령으로 object파일을 만든후 make를 통해서 SVR, CLI의 실행파일을 만들 수 있습니다.)
네트워크 설정 스크린샷, 동작동영상입니다.
