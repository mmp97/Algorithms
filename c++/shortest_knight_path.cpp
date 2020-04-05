#include <vector>
using namespace std;
int knight(string start,string finish)
{
    int a=start[0]-96;
    int b=start[1]-'0';
    int res=0;
    vector <int> moves= {1,2,-1,2,1,-2,-1,-2,2,1,-2,1,2,-1,-2,-1};
    start:
    vector <int> history;
    history.push_back(a);
    history.push_back(b);
    for(int i=0; i<history.size(); i+=2)
    {
        for(int j=0; j<moves.size(); j+=2)
        {
            int a=history[i]+moves[j];
            int b=history[i+1]+moves[j+1];
            if(a==finish[0]-96&&b==finish[1]-'0')
            {
                char c=history[i]+96;
                char d=history[i+1]+'0';
                finish[0]=c;
                finish[1]=d;
                res++;
                if(start==finish)
                {
                    return res;
                }
                else 
                    goto start;
            }
            if(a<=8&&a>=1&&b<=8&&b>=1)
            {
                history.push_back(a);
                history.push_back(b);
            }
        }
    }
}
