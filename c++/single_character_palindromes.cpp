#include <string>
bool palindrome(std::string s){
  for(int i = 0; i < s.length(); i++){
    if(s[i] != s[s.length()-i-1] )
      return false;
  }
  return true;
}
bool remove(std::string s){
  for(int i = 0; i < s.length(); i++){
    char temp = s[i];
    s.erase(i,1);
    if(palindrome(s) )
      return true;
    s.insert(s.begin() + i,temp);
    } 
  return false;
}
std::string solve(std::string s){
  if(palindrome(s) )
    return "OK";
  else if(remove(s) )
    return "remove one";
  else
    return "not possible";
}
