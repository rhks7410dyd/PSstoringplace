# PSstoringplace
깃허브 사용 단계

- 푸쉬 과정
git add . -> git commit -> git push

To do
git add가 아닌 git add .을 사용해야 하는 이유 알아보기.

+ 깃 허브 자체에서 무엇인가 수정한 경우 git pull을 우선적으로 진행해 줘야됨.

git add Math/boj2407.cpp 와 같이 쓰면 이 파일만 add됨

- 터미널에서 특정 파일을 실행시킬 때, g++ boj11779.cpp -o test && ./test 이런 식으로 작성하면 터미널에서 파일을 실행시킬 수 있다.

# Tip3
1. C++의 벡터,스트링은 push_back, pop_back이 있어서 중간 노드를 확인할 수 있는 스택으로서 사용할 수 있다.
2. 언제나 코드를 짤 때는 수정이나 스캐폴딩 등을 위해 여러 함수로 나누어서 전역 변수를 이용하여 만드는 것이 좋다.
3. C++에서 algorithm 헤더의 next_permutation() 함수는 모든 순열을 순서대로 생성하는 작업을 해줌 (https://twpower.github.io/82-next_permutation-and-prev_permutation)
4. char의 범위는 -128 ~ 127 이므로 -1,0,1 세 가지 값으로 상태를 표현할 때는 char을 사용하면 메모리 소비를 줄일 수 있다(int의 1/4배니까 의미가 큼)
5. CCW 알고리즘 https://snowfleur.tistory.com/98
6. algorithm 헤더 upper_bound && lower_bound 함수 (https://chanhuiseok.github.io/posts/algo-55/)

# 풀다가 못푼 문제

## 백준
Backtracking - boj9202 <- now
Dynamic_Programming - boj4781
Dynamic_Programming - boj2629
Devide_and_Conquer - boj15824
Devide_and_Conquer - boj12850
Floyd_warshall - boj20056 
Implementation - boj2836
Implementation - boj17779
Implementation - boj19236
Geometry - boj16937

## 알고스팟
### DP
##### algospot_OCR <- 얘는 진짜 뭐하자는 건지 모르겠어서 나중에 풀기
##### algospot_GENIUS

### GREEDY
##### Greedy algospot_MINASTIRITH

### Combinational Search
##### Combinational_Search algospot_KAKURO2


# Memo
1. 토익 실전모의고사 문제집
2. 한 권으로 끝내는 네트워크 기초
3. 팀 개발을 위한 Git, GitHub 시작하기
4. https://play2048.co/ 2048 html 게임 사이트

# 코딩 관련 글 or 사이트
웹프로그래밍 분야에서 배워야 할 개발 언어에 대해 이야기하겠습니다.

웹프로그밍은 보통 두가지 분야로 갈립니다.

Windows 서버와 Linux 서버입니다.

어떤 O/S 플랫폼을 주로 잡느냐에 따라 배우셔야할 내용은 어느 정도 갈립니다.

다음과 같이 정리하겠습니다.

공통
-----

필수 - HTML의 모든 것(HTML5 포함), CSS, Javascript

선택 - Javascript Framework Open Sources(보통 jQuery 등을 이야기), ActionScript(플래시 분야), Adobe Air

# 학자금 대출
1월에 휴가 나가서 신청 기간 시작되면 소득 분위 확인 이후 신청 가능하면 신청하기

O/S별

------

※ Linux(리눅스) 서버

필수 - PHP, MySQL

선택적 필수 - JSP, JAVA 기초(이것을 원하는 클라이언트도 있으므로)

소양적 필수 - Linux 서버의 기본적 작동에 필요한 지식, 보안

 

※ Windows 서버

필수 - ASP.net(C# 또는 Visual Basic), ASP.net​은 언어가 아니라 기술을 칭하는 용어입니다. 그 기술에 사용하는 언어가 C# 등이 되겠습니다.

선택적 필수 - ASP(ASP.net이 나오기전에 주로 사용하던 언어입니다. 이것을 원하는 클라이언트도 있겠죠?)

소양적 필수 - Windows 서버의 기본적 작동에 필요한 지식, 보안

#codeing_test_link
1. 2022 카카오 신입 공채 1차 온라인 코딩테스트 - https://tech.kakao.com/2022/01/14/2022-kakao-recruitment-round-1/

# 컴퓨터 견적
본체 : 140 ~ 150
모니터 : 20 (27인치 144~165fps)
듀얼 모니터 암 : 10 (슬림형)
의자 : 20 (매쉬 or 패브릭 소재)
190 ~ 200

# 프로젝트 주제
1. 스프링 쇼핑몰 프로젝트
장점 : 겉핥기식으로 하기 좋음. 스프링을 경험해 보며 웹프로그래밍 찍먹이 가능함.
단점 : 너무 방대한 부분을 다뤄야되서 현실성이 없을 거 같음. 둘이서 하기엔 분량이 너무 많아서 선우가 부담스러워 할 것 같음.

2. js 게임 만들기(테트리스,2048,지뢰찾기)
장점 : 비교적 수준에 맞는 첫 프로젝트라고 느껴짐
단점 : 너무 단순함, 말그대로 웹 프로젝트만 하는 느낌이라 뭔가 잘 이뤄지지는 않을듯?


## code server를 이용한 스프링 부트 공부 계획
1. 리눅스 서버 구축
2. code server를 그 서버에 설치
3. 공부

-----

## 서버 구축 방안
- aws
- 구글클라우드 플랫폼(무료를 이미 써버린듯)
- 네이버 클라우드
- 가비아 클라우드(정액제 있음)

<br>

## 이어폰
23년 일본 vgp? 추천이어폰
https://ooolabs.tistory.com/211

iFi Audio UNO USB DAC 헤드폰 앰프 (DSD MQA PCM 지원)

Simgot DEW0 고음질 휴대용 꼬다리 DAC & 앰프

꼬다리 dac는 다른 이어폰 구매를 고려할 때 사면 될듯.
퀸텟은 저항이 높지 않아서 사실 큰 의미가 없기도 하고, 집에서 사용할 dac정도만 생각하기 or 허브 + 꼬다리 dac로 사용하는 것도 낫배드

AceOrpheus
스타드림 4.4
힙덱 2
모조2
h5

Sonata BHD Pro
FiiO-JadeAudio Q11
DH80s - c to 8pin 필요
SHANLING UA3 - c to 8pin 필요
