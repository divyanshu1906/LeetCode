class Solution {
public:
    int maxContainers(int n, int w, int maxWeight) {
        int deckCell = n*n;
        if((maxWeight/w) <= deckCell) return (maxWeight/w);
        else return deckCell;
    }
};