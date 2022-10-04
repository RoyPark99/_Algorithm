#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s) {
	vector<int> length(s.length() + 1);

	// abcabcdede
	// 1,2, 3 단위로 글자수 결정...
	for (int i = 1; i <= s.length(); i++)
	{
		// next > 문자열을 현재 i개 단위로 잘랐을 때의 현재 자른 문자열의 위치!
		int next = 0;
		while (next < s.length())
		{
			// next ~ i 범위의 토큰을 가져온다.
			//1 substr(0, 3)...str = [abc]
			//1 substr(6, 3)...str = [ded]
			//1 substr(9, 3)...str = [e]
			string sub = s.substr(next, i);
			//printf("1 substr(next%d, i%d)...str=[%s]\n", next, i, sub.c_str());

			// next + i = k, k에서 i만큼과 sub랑 같으면 count올리고 i만큼 카운트 올린다.
			int count = 1;
			for (int k = next + i; k < s.length(); k += i)
			{
				//printf("2 substr(k%d, i%d)=[%s]\n", k, i, s.substr(k, i).c_str());
				if (sub == s.substr(k, i))
				{
					next += i;
					count++;
					//printf("3 next=[%d], count=[%d], substr(k%d, i%d)=[%s]\n", next, count, k, i, s.substr(k, i).c_str());
				}
				else
				{
					//cout << "break;" << endl;
					break;
				}
			}
			
			// i단위로 압축했을때... 압축 불가 (해당 문자열의 길이만 더함)
			if (count == 1)
				length[i] += sub.length();

			// i단위로 압축했을때... 압축 가능 (해당 문자열의 길이 + 반복 숫자의 문자열 길이 버전)
			if (count > 1) 
				length[i] += sub.length() + to_string(count).length();

			next += i;
		}
	}

	// 글자수 단위로 압축했을때 글자수 중에서 최소값 찾기...
	//for (auto vec : length)
	//	cout << "vec : " << vec << endl;

	return *min_element(length.begin() + 1, length.end());
}