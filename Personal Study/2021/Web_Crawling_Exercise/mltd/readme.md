<h2>아이돌 마스터 밀리언 라이브 시어터 데이즈 카드 정보 crawling 연습</h2>
<hr>

1. 데이터 출처 -> 나무 위키
- 위키 특성상 많은 데이터를 여러 번 호출 시도를 하게 되면 차단 될 수 있으므로
- 연습은 html파일을 복사를 해서 이 파일로 부터 긁어 오는 식으로 연습하였다.
2. main.py 에서는 데이터를 읽어오는 module를 불러와서(ListRead) 출력하는 느낌으로 구현
- 즉, UI만 담당 -> pyqt 같은 것 안 써서 콘솔터미널에서 조작하게 됨...ㅠ

3. listread에서는 데이터 읽기, 데이터 정보 찾기, 마지막 SSR 출시 이후의 날짜 계산을 지원.

4. 그리고 각종 시도는 data_read_test, data_read_test_2.py에 있음. => 최종적으로 data_read_test_2.py를 정리.

cf) 웹 주소로 부터 긁어 오는 연습은 assault_lily 프로젝트에 저장되어 있다.
- https://github.com/NgaAdrain/Adrain_Code_History/blob/master/Personal%20Study/2021/Web_Crawling_Exercise/assault_lily/crawling_exercise.py

