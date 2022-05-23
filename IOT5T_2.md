# IOT프로그래밍 5조 프로젝트-2

0524 발표자 이재현

## 네모로직을 구현하기 위해서 필요한 기능들

택트 스위치를 방향키처럼 사용하고 도트 매트릭스 키기

작성한 행렬과 정답 행렬 비교하기

LCD에 행과 열에 대한 힌트 표시하기



## 택트 스위치를 방향키처럼 사용하고 도트 매트릭스 키기를 위해 구현한 코드

[Cursor.cpp] (https://github.com/gururur/IOT5T/blob/gh-pages/logicGame/Cursor.cpp)

[DotMatrixPaper.cpp] (https://github.com/gururur/IOT5T/blob/gh-pages/logicGame/DotMatrixPaper.cpp)

[TactSw.cpp] (https://github.com/gururur/IOT5T/blob/gh-pages/logicGame/TactSW.cpp)



## Cursor.cpp

방향키에 따라 이동하는 커서의 위치를 확인하고 테라텀에 표시합니다.

coord 구조체를 사용하여 콘솔 화면 버퍼에서 커서의 위치를 정의 합니다.

![1](https://user-images.githubusercontent.com/64446278/169743335-e2d4c0fe-1148-4017-9b7a-3456ba5f0fce.PNG)

ENUM을 활용해서 0,1,2,3,4 순서로 방향키를 설정합니다. 

![2](https://user-images.githubusercontent.com/64446278/169743437-4236775a-51d5-433a-9a22-f6a4fb7b531a.PNG)

커서의 방향을 이동시킵니다. 

![3](https://user-images.githubusercontent.com/64446278/169743452-797a4ad0-f055-4284-9fae-ddb5df6ada8b.PNG)



## DotMatrixPaper.cpp

장치의 도트 매트릭스에 표시될 도트들을 표시합니다. 

8x8 크기의 matrixPaper 행렬의 모든 값을 0으로 세팅합니다.

![4](https://user-images.githubusercontent.com/64446278/169743484-0a557893-7f24-42f0-8325-5e531c651585.PNG)

모든 매트릭스의 내용을 0으로 초기화 하는 내용과 택트 스위치의 5번 버튼을 눌렀을 때 led를 켜고 끄게 하는 내용입니다. 

![5](https://user-images.githubusercontent.com/64446278/169743519-42f1e835-4877-403c-ba82-e37c5b127374.PNG)

matrixPaper 행렬의 값들을 읽어서 도트 매트릭스에 출력합니다. 

![6](https://user-images.githubusercontent.com/64446278/169743552-e2d1ca85-9ee5-49ad-9775-91ff5eee811a.PNG)

## TactSW.cpp

택트 스위치들의 기능들을 정의 합니다.

cursor.cpp에서 enum을 활용하여 정의한 상하좌우의 값들로 return 값을 정의 합니다.

![7](https://user-images.githubusercontent.com/64446278/169743570-088e67b1-12dc-42f7-a6a2-c369c1229d4b.PNG)

## 참고 :

[뱀 게임]https://github.com/jinwoo1225/SnakeGameWithSmart4412

