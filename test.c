
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
	int* nums3 = (int*)malloc(sizeof(int)*(m + n));
	int i = 0, j = 0, idx = 0;
	while (i<m&&j<n)
	{
		if (nums1[i] <= nums2[j])
		{
			nums3[idx++] = nums1[i++];
		}
		else
		{
			nums3[idx++] = nums2[j++];
		}
	}
	if (i<m)
		memcpy(nums3 + idx, nums1 + i, sizeof(int)*(m - i));
	if (j<n)
		memcpy(nums3 + idx, nums2 + j, sizeof(int)*(n - j));
	memcpy(nums1, nums3, sizeof(int)*(m + n));
	free(nums3);
}
