#include <bits/stdc++.h>
using namespace std;

int main() {

    while (1) {
        system("r.exe > a.in");
        system("std.exe < a.in > a_std.out");
        system("a.exe < a.in > a.out");
        if (system("fc a_std.out a.out")) break;
    }

    return 0;
}