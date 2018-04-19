#include <iostream>
#include <QVector>

using namespace std;

QVector<QVector<int>> input(const int& m, const int& n)
{
    QVector<QVector<int>> tempSet;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            char temp;
            cin >> temp;
            if (temp != '#' && temp != '.') temp = '#';
            if (temp == '#') tempSet.push_back(QVector<int> {i,j,0});
        }
    }
    return tempSet;
}

void recSearch(const int& i0, const int& i1, const int& i2, QVector<QVector<int>>& cells)
{
    int f = cells.indexOf(QVector<int> {i0, i1, 0});
    if (f == -1) return;
    else
    {
        cells[f][2] = i2;
        recSearch(cells[f][0] - 1, cells[f][1], cells[f][2], cells);
        recSearch(cells[f][0] + 1, cells[f][1], cells[f][2], cells);
        recSearch(cells[f][0], cells[f][1] - 1, cells[f][2], cells);
        recSearch(cells[f][0], cells[f][1] + 1, cells[f][2], cells);
    }
}

int calcParts(QVector<QVector<int>>& cells)
{
    int parts = 0;
    for (auto &i: cells)
    {
        if (i[2] == 0)
        {
            parts += 1;
            i[2] = parts;
//            cout << i[0] << i[1] << i[2] << endl;
            recSearch(i[0] - 1, i[1], i[2], cells);
            recSearch(i[0] + 1, i[1], i[2], cells);
            recSearch(i[0], i[1] - 1, i[2], cells);
            recSearch(i[0], i[1] + 1, i[2], cells);
        }
    }
    return parts;
}

int main()
{
    int m, n;
    cin >> m >> n;
    QVector<QVector<int>> cells = input(m, n);
    cout << calcParts(cells) << endl;

    return 0;
}
