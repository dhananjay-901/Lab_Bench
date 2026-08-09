//given an array of words arr[] and line width l, format the owrds such that each line has exactly l characters and is fully justified both left and right. Pack as many words as possible into each line greedily. Distribute extra spaces as evenly as possible between words on each line. If spaces cannot be distributed evenly, the left gaps get one more space than the right gaps. The last line is left-justified with a single space between words and trailing spaces to fill the line.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> justifytext(vector<string>& words, int l){
    vector<string> result;
    int i=0, n=words.size();
    while(i<n){
        int linelen = words[i].size();
        int j = i+1;
        while(j<n && linelen+1+(int)words[j].size()<=l){
            linelen+=1+words[j].size();
            j++;
        }
        int numwords = j-i;
        int totalchars = 0;
        for(int k=i;k<j;k++) totalchars+=words[k].size();
        int numspaces = l - totalchars;
        string line = "";

        if(j==n || numwords == 1){
            for(int k = i;k<j;k++){
                if(k>i) line+=" ";
                line+=words[k];
            }
            line+=string(l-line.size(), ' ');
        }else{
            int gaps = numwords - 1;
            int spacepergap = numspaces/gaps;
            int extra = numspaces % gaps;
            for(int k=i;k<j-1;k++){
                line+=words[k];
                line+=string(spacepergap + (k-i <extra ? 1:0), ' ');
            }
            line+=words[j-1];
        }
        result.push_back(line);
        i=j;
    }
    return result;
}

int main(){
    vector<string> words = {"geeksforgeeks", "is", "the","best", "computer","science", "portal", "for", "geeks"};

    int l = 16;
    vector<string> ans = justifytext(words, l);
    cout << "[";
    for(int i=0;i<ans.size();i++){
        cout << "\"" << ans[i] << "\"";
            if(i!=ans.size()-1) cout << ",";
    }
    cout << "]"<<endl;
    return 0;
}
