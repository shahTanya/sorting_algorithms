#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};

	/* int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30}; */

	/* int array[] = {114, 183, 44, 106, 166, 188, 164, 174, 118, 34, 8, 63, 46, 18, 71, 121, 113, 145, 115, 75, 111, 146, 98, 37, 29, 119, 125, 24, 41, 1, 56, 173, 73, 156, 35, 120, 181, 123, 40, 194, 152, 77, 70, 117, 198, 50, 5, 3, 4, 94, 1157, 597, 1895, 1247, 201, 142, 1899, 910, 1029, 515, 810, 1173, 101, 191, 92, 62, 802, 1986, 1037, 1076, 503, 858, 873, 452, 508, 1668, 22, 1078, 637, 1457, 1725, 145, 716, 346, 928, 1332, 1180, 542, 588, 1903, 464, 1006, 697, 1932, 21, 436, 453, 1309, 40, 684, 818, 1268, 1378, 857, 607, 13, 1261, 1942, 85, 1245, 1082, 1498, 1961, 1046, 674, 1805, 216, 646, 1113, 1302, 1460, 1575, 429, 1653, 1028, 868, 1673, 729, 1208, 833, 675, 761, 1214, 1271, 1737, 1499, 1095, 1427, 621, 1449, 1235, 80, 1732, 1767, 412, 1589, 771, 282, 1163, 864, 603, 1312, 711, 791, 95, 333, 427, 1600, 985, 632, 486, 1317, 111, 1569, 192, 475, 383, 159}; */

	/* int array[] = {1, 3, 4, 5, 8, 13, 18, 21, 22, 24, 29, 34, 35, 37, 40, 40, 41, 44, 46, 50, 56, 62, 63, 70, 71, 73, 75, 77, 80, 85, 92, 94, 95, 98, 101, 106, 111, 111, 113, 114, 115, 117, 118, 119, 120, 121, 123, 125, 142, 145, 145, 146, 152, 156, 159, 164, 166, 173, 174, 181, 183, 188, 191, 192, 194, 198, 201, 216, 282, 333, 346, 383, 412, 427, 429, 436, 452, 453, 464, 475, 486, 503, 508, 515, 542, 588, 597, 603, 607, 621, 632, 637, 646, 674, 675, 684, 697, 711, 716, 729, 761, 771, 791, 802, 810, 818, 833, 857, 858, 864, 868, 873, 910, 928, 985, 1006, 1028, 1029, 1037, 1046, 1076, 1078, 1082, 1095, 1113, 1157, 1163, 1173, 1180, 1208, 1214, 1235, 1245, 1247, 1261, 1268, 1271, 1302, 1309, 1312, 1317, 1332, 1378, 1427, 1449, 1457, 1460, 1498, 1499, 1569, 1575, 1589, 1600, 1653, 1668, 1673, 1725, 1732, 1737, 1767, 1805, 1895, 1899, 1903, 1932, 1942, 1961, 1986}; */
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    quick_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}
