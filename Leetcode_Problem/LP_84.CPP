class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> Nsi(n), Psi(n);
        stack<int> st;

        // Next Smaller Element/Index (Right to left)
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if(st.empty()) Nsi[i] = n;
            else Nsi[i] = st.top();

            st.push(i);
        }

        // clear stack
        while(!st.empty()) st.pop();

        //  Previous Smaller Element/Index (Left to right)
        for(int i = 0; i < n; i++) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if(st.empty()) Psi[i] = -1;
            else Psi[i] = st.top();

            st.push(i);
        }

        //  Calculate max area
        int maxArea = 0;
        for(int i = 0; i < n; i++) {
            int width = Nsi[i] - Psi[i] - 1;
            int area = heights[i] * width;
            maxArea = std::max(maxArea, area);
        }

        return maxArea;
    }
};