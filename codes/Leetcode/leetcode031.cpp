class Solution {
	public:
		void nextPermutation(vector<int>& nums) {
			int n = nums.size();
			int idx = n - 1;

			while (idx && nums[idx-1] >= nums[idx]) idx--;

			if (idx) {
				int p = n - 1;
				while (p >= idx && nums[p] <= nums[idx-1]) p--;
				int tmp = nums[idx-1];
				nums[idx-1] = nums[p];
				nums[p] = tmp;
				sort(nums.begin() + idx, nums.end());
			} else {
				sort(nums.begin(), nums.end());
			}
		}
};
