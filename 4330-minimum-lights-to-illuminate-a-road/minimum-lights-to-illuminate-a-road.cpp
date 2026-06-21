class Solution {
public:
    int minLights(vector<int>& l) {
        int n=l.size();
        vector<int>d(n+1,0);
        vector<int>v(n,0);
        for(int i=0;i<n;i++){
            if(l[i]>0){
                int left=max(0,i-l[i]);
                int right=min(n-1,i+l[i]);
                d[left]++;
                d[right+1]--;
                // for(int j=left;j<=right;j++){
                //     v[j]=true;
                // }
            }
        }

        int curr=0;
        for(int i=0;i<n;i++){
            curr+=d[i];
            v[i]=(curr>0);
        }
        
        int ans=0;

        for (int i=0;i<n;i++){
            if(v[i]) continue;
            ans++;
            int pos=min(n-1,i+1);

            for(int j=max(0,pos-1);j<=min(n-1,pos+1);j++) {
                v[j]=1;
            }
        }

        return ans;
    }
};