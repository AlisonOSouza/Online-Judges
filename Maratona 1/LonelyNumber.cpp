#include <iostream>
#include <map>

using namespace std;

int main()
{
    int i, n;
    string s;
    
    std::cin >> n;
    while(n > 0)
    {
        map <string, int> m_p;
        for(i = 0; i < n; i++)
        {
            std::cin >> s;
            m_p[s]++;
        }
    
        for(map <string, int >::iterator it = m_p.begin();
            it != m_p.end(); it++)
        {
            if((it->second) % 2 == 1)
            {
                std::cout << it->first << endl;
                break;
            }
        }
        std::cin >> n;
    }
    return 0;
}