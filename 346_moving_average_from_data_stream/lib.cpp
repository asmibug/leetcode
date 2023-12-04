/**
 * https://leetcode.com/problems/moving-average-from-data-stream/
 * 
 * Approaches:
 * 1) Using queue
 * 2) Using circular buffer
*/

#include <vector>

class MovingAverage {
public:
    MovingAverage(int size)
        : max_size_(size) {
    }
    
    double next(int val) {
        if (window_.size() == max_size_) {
            sum_ -= window_[index_];
            window_[index_] = val;
        } else {
            window_.push_back(val);
        }
        index_ = (index_ + 1) % max_size_;

        sum_ += val;
        return 1.0 * sum_ / window_.size();
    }

private:
    std::vector<int> window_;
    unsigned max_size_;
    unsigned index_ = 0;
    int sum_ = 0;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
 