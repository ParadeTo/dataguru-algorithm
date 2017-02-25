/**
 * Created by ayou on 2017/2/25.
 */


var arr = [];
var sum = 0;

// 查询k位前是否存在item
function isInArray(item, k, arr) {
  for (var i=0;i<k;i++) {
    if (item===arr[i]) return true;
  }
  return false;
}

function isSatisfy(num) {
  for (var i=1;i<arr.length;i++) {
    const int = arr.join('').substr(0, i);
    const fraction = arr.join('').substr(i, 9-i);
    if (parseInt(int) > num) continue;
    for (var j=1;j<fraction.length;j++) {
      const numerator = fraction.substr(0, j);
      const denominator = fraction.substr(j, fraction.length-j);
      if (parseInt(numerator) % parseInt(denominator) === 0) {
        if (parseInt(int)+parseInt(numerator) / parseInt(denominator) === num) {
          sum += 1;
        }
      }
    }
  }
}

function dfs(n, k, num) {
  if (k === n) {
    isSatisfy(num);
  }
  for (var next=0;next<n;next++) {
    var flag = isInArray(next+1, k, arr);
    if(!flag) {
      arr[k] = next+1;
      dfs(n, k+1, num);
    }
  }
}


dfs(9,0,100);

console.log(sum); // 11
