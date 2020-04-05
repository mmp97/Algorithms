#include <string>
#include <unordered_map>
#include <vector>
#include <sstream>

static int getReg(std::unordered_map<std::string, int>& regs, std::string name)
{
  if(isalpha(name[6]) ){
    std::string adx(1, name[6]);
    return regs[adx];
  }
  int val = 0;
  std::stringstream g(name.substr(6, name.length() ) );
  g >> val;
  return val;
}

std::unordered_map<std::string, int> assembler(const std::vector<std::string>& program)
{
  std::unordered_map <std::string, int> regs{};
  for(unsigned long i = 0; i < program.size(); i++){
    std::string idx(1, program[i][4]);
    if(program[i].find("jnz") != std::string::npos){
      if(isalpha(program[i][4]) ){
        if(regs[idx] != 0)
          i += getReg(regs,program[i])-1;
      }
      else if(program[i][4] != 0)
        i += getReg(regs,program[i])-1;
    }
    else if(program[i].find("mov") != std::string::npos)
      regs.insert_or_assign(idx,getReg(regs,program[i]) );
    else if(program[i].find("inc") != std::string::npos)
      regs[idx]++;
    else if(program[i].find("dec") != std::string::npos)
      regs[idx]--;
  }
  return  regs;
}
