class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result(nums1.size(), -1);
        if (nums1.size() == 0) return result;
        for(int i = 0; i < nums1.size(); i++)
        {
            for(int j = 0; j <nums2.size(); j++)
            {
                if(nums1[i]==nums2[j])
                {
                    int index = j+1;
                    while(index < nums2.size())
                    {
                        if(nums2[index]>nums2[j])
                        {
                            result[i] = nums2[index];
                            break;
                        }
                        index++;
                    }
                    break;
                }

            }
        }
        return result;
    }
};





class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result(nums1.size(), -1);
        stack<int> st;
        if (nums1.size() == 0) return result;

        unordered_map<int, int> umap;
        for (int i = 0; i < nums1.size(); i++) 
        {
            umap[nums1[i]] = i;
        }
        st.push(0);
        for (int i = 1; i < nums2.size(); i++) 
        {
            if (nums2[i] < nums2[st.top()]) 
            {
                st.push(i);
            } 
            else if (nums2[i] == nums2[st.top()]) 
            {
                st.push(i);
            }
            else 
            {
                while (!st.empty() && nums2[i] > nums2[st.top()]) 
                {
                    if (umap.count(nums2[st.top()]) > 0) 
                    {
                        int index = umap[nums2[st.top()]];
                        result[index] = nums2[i];
                    }
                    st.pop();
                }
                st.push(i);
            }
        }
        return result;
    }
};