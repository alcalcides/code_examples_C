#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int main () {
    stack<int> hotIssues;
    hotIssues.push(2);
    hotIssues.push(20);
    hotIssues.push(200);

    cout << hotIssues.top() << endl;
    hotIssues.pop();
    cout << hotIssues.top() << endl;

    return 0;
}