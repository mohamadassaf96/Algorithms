#include<vector>

int shiftAmount(const std::vector<int>& cyclic_sorted){
    int j = cyclic_sorted.size(), i = 0;
    while (j>=i){
        int mid = i + (j - i)/2;
        if ((cyclic_sorted[mid-1] < cyclic_sorted[mid]) && (cyclic_sorted[mid-1] < cyclic_sorted[0]) )
            j = mid;
        else if ((cyclic_sorted[mid-1] < cyclic_sorted[mid]) && (cyclic_sorted[mid-1] >= cyclic_sorted[0]) )
            i = mid;
        else
            return mid;
        }
}