# IOT프로그래밍 5조 프로젝트-4

0607 발표자 추지연

## 네모로직을 구현하기 위해서 필요한 기능들

택트 스위치를 방향키처럼 사용하고 도트 매트릭스 키기

작성한 행렬과 정답 행렬 비교하기

LCD에 행과 열에 대한 힌트 표시하기



## 하나로 합친 코드

파일 여러 개를 사용하다보니 오류가 많이 발생해 코드를 정리해 하나의 파일로 합쳤습니다.

[logicGameVer03.CPP](https://github.com/gururur/IOT5T/blob/gh-pages/logicGame/logicGame.Ver.03/logicGameVer03.CPP)


## 추가한 기능

### 1. 커서와 페이퍼(그림) 표시

예전 코드에서 ok 버튼을 눌러 그림을 그리기 전에 이미 점 하나가 찍혀있는 등 의도치않게 동작하여 커서와 페이퍼 매트릭스를 따로 나눠 해결했습니다.

![1](https://user-images.githubusercontent.com/64446278/172176017-59467240-dabb-41ca-a010-ac6891a96b0f.png)



### 재시작 버튼

택트 스위치 10번을 누르면 그렸던 그림과 점수, 커서 위치가 모두 초기화되고 다음 게임으로 넘어갑니다. 또한 힌트도 다음 게임의 힌트로 넘어갑니다.

![2](https://user-images.githubusercontent.com/64446278/172176161-5482edfa-e514-4f81-bdef-2fe322d2d307.png)



### 힌트 수정

저번에 구현했던 힌트 표시 방법은 lcd 공간이 모자라 힌트가 전부 출력이 안되었습니다.

따라서 이번에는 택트 스위치 1번을 누르면 행 힌트가 출력되고 3번을 누르면 열 힌트가 출력되는 방법으로 수정했습니다.

![3](https://user-images.githubusercontent.com/64446278/172176223-edc4bb36-bee3-4e04-8d2d-26cc7906a7ff.png)


## 구현 영상

[logicGame Test](https://youtube.com/shorts/LqGu0MpaCag?feature=share)
