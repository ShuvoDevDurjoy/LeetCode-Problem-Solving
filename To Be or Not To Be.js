/**
 * @param {string} val
 * @return {Object}
 */
var expect = function(val) {
    return {
        toBe : (m)=>
        {
            if(m!==val) {
                throw new Error("Not Equal") ;
            }
            else {
                return true ; 
            }
        },

        notToBe : (m)=>{
            if(m===val) {
                throw new Error("Equal") ;
        }
        else {
            return true ; 
        } 
    }
    }
};

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */
