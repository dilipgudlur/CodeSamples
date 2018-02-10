#include <iostream>
#include <vector>

using namespace std;

/*10.2 Group Anagrams: Write a method to sort an array ot strings so that all 
tne anagrnms are next to each other. 
*/

//Approach: Either use (char counting or sort the string) and store in the hash table along wihth row number
//If string is found in the hash table, use the row number to append the anagram in that row
//else add a new row

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        size_t n = strs.size();
        if(!n)
            return result;
        
        unordered_map<string,int> map; //map that stores sorted string and the row number
        unordered_map<string,int>::iterator it;

        for(int i = 0;i < n;i++) {
            string tmp = strs[i];
            sort(tmp.begin(),tmp.end());
            it = map.find(tmp);
            if(it != map.end()) {
                result[it->second].push_back(strs[i]);
            }
            else {
                map.insert({tmp,result.size()});
                vector<string> tmp;
                tmp.push_back(strs[i]);
                result.push_back(tmp);
            }
        }
        return result;
    }
