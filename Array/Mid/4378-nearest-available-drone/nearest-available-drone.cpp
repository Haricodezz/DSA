class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        
        int minInd=-1;
    
        map<int,int>mp;
        for(int i =0; i<drones.size();i++){
            int x=drones[i][0];
            int y = drones[i][1];
            int range=drones[i][2];

           int dis =abs(x-target[0])+ abs(y-target[1]);
        
           if(dis<=range){
           mp[i]=dis;
               }
           

        }
        int mindis=INT_MAX;
        for(auto it: mp){
            if(it.second<mindis){
                mindis=it.second;
                minInd=it.first;
            }
        }
        


        return minInd;

    }
};