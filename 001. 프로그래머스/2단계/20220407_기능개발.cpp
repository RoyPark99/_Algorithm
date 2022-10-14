#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> p, vector<int> s) {
    vector<int> answer;
    vector<int> temp;
    
    // 프로그래스별 남은 날짜 계산하여 temp에 넣는다.
    for (int i = 0; i < p.size(); i++)
    {
        // 남은 프로그래스 %
        int remain_progress = 100 - p[i];
        int need_day = remain_progress / s[i];
        
        if (!remain_progress)
        {
            temp.push_back(0);
        }
        else
        {
            // 스피드로 나눴을때 0이면 날짜
            if (remain_progress % s[i] == 0)
            {
                temp.push_back(need_day);
            }
            else
            {
                // 아니면 + 1일
                temp.push_back(need_day + 1);
            }
        }
    }

    // tmep에서 빼내면서 answer에 push하거나 ++한다.
    int val = 0;
    int idx = 0;
    while (!temp.empty())
    {
        if (answer.empty())
        {
            val = temp.front();
            answer.push_back(1);
            temp.erase(temp.begin());
        }
        else
        {
            if (val >= temp.front())
            {
                answer[idx]++;
                temp.erase(temp.begin());
            }
            else
            {
                idx++;
                val = temp.front();
                answer.push_back(1);
                temp.erase(temp.begin());
            }
        }
    }
    
    return answer;
}


/* 좋아보이는 코드 첨부
#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int count = 0;
    queue<int> q;

    while (!progresses.empty())
    {
        for (int i = 0; i < progresses.size(); i++)
        {
            progresses[i] += speeds[i];
        }

        if (progresses.front() >= 100)
        {
            for (int i = 0; i < progresses.size(); i++)
            {
                if (progresses[i] >= 100)
                {
                    count++;
                }
                else
                {
                    break;
                }
            }
            answer.push_back(count);
            progresses.erase(progresses.begin(), progresses.begin() + count);
            speeds.erase(speeds.begin(), speeds.begin() + count);
            count = 0;
        }

    }
    return answer;
}
*/