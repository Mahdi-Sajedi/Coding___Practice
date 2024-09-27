Here are progression of codes from Trie to bottom up dp:
```python
class TrieNode:
    def __init__(self):
        self.child = [None] * 26
        self.wordEnd = False

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        def insert_key(root, key):
            curr = root
            for c in key:
                idx = ord(c) - ord('a')
                if curr.child[idx] == None:
                    curr.child[idx] = TrieNode()
                curr = curr.child[idx]
            curr.wordEnd = True
            
        def search(root, key, start, dp):
            if start == len(key):
                return True
            if dp[start] != -1:
                return False
            curr = root
            for i in range(start, len(key)):
                idx = ord(key[i]) - ord('a')
                if curr.child[idx] is None:
                    dp[start] = 0
                    return False
                curr = curr.child[idx]
                if curr.wordEnd:
                    if search(root, key, i+1, dp):
                        return True
                    
            return False 
        
        root = TrieNode()
        dp = [-1] * len(s)
        dictchars = set()
        for w in wordDict:
            insert_key(root, w)
            dictchars.update(w)
        if not (set(s) <= dictchars):
            return False
        return search(root, s, 0, dp)
```

Using startswith and checking for all words in wordDict can be improved (later to bottom up approach):

```python
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        def solver(start, s, dp):
            if start == len(s):
                return True
            if dp[start] == 0:
                return False
            rest = s[start:]
            for w in wordDict:
                if rest.startswith(w):
                    if solver(start + len(w), s, dp):
                        return True
            
            dp[start] = 0
            return False
        
        dp = [-1] * len(s)
        return solver(0, s, dp)
```

Top-down dp:
```python
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        def solver(start, s, dp):
            if start == len(s):
                return True
            if dp[start] == 0:
                return False
            for i in range(start, len(s)):
                if (s[start: i+1] in wordSet) and solver(i+1, s, dp):
                    return True
            dp[start] = 0
            return False
        
        dp = [-1] * len(s)
        wordSet = set(wordDict)
        return solver(0, s, dp)
```

The efficient approach is bottom-up:

```python
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        dp = [False] * (len(s)+1)
        dp[0] = True
        wordSet = set(wordDict)

        for i in range(1, len(s)+1):
            for j in range(i):
                if dp[j] and s[j:i] in wordSet:
                    dp[i] = True
                    break
        return dp[-1]
```

and here is C++ version (thanks to [LCuser](https://leetcode.com/u/paul7/))
```cpp
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(wordDict.size()==0) return false;

        unordered_set<string> dict;
        for(auto w: wordDict){
            dict.insert(w);
        }

        vector<bool> dp(s.size()+1, false);
        dp[0] = true; //You can make empty string with any wordDict
        for (int i=1; i<=s.size(); ++i){
            for (int j=0; j<=i-1; j++){
                if (dp[j]){
                    string word = s.substr(j, i-j);
                    if (dict.find(word) != dict.end()){
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[s.size()];
    }
};
```
