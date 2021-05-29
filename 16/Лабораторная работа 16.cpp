

/*#include <iostream>
#include <fstream>
using namespace std;

void mergeSortRec(int* v, int r, int t) {
    int p = 1;
    int k = 1;
    int i = 0;
    bool flag = false;
    while (v[i] <= v[i + 1] && i < r - 1) {
        p++;
        i++;
    }
    if (v[i] > v[i + 1] && i < r - 1) {
        i++;
        flag = true;
        while (v[i] <= v[i + 1] && i < r - 1) {
            k++;
            i++;
        }
    }
    int num = i + 1;
    int* a = new int[p];
    int* b = new int[k];
    for (i = 0; i < p; i++) {
        a[i] = v[i];
    }
    int g = 0;
    if (flag == true) {
        for (i = p; i < p + k; i++) {
            b[g] = v[i];
            g++;
        }
    }
    int l = 0;
    int j = 0;
    if (flag == true) {
        for (i = 0; i < num; i++) {
            if ((a[l] < b[j] || j >= k) && l < p) {
                v[i] = a[l];
                l++;
            }
            else {
                if ((a[l] > b[j] || l >= p) && j < k) {
                    v[i] = b[j];
                    j++;
                }
                else {
                    if (a[l] == b[j] && j < k && l < p) {
                        v[i] = a[l];
                        v[i + l] = b[j];
                        l++;
                        j++;
                        i++;
                    }
                }
            }
        }
    }
    delete[] a;
    delete[]b;
}
void mergeSort1(int* v, int r, int i) {
    if (i < r) {
        mergeSortRec(v, r, i);//Cортировка
        mergeSort1(v, r, i + 1);//Рекурсия
    }
}
/*void Merge(int* A, int first, int last) {
    int start, final, j;
    int middle;
    int* mas = new int[100];
    middle = (first + last) / 2;
    start = first;
    final = middle + 1;
    for (j = first; j <= last; j++) {
        if ((start <= middle) && ((final > last) || (A[start] < A[final]))) {
            mas[j] = A[start];
            start++;
        }
        else {
            mas[j] = A[final];
            final++;
        }
        for (j = first; j <= last; j++) {
            A[j] = mas[j];
        }
        delete[]mas;
    }

}

void MergeSort(int* A, int first, int last) {
    if (first < last) {
        MergeSort(A, first, (first + last) / 2);
        MergeSort(A, (first + last) / 2 + 1, last);
        Merge(A, first, last);
    }
}
void MergeSort(int* a, int l, int r)
{
    if (l == r) return; // границы сомкнулись
    int mid = (l + r) / 2; // определяем середину последовательности
    // и рекурсивно вызываем функцию сортировки для каждой половины
    MergeSort(a, l, mid);
    MergeSort(a, mid + 1, r);
    int i = l;  // начало первого пути
    int j = mid + 1; // начало второго пути
    int* tmp = (int*)malloc(r * sizeof(int)); // дополнительный массив
    for (int step = 0; step < r - l + 1; step++) // для всех элементов дополнительного массива
    {
        // записываем в формируемую последовательность меньший из элементов двух путей
        // или остаток первого пути если j > r
        if ((j > r) || ((i <= mid) && (a[i] < a[j])))
        {
            tmp[step] = a[i];
            i++;
        }
        else
        {
            tmp[step] = a[j];
            j++;
        }
    }
    // переписываем сформированную последовательность в исходный массив
    for (int step = 0; step < r - l + 1; step++)
        a[l + step] = tmp[step];
}

int main()
{
    setlocale(LC_ALL, "rus");

    int q; 
   
    int op = 0;
    while (op != 4) {
        cout << endl << "1-Сортировка естественным слиянием" << endl << "2-Сортировка сбалансированным слиянием" << endl;
        cout << "3-Многофазное слияние" << endl << "4-Завершение работы" << endl << "Введите номер вашей операции:" << endl;
        cin >> op;
        while ((op < 0) || (op > 5)) {
            cout << "Введите номер вашей операции:" << endl;
            cin >> op;
        }
        if (op == 1) {
            cout << "Введите размер массива" << endl;
            cin >> q;
            int* arr = new int[q];
            for (int i = 0; i < q; i++) {
                cin >> arr[i];
            }
            mergeSort1(arr, q, 0);//вызов рекурсивной функции
            for (int i = 0; i < q; i++) {//вывод
                cout << arr[i] << " ";
            }
           
        }
        if (op == 2) {
            int i, w;
            cout << "Введите размер массива" << endl;
            cin >> w;
            int* A = new int[w];
            for (int i = 0; i < w; i++) {
                cin >> A[i];
            }
            MergeSort(A, 0, w - 1);//Вызов сортирующей функции
            for (i = 0; i < w; i++) {
                cout << A[i]<<" ";
            }
            delete[]A;
            cout << endl;
            
            
        }
        if (op == 3) {
			
				setlocale(LC_ALL, "Rus");
				/*int n;
				cin >> n;
				int* order = new int[n];
				cin >> order[0];
				int i = 1; int size = 1, row = 1;
				int* max = new int[n];

				while (i < n)
				{
					cin >> order[i];
					if (order[i - 1] <= order[i])
					{
						size++;
						i++;
					}
					else
					{
						max[row] = size;
						row++;
						i++;
						size = 1;
					}
				}
				max[row] = size;
				for (i = 1; i <= row; i++)
				{
					cout << max[i] << " " << i << endl;
				}

				int** F1 = new int* [row];
				for (int i = 1; i <= row; i++)
				{
					F1[i - 1] = new int[n];
				}
				i = 0;  int j = 0;
				int pos = 0;

				if (order[j] <= order[j + 1])
				{
					F1[i][pos] = order[j];
					pos++;
					j++;
				}
				while (j < n)
				{
					if (order[j] <= order[j + 1])
					{
						F1[i][pos] = order[j];
						j++;
						pos++;
					}
					else
					{
						F1[i][pos] = order[j];
						i++;
						pos = 0;
						j++;
					}
				}

				for (i = 0; i < row; i++)
				{
					for (j = 0; j < max[i + 1]; j++)
					{
						cout << F1[i][j] << "\t";
					}
					cout << endl;
				}

				int** F2 = new int* [row];
				for (int i = 1; i <= row; i++)
				{
					F2[i - 1] = new int[n];
				}
				int** F3 = new int* [row];
				for (int i = 1; i <= row; i++)
				{
					F3[i - 1] = new int[n];
				}
				for (i = 1; i <= 3; i++)
				{
					for (j = 0; j < max[i]; j++)
					{
						F2[i][j] = F1[i - 1][j];
					}
				}
				for (i = 1; i <= 2; i++)
				{
					for (j = 0; j < max[i]; j++)
					{
						F3[i][j] = F1[i + 2][j];

					}
				}
				//---------------------------------------------------
				int k = 0;
				system("cls");
				for (i = 1; i <= 3; i++)
				{
					k = 0;
					int* G = new int[n];
					for (j = 0; j <= max[i]; j++)
					{
						G[k] = F2[i][j];
						k++;
					}
					k--;
					for (j = 0; j <= max[i]; j++)
					{
						G[k] = F3[i][j];
						k++;
					}
					k--;
					MergeSort(G, 0, k - 1);
					for (j = 0; j < k; j++)
					{
						F1[i][j] = G[j];
					}
					for (j = 0; j < max[i]; j++)
					{
						F2[i][j] = F2[i + 3][j];
					}
					for (j = 0; j < max[i]; j++)
					{
						F3[i][j] = F3[i + 3][j];
					}
				}
				//---------------------------------------------------
				for (i = 1; i <= 2; i++)
				{
					k = 0;
					int* G = new int[n];
					for (j = 0; j <= max[i] * 2; j++)
					{
						G[k] = F1[i][j];
						k++;
					}
					k--;
					for (j = 0; j <= max[i]; j++)
					{
						G[k] = F2[i][j];
						k++;
					}
					k--;
					MergeSort(G, 0, k - 1);
					for (j = 0; j < k; j++)
					{
						F3[i][j] = G[j];
					}
					for (j = 0; j < max[i] * 2; j++)
					{
						F1[i][j] = F1[i + 2][j];
					}
					for (j = 0; j < max[i]; j++)
					{
						F2[i][j] = F2[i + 2][j];
					}
				}
				//---------------------------------------------------
				for (i = 1; i <= 1; i++)
				{
					k = 0;
					int* G = new int[n];
					for (j = 0; j <= max[i] * 3; j++)
					{
						G[k] = F3[i][j];
						k++;
					}
					k--;
					for (j = 0; j <= max[i] * 2; j++)
					{
						G[k] = F1[i][j];
						k++;
					}
					k--;
					MergeSort(G, 0, k - 1);
					for (j = 0; j < k; j++)
					{
						F2[i][j] = G[j];
					}
					for (j = 0; j < max[i] * 2; j++)
					{
						F1[i][j] = F1[i + 1][j];
					}
					for (j = 0; j < max[i] * 3; j++)
					{
						F3[i][j] = F3[i + 1][j];
					}
				}
				//---------------------------------------------------
				for (i = 1; i <= 1; i++)
				{
					k = 0;
					int* G = new int[n];
					for (j = 0; j <= max[i] * 3; j++)
					{
						G[k] = F3[i][j];
						k++;
					}
					k--;
					for (j = 0; j <= max[i] * 5; j++)
					{
						G[k] = F2[i][j];
						k++;
					}
					k--;
					MergeSort(G, 0, k - 1);
					for (j = 0; j < k; j++)
					{
						F1[i][j] = G[j];
					}
				}
				for (i = 1; i <= 1; i++)
				{
					for (j = 0; j < max[i] * 8; j++)
					{
						cout << F1[i][j] << " ";
					}
					cout << endl;
				}
				system ("pause");
			}
           
        }
    
    return 0;
    
}
*/
#include <iostream>
#include <vector>
using namespace std;
void PrintVector(vector<int> vec)
{
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";
	cout << endl;
}
void PrintSeries(vector<vector<int>> series)
{
	for (int i = 0; i < series.size(); i++)
	{
		cout << "(";
		for (int j = 0; j < series[i].size(); j++) cout << series[i][j] << " ";
		cout << ")";
	}
	cout << endl;
}
vector<int> MergeSeries(vector<int> ser1, vector<int> ser2)
{
	int i = 0, j = 0;
	vector<int> res;
	while (i < ser1.size() && j < ser2.size())
	{
		if (ser1[i] < ser2[j])
		{
			res.push_back(ser1[i]);
			i++;
		}
		else
		{
			res.push_back(ser2[j]);
			j++;
		}
	}
	if (i < ser1.size()) for (int k = i; k < ser1.size(); k++) res.push_back(ser1[k]);
	else if (j < ser2.size()) for (int k = j; k < ser2.size(); k++) res.push_back(ser2[k]);
	return res;
}
vector<vector<int>> SplitToSeries(vector<int> vec)
{
	int i = 0;
	vector<vector<int>> res;
	while (i < vec.size())
	{
		vector<int> newSerie;
		newSerie.push_back(vec[i]);
		i++;
		while (i < vec.size() && vec[i - 1] < vec[i])
		{
			newSerie.push_back(vec[i]);
			i++;
		}
		res.push_back(newSerie);
	}
	return res;
}
vector<int> NaturalMergeSort(vector<int> vec)
{
	vector<vector<int>> series = SplitToSeries(vec);
	PrintSeries(series);
	while (series.size() > 1)
	{
		series.push_back(MergeSeries(series[0], series[1]));
		series.erase(series.begin(), series.begin() + 2);
		PrintSeries(series);
	}
	return series[0];
}
vector<int> BalancedMergeSort(vector<int> vec)
{
	if (vec.size() == 1) return vec;
	else if (vec.size() == 2)
	{
		if (vec[0] > vec[1]) swap(vec[0], vec[1]);
		return vec;
	}
	else
	{
		vector <int> new_vec1;
		vector <int> new_vec2;
		for (int i = 0; i < vec.size() / 2 + 1; i++) new_vec1.push_back(vec[i]);
		for (int i = vec.size() / 2 + 1; i < vec.size(); i++) new_vec2.push_back(vec[i]);
		return MergeSeries(BalancedMergeSort(new_vec1), BalancedMergeSort(new_vec2));
	}
}
void PrintFiles(vector<vector<int>> f1, vector<vector<int>> f2, vector<vector<int>>f3)
{
	cout << "F1 : ";
	PrintSeries(f1);
	cout << "F2 : ";
	PrintSeries(f2);
	cout << "F3 : ";
	PrintSeries(f3);
	cout << endl;
}
vector<int> DeleteEmptyElements(vector<int> vec, int num)
{
	for (int i = 0; i < num; i++) vec.pop_back();
	return vec;
}
void Fibbonachi(int numberOfSeries, int& size1, int& size2)
{
	size1 = 0;
	size2 = 1;
	while (size1 + size2 < numberOfSeries)
	{
		int t = size2;
		size2 = size2 + size1;
		size1 = t;
	}
}
vector<vector<int>> SplitToEqualSeries(vector<int> vec)
{
	int num = 2; //кол-во элементов в серии
	vector<vector<int>> res;
	int i = 0;
	vector<int> newSerie;
	while (i < vec.size())
	{
		if ((i + 1) % num == 0 || i == vec.size() - 1)
		{
			newSerie.push_back(vec[i]);
			res.push_back(newSerie);
			newSerie.clear();
		}
		else newSerie.push_back(vec[i]);
		i++;
	}
	return res;
}
vector<vector<int>> MergeFiles(vector<vector<int>>& f1, vector<vector<int>>& f2)
{
	vector<vector<int>> res;
	int minimum = f1.size() < f2.size() ? f1.size() : f2.size();
	for (int i = 0; i < minimum; i++)
	{
		res.push_back(MergeSeries(f1[i], f2[i]));
	}
	f1.erase(f1.begin(), f1.begin() + minimum);
	f2.erase(f2.begin(), f2.begin() + minimum);
	return res;
}
vector<int> PolyphaseMergeSort(vector<int> vec)
{
	vector<vector<int>> series = SplitToEqualSeries(vec);
	int size1, size2;
	Fibbonachi(series.size(), size1, size2);
	vector<vector<int>> F1, F2, F3; // files
	cout << "Разделение на серии" << endl;
	PrintSeries(series);
	for (int i = 0; i < size1; i++) F1.push_back(series[i]);
	for (int i = size1; i < series.size(); i++) F2.push_back(series[i]);
	for (int i = series.size(); i < size1 + size2; i++)
	{
		vector<int> serie;
		for (int j = 0; j < F2[0].size(); j++)
			serie.push_back(INT32_MAX);
		F2.push_back(serie);
	}
	cout << "Разделение серий на файлы" << endl;
	PrintFiles(F1, F2, F3);
	cout << "Сортировка элементов внутри файлов" << endl;
	for (int i = 0; i < F1.size(); i++) F1[i] = NaturalMergeSort(F1[i]);
	for (int i = 0; i < F2.size(); i++) F2[i] = NaturalMergeSort(F2[i]);
	PrintFiles(F1, F2, F3);
	cout << "Слияние файлов" << endl;
	int countEmptyFiles = 1;
	while (countEmptyFiles < 2)
	{
		int num = 1;
		if (F2.size() == 0) num = 2;
		if (F3.size() == 0) num = 3;
		switch (num)
		{
		case 1:
			F1 = MergeFiles(F2, F3);
			break;
		case 2:
			F2 = MergeFiles(F1, F3);
			break;
		case 3:
			F3 = MergeFiles(F1, F2);
			break;
		}
		countEmptyFiles = 0;
		if (F1.size() == 0) countEmptyFiles++;
		if (F2.size() == 0) countEmptyFiles++;
		if (F3.size() == 0) countEmptyFiles++;
		PrintFiles(F1, F2, F3);
	}
	if (F1.size() != 0) return DeleteEmptyElements(F1[0], size1 + size2 - series.size());
	if (F2.size() != 0) return DeleteEmptyElements(F2[0], size1 + size2 - series.size());
	return DeleteEmptyElements(F3[0], size1 + size2 - series.size());
}
int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Исходный вектор" << endl;
	vector<int> vec = { 9,3,1,6,4,2,8,7,0,5 };
	PrintVector(vec);
	cout << endl << "Сортировка методом естественного слияния" << endl;
	PrintVector(NaturalMergeSort(vec));
	cout << endl << "Сортировка методом сбалансированного слияния" << endl;
	PrintVector(BalancedMergeSort(vec));
	cout << endl << "Сортировка методом многофазного слияния" << endl;
	PrintVector(PolyphaseMergeSort(vec));
	system("pause");
}

