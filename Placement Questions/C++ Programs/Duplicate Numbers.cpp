/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;
 class Solution {
     public int findDuplicate(int[] nums){
         int slow = nums[0];
         int fast = nums[0];
         do{
             slow= nums[slow];
             fast = nums[nums[fast]];
         } while(slow != fast);
         fast = nums[0];
         while(slow!= fast){
             slow = nums[slow];
             fast = nums[fast];
         }
         return slow;
     }
 }
 