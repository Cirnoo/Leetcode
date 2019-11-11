import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.TreeMap;

/*
 * @lc app=leetcode.cn id=1200 lang=java
 *
 * [1200] 最小绝对差
 *
 * https://leetcode-cn.com/problems/minimum-absolute-difference/description/
 *
 * algorithms
 * Easy (62.21%)
 * Likes:    3
 * Dislikes: 0
 * Total Accepted:    3K
 * Total Submissions: 4.8K
 * Testcase Example:  '[4,2,1,3]'
 *
 * 给你个整数数组 arr，其中每个元素都 不相同。
 * 
 * 请你找到所有具有最小绝对差的元素对，并且按升序的顺序返回。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：arr = [4,2,1,3]
 * 输出：[[1,2],[2,3],[3,4]]
 * 
 * 
 * 示例 2：
 * 
 * 输入：arr = [1,3,6,10,15]
 * 输出：[[1,3]]
 * 
 * 
 * 示例 3：
 * 
 * 输入：arr = [3,8,-10,23,19,-4,-14,27]
 * 输出：[[-14,-10],[19,23],[23,27]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 <= arr.length <= 10^5
 * -10^6 <= arr[i] <= 10^6
 * 
 * 
 */

// @lc code=start
class Solution {
	public List<List<Integer>> minimumAbsDifference(int[] arr) {
		TreeMap<Integer,List<List<Integer>>> mp = new TreeMap<>();
		Arrays.sort(arr);
		for(int i=1;i<arr.length;++i){
			int diff = arr[i]-arr[i-1];
			if(mp.containsKey(diff)){
				mp.get(diff).add(Arrays.asList(arr[i-1],arr[i]));
			}else{
				List<List<Integer>> ls = new ArrayList<>();
				ls.add(Arrays.asList(arr[i-1],arr[i]));
				mp.put(diff,ls);
			}
		}
		return mp.get(mp.firstKey());
	}
}
// @lc code=end

