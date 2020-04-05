#include <algorithm> 
#include <vector> 
#include<string>
class Automaton
{
public:
  Automaton(){};
  bool read_commands(const std::vector<char>& commands);
};
bool Automaton::read_commands(const std::vector<char>& commands){  
  if (std::find(commands.begin(), commands.end(), '1') != commands.end() == false)
    return false;
  if (commands.size()>=2){
    if(*commands.rbegin() == '0' && *(commands.rbegin()+1) == '1')
      return false;
    else
      return true;
      }
  else
    return true;
}
