#include<vector>

int shiftAmount(const std::vector<int>& cyclicSorted){

    int j = cyclicSorted.size(), i = 0;
    while (j>=i){
        int mid = i + (j - i)/2;
        if ((cyclicSorted[mid-1] < cyclicSorted[mid]) && (cyclicSorted[mid-1] < cyclicSorted[0]) )
            j = mid;
        else if ((cyclicSorted[mid-1] < cyclicSorted[mid]) && (cyclicSorted[mid-1] >= cyclicSorted[0]) )
            i = mid;
        else
            return mid;
        }
}