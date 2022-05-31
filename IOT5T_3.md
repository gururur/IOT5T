# IOT프로그래밍 5조 프로젝트-3

0531 발표자 방경민

## 네모로직을 구현하기 위해서 필요한 기능들

택트 스위치를 방향키처럼 사용하고 도트 매트릭스 키기

작성한 행렬과 정답 행렬 비교하기

LCD에 행과 열에 대한 힌트 표시하기



## 작성 행렬과 정답 행렬을 비교하고, LCD에 행과 열에 대한 힌트를 표시하기 위한 코드

[Cursor.cpp](https://github.com/gururur/IOT5T/blob/gh-pages/logicGame/logicGame.Ver.02/Cursor.cpp)

[DotMatrixPaper.cpp](https://github.com/gururur/IOT5T/blob/gh-pages/logicGame/logicGame.Ver.02/DotMatrixPaper.cpp)

[TactSw.cpp](https://github.com/gururur/IOT5T/blob/gh-pages/logicGame/logicGame.Ver.02/TactSW.cpp)

[CharacterLCD.cpp](https://github.com/gururur/IOT5T/blob/gh-pages/logicGame/logicGame.Ver.02/CharacterLCD.cpp)



## Cursor.cpp

ENUM 부분에서 시작과 정답 제출키를 설정합니다. 

![1](https://user-images.githubusercontent.com/64446278/170932300-be823be2-419d-4b9e-87fb-b5f7d61bb5e5.png)



## TactSW.cpp

택트 스위치의 기능을 추가 정의합니다.

![2](https://user-images.githubusercontent.com/64446278/170934358-53814e00-09d0-4413-8655-39a008afbff4.png)



## DotMatrixPaper.cpp

정답 행렬을 만듭니다. 

![3](https://user-images.githubusercontent.com/64446278/170933128-57aa9c24-b2fc-4429-b99d-fefe6c62e194.png)

이후 사용자가 로직게임을 통해 만들고 제출한 matrixPaper 행렬과 비교해 점수를 산출합니다.

원소별로 비교하여 만점 64점입니다.

![4](https://user-images.githubusercontent.com/64446278/170933706-34befcc9-fdfe-4b8b-95fb-b156a41057fe.png)



## CharacterLCD.cpp

로직게임에 힌트를 표시할 문자열 행렬입니다.

![5](https://user-images.githubusercontent.com/64446278/170934957-406cd353-24c9-481f-9484-e5bbd17ccc56.png)

함수 안에 들어갈 rnd 변수값에 따라 나오는 힌트가 바뀝니다.

![6](https://user-images.githubusercontent.com/64446278/170935341-411ecaf5-9dd0-4f05-8461-652511efe5c1.png)
