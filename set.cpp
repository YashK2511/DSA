#include<iostream>
using namespace std;

class SET {
public:
    void input_set(int set[], int &size);
    void display(int set[], int size);
    void add_element(int ele, int set[], int &size);
    void remove_element(int ele, int set[], int &size);
    void search_element(int ele, int set[], int size);
    void union_set(int seta[], int size1, int setb[], int size2);
    void intersection_set(int seta[], int size1, int setb[], int size2);
    void diffrence_set(int seta[], int size1, int setb[], int size2);
    void is_subset(int seta[], int size1, int setb[], int size2);
};

void SET::input_set(int set[], int &size) {
    cout << "Enter number of total elements in set: ";
    cin >> size;
    for (int i = 0; i < size; i++) {
        cout << "Enter element " << i+1 << ": ";
        cin >> set[i];
    }
}

void SET::display(int set[], int size) {
    cout << "Displaying set: ";
    for (int i = 0; i < size; i++) {
        cout << set[i] << " ";
    }
    cout << endl;
}

void SET::add_element(int ele, int set[], int &size) {
    cout << "Enter the element to add: ";
    cin >> ele;
    for (int i = 0; i < size; i++) {
        if (set[i] == ele) {
            cout << "Element already present..." << endl;
            return;
        }
    }
    set[size++] = ele;
    cout << "Element added successfully..." << endl;
}

void SET::remove_element(int ele, int set[], int &size) {
    cout << "Enter element to remove: ";
    cin >> ele;
    int pos = -1;
    for (int i = 0; i < size; i++) {
        if (set[i] == ele) {
            pos = i;
            break;
        }
    }
    if (pos == -1) {
        cout << "Element cannot be found..." << endl;
    } else {
        for (int i = pos; i < size - 1; i++) {
            set[i] = set[i + 1];
        }
        size--;
        cout << "Element removed successfully..." << endl;
    }
}

void SET::search_element(int ele, int set[], int size) {
    cout << "Enter element to search: ";
    cin >> ele;
    for (int i = 0; i < size; i++) {
        if (set[i] == ele) {
            cout << "Element " << ele << " found..." << endl;
            return;
        }
    }
    cout << "Element cannot be found..." << endl;
}

void SET::union_set(int seta[], int size1, int setb[], int size2) {
    int result[40], res = 0;

    for (int i = 0; i < size1; i++) {
        result[res++] = seta[i];
    }

    for (int i = 0; i < size2; i++) {
        bool found = false;
        for (int j = 0; j < size1; j++) {
            if (setb[i] == seta[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            result[res++] = setb[i];
        }
    }

    cout << "Union result: ";
    for (int i = 0; i < res; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
}

void SET::intersection_set(int seta[], int size1, int setb[], int size2) {
    int result[20], res = 0;
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (seta[i] == setb[j]) {
                result[res++] = seta[i];
                break;
            }
        }
    }
    cout << "Intersection result: ";
    for (int i = 0; i < res; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
}

void SET::diffrence_set(int seta[], int size1, int setb[], int size2) {
    int result[20], res = 0;
    for (int i = 0; i < size1; i++) {
        bool found = false;
        for (int j = 0; j < size2; j++) {
            if (seta[i] == setb[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            result[res++] = seta[i];
        }
    }

    cout << "Difference A - B: ";
    for (int i = 0; i < res; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
}

void SET::is_subset(int seta[], int size1, int setb[], int size2) {
    for (int i = 0; i < size1; i++) {
        bool found = false;
        for (int j = 0; j < size2; j++) {
            if (seta[i] == setb[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Set A is NOT a subset of Set B." << endl;
            return;
        }
    }
    cout << "Set A is a subset of Set B." << endl;
}

int main() {
    SET s;
    int set1[20], set2[20], n1, n2;

    cout << "Input for Set A:\n";
    s.input_set(set1, n1);
    s.display(set1, n1);

    cout << "\nInput for Set B:\n";
    s.input_set(set2, n2);
    s.display(set2, n2);

    s.union_set(set1, n1, set2, n2);
    s.intersection_set(set1, n1, set2, n2);
    s.diffrence_set(set1, n1, set2, n2);
    s.is_subset(set1, n1, set2, n2);

    s.add_element(0, set1, n1);
    s.display(set1, n1);

    s.remove_element(0, set1, n1);
    s.display(set1, n1);

    s.search_element(0, set1, n1);

    return 0;
}

