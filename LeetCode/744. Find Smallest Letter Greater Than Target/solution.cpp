class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char found = letters[0];
       for(int i =0; i < letters.size();i++)
           {
           if(letters[i] > target)
               {
               found = letters[i];
               break;
               }
           }
        return found;
    }
};