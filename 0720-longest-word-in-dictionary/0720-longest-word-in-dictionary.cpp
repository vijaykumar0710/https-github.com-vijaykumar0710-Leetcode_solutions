class Solution {
public:
struct trieNode{
  trieNode *children[26];
};
trieNode *get_node(){
    trieNode* new_node=new trieNode();
    for(int i=0;i<26;i++){
        new_node->children[i]=NULL;
    }
    return new_node;
}
void formed(string &word,trieNode *root){
int n=word.size();
trieNode* crawler=root;
for(int i=0;i<n;i++){
    int idx=word[i]-'a';
    if(!crawler->children[idx]){
       crawler->children[idx]=get_node();
    }
     crawler=crawler->children[idx];
  }
}

bool prefix(string &word,trieNode *root){
  int n=word.size();
trieNode* crawler=root;
int i=0;
for(;i<n;i++){
    int idx=word[i]-'a';
    if(!crawler->children[idx]){
       return false;
    }
     crawler=crawler->children[idx];
  }
  if(i==n) return true;
  return false;
}

    string longestWord(vector<string>& words) {
        sort(words.begin(),words.end());
        int n=words.size();
        string res="";
        trieNode *root=get_node();
        for(auto &word:words){
             string temp=word.substr(0,word.size()-1);
            if(word.size()==1 || prefix(temp,root)){ 
            formed(word,root);
                 if(res.size()<word.size())
                  res=word;
                   else if(res.size()==word.size())
                    res=min(res,word);
          }
       }
       return res;
    }
};