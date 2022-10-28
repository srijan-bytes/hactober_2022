class NumArray {
public:
    int n;
    vector<int> v;
    vector<int> seg;
    
    int sum(int ind, int low, int high, int left, int right)
    {
        if(low>=left&&high<=right){
            return seg[ind];
        }
        
        if(low>right||high<left) return 0;
        int mid=(low+high)/2;
        int a=sum(2*ind+1, low, mid, left, right);
        int b=sum(2*ind+2, mid+1, high, left, right);
        
        return a+b;
    }
    
    void build(int ind, int low, int high)
    {
        if(low==high){
            seg[ind]=v[low];
            return;
        }
        
        int mid=(low+high)/2;
        build(2*ind+1, low, mid);
        build(2*ind+2, mid+1, high);
        
        seg[ind]=seg[2*ind+1]+seg[2*ind+2];
    }
    
    void upd(int ind, int low, int high, int index, int val)
    {
        if(low==high&&low==index){
            seg[ind]=val;
            return;
        }
        
        int mid=(low+high)/2;
        if(index<=mid) upd(2*ind+1, low, mid, index, val);
        else upd(2*ind+2, mid+1, high, index, val);
        
        seg[ind]=seg[2*ind+1]+seg[2*ind+2];
        
    }
    
    NumArray(vector<int>& nums) {
        v=nums;
        n=v.size();
        seg=vector<int>(10*n+1,0);
        // cout<<n<<endl;
        build(0, 0, n-1);
    }
    
    void update(int index, int val) {
        upd(0, 0 , n-1, index, val);
    }
    
    int sumRange(int left, int right) {
        return sum(0, 0, n-1, left, right);
    }
};
