#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;
// 1. ColCnt만큼 조합을 구한다. nCr
// 2. 조합의 경우의 수로 또 조합의 경우의 수를 -1 개 만큼 구한다. -> 최소성 검사
// 3. 선택된 조합 ColIdx 으로 
int solution(vector<vector<string>> relation) {
    int RowCnt = relation.size();
    int ColCnt = relation[0].size();
    map<vector<int>, bool> candidate_Keys;

    // 뽑아낼 조합 개수 설정 루프, nCr, n = 4, r = 1, 2, 3, 4 개씩 조합을 구한다.
    for (int cr = 1; cr <= ColCnt; cr++) {
        // 조합을 뽑기위한 임시 버퍼 (ex, ColCnt=4, cr=1 -> (false, false, false, true) / ColCnt=4, cr=2 -> (false, false, true, true))
        vector<bool> choiceCol(ColCnt - cr, false);
        choiceCol.insert(choiceCol.end(), cr, true);
        do {
            // 조합 경우의 수 : (3 2 1 0), (23 13 12 03 02 01), (123 023 013 012, 0123)
            string temp = ""; // log
            vector<int> ColIdx;
            for (int j = 0; j < choiceCol.size(); j++)
                if (choiceCol[j]) {
                    ColIdx.push_back(j);
                    temp.append(to_string(j));
                    //cout << j << " ";
                }
            //cout << endl;
            cout << "ColIdx: " << temp << endl;
            
            /*
            // log
            for (int j = 1; j < ColIdx.size(); j++) {
                vector<bool> v1(ColIdx.size() - j, false); v1.insert(v1.end(), j, true);
                do {
                    string temp2 = ""; vector<int> column_key1;
                    for (int k = 0; k < ColIdx.size(); k++)
                        if (v1[k]) temp2.append(to_string(ColIdx[k]));
                    cout << "temp2: " << temp2 << endl;

                } while(next_permutation(v1.begin(), v1.end()));
                cout << "j : " << j << "개 일때!" << endl;
            }
            */
            
            
            //--- 최소성
            bool isMinimal = true;
            // ColIdx 중에서 최소성을 만족하는 key의 조합이 있는가를 찾는것.
            // nCr, r = 1 ~ (ColIdx - 1) 만큼 조합을 돌린다.
            for (int j = 1; j < ColIdx.size(); j++) {
                vector<bool> v1(ColIdx.size() - j, false);
                v1.insert(v1.end(), j, true);
                do {
                    // column_key1에 1~(ColIdx-1) 만큼의 경우의 수를 넣는다.
                    vector<int> column_key1;
                    for (int k = 0; k < ColIdx.size(); k++)
                        if (v1[k]) column_key1.push_back(ColIdx[k]);
                    // column_key1에 후보키를 만들기위한 컬럼들이 들어가 있고, 그것을 후보키에서 찾아봐서 없으면 최소성 불만족이므로 루프 중단.
                    if (!candidate_Keys.empty() && candidate_Keys.find(column_key1) != candidate_Keys.end()) {
                        isMinimal = false;
                        break;
                    }
                } while(next_permutation(v1.begin(), v1.end()));
                if (!isMinimal) break;
            }

            if (!isMinimal) continue;
            //--- 최소성

            //--- 유일성
            // 전체 : relation의 모든 행을 돌면서, 선택된 컬럼을 vector<string>에 넣고, reslut개수가 RowCnt와 같으면 유일성이 확보되므로 후보키에 넣는다.
            map<vector<string>, int> result;
            for (int j = 0; j < relation.size(); j++) {
                //relations의 j번째행, 선택된 ColIdx 인덱스들의 값을 temp에 넣는다.(선택된 컬럼을 합치는거와 같은 맹락)
                vector<string> temp;
                for (int k = 0; k < ColIdx.size(); k++)
                    temp.push_back(relation[j][ColIdx[k]]);

                // result가 있으면, result에서 temp가 없으면 넣는다. 중복된게 있으면 안들어가진다.
                if (result.empty() || result.find(temp) == result.end())
                    result.insert(make_pair(temp, 1));
            }
            
            // 개수가 같으면 유니크한 값이므로 후보키로 사용가능하다.
            if (result.size() == RowCnt)
                candidate_Keys.insert(make_pair(ColIdx, true));
            //--- 유일성
            
        } while(next_permutation(choiceCol.begin(), choiceCol.end()));
        cout << "cr : " << cr << "개 일때! <<<<<<<<<<<<<<<" << endl;
    }
    
    return candidate_Keys.size();
}
