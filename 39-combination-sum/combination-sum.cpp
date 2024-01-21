class Solution {
private:
    void combination(int i , vector<vector<int>> & ans, vector<int> & ds , vector<int> &candidates, int &target ){
        if(i== candidates.size()){
            if(target == 0){
                ans.push_back(ds);
                return ;
            }
            return ;
        }
        if(candidates[i] <= target){
            ds.push_back(candidates[i]);
            int a = target - candidates[i] ;
            combination(i, ans, ds, candidates , a  );
            ds.pop_back();
        }
        combination(i+1 ,ans , ds, candidates, target) ;


        
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans ;
        vector<int> ds ;
        combination(0 ,ans, ds , candidates, target );
         
        return ans;
    }
};