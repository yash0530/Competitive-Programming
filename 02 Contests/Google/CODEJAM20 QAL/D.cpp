#include <bits/stdc++.h>
using namespace std;

int ask(int p) {
	int val;
	cout << p << endl;
	fflush(stdout);
	cin >> val;
	return val;
}

int t, b;
int arr[150];
int samepair, diffpair;

void printRes() {
    for (int i = 0; i < b; i++) {
        cout << arr[i];
    } cout << endl;
    fflush(stdout);
    char x; cin >> x;
    if (x == 'N') {
        exit(0);
    }
}

void reverse() {
    int i = 0, j = b - 1;
    while (i < j) {
        swap(arr[i], arr[j]);
        i++; j--;
    }
}

void comp() {
	for (int i = 0; i < b; i++) {
        arr[i] = 1 - arr[i];
    }
}

void findpair(int i) {
    arr[i] = ask(i + 1);
    arr[b - i - 1] = ask(b - i);
    if ((samepair == -1) and (arr[i] == arr[b - i - 1])) {
        samepair = i;
    }
    if ((diffpair == -1) and (arr[i] != arr[b - i - 1])) {
        diffpair = i;
    }
}

void makechanges() {
    bool cmp = false;
    if (samepair != -1) {
        if (ask(samepair + 1) != arr[samepair]) {
            cmp = true;
        }
    } else ask(1);
    bool rev = cmp;
    if (diffpair != -1) {
        if (ask(diffpair + 1) != arr[diffpair]) {
            rev = !cmp;
        }
    } else ask(1);

    if (rev) reverse();
    if (cmp) comp();
}

int32_t main() {	
    cin >> t >> b;
    while (t--) {
        int i;
        samepair = -1; diffpair = -1;
        for (i = 0; i < 5; i++) {
            findpair(i);
        }
        makechanges();
        while (i < (b / 2)) {
            int x;
            for (x = 0; (i < (b / 2)) and (x < 4); i++, x++) {
                findpair(i);
            }
            if (x == 4)
                makechanges();
        }
        printRes();
    }
    return 0;
}

/*
0 0 . . . 0 1

* rev           => diffpair (swapped)   | samepair (same)
* comp          => diffpair (swapped)   | samepair (swapped)
* rev comp      => diffpair (same)      | samepair (swapped)
* none          => diffpair (same)      | smaepair (same)

*/