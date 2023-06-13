#include <iostream>
#include <vector>

using namespace std;

int NDD(int x) {
    int num_divisors = 0;
    for (int i = 1; i <= x; i++) {
        if (x % i == 0) {
            num_divisors++;
        }
    }
    return num_divisors;
}

int calculateSequenceTerm(int i, vector<int>& sequence) {
    if (i == 0) {
        sequence.push_back(1);
        return 1;
    }
    int prev_term = calculateSequenceTerm(i - 1, sequence);
    int num_divisors = NDD(prev_term);
    int next_term = prev_term + num_divisors;
    sequence.push_back(next_term);
    return next_term;
}

int countNumbersInRange(int A, int B, vector<int>& sequence, int i = 0) {
    int count = 0;
    if (i < sequence.size()) {
        int x = sequence[i];
        if (x >= A && x <= B) {
            count++;
        }
        count += countNumbersInRange(A, B, sequence, i + 1);
    }
    return count;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int A, B;
        cin >> A >> B;
        vector<int> sequence;
        calculateSequenceTerm(B, sequence);
        int count = countNumbersInRange(A, B, sequence);
        cout << count << endl;
    }
    return 0;
}
