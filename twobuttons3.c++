#include <iostream>
#include <queue>

using namespace std;

int main () {
    int start, end;
    int retval = 0;
    // Grab start and end 
    cin >> start >> end;
    
    // Early exit, if start >= end 
    if (start >= end) {
        retval = start-end ;
    }
    // If start < end
    else {
        // Queue contains starting number, click count 
        queue < pair<int, int> > pairq;
        // First entry = start, 0
        pairq.push(make_pair(start,0));
        
        while (!pairq.empty()) {
            pair <int, int> cur = pairq.front();
            // If we've converged, exit  
            if (cur.first == end) {
                retval = cur.second;
                break;
            }
            // Follow the subtraction path as long as we're > 0
            if (cur.first > 0) {
                pairq.push(make_pair(cur.first -1, cur.second +1));
            }
            // Follow the *2 path as long as we're < end
            if (cur.first < end) {
                pairq.push(make_pair(cur.first*2, cur.second + 1));
            }
            // Remove the parent, don't need it anymore  
            pairq.pop();
        }
    }
    
    cout << retval << endl;

    return 0;
}
