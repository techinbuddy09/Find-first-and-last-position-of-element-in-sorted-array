//using binary search an optimized way for a solution with complexity level O(log n)
//in this question basically we have to get the leftmost target and the right most target
// so even if i check in the array arr[mid]==target...but we cant return it there ..because we have to return the leftmost and rightmost target
// we have to basically return the(leftmostindicies,rightmostindicies)
class Solution {
public:
int findstartmost(vector<int>&nums,int target,int n)//initially setting leftmost(startmost) at-1
{
 int l=0;//left pointer
 int h=n-1;//right pointer storing the last element
 int startmost=-1;// initially at -1
 //now applying binary search
 while(l<=h)
 {
    long long mid=l+(h-l)/2;//calculating the mid value
    if(nums[mid]==target)// if suppose target found
    {
        startmost=mid;//storing the one ans found 
        //we will still check till the startmost
        h=mid-1;// moving towards left now
    }
    else if(nums[mid]<target)
    {
        // we will move towards right
        l=mid+1;
        
    }
    else
    {
        h=mid-1;//move towards right
    }
 }
 return startmost;// in the end return the startmost element
 }
 int endmost(vector<int>&nums,int target,int n)//initially setting rightmost(endmost) at-1
{
 int l=0;//left pointer
 int h=n-1;//right pointer storing the last element
 int endmost=-1;// initially at -1
 //now applying binary search
 while(l<=h)
 {
    long long mid=l+(h-l)/2;//calculating the mid value
    if(nums[mid]==target)// if suppose target found
    {
        endmost=mid;//storing the one ans found 
        //we will still check till the startmost
        l=mid+1;// moving towards right now
    }
    else if(nums[mid]<target)
    {
        l=mid+1;
        
    }
    else
    {
        h=mid-1;//move towards right
    }
 }
    return endmost;//finally returning endmost element
 }
 
    vector<int> searchRange(vector<int>& nums, int target) {
        int n_size=nums.size();// to find the size of the array
        int startmosty=findstartmost(nums,target,n_size); // here we are finding the startmosty element 
        int endmosty=endmost(nums,target,n_size);
        return{startmosty,endmosty};// here basically returning the startmosty and endmosty position
        
    }
};
