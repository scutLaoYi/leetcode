#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

class MinStack {
    private:
        int *data;
        int size;
        int min;
    public:
        MinStack():size(0)
        {
            data = new int[100000];
        }
        ~MinStack()
        {
            delete []data;
        }
        void push(int x) {
            if (size) {
                min = min > x ? x : min;
            } else {
                min = x;
            }
            data[size++] = x;
        }

        void pop() {
            if (!size) {
                return;
            }
            if (data[size-1] == min) {
                min = data[0];
                for(int i = 1; i < size-1; ++i) {
                    if (min > data[i]) {
                        min = data[i];
                    }
                }
            }
            --size;
        }

        int top() {
            if (!size) {
                return 0;
            }
            return data[size-1];
        }

        int getMin() {
            return min;
        }
         
        void trace() {
            for(int i = 0; i < size; ++i) {
                cout<<data[i]<<' ';
            }
            cout<<"min:"<<getMin()<<endl;
        }

};

