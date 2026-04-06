#ifndef HVLCS_H
#define HVLCS_H

#include <string>
#include <unordered_map>
#include <utility>

using namespace std;

pair<int, string> computeHVLCS(
    const string& a,
    const string& b,
    const unordered_map<char, int>& values
);

#endif