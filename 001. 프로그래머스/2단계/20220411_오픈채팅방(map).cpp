#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <unordered_map>

using namespace std;

vector<string> split(string str, char Delimiter) {
    istringstream iss(str);
    string buffer;
    vector<string> result;
    while (getline(iss, buffer, Delimiter)) 
        result.push_back(buffer);
 
    return result;
}

vector<string> solution(vector<string> record) {
	vector<string> answer;

    // (ID, nickname) 아이디별 닉네임 저장
	unordered_map<string, string> info;
    // (ID, command) enter, leave 모든 기록 저장
	vector<pair<string, string>> command_vec;

	// {"Enter uid1234 Muzi", "Enter uid4567 Prodo", "Leave uid1234", "Enter uid1234 Prodo", "Change uid4567 Ryan"}
	for (int i = 0; i < record.size(); i++) 
	{
		// Enter uid1234 Muzi, Leave uid1234
		vector<string> result = split(record[i], ' ');
		if (result[0] != "Change")
		{
			// 엔터나 리브 벡터에 id, cmd 로 추가
			command_vec.push_back(make_pair(result[1], result[0]));
		}

		if (result[0] != "Leave")
		{
			//  Leave가 아니면 map에 (id, 닉네임)
			info[result[1]] = result[2];
		}
	}
/*
	for (auto vec : command_vec)
		cout << vec.first << " " << vec.second << endl;
	cout << endl;
	for (auto map : info)
		cout << map.first << " " << map.second << endl;
*/
	for (int i = 0; i < command_vec.size(); i++)
	{
		string nickName = info[command_vec[i].first];
		//cout << "nickName : " << nickName << endl;

		if (command_vec[i].second == "Enter")
			answer.push_back(nickName + "님이 들어왔습니다.");

		else if (command_vec[i].second == "Leave")
			answer.push_back(nickName + "님이 나갔습니다.");
	}

	return answer;
}

