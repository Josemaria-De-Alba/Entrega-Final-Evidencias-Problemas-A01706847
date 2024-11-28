class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int h; //Altura para base * altura
        int water = 0;
        while (i < j){
            int base = j - i;
            if(height[i] > height[j]){
                h = height[j];
            }
            else{
                h = height[i];
            }
            int aux = h * base;
            if(aux > water){
                water = aux;
            }
            if (height[i] < height[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return water;
    }
};
