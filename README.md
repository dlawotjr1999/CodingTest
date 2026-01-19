# CodingTest

p.s. boj는 알고리즘 별로 구분했으면서 프로그래머스는 왜 달랑 폴더로 되어있느냐 물어보면 boj는 알고리즘 별 연습, 프로그래머스는 실전처럼 임하기 때문입니다.

## 1. 유형 분류

- 구현
- Greedy Algorithm
- DFS / BFS
- DP
- 정렬
- 분할 정복
- 누적 합
- 이분 탐색
- 그래프
- 최단 경로 알고리즘

## 2. 기초 구현

- Greedy Algorithm
  - “현재 상태에서 최적의 선택”
  - 대부분 정렬을 먼저 수행한 뒤 해결
  - [https://velog.io/@kyunghwan1207/그리디-알고리즘Greedy-Algorithm-탐욕법](https://velog.io/@kyunghwan1207/%EA%B7%B8%EB%A6%AC%EB%94%94-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98Greedy-Algorithm-%ED%83%90%EC%9A%95%EB%B2%95)
- DFS / BFS : [https://velog.io/@jxlhe46/알고리즘-DFSBFS](https://velog.io/@jxlhe46/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-DFSBFS)
- 최단 경로 알고리즘
  - Dijkstra Algorithm
  - Floyd-Warshall Algorithm
  - Bellman-Ford Algorithm

## 3. Tip

### 3.1. General

- 순회를 순방향이 아닌 역방향으로도 생각해보기
- 시간의 흐름과 관련된 문제는 반복문을 거꾸로 돌려보면서 해결

### 3.2. Greedy Algorithm

- 모르겠으면 일단 정렬부터 진행해보기

### 3.3 Dynamic Programming

- DP 배열이 무엇인지 선언하는 방법 - 최댓값 / 최솟값 구하기 - 최소 횟수 / 최소 연산 - 가능 여부 - 방법의 수
  ⇒ **‘부분 문제 상태’가 바로 DP 배열에 들어갈 값**

## 4. 기타

### 4.1. modular 공식

- modular 덧셈 : (a + b) % m = ((a % m) + (b % m)) % m
- modular 뺄셈 : (a - b) % m = ((a % m) - (b % m) + m) % m
- modular 곱셈 : (a _ b) % m = ((a % m) _ (b % m)) % m
- 지수 분해 : a^(x + y) % m = (a^x % m)(a^y % m) % m

### 4.2. 유용한 STL 함수

- lower_bound / upper_bound : x 이상 / x 초과가 되는 iterator 반환
- next_permutation / prev_permutation : 순열 완전 탐색 / 역순 순열 탐색
- substr(pos, len) : 문자열 추출
