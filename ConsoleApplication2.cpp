#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
        struct Element
        {
                unsigned int n;
                unsigned int occurs;
        } e;
        vector<struct Element> v;
        unsigned int* arr;
        unsigned int i, n;
        bool cont;
        cout << "n = ";
        cin >> n;;
        arr = new unsigned int[n];
        for (i = 0; i < n; i++)
        {
                cout << "arr[" << i << "] = ";
                cin >> arr[i];
        } // for i ...
        for (i = 0; i < n; i++)
        {
                cont = false;
                for (struct Element& ce : v)
                        if (ce.n == arr[i])
                        {
                                ce.occurs++;
                                cont = true;
                                break;
                        }
                if (!cont)
                {
                        e.n = arr[i];
                        e.occurs = 1;
                        v.push_back(e);
                }
        } // for i ...
        auto comp = [](struct Element a, struct Element b)
        {
                if (a.occurs != b.occurs)
                        return (a.occurs > b.occurs);
                else
                        return (a.n > b.n);
        };
        sort(v.begin(), v.end(), comp);
        n = 0;
        for (struct Element& ce : v)
        {
                for (i = 0; i < ce.occurs; i++, n++)
                        arr[n] = ce.n;
        }
        for (i = 0; i < n; i++)
                cout << arr[i] << endl;
        delete arr;
                }

