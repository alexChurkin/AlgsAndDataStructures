#include <iostream>
#include <string>
#include "TLQueue.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "russian");
    setlocale(LC_NUMERIC, "eng");

    cout << "Console TLQueue demo\n";
    cout << "=========================\n\n";

    TLQueue<int> q;

    cout << "q:\n" << q << " (IsEmpty = " << q.IsEmpty() << ")\n\n";

    for (int i = 1; i <= 5; i++)
    {
        q.Push(i);
        cout << q << " (IsEmpty = " << q.IsEmpty() << ")\n";
    }
    cout << "\n";

    cout << "Let's assign q to q2 and clear q. The result is:\n";
    TLQueue<int> q2 = q;
    q.Clear();
    cout << "q:\n" << q << " (IsEmpty = " << q.IsEmpty() << ")\n\n";
    cout << "q2:\n" << q2 << " (IsEmpty = " << q2.IsEmpty() << ")\n\n";


    cout << "And we can't pop from q again:\n";
    try
    {
        q.Pop();
    }
    catch(TLQueueException e)
    {
        cout << e <<"\n";
    }

    cout << "Attempts to get first/last element of q will also lead to exceptions:\n";
    try
    {
        q.GetFirst();
    }
    catch (TLQueueException e)
    {
        cout << e;
    }
    try
    {
        q.GetLast();
    }
    catch (TLQueueException e)
    {
        cout << e << "\n\n";
    }

    cout << "Then, we will continue with q2.\n\n";

    for (int i = 1; i <= 5; i++)
    {
        cout << q2.Pop() << " popped:\n";
        cout << q2 << " (IsEmpty = " << q2.IsEmpty() << ")\n";
    }
    cout << "\n";


    for (int i = 6; i <= 10; i++)
    {
        q2.Push(i);
        cout << q2 << " (IsEmpty = " << q2.IsEmpty() << ")\n\n";
    }

    cout << "Other tests:\n\n";
    TLQueue<int> q3(q2);

    cout << "q2:\n" << q2 << " (IsEmpty = " << q2.IsEmpty() << ")\n\n";
    cout << "q3(q2):\n" << q3 << " (IsEmpty = " << q3.IsEmpty() << ")\n\n";

    cout << "(q3 == q2) = " << (q3 == q2) << "\n\n";

    cout << q2.Pop() << " popped from q2:\n";
    cout << "q2:\n" << q2 << " (IsEmpty = " << q2.IsEmpty() << ")\n\n";

    cout << "(q3 == q2) = " << (q3 == q2) << "\n";
}