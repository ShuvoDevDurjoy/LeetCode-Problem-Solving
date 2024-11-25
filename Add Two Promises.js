/**
 * @param {Promise} promise1
 * @param {Promise} promise2
 * @return {Promise}
 */
var addTwoPromises = async function(promise1, promise2) {
    // Wait for both promises to resolve and store the results
    const x = await promise1;
    const y = await promise2;
    
    // Return the sum
    return x + y;
};

/**
 * Example usage:
 * addTwoPromises(Promise.resolve(2), Promise.resolve(2))
 *   .then(console.log); // 4
 */
