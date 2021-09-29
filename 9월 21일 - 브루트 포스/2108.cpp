#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int count(int *n,int max) {
	int cnt=0,result=0;
	for (int i = 0; i <8001; i++) {
		if (cnt == 2) break; //2번째 작은 값
		if (n[i]==max) {
			result = i-4000;
			cnt++;
		}
	}
	return result;
}
int main() {
	int n, max=0;
	double sum=0;
	int cnt[8001] = {0}; //-4000~+4000

	cin >> n;
	vector<int> num(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> num[i];
		sum += num[i];

		int tmp = num[i] + 4000; //음수 인덱스 방지
		cnt[tmp]++;
		if (cnt[tmp] > max) //최대갯수 구하기
			max = cnt[tmp];
	}
	sort(num.begin(),num.end());

	cout << round(sum / n)<<'\n'; //round로 반올림
	cout << num[n / 2] << '\n'; //중앙값
	cout<< count(cnt,max)<<'\n'; //최빈값
	cout << abs(num[n-1]-num[0]); //범위
}