class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {

        vector<vector<int>> v(m, vector<int>(n, -1));

        int minr = 0;
        int maxr = m - 1;
        int minc = 0;
        int maxc = n - 1;

        ListNode* temp = head;

        while (minr <= maxr && minc <= maxc && temp != nullptr) {

            // left to right
            for (int j = minc; j <= maxc && temp != nullptr; j++) {
                v[minr][j] = temp->val;
                temp = temp->next;
            }
            minr++;

            // top to bottom
            for (int i = minr; i <= maxr && temp != nullptr; i++) {
                v[i][maxc] = temp->val;
                temp = temp->next;
            }
            maxc--;

            // right to left
            if (minr <= maxr) {
                for (int j = maxc; j >= minc && temp != nullptr; j--) {
                    v[maxr][j] = temp->val;
                    temp = temp->next;
                }
                maxr--;
            }

            // bottom to top
            if (minc <= maxc) {
                for (int i = maxr; i >= minr && temp != nullptr; i--) {
                    v[i][minc] = temp->val;
                    temp = temp->next;
                }
                minc++;
            }
        }

        return v;
    }
};