스크린 캡쳐 사용법
1. 실행 후 콘솔창에 Left Upper 클릭하라고 하면 
<원하는 화면 좌측 상단 좌클릭>
2. 콘솔창에 Right Lower 클릭하라고 하면 
<원하는 화면 우측 하단 우클릭>
3. 캡쳐하고 싶은 화면에서 ctrl+alt를 눌러주면 캡쳐 완료
4. 종료하고 싶으면 ctrl+q를 누르면 종료

주의! screenshot 폴더가 없으면 에러가 남. 압축파일에 포함시켜놓겠지만 삭제X
그리고 사진은 github 커밋할 때 파일 없으면 인식 못하기 때문에 넣어놓음.
Created by Adrain
2021-03-11 Version 0.01
===================================================
1. configure 파일 확인해서 없으면 만들고 있으면 설정 건너뜀
2. 동작 안내 가독성 높임
3. 캡쳐 위치 설정 버그 수정=> (region = 좌측 x, y 좌표, 너비, 높이)
4. 설정 값 있으면 재실행 이후 설정 과정 건너뜀
5. 설정 값 변경 기능 추가. (ctrl+shift)
2021-03-11 Version 0.02
===================================================
Bug Report
-> 다중 디스플레이 환경에서 주모니터 이외에는 정상적으로 캡쳐 불가
(reported by HTYKKR)
EU : 사용하는 모듈(pyautogui)의 screenshot이 multiple monitor를 지원하지 않음!
이 부분은 다른 모듈로 교체하는 것으로 해결해야 한다!
