2020 컴퓨터응용설계및실험 
3주차 장치드라이버 응용프로그램 작성
전기컴퓨터공학부 정보컴퓨터공학전공
201524582 정희석

main코드는 fpga_test_push_switch.c이며 
compile용 Makefile은 DVD-1_SRC/examples/linux/fpga_driver/fpga_push_switch에 있는 Makefile을 사용.
헤더 파일로는 fpga_dot_font.h를 사용함.

동작전 해야하는 것
insmod fpga_fnd_driver.ko
mknod /dev/fpga_fnd c 261 0
insmod fpga_dot_driver.ko
mknod /dev/fpga_dot c 262 0
insmod fpga_text_lcd_driver.ko
mknod /dev/fpga_text_lcd c 263 0
insmod fpga_push_switch_driver.ko
mknod /dev/fpga_push_switch c 265 0

스크린샷 기준 시각 2020/04/15 16:18~
achro보드에서는 날짜와 시간이 초기화 되어 있기 때문에
date MMDDHHmmYYYY.SS를 통해 시간을 초기화 해야 한다.
NFS를 통해 host와 통신을 하기 때문에 인터넷 연결이 안되므로 시간 동기화는 지금 단계에서는 어렵다.
오전시간을 설정했을 때 정상 작동하는 것을 보이기 위해 시간을 설정하고 동작사진을 찍었다.