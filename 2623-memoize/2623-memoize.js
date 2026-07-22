/**
 * @param {Function} fn
 * @return {Function}
 */
function memoize(fn) {
    let cache={};
    return function(...args) {
        let x=JSON.stringify(args);
        if(x in cache){
         return cache[x];
        }else{
            let res=fn.apply(this,args);
            cache[x]=res;
            return res;
        }
    }
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */