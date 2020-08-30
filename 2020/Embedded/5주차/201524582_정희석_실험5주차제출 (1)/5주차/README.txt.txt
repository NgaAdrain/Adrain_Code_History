2020 컴퓨터응용설계및실험 
5주차 bluetooth를 통해 GPIO monitoring
전기컴퓨터공학부 정보컴퓨터공학전공
201524582 정희석

main코드는 us_app.c이며 
compile용 Makefile은 이전주차의 Makefile을 사용.
헤더 파일로는 fpga_dot_font.h를 사용함. => FPGA와 GPIO의 충돌로 사용하지 않음

동작전 해야하는 것
insmod us_driver.ko
=> major #는 보통 246으로 할당 => 이때 나온 숫자로 mknod를 진행
ex) major number : 246
mknod /dev/us c 246 0

(4주차)
ultrasonic driver에서 interrupt의 정상 작동을 확인하기위해서 printk를 이용하여 echo의 값을 출력
=> 이를 통해 interrupt 진행여부를 확인하였다
Ultrasonic으로 부터 받은 charactor값을 atoi 함수를 이용하여 integer로 변환 후 이를 조건문에서 비교,
확인 절차에서 US센서를 손으로 막았을 때 값이 2000이상으로 나오는 것을 확인, 이를 조건문에서 처리하여
앞을 막았을 경우 Distance is too close를 출력하도록 하였고
거리가 300cm이상인 경우(계속 측정한 결과 1.5m를 넘어가면 오차가 많은 것으로 예상됨) 값이 부정확하다고
판단하여 Distance is too far를 출력하도록 하였다.
10cm보다 짧은 경우는 distance less than 10cm로 출력하게 하였다.
(5주차)
fpga를 사용하면 발생하는 문제는 Ultrasonic Sensor의 interrupt가 정상적으로 작동하지 않는다.
위의 4주차 동작에서 거리를 bluetooth를 통해 휴대폰 terminal에 출력하도록 하였다
bluetooth를 연결했을 때 /dev/rfcomm0에서 통신이 이루어 지는데 cat > /dev/rfcomm0일 때 send,
cat /dev/rfcomm0일 때 receive라는 것을 응용하여 FILE pointer를 사용 /dev/rfcomm0을 read & writable로 fopen,
fputs(char*,file*)함수를 이용하여 거리를 출력하게 하였다. us로 부터 받은 값은 atoi를 거쳐 integer로 변환되는 과정을
거치는데 이를 sprintf를 통해 다시 char *로 바꿔서 출력하였다.