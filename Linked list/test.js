function flipping(arr,k){
    var result = 0;
    var start = 0;
    var back = 0;
    var flag = true;
    var dup_k = k;
    var prev = -1;
    
    function assignPrev(index){
        while(arr[index] == 0){
            index++;
        }
        prev = index;
    }
    
    while(back<arr.length){
        if(arr[back] == 0 && dup_k > 0){
            dup_k--;
            if(flag){
                assignPrev(back);
                flag = false;
            }
        }
        else if(arr[back] == 0 && dup_k == 0){
            result = Ma
        }
    }
}