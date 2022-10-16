 string longestCommonPrefix(vector<string>& str) {
        if(str.size()==1) return str[0];
        string small= str[0];
        for(int i=1;i<str.size();i++){
            if(str[i].length()<small.length()) small= str[i];
        }
        int mini= INT_MAX;
        for(int i=0;i<str.size();i++){
            int k=0,j=0,count=0;
            while(j<small.length()){
                if(str[i][k]==small[j]){
                    count++;
                    j++,k++;
                }
                else{
                    break;
                }
            }
            mini= min(mini,count);
        }
        if(mini==INT_MAX) return "";
        return small.substr(0,mini);
        
    }
