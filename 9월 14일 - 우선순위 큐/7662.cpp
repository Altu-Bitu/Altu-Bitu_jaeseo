#include<iostream>
#include<set>
using namespace std;
int main() {
	int t, k, n;
	char c;

	cin >> t;
	while (t--)
	{
		multiset<int> s;//key 값 중복 set

		cin >> k;
		while (k--)
		{
			cin >> c >> n;

			if (c == 'I')
				s.insert(n);
			else if (!s.empty()) { //c=='D'
					if (n == 1)//최댓값 삭제
						s.erase(--s.end());
					else //최솟값 삭제
						s.erase(s.begin());
			}
		}
		if (s.empty())
			cout << "EMPTY" << '\n';
		else
			cout << *(--s.end()) << ' ' << *s.begin() << '\n';
	}
}