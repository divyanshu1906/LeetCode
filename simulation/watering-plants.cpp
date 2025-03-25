class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int n = plants.size();
        int steps = 1;
        int availableWater = capacity;
        int i=0;
        for(int i=0; i<n-1; i++){
            availableWater -= plants[i];
            steps++;
            if(availableWater < plants[i+1]){
                steps += (i*2)+2;
                availableWater = capacity;
            }
        }
        return steps;
    }
};