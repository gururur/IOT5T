# IoT 프로그래밍 5조 프로젝트 Final

주석 이상의 자세한 설명 필요

찬스 코드는 일정 부분 의도대로 되지 않아 추후 완성되면 추가함

사진 변경 및 추가 필요한거 요청

참고 프로젝트 등 참고한거 있으면 링크 달고 여기서 어느어느 부분을 참고했다 식의 설명 추가 필요



## 사용 장치

![스크린샷(1244)](https://user-images.githubusercontent.com/64446278/172448194-0cf159f3-f887-4837-ba34-76cc350c047b.png)

logicGame을 구현하는데 있어 택트 스위치, CLCD, LED, 8x8 Dot Matrix를 사용했습니다.



## 행 힌트와 열 힌트

![스크린샷(1245)](https://user-images.githubusercontent.com/64446278/172448423-f1b27172-9e5b-4440-9a6e-a5f7f569f96e.png)

행 힌트와 열 힌트입니다. 이후 CLCD에 표시됩니다.



## 페이퍼, 커서, 정답 매트릭스

![스크린샷(1246)](https://user-images.githubusercontent.com/64446278/172448681-5e302e18-f8d4-47eb-b015-662eeb1f8e1c.png)

그린 그림 값을 저장하는 페이퍼 매트릭스, 커서의 위치를 저장하는 커서 매트릭스, 문제의 정답값을 가진 정답 매트릭스입니다.



## coord 구조체

![스크린샷(1247)](https://user-images.githubusercontent.com/64446278/172448986-dff19691-6df2-4402-98f1-799700cfa763.png)

x,y 매개변수값을 지니는 coord 구조체를 사용합니다. 커서의 위치 등에 사용됩니다. y값에 +가 되면 좌표 위치가 아래로 내려가고 x값에 +가 되면 좌표 위치가 왼쪽으로 이동합니다.



## 닷 매트릭스 함수

![스크린샷(1249)](https://user-images.githubusercontent.com/64446278/172450189-f60365a8-7c65-470c-8950-9f85d567de88.png)

8x8 매트릭스 상의 led를 조작합니다.



## 닷 매트릭스 상 보이는 매트릭스

![스크린샷(1248)](https://user-images.githubusercontent.com/64446278/172450461-6d50a62b-00d7-4082-89f1-0c3c777c85b2.png)

기본적으로 페이퍼 매트릭스와 커서 매트릭스를 출력합니다.



## 초기화, 그리기, 지우기, 커서 위치

![스크린샷(1250)](https://user-images.githubusercontent.com/64446278/172450752-5b5e13aa-af39-42d5-a2b8-43db4929d17a.png)

페이퍼 매트릭스와 커서 매트릭스를 초기화하고, 페이퍼 매트릭스의 좌표값을 조작하고, 커서의 위치를 출력하는데 사용합니다.



## 각 매트릭스의 값 출력

![스크린샷(1252)](https://user-images.githubusercontent.com/64446278/172451227-33f30d17-0b70-4367-8c2b-8239afd24118.png)

각 매트릭스의 좌표값들을 읽어 닷 매트릭스 상에서 출력하는데 사용합니다.



## CLCD 함수

![스크린샷(1254)](https://user-images.githubusercontent.com/64446278/172451747-94b0bc06-c928-4c65-939f-4c6859405447.png)

CLCD를 사용하기 위한 코드입니다. CLCD는 한 줄당 16자로 한번에 총 32자를 출력할 수 있습니다. 

beforGame()은 게임을 시작하기전에 출력합니다.

rHint()와 cHint()는 문제를 정하는 rnd값에 따라 힌트를 출력합니다.

endGame()은 이후 계산된 점수를 CLCD상에 출력합니다.
coord 구조체 변수 ret의 좌표를 0,0으로 잡아주고 rnd의 값을 랜덤으로 돌려 문제를 무작위로 정합니다.

택트 스위치를 사용하고 CLCD에 beforeGame()의 내용을 출력한 뒤 5초 뒤 게임을 시작함과 동시에 기본적으로 행 힌트를 출력합니다.




## LED 사용 

![스크린샷(1260)](https://user-images.githubusercontent.com/64446278/172526719-26991870-100d-478f-aea4-7201019dafa1.png)

led를 사용합니다. 문제를 푸는데 있어 정답을 하나 알려주는 힌트 3개가 주어집니다. 힌트 갯수만큼 오른쪽부터 led가 켜지며 힌트를 쓸수록 켜진 led가 줄어듭니다.



## main_01

![스크린샷(1261)](https://user-images.githubusercontent.com/64446278/172527075-881fb26c-67d5-429f-800e-b9232aa0bb14.png)

LED와 택트 스위치를 사용하고 CLCD에 beforeGame()의 내용을 출력한 뒤 5초 뒤 게임을 시작함과 동시에 기본적으로 행 힌트를 출력합니다.



## main_02 tact switch 조작

![스크린샷(1262)](https://user-images.githubusercontent.com/64446278/172527257-d44bc907-8c81-4dae-85f2-b683d1a075e2.png)

택트 스위치는 좌상단에서 우하단으로 1~12의 값을 가집니다. 

이후 각 버튼의 역할 설명

1, 3번 버튼은 각각 행 힌트와 열 힌트를 CLCD에 출력합니다.

2, 4, 6, 8번 버튼은 ret의 좌표값을 증감함으로써 커서를 상하좌우로 움직이는 버튼입니다. 닷 매트릭스를 벗어난 좌표값을 가져 오류가 일어나는 것을 방지하기 위해 if문을 통해 그 범위를 제한합니다.

5번 버튼은 ret 좌표값과 같은 페이퍼 매트릭스의 좌표값을 true로 변경합니다. 즉 그림을 그리는 역할입니다.

9번 버튼은 사용자가 조작한 paper 매트릭스의 좌표값들과 정답 매트릭스의 좌표값들을 비교해서 좌표값이 같을수록 점수를 올려줍니다. 8x8 닷 매트릭스이므로 64점 만점입니다.

이후 CLCD에 점수를 표시하고, 페이퍼 매트릭스를 초기화한 뒤 해당 문제의 정답 매트릭스를 5초간 출력합니다.(5초 출력은 drawToAns()에 있다. clearPaper()는 하나만 있어도 될 듯?)

5초 출력 뒤에 점수와 ret 좌표값을 초기화하고 rnd의 값을 랜덤으로 정해 다음 문제를 출력함과 동시에 행 힌트를 출력합니다.

11번 버튼은 힌트를 주는 역할로 정답 매트릭스에서 1인 좌표와 페이퍼 매트릭스에서 0인 좌표를 찾아서 페이퍼 매트릭스에 1을 채웁니다. 그리고나서 힌트 횟수를 하나 줄여줍니다. 

10번 버튼은 페이퍼 매트릭스, 점수와 ret 좌표값을 초기화하고 rnd의 값을 랜덤으로 정해 다음 문제를 출력함과 동시에 행 힌트를 출력합니다.

12번 버튼은 ret 좌표값과 같은 페이퍼 매트릭스의 좌표값을 false로 변경합니다. 즉 그림을 지우는 역할입니다.



## 실제 닷 매트릭스상 출력

![스크린샷(1263)](https://user-images.githubusercontent.com/64446278/172527487-8b13447e-6b09-46d3-8990-055c814c03eb.png)

hintl()을 통해서 힌트 갯수에 따라 LED를 어떻게 킬 것인지 결정합니다.

clearCusor(), cursor()를 반복하여 커서가 지나간 자리는 초기화하고 커서가 위치한 좌표만 true값을 지닙니다.

drawToPaper()와 drawToCursor()를 통해 조작된 paper 매트릭스값과 커서 위치가 표시된 커서 매트릭스 읽어 8x8 닷 매트릭스 상에 출력합니다.



## 실행영상

[시작](https://youtu.be/n8fuc5eg26Y)

[그리기](https://youtu.be/MybUXdb1VBk)

[지우기](https://youtu.be/e2sFiR8XnzU)

[행 힌트와 열 힌트](https://youtu.be/IYqChWMoMWw)

[힌트](https://youtu.be/uoIqrBEmG-c)

[재시작](https://youtu.be/5xz7jcQEqQo)

[점수와 정답](https://youtu.be/uwiTKYtVb0I)



### 참고


[SMART4412TKU LED 점멸하기](https://comonyo.tistory.com/6)
  
  led 점별 방법을 참고했습니다.
  
[뱀 게임](https://github.com/jinwoo1225/SnakeGameWithSmart4412)

  전반적인 기기 동작 코드와 coord 구조체 함수를 참고했습니다.

[로직큐브 하는 법](https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=logic_puzzle&logNo=130074665885)


