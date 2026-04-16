class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int n = height.size();

        int i=0,j=n-1;
        int maxWater = 0;

        while(i<j){
            int width = j-i;
            int length = min(height[i],height[j]);
            int area = width*length;

            //without this line we would lose the track of the maximum
            //and only have the calculated the area
            maxWater = max(maxWater,area);

            if(height[i]>height[j]){
                j--;//area max karne ke lie agar width kamm kar rhe hai toh hame area ko badhana padega
            //toh uska ek option hai height badha de hum
            }
            else{
                i++;
            }
        }
        return maxWater;
    }
};
