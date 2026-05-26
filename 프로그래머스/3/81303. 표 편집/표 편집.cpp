#include <string>
#include <vector>
#include <stack>

using namespace std;

struct Node{

    int data;
    Node* next;
    Node* prev;

};

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    stack<int> deleted; 

    vector<Node*> node(n);

    for(int i = 0; i < n; i++)
    {
        node[i] = new Node();   
        node[i]->data = i;
    }
    
    
    for(int i = 0; i < n; i++)
    {
        if(i > 0){
            node[i]->prev = node[i - 1];
        }
        if(i < n - 1){
            node[i]->next = node[i + 1];    
        }
    }
    
    
    Node* curr = node[k];
		// 정답 출력용 bool 배열
    vector<bool> remained(n, true);

    for(int i = 0; i < cmd.size(); i++){
        if(cmd[i][0] == 'U'){
            int move = stoi(cmd[i].substr(2));
            while(move-- > 0){
                curr = curr->prev;
            }
        }else if(cmd[i][0] == 'D'){
            int move = stoi(cmd[i].substr(2));
            while(move-- > 0){
                curr = curr->next;
            }
        }else if(cmd[i][0] == 'C'){

            deleted.push(curr->data);
            remained[curr->data] = false;

            if(curr->prev){
                curr->prev->next = curr->next;
            }
            if(curr->next){
                curr->next->prev = curr->prev;
            }

            if(curr->next){
                curr = curr->next;
            }else{
                curr = curr->prev;
            }

        }else if(cmd[i][0] == 'Z'){
            int row = deleted.top();
            deleted.pop();
            remained[row] = true;
            if(node[row]->prev){
                node[row]->prev->next = node[row];
            }
            if(node[row]->next){
                node[row]->next->prev = node[row];
            }
        }
    }

    for(int i = 0; i < remained.size(); i++){
        if(remained[i]){
            answer += 'O';
        }else{
            answer += 'X';
        }
    }

    
    
    
    
    
    return answer;
}