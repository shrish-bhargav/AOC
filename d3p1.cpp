#include <iostream>
#include <fstream>
#include <regex>
#include <string>

using namespace std;

int answer(const string &mull)
{
  regex reg(R"(mul\((\d+),(\d+)\))");
  int prod, first, second;
  smatch match;
  if (regex_match(mull, match, reg))
  {
    first = stoi(match[1].str());
    second = stoi(match[2].str());
  }
  prod = first*second;
  return prod;
}

int mull_regex_search(const string &line)
{
  int sumEach = 0;
  regex regexPattern(R"(mul\(\d{1,3},\d{1,3}\))");

  auto matches_begin = sregex_iterator(line.begin(), line.end(), regexPattern);
  auto matches_end = sregex_iterator();

  for (sregex_iterator it = matches_begin; it != matches_end; ++it)
  {
    smatch match = *it;
    sumEach+= answer(match.str());
  }
  return sumEach;
}

int main()
{
  ifstream file("input.txt");

  if (!file.is_open())
  {
    cerr << "Error opening the file";
    return 1;
  }

  string line;
  int sum = 0;
  vector<int> answer;

  while (getline(file, line))
  {
    sum+=mull_regex_search(line);
  }
  cout << sum << endl;
  file.close();
  return 0;
}
