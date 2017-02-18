/**
 * Created by ayou on 2017/2/18.
 */

function getMinNum(str) {
    // 找到最右边最小非0数的位置，该数一定要放到最左边
    var rightMinPos, rightMin=9;
    for (var i=0;i<str.length;i++) {
        if (str[i] != '0' && rightMin >= parseInt(str[i])) rightMin = str[rightMinPos = i];
    }

    // 遍历str
    var ret = str[0];
    for (var i=1;i<str.length;i++) {
        // 最右边最小非0数放到结果的左边
        if (i===rightMinPos) ret = str[i] + ret;
        else if (i < rightMinPos) {
            // 当前数小于第一位，放到左边
            if (str[i] <= ret[0]) ret = str[i] + ret;
            else ret = ret + str[i];
        }
        // 最右边最小非0数右边的数全部放到结果右边
        else ret = ret + str[i];
    }
    return ret;
}

console.log(getMinNum('98754610123'));
console.log(getMinNum('98754610243'));