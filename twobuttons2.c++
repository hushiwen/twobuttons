// twobuttons2.c++ 

#include <iostream>

using namespace std;

int recurse(int start, int end, int steps, int max_steps)
{
    // If we've converged, just return steps
    if (start == end) {
        return steps;
    }
    // Initialize return value
    int ret_steps = max_steps;
    // Start right tree - start x 2
    if (steps < max_steps) {
        ret_steps = recurse(start*2, end, steps+1, max_steps);
    }
    // Update max_steps  
    if (ret_steps < max_steps) {
       max_steps = ret_steps;
    }
    // Start left tree - start -1 
    if (start > 0 && steps < max_steps) {
        int left_steps; 
        // Early out if start > end
        if (start > end) {
            left_steps = steps + (start - end);
        } 
        else {
            left_steps = recurse(start-1, end, steps+1, max_steps);
        }
        // Update ret val if left tree is faster
        if (left_steps < ret_steps) {
            ret_steps = left_steps;
        }
    }
    
    // Update max_steps again 
    if (ret_steps < max_steps) {
       max_steps = ret_steps;
    }
    
    return ret_steps;
}

int main() 
{
    int start, end;

    cin >> start >> end;
    // Early out, if starting num >= ending num 
    if (start >= end) {
        cout << (start - end) << endl;
    }
    else { // Populate a binary tree
        cout << recurse(start,end,0,40000) << endl;
    }

    return 0;
}
