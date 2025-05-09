#include<bits/stdc++.h>
using namespace std;
/*int large(vector<int>& Edge){
    int n=Edge.size();
   // vector<bool>visited(n,false);
    int max=-1;
    for(int i=0; i<n; i++){
        vector<int>p;
        vector<bool>visited(n, false);
        int current=-1;
        while (current != -1 && !visited[current]) {
            visited[current] = true;
            p.push_back(current);
            current = Edge[current];
        }
        if (current != -1 && visited[current]) {
            int sum = 0;
            bool in = false;
            for (int node : p) {
                if (node == current) in = true;
                if (in) sum += node;
            }
    }
    return 

}*/
int main(){
    int n;
    cin>>n;
    vector<int>vis(n,0);
    vector<int>edge(n), indegree(n);
    for(int i=0; i<n; i++){
        cin>>edge[i];
        indegree[edge[i]]++;
    }
    queue<int>q;
    for(int i=0; i<n; i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    while(q.size()>0){
        int x=q. front();
        q.pop();
        vis[x]=1;
        int next=edge[x];
        indegree[next]--;
        if(indegree[next]==0){
            q.push(next);
        }
    }
    
    int ans=0;
    for(int i=0; i<n-1; i++){
        if(vis[i]==0){
            int current=i;
            int sum=0;
            /*if(vis[current]!=0 && current!=-1){
                int sum=0;
            }*/
            while(current != -1 && vis[current]==0){
                vis[current]=1;// now attendence marked
                sum+=current;
                int next=edge[current];// i goes to edge
                current=next;// update current
            }
            
            ans=max(ans, sum);
        }
        
    }
    cout<<ans;
}