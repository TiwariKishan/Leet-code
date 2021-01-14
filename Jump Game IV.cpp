class Solution {
public:
    int    minJumps(vector<int>& arr) {
        if(arr.size()==1) return 0;
        map<int,vector<int> > m;
        for(int i=0;i<arr.size();i++)
            m[arr[i]].push_back(i);
        for(auto i: m)
            sort(i.second.begin(),i.second.end(),[](int a,int b){return a>b;});
        vector<bool> vis(arr.size(),false);
        queue<int> q;
        q.push(0);
        vis[0]=true;
        int l=0;
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                int u=q.front();
                q.pop();
                if(u==arr.size()-1) return l;
                if(u-1>=0&&!vis[u-1])
                {
                    q.push(u-1);
                    vis[u-1]=true;
                }
                 if(u+1<arr.size()&&!vis[u+1])
                {
                    q.push(u+1);
                    vis[u+1]=true;
                }
                vector<int> &v=m[arr[u]];
                for(auto i:v)
                {
                    if(!vis[i])
                    {   if(i==arr.size()-1) return l+1;
                        q.push(i);
                        vis[i]=true;
                    }
                }
                v.clear();
            }
            l++;
        }
        return l;
    }
};
