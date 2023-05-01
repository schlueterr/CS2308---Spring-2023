#include <iostream>
#include <queue>

using namespace std;

class MovingAverage{
    private:
        int windowSize;
        queue<int> queue1;
        double sum;

    public:
        MovingAverage(int size){
            windowSize = size;
            sum = 0.0;
        }

        double next(int val){
            queue1.push(val);
            sum += val;
            if (queue1.size() > windowSize){
                sum -= queue1.front();
                queue1.pop();
            }
            return sum / queue1.size();
        }
};

int main(){
    MovingAverage ma(3);
    cout << ma.next(1) << endl; // 1
    cout << ma.next(10) << endl; // 5.5
    cout << ma.next(3) << endl; // 4.66667
    cout << ma.next(5) << endl; // 6

    return 0;
}