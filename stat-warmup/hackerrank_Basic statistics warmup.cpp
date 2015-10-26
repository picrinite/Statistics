#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//Mode: The element(s) which occurs most frequently.If multiple elements satisfy this criteria, display the numerically smallest one.
// input is sorted
int getMode(int nums[], int size) {
	int i, mode = nums[0], record = nums[0], cnt = 1, max_cnt = 1;
	for (i = 1; i < size; ++i) {
		if (nums[i] != nums[i - 1]) {
			if (cnt > max_cnt) {
				max_cnt = cnt;
				mode = record;
			}
			record = nums[i];
			cnt = 0;
		}
		++cnt;
	}
	return mode;
}

double getSD(int nums[], int mean, int size) {
	double sum = 0;
	for (int i = 0; i < size; ++i)
		sum += pow(nums[i] - mean, 2);
	return sqrt(sum / size);
}

int main() {
	int size;
	scanf("%d", &size);
	int *nums;
	nums = (int*)malloc(size);
	int i = size;
	while (i--)
		scanf("%d", &nums[i]);
	double c = 1.96;
	double sum = 0, mean, median, sd, lower_limit, upper_limit;
	sort(nums, nums + size);
	for (i = 0; i < size; ++i) 
		sum += nums[i];
	if (size % 2)
		median = nums[size / 2];
	else
		median =  ( (double) (nums[size / 2 - 1] + nums[size / 2]) ) / 2;
	

	sd = getSD(nums, sum / size, size);
	// c*sd/
	double diff = c * sd / sqrt(size); 
	mean = sum / size;
	printf("%.1f\n", mean);
	printf("%.1f\n", median);
	printf("%d\n", getMode(nums, size));
	printf("%.1f\n", sd);
	printf("%.1f %.1f\n", mean - diff, mean + diff );
	return 0;
}