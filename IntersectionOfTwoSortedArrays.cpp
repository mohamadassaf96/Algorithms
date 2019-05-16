#include<unordered_set>
#include<vector>
#include <algorithm>

std::unordered_set<int> intersectionOfTwoSortedArrays(const std::vector<int>& A, const std::vector<int>& B){
    std::unordered_set<int> result;
    if  (((A.size()/B.size())<1.1) && ((A.size()/B.size())>0.9)){
        int i = 0, j = 0;
        while ( (i < A.size()) && (j < B.size())){
            if ( A[i] > B[j]) {
                j++;
            }
            else if (A[i]<B[j]) {
                i++;
            }
            else {
                result.insert(A[i++]);
                j++;
            }
        }
    }
    else {
        std::vector<int> A_ = A.size() > B.size() ? A : B;
        std::vector<int> B_ = A.size() < B.size() ? A : B;
        for ( int i = 0; i < B_.size(); i++){
            if (std::binary_search(A_.begin(), A_.end(), B_[i])){
                result.insert(B_[i]);
            }
        }
    }
    return result;

}