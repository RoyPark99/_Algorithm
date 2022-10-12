#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool visit[20];
string item, tmp;
map<string,int> ans;

void dfs(int index, int count, string& order){
    if(2<=count&&count<=10){
        tmp=item;
        sort(tmp.begin(), tmp.end());     // 알파벳 순으로 정렬
        ++ans[tmp];
    }
    
    else if(count>10)       // 10개까지만 보관
        return;
    
    for(int i=index;i<order.size();++i){
        if(!visit[i]){
            visit[i]=true;
            item.push_back(order[i]);
            dfs(i+1,count+1,order);
            visit[i]=false;
            item.pop_back();
       }
    }
}
vector<string> solution(vector<string> orders, vector<int> course) {
    fill(visit, visit+20, false);
    vector<string> answer;
    for(auto& order : orders)
        dfs(0,0,order);
    
    for(const auto& c : course){
        int max_count = 0;
        for(auto iter=ans.begin(); iter!=ans.end(); ++iter){
            if(iter->first.size() == c)
                max_count=max(max_count, iter->second);   // course별 최대 문자열 찾기
        }
        if(max_count == 1)
            continue;
        for(auto iter=ans.begin(); iter!=ans.end(); ++iter)
            if(iter->first.size() == c && iter->second == max_count)
                answer.push_back(iter->first);
    }
    sort(answer.begin(), answer.end());
    return answer;
}