#include <string>
#include <vector>
class WeightSort
{
public:
  static std::string orderWeight(const std::string &strng);
  static bool alphanum_sort(std::string str1, std::string str2);
  static int sum(std::string str);
};
bool WeightSort::alphanum_sort(std::string str1, std::string str2)
{
  int len;
  if (str1.length() > str2.length())
    len = str2.length();
  else
    len = str1.length();
  for (int i = 0; i < len; i++)
  {
    if (str2[i] < str1[i])
      return true;
    else if (str2[i] > str1[i])
      return false;
    else if (str2[i] == str1[i] && i == len - 1)
    {
      if (len == str2.length())
        return true;
      else
        return false;
    }
  }
  return false;
}
int WeightSort::sum(std::string str)
{
  int sum = 0;
  for (int i = 0; i < str.length(); i++)
  {
    sum += str[i] - 48;
  }
  return sum;
}
std::string WeightSort::orderWeight(const std::string &string)
{
  if (string == "")
    return "";
  std::string strng = string;
  size_t found = strng.find(' ');
  std::string number;
  std::vector<std::string> numbers;
  std::vector<int> sum_numbers;
  if (found == std::string::npos)
    return strng;
  while (found != std::string::npos)
  {
    found = strng.find(' ');
    number = strng.substr(0, found);
    strng.erase(0, found + 1);
    numbers.push_back(number);
    sum_numbers.push_back(sum(number));
    if (numbers[numbers.size() - 1] == "" || sum_numbers[sum_numbers.size() - 1] == 0)
    {
      numbers.erase(numbers.end() - 1);
      sum_numbers.erase(sum_numbers.end() - 1);
    }
  }
  strng = "";
  for (int i = 0; i < sum_numbers.size(); i++)
    for (int j = 0; j < sum_numbers.size() - 1; j++)
    {
      if (sum_numbers[j] > sum_numbers[j + 1])
      {
        std::swap(numbers[j], numbers[j + 1]);
        std::swap(sum_numbers[j], sum_numbers[j + 1]);
      }
      else if (sum_numbers[j] == sum_numbers[j + 1] && alphanum_sort(numbers[j], numbers[j + 1]))
      {
        std::swap(numbers[j], numbers[j + 1]);
      }
    }
  for (auto &a : numbers)
  {
    strng += a + " ";
  }
  strng.erase(strng.end() - 1);
  return strng;
}
