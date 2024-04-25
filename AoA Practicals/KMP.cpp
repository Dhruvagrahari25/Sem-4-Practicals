#include <iostream>
#include <vector>

using namespace std;

// Function to compute LPS (Longest Proper Prefix which is also a Suffix) array
vector<int> computeLPS(const string& pat) {
  int m = pat.size();
  vector<int> lps(m);
  int len = 0;  // length of the previous longest prefix suffix

  lps[0] = 0;  // lps[0] is always 0

  // the loop calculates lps[i] for i = 1 to m-1
  int i = 1;
  while (i < m) {
    if (pat[i] == pat[len]) {
      len++;
      lps[i] = len;
      i++;
    } else {
      // This is tricky. Consider the example "ABABDAB"
      // Also, note that we do not increment i here
      if (len != 0) {
        len = lps[len - 1];
      } else {
        lps[i] = 0;
        i++;
      }
    }
  }
  return lps;
}

// KMP Algorithm for Pattern Searching
void KMPSearch(const string& txt, const string& pat) {
  int n = txt.size();
  int m = pat.size();

  // create lps array for pattern
  vector<int> lps = computeLPS(pat);

  int i = 0;  // index for txt[]
  int j = 0;  // index for pat[]

  while (i < n) {
    if (pat[j] == txt[i]) {
      j++;
      i++;
    }

    if (j == m) {
      cout << "Found pattern at index " << i - j << endl;
      j = lps[j - 1];
    } else if (i < n && pat[j] != txt[i]) {
      // Do not match lps[0..lps[j-1]] characters,
      // they will match anyway
      if (j != 0) {
        j = lps[j - 1];
      } else {
        i = i + 1;
      }
    }
  }
}

int main() {
  string txt = "";
  string pat = "";
  cout<<"Enter the string anf pattern:\n";
  std::cin >> txt;
  std::cin >> pat;
  KMPSearch(txt, pat);
  return 0;
}
