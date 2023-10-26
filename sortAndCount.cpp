#include <bits/stdc++.h>
using namespace std;

int mergeAndCount(vector<int> &vec, int low, int mid, int high) {
  vector<int> merged;
  int count = 0;
  int i = low, j = mid + 1;

  while (i <= mid && j <= high) {
    if (vec[i] <= vec[j]) {
      merged.push_back(vec[i]);
      i++;
    } else {
      merged.push_back(vec[j]);
      j++;
      count += mid - i + 1;
    }
  }

  while (i <= mid) {
    merged.push_back(vec[i]);
    i++;
  }

  while (j <= high) {
    merged.push_back(vec[j]);
    j++;
  }

  for (int k = low; k <= high; k++) {
    vec[k] = merged[k - low];
  }

  return count;
}

int sortAndCount(vector<int> &vec, int low, int high) {
  if (low >= high) {
    return 0;
  }

  int mid = (low + high) / 2;
  int count = 0;

  count += sortAndCount(vec, low, mid);
  count += sortAndCount(vec, mid + 1, high);
  count += mergeAndCount(vec, low, mid, high);

  return count;
}

int main() {
  vector<int> vec{3, 7, 10, 14, 18, 19, 2, 11, 16, 17, 23, 25};
  int result = sortAndCount(vec, 0, vec.size() - 1);
  cout << "Sorted list: ";
  for (int i = 0; i < vec.size(); i++) {
    cout << vec[i] << " ";
  }
  cout << endl;
  cout << "Inversions: " << result << endl;
  return 0;
}
