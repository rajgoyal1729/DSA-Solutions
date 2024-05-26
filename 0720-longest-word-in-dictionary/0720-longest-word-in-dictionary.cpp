class Solution {
public:
    struct Node{
        Node *arr[26];
        bool isEnd;
    };
    Node*head= new Node();
    void insert(string word)
    {
        Node *curr=head;
        for(char c:word)
        {
            if(!curr->arr[c-'a']) curr->arr[c-'a']= new Node();
            curr=curr->arr[c-'a'];
        }
        curr->isEnd=true;
    }
    string ans;
    void dfs(Node*root, string temp)
    {
        for(int i=0;i<26;i++)
        {
            if(root->arr[i]  && root->arr[i]->isEnd)
            {
                temp+=(i+'a');
                if(temp.size()>ans.size())
                {
                    ans=temp;
                }
                else if(temp.size()==ans.size() && temp<ans) ans=temp;
                dfs(root->arr[i],temp);
                temp.pop_back();
            }
        }
    }
    string longestWord(vector<string>& words) {
        for(auto word:words)
        {
            insert(word);
        }
        dfs(head,"");
        return ans;
    }
};