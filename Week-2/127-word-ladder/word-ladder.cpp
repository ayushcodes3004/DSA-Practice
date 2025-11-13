class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>dict(wordList.begin(),wordList.end());
        if(!dict.count(endWord)) return 0;

        queue<pair<string,int>>q;
        q.push({beginWord,1});

        while(!q.empty()){
            auto [word,step] =q.front();
            q.pop();

            if (word == endWord) return step;
            for(int i=0;i<word.size();i++){
                string temp=word;
                for(char c='a';c<='z';c++){
                    temp[i]=c;
                    if(dict.count(temp)){
                        q.push({temp,step+1});
                        dict.erase(temp);
                    }
                }
            }
        }
        return 0;
    }
};