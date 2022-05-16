# IOT프로그래밍 5조 프로젝트-1

[프로젝트파일공유용링크](https://github.com/gururur/IOT5T)

[SMART4412TKU 로 가위바위보 베팅](https://syki66.github.io/blog/2020/06/15/H-smart4412TKU.html)

[SMART4412TKU 로 오목](https://github.com/Seungkyu8/Smart4412-IoT-program)

[로직큐브 하는 법](https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=logic_puzzle&logNo=130074665885)

기존에 있던 위 프로젝트들을 활용해 "FPGA Board에 있는 8*8 Dot Matrix에 로직 큐브" 를 구현하는 것을 프로젝트 주제로 정했습니다.

![logicCubeEX](https://user-images.githubusercontent.com/64446278/168637674-e1dbbc83-505f-49af-8bdf-7ff927f7b60d.png)

로직 큐브 게임이란 : 바둑판 모양의 판에 숫자로 표시된 힌트를 따라 칸을 채우면 그림이 나오는 퍼즐 게임.

각 숫자는 그 행/열에서 이어서 채워지는 칸을 의미, 행에 3 이라고 적혀있으면 그 행은 3칸을 이어서 채워야하고 3 3 이면 3칸씩 2번을 채워야 하며 채운 칸이 붙어있으면 안됨.

tact switch로 8*8행렬 내에서 움직일 수 있도록 해주는 상하좌우키와 led를 키고 끄는 스위치, 정답 제출 스위치를 구현.

어느 led를 조작할 것인지 알 수 있도록 해당 위치의 led가 느리게 점멸, 그 위치(좌표)를 lcd에 표시.

태블릿에서 숫자 힌트 출력.

정답 행렬 n개와 과 시험지(?) 행렬를 두어 정답 제출 스위치를 눌러 시험지 행렬과 정답 행렬을 비교.

lcd에서 점수 출력 및 시험지 행렬 초기화, 다른 정답 행렬 불러와 새 게임 시작.

재시작 시 이전 게임에서의 최고 점수 출력.



* 팀 사정에 따라 위 내용은 달라질 수도 있음.


