#include<iostream>
#include<vector>
#include<map>

using namespace std;

long long sumArr(vector<int> arr, vector<int> brr, int t) {
	map<int, int> m;//구할 수 있는 부분합을 map으로 저장해놓기
	long long sum = 0;

	// 1 3 1 2
	// arr : 1 4 5 7
	// map : -6 -4 -3 -3 -2 -1 0 1 1 2 3 3 4 4 5 6 7  //가지 수를 구하려면 중복 수를 저장해야함
	for (int i = 1; i < arr.size(); i++)
		for (int j = 0; j < i; j++)
			m[arr[i] - arr[j]]++;

	for (int i = 1; i < brr.size(); i++)
		for (int j = 0; j < i; j++)
			//t=a[i]-a[j]+b[i]-b[j]->a[i]-a[j]=t-b[i]+b[j]
			sum += m[t - brr[i] + brr[j]];//찾을 수 있는 가지 수

	return sum;
}

int main() {
	int t, n, m, num;//t: a의 부 배열의 합에 b의 부 배열의 합을 더한 수

	cin >> t >> n;
	vector<int> arr(n + 1, 0);
	for (int i = 1; i < n + 1; i++) {//arr 누적합 구하기
		cin >> num;
		arr[i] = arr[i - 1] + num;
	}
	cin >> m;
	vector<int> brr(m + 1, 0);
	for (int i = 1; i < m + 1; i++) {//brr 누적합 구하기
		cin >> num;
		brr[i] = brr[i - 1] + num;
	}

	cout << sumArr(arr, brr, t);

}