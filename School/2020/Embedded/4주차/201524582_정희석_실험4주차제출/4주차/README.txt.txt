2020 컴퓨터응용설계및실험 
4주차 장치드라이버 응용프로그램 with GPIO 작성
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
insmod us_driver.ko
=> major #는 보통 246으로 할당 => 이때 나온 숫자로 mknod를 진행
ex) major number : 246
mknod /dev/us c 246 0

ultrasonic driver에서 interrupt의 정상 작동을 확인하기위해서 printk를 이용하여 echo의 값을 출력
=> 이를 통해 interrupt 진행여부를 확인하였다
Ultrasonic으로 부터 받은 charactor값을 atoi 함수를 이용하여 integer로 변환 후 이를 조건문에서 비교,
확인 절차에서 US센서를 손으로 막았을 때 값이 2000이상으로 나오는 것을 확인, 이를 조건문에서 처리하여
앞을 막았을 경우 Distance is too close를 출력하도록 하였고
거리가 300cm이상인 경우(계속 측정한 결과 1.5m를 넘어가면 오차가 많은 것으로 예상됨) 값이 부정확하다고
판단하여 Distance is too far를 출력하도록 하였다.
10cm보다 짧은 경우는 distance less than 10cm로 출력하게 하였다.
fpga를 사용하면 발생하는 문제는 Ultrasonic Sensor의 interrupt가 정상적으로 작동하지 않는다.