class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int n =numbers.length;
        int i=0,j=n-1;
        int sum=0;
        int [] ans = {-1,-1};
        while(i<j){
            sum = numbers[i]+numbers[j];
            if (sum == target){
                ans[0] = i+1;
                ans[1] = j+1;
                break;
            }
        else if(sum>target){
            j--;
        }
        else{
            i++;
        }
        
        }
        return ans;
        
        
    }
}
