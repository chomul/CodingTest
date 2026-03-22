#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;

    unordered_set<char> skill_set(skill.begin(), skill.end());

    for (int i = 0; i < skill_trees.size(); i++)
    {
        int skill_idx = 0;
        int skill_tree_idx = 0;
        bool is_found = false;
        
        while (skill_tree_idx != skill_trees[i].size())
        {
            // 스킬트리에 없는 스킬들 무시
            if (skill_set.find(skill_trees[i][skill_tree_idx]) == skill_set.end())
            {
                skill_tree_idx++;
                is_found = true;
                continue;
            }
            
            if (skill[skill_idx] == skill_trees[i][skill_tree_idx])
            {
                // 같으면 계속 검증
                skill_idx++;
                skill_tree_idx++;
                is_found = true;
            }
            else
            {
                is_found = false;
                break;
            }
        }

        if (is_found)
        {
            answer++;
        }
    }

    return answer;
}