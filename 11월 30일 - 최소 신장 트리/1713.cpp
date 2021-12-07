#include <iostream>
#include <vector>
#include <map>

using namespace std;
typedef pair<int, int> ci;

map<int, ci>::iterator delCandidate(map<int, ci>& candidate) {
    auto del = candidate.begin(); //처음 후보를 삭제한다 가정
    int cnt = candidate.begin()->second.first; //처음 후보의 추천 횟수
    int t = candidate.begin()->second.second; //처음 후보의 게시 시간
    for (auto iter = ++candidate.begin(); iter != candidate.end(); iter++) {// 남은 후보들 중에서
        int cur_cnt = iter->second.first;// 현재 후보의 추천 횟수
        int cur_t = iter->second.second;//현재 후보의 게시 시간
        if (cur_cnt < cnt) { //추천 횟수가 가장 작은 후보 찾기
            cnt = cur_cnt; // 추천 횟수 가장 작은 후보의 추천 횟수로 갱신
            t = cur_t; // 추천 횟수 가장 작은 후보의 게시 시간으로 갱신
            del = iter; // 추천 횟수 가장 작은 후보로 갱신 
        }
        else if (cur_cnt == cnt && cur_t < t) { //추천 횟수가 가장 작은 후보가 여러명이라면, 게시 시간이 오래된 후보 찾기
            t = cur_t; //위 조건에 맞는 후보의 게시 시간으로 갱신
            del = iter;//위 조건에 맞는 후보로 갱신
        }
    }
    return del;//가장 추천수가 작은 학생 중 게시 시간이 오래된 학생 리턴
}

/**
 * 1. 비어있는 사진틀이 없는 경우, 가장 추천수가 작은 학생 중 게시 시간이 오래된 학생을 삭제
 * 2. 후보 학생을 바로 찾기 위해 본 풀이는 map 컨테이너를 사용해 구현
 *
 * !주의! 게시 시간 정보 저장 시, 후보로 올라간 가장 첫 시간을 저장. 이미 후보에 있는데 게시 시간이 갱신되지 않도록 주의.
 */

int main() {
    int n, m, input;//n: 사진틀의 개수, m: 전체 학생의 총 추천 횟수

    //입력 & 연산
    cin >> n >> m;
    map<int, ci> candidate; //first: 후보 학생, second: {추천 횟수, 게시 시간}
    for (int i = 0; i < m; i++) {
        cin >> input;
        if (candidate.size() == n && candidate.find(input) == candidate.end()) //비어있는 사진틀이 없는 경우
            candidate.erase(delCandidate(candidate)); // 가장 추천수가 작은 학생 중 게시 시간이 오래된 학생

        if (candidate.find(input) == candidate.end()) //첫 게시라면(비어있는 사진틀이 있는 경우)
            candidate[input].second = i;// 그 사진틀에 후보 사진 게시
        candidate[input].first++; //추천 횟수 증가
    }

    //출력
    for (auto iter = candidate.begin(); iter != candidate.end(); iter++)
        cout << iter->first << ' ';// 최종 후보의 학생 번호
}