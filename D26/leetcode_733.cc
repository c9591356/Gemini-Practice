class Solution {
public:
    bool check(vector<vector<int>>& image, int sr,int sc,int cur_color){
        if(sr<0||sc<0||sr>=image.size()||sc>=image[0].size()||image[sr][sc]!=cur_color)
            return false;
        return true;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        stack<pair<int,int>> st;
        int cur_color =  image[sr][sc];
        if(color==cur_color)
            return image;
        if(check(image,sr,sc,cur_color)){st.push({sr,sc});}
        while(!st.empty()){
            int x= st.top().first,y=st.top().second;
            st.pop();
            image[x][y] = color;
            if(check(image,x+1,y,cur_color)){st.push({x+1,y});}
            if(check(image,x-1,y,cur_color)){st.push({x-1,y});}
            if(check(image,x,y+1,cur_color)){st.push({x,y+1});}
            if(check(image,x,y-1,cur_color)){st.push({x,y-1});}
        }
        return image;
    }
};