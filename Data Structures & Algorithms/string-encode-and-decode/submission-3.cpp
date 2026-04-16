class Solution {
public:

    //ENCODE: vector<string>-->single string
    string encode(vector<string>& strs) {

        string res = "";

        //har string ke liye
        for(string s: strs){
            //formart : length+'#+string
            //example : "ab" -->"2#ab"
            res+= to_string(s.length())+"#"+s;

        }
        return res;
    }

    vector<string> decode(string s) {

        vector<string>res;

        int i=0;

        //pura encoded string traverse karenge hum log
        while(i<s.length()){

            int j = i;

            //# tak jao --> yaha tak length likhi hai
            while(s[j]!='#')j++;

            //length extract karo samjhe
            int len = stoi(s.substr(i,j-i));

            //actual string uthao
            string word = s.substr(j+1,len);

            res.push_back(word);

            i=j+1+len;//pointer move karo next ke lie
            
      
        }
        return res;
    }
};
