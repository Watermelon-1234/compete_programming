// C++ program for Merge Sort
#include <iostream>
using namespace std;

// Merges two subarrays of array[].
// First subarray is arr[begin..mid]
// Second subarray is arr[mid+1..end]
void merge(int array[], int const left, int const mid,
		int const right)
{
	auto const subArrayOne = mid - left + 1;
	auto const subArrayTwo = right - mid;

	// Create temp arrays
	auto *leftArray = new int[subArrayOne],
		*rightArray = new int[subArrayTwo];

	// Copy data to temp arrays leftArray[] and rightArray[]
	for (auto i = 0; i < subArrayOne; i++)
		leftArray[i] = array[left + i];
	for (auto j = 0; j < subArrayTwo; j++)
		rightArray[j] = array[mid + 1 + j];

	auto indexOfSubArrayOne
		= 0, // Initial index of first sub-array
		indexOfSubArrayTwo
		= 0; // Initial index of second sub-array
	int indexOfMergedArray
		= left; // Initial index of merged array

	// Merge the temp arrays back into array[left..right]
	while (indexOfSubArrayOne < subArrayOne
		&& indexOfSubArrayTwo < subArrayTwo) {
		if (leftArray[indexOfSubArrayOne]
			<= rightArray[indexOfSubArrayTwo]) {
			array[indexOfMergedArray]
				= leftArray[indexOfSubArrayOne];
			indexOfSubArrayOne++;
		}
		else {
			array[indexOfMergedArray]
				= rightArray[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
		}
		indexOfMergedArray++;
	}
	// Copy the remaining elements of
	// left[], if there are any
	while (indexOfSubArrayOne < subArrayOne) {
		array[indexOfMergedArray]
			= leftArray[indexOfSubArrayOne];
		indexOfSubArrayOne++;
		indexOfMergedArray++;
	}
	// Copy the remaining elements of
	// right[], if there are any
	while (indexOfSubArrayTwo < subArrayTwo) {
		array[indexOfMergedArray]
			= rightArray[indexOfSubArrayTwo];
		indexOfSubArrayTwo++;
		indexOfMergedArray++;
	}
	delete[] leftArray;
	delete[] rightArray;
}

// begin is for left index and end is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(int array[], int const begin, int const end)
{
	if (begin >= end)
		return; // Returns recursively

	auto mid = begin + (end - begin) / 2;
	mergeSort(array, begin, mid);
	mergeSort(array, mid + 1, end);
	merge(array, begin, mid, end);
}

// UTILITY FUNCTIONS
// Function to print an array
void printArray(int A[], int size)
{
	for (auto i = 0; i < size; i++)
		cout << A[i] << " ";
}

// Driver code
int main()
{
	int arr[] = { 4634,9317,7719,8990,5289,5868,8591,878,1466,5731,2507,2130,4677,6642,4614,6238,134,4005,1808,9421,8945,4647,7077,7776,6091,4435,5023,202,2265,5414,5293,6898,4731,9364,2239,6371,5231,830,7248,6697,2912,6107,5178,7588,2748,6144,177,2881,148,8336,8653,5444,2982,5729,3220,9072,6515,8242,5625,5131,3656,918,2028,4738,6633,4267,7460,1863,1448,4708,4911,4359,7166,6441,8298,9913,8936,8475,9145,9083,6810,7797,4526,6144,9877,4097,1567,6392,8691,7192,7874,8698,4461,9902,9787,1093,520,7246,9307,8319,8305,570,2677,5470,7010,974,1734,5945,5800,878,1379,2610,5026,2256,5105,4903,6353,6671,7646,1395,3862,5519,92,8322,1772,9878,5766,8643,3475,5073,3313,1780,5642,5989,7249,9003,3315,8983,4947,9114,6212,2677,8075,7590,4932,3179,8844,7636,6202,2841,9030,63,4711,5473,4737,2835,5350,502,1477,5177,1926,1142,6956,7567,7130,556,2921,6796,5890,4219,2262,8454,6895,6688,6043,1827,6219,4886,9462,2420,4078,4844,2482,8788,316,7218,1622,2018,4072,9451,7194,5997,592,4149,9916,4073,1056,2836,869,6946,7055,3130,5399,3949,9817,7793,2127,6035,9030,7941,4806,3107,2784,7288,1894,3099,857,3516,1468,1280,9318,8661,7277,9909,9161,3544,3981,217,6379,4849,3514,3433,4330,5264,3734,499,3056,5860,2885,2085,152,7691,1543,2935,1330,3436,2386,2186,3303,3853,9818,2620,8866,7094,2528,8026,637,6509,4594,3367,7709,8107,3152,8391,3370,6885,8889,6425,9096,8125,4861,9248,2167,6403,8534,3496,6191,7271,2034,9493,1124,1851,8465,9989,5296,992,4366,5932,3852,8960,5650,7913,3418,8801,6303,6788,2037,1543,9564,1133,6019,777,6732,8186,7179,1617,1681,9721,8888,3714,9214,6363,1916,7678,6351,7211,5021,7068,3142,5225,2379,5144,3137,5797,3944,5791,8936,5981,3685,8499,3465,9703,5627,196,7888,9158,1812,9569,8878,7051,9634,4443,3413,1550,8472,6115,8760,3493,3183,8254,5069,5561,3397,8205,1357,3692,347,292,9672,4031,5143,3136,3733,7121,9683,1621,6278,7847,7541,5156,4897,3526,9598,4662,1427,4422,776,187,7914,310,4792,2982,5871,4540,7538,3579,8231,7884,223,4255,1914,1717,3742,1998,8837,9777,9970,5115,7623,3862,6622,8871,7388,2571,9884,5166,6992,660,5352,1257,969,6495,590,3191,7386,8127,3122,5617,2362,3344,6223,627,5060,9964,2625,248,9740,8946,1714,3714,2808,4687,8937,6547,7258,8820,1712,601,5831,3416,1858,3152,6262,2447,2694,3648,6926,5815,5616,9287,9158,1838,6266,569,8153,5242,7169,7893,4187,8882,7958,3346,3569,3246,9892,7178,8418,7956,7778,600,7723,5987,3751,3984,4786,6445,3983,1711,8611,9598,7349,7769,1435,3614,4689,9588,8855,1857,3832,9394,7091,8141,2739,659,7739,8983,4188,2508,3290,1965,3107,1012,7952,3210,1347,2737,6006,1682,799,4616,1279,4499,8736,9066,8113,3425,5005,3319,5281,5188,9064,2371,9680,1803,9381,7418,7137,3568,9925,426,1885,9384,7789,6188,2593,5487,5276,8598,3520,6074,9565,4799,572,8301,216,5036,1725,1572,4707,3357,6759,3770,2080,6438,1924,7812,208,5412,1380,6484,2189,9616,5867,6329,5803,8459,8168,1078,3408,1687,3503,2973,2837,4074,1273,3052,5462,9349,4623,168,2705,7733,289,1136,523,8565,8948,730,3976,6679,3565,2517,6294,9432,8845,2096,4242,7012,3173,4002,5051,6675,6974,7887,7100,4598,939,2561,298,1913,9080,3002,9646,5721,490,168,637,9437,7249,964,6115,813,3480,2408,6596,8677,855,838,2040,4027,4839,7090,7053,8164,4977,504,9113,2267,9417,9410,4179,4848,8763,176,6920,9252,6695,7556,8688,3943,8520,1154,1108,8351,3561,7703,7027,767,4892,9067,1145,6082,6156,8197,4245,7484,5053,9709,9750,4469,9118,281,9316,4233,456,6236,3484,3503,143,8524,7445,8662,9677,8552,3365,9590,2607,391,356,7498,5809,1501,3580,8317,6049,4176,5800,1101,3885,1902,1921,9354,8534,1237,3586,8989,3824,7070,2491,3966,5593,6288,8980,1621,1191,2344,1210,3797,9086,7918,1295,4895,9418,1226,9563,5466,5401,5362,2919,9285,3615,4839,4991,2148,2427,8576,7489,2602,1997,6331,6568,3941,2618,1899,5562,161,594,3123,3957,9679,1040,1603,925,457,2828,487,2275,8229,2201,1545,3865,5815,6383,8855,7963,8810,3783,1803,7763,5779,8133,4330,9720,7103,2580,1633,7263,3173,4755,7571,9204,5795,9174,128,2603,8353,615,1229,2933,2815,2773,6798,4981,5508,5652,9295,669,5786,1097,8431,1565,9230,9113,1284,2684,1692,9268,6298,1217,4022,3868,420,6168,9393,6899,5123,7746,7513,6351,678,6679,5476,3827,1660,7335,5831,954,8003,1616,2051,2785,3180,7632,1897,815,6667,9941,82,2964,1157,456,6831,7928,6623,2576,4826,1745,321,8691,4448,7350,5369,6275,1177,3380,3609,3359,4334,1611,4974,2736,747,4506,6719,2644,5320,3385,2584,1754,6348,92,2209,9530,8019,5183,2105,9196,6928,8777,7886,7727,6127,3255,4001,3655,6634,3961,7013,7319,1923,8338,6406,2669,2843,3124,5312,4515,6508,4247,6268,2855,690,8476,2385,5060,10,841,4256,6937,9618,8493,1015,5744,8099,1367,5750,4733,5327,9114,8403,7249,3803,4809,9918,6646,7932,1581,1160,792,2180,3779,9998,2869,8606,8734,4281,8615,9575,8536,1904,9192,3380,2918,1287,1479,4285,3388,2563,5963,2501,965,3212,2655,2125,9481,9300,6409,7413,6811,7200,5944,589,3549,8813,9194,2283,9445,7809,8209,4332,9712,7400,7711,8981,5038,9189,9617,8425,1751,5580,7277,2716,5143,9931,4840,975,5583,7600,8387,2393,4799,683,9334,4700,9495,8527,6982,8939,2687,5190 };
	auto arr_size = sizeof(arr) / sizeof(arr[0]);

	cout << "Given array is \n";
	printArray(arr, arr_size);

	mergeSort(arr, 0, arr_size - 1);

	cout << "\nSorted array is \n";
	printArray(arr, arr_size);
	return 0;
}

// This code is contributed by Mayank Tyagi
// This code was revised by Joshua Estes