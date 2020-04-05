#include <string>
#include <vector>
#include <unordered_map>
class RGBToHex
{
  public:
  static std::string rgb(int r, int g, int b);
  static std::unordered_map<int, std::string> IntToHex;
};

std::unordered_map<int, std::string> RGBToHex::IntToHex 
{
  {0, "0"},{1, "1"},{2, "2"},{3, "3"},
  {4, "4"},{5, "5"},{6, "6"},{7, "7"},
  {8, "8"},{9, "9"},{10, "A"},{11, "B"},
  {12, "C"},{13, "D"},{14, "E"},{15, "F"}
};

std::string RGBToHex::rgb(int r, int g, int b)
{
  std::string result=""; 
  for (int v : {r,g,b})
  {
    v =(v < 0)?0:(v > 255)?255:v;
    int Low=v%16;
    int High=(v-Low)/16;
    result+=IntToHex[High]+IntToHex[Low]; 
  }
  return result;
}
