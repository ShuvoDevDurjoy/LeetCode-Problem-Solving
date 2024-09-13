class Solution {
    public int[] xorQueries(int[] arr, int[][] queries) {
        int qsize = queries.length ; 
        int size = arr.length ; 
        for(int i = 1 ;i < size ; ++i){
            arr[i] = arr[i-1]^arr[i] ; 
        }

        for(int i = 0 ; i < size ; ++i){
            System.out.println(arr[i]) ; 
        }
        int[] ans = new int[qsize] ;
        for(int i = 0 ; i < qsize ; ++i){
            ans[i] = arr[queries[i][1]] ^ (queries[i][0]==0?0:arr[queries[i][0]-1]);
        } 
        return ans ;
    }
}
