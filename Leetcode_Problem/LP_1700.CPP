class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        // insert studens into queue
        for(int i=0;i<students.size();i++){
            q.push(students[i]);
        }
        // now match q with sandwich
        int j = 0;
        int count = 0;
        while(!q.empty() && count<q.size()){
            if(q.front()==sandwiches[j]){
                j++;
                q.pop();
                count = 0;
            }
            else{
                q.push(q.front());
                q.pop();
                count++;
            }
        }
        return q.size();
    }
};