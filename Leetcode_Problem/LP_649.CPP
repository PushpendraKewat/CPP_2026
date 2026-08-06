// method 2
class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.length();

        queue<int> r;
        queue<int> d;

        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R')
                r.push(i);
            else
                d.push(i);
        }

        while (!r.empty() && !d.empty()) {
            int ri = r.front();
            r.pop();

            int di = d.front();
            d.pop();

            if (ri < di) {
                r.push(ri + n);
            } else {
                d.push(di + n);
            }
        }

        return r.empty() ? "Dire" : "Radiant";
    }
}; 

// method 1

class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.length();

        queue<int> q;
        queue<int> r;
        queue<int> d;

        for (int i = 0; i < n; i++) {
            q.push(i);
            if (senate[i] == 'D')
                d.push(i);
            else
                r.push(i);
        }

        while (!q.empty()) {
            int idx = q.front();
            q.pop();

            if (senate[idx] == 'X')
                continue;

            while (!r.empty() && senate[r.front()] == 'X')
                r.pop();

            while (!d.empty() && senate[d.front()] == 'X')
                d.pop();

            if (senate[idx] == 'R') {
                if (d.empty())
                    return "Radiant";

                senate[d.front()] = 'X';
                d.pop();

                q.push(idx);
                r.push(idx);
                r.pop();
            }
            else {
                if (r.empty())
                    return "Dire";

                senate[r.front()] = 'X';
                r.pop();

                q.push(idx);
                d.push(idx);
                d.pop();
            }
        }

        return "";
    }
}