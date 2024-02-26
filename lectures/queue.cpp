#include<iostream>
#include<queue>

using namespace std;

int main()
{
    system("cls");
    queue<int> q1;
    queue<int> q2;

    cout << "Queue size: " << q1.size() << endl; // 0
    cout << "Check if queue is empty: " << q1.empty() << endl; // 1

    q1.push(3);  //   3   6  8  4   1
    q1.push(6);  // front          back
    q1.push(8);
    q1.push(4);
    q1.push(1); // value added at back end

    // q2.push(1);  
    // q2.push(2); 
    // q2.push(3);
    // q2.push(4);
    // q2.push(5); 

    // if (!(q1.empty() && !(q2.empty())))
    // {
    //     q1.swap(q2);
    //     cout << "Queue is successfully swaped with queue 2" << endl;
    // }
    

    cout << "Queue size: " << q1.size() << endl; // 5
    cout << "Check if queue is empty: " << q1.empty() << endl; // 0

    if (!q1.empty())
    {
        cout << "Value at front end: " << q1.front() << endl; // 3
        cout << "Value at back(rare) end: " << q1.back() << endl; // 1
        q1.pop(); // value removed at front end: 3 
    }

    cout << "Queue size: " << q1.size() << endl; // 4
    cout << "Check if queue is empty: " << q1.empty() << endl; // 0


    if (!q1.empty())
    {
        cout << "Value at front end: " << q1.front() << endl; // 6
        cout << "Value at back(rare) end: " << q1.back() << endl; // 1
        q1.pop();
    }    
    
    cout << "Queue size: " << q1.size() << endl; // 3
    cout << "Check if queue is empty: " << q1.empty() << endl; // 0

    



    return 0;
}