class Trie {
public:
    struct Node
    {
        Node* arr[26];
        bool isEnd; 
    };
    Node* head;
    Trie() {
         head= new Node();
    }
    
    void insert(string word) {
        Node*curr=head;
        for(char c: word)
        {
            if(!curr->arr[c-'a']) curr->arr[c-'a']= new Node();
            curr=curr->arr[c-'a'];
        }
        curr->isEnd=true;
    }
    
    bool search(string word) {
        Node*curr=head;
        for(char c:word)
        {
            if(!curr->arr[c-'a']) return false;
            curr=curr->arr[c-'a'];
        }
        return curr->isEnd;
    }
    
    bool startsWith(string prefix) {
        Node*curr=head;
        for(char c:prefix)
        {
            if(!curr->arr[c-'a']) return false;
            curr=curr->arr[c-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */