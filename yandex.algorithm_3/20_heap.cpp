/*В этой задаче вам необходимо самостоятельно (не используя соответствующие классы и функции стандартной библиотеки) организовать структуру данных Heap для хранения целых чисел, над которой определены следующие операции: a) Insert(k) – добавить в Heap число k ; b) Extract достать из Heap наибольшее число (удалив его при этом). */
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> heap;
    int c, n, r;
    cin >> r;
    for (int i = 0; i < r; i++)
    {
        cin >> c;
        if (c == 0)
        {
            cin >> n;
            heap.push_back(n);
            int index = heap.size() - 1;
            while (heap[index] > heap[(index - 1) / 2])
            {
                swap(heap[index], heap[(index - 1) / 2]);
                index = (index - 1) / 2;
            }
        }
        if (c == 1)
        {
            cout << heap[0] << endl;
            heap[0] = heap.back();
            heap.pop_back();
            int index = 0;
            while (true)
            {
                int left = index * 2 + 1;
                int right = index * 2 + 2;
                int lagest = index;
                if (left < heap.size() && heap[left] > heap[index])
                {
                    lagest = left;
                }
                if (right < heap.size() && heap[right] > heap[lagest])
                {
                    lagest = right;
                }
                if (lagest == index)
                {
                    break;
                }
                swap(heap[index], heap[lagest]);
                index = lagest;
            }
        }
    }
}