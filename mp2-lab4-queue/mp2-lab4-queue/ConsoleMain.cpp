#include <iostream>
#include "TQueue.h"

using namespace std;

int main()
{
    TQueue<int> q(3);

    cout << q << '\n';

    q.Push(1);
    cout << q << '\n';

    q.Push(2);
    cout << q << '\n';

    q.Push(3);
    cout << q << '\n';

    q.Pop();
    cout << q << '\n';

    q.Push(4);
    cout << q << '\n';

    q.Pop();
    cout << q << '\n';

    q.Push(5);
    cout << q << '\n';

    q.Pop();
    cout << q << '\n';

    q.Push(6);
    cout << q << '\n';

    q.Pop();
    cout << q << '\n';

    q.Pop();
    cout << q << '\n';

    q.Pop();
    cout << q << '\n';

    q.Push(1000);
    cout << q << '\n';

    q.Push(2000);
    cout << q << '\n';

    q.Push(3000);
    cout << q << "\n\n";

    cout << "Trying to add 4000:\n";
    try
    {
        q.Push(4000);
    }
    catch (TQueueException e)
    {
        cout << "\n" << e << "\n";
    }

    cout << "Let's copy to \"other\" variable and continue:\n\n";
    TQueue<int> other(q);
    cout << other << '\n';

    other.Pop();
    cout << other << '\n';

    other.Pop();
    cout << other << '\n';

    other.Pop();
    cout << other << "\n\n";

    cout << "Trying to pop again:\n";
    try
    {
        other.Pop();
    }
    catch (TQueueException e)
    {
        cout << "\n" << e << "\n\n";
    }

    cout << "Trying to create queue with MaxSize < 2:\n";
    try
    {
        TQueue<char> q2(-2);
    }
    catch (TQueueException e)
    {
        cout << "\n" << e << "\n";
    }

    return 0;
}