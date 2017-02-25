/**
 * Created by ayou on 2017/2/25.
 */

var sum = 0;
var arr = [];

// 查询k位前是否存在item
function isInArray(item, k, arr) {
  for (var i=0;i<k;i++) {
    if (item===arr[i]) return true;
  }
  return false;
}

// 判断是否满足需求
function isSatisfy(n) {
  var flag = true;
  for (var i=0;i<n;i++) {
    for (var j=0;j<n;j++) {
      if (j===i) continue;
      if (Math.abs(i-j) == Math.abs(arr[i] - arr[j])) {
        flag = false;
        break;
      }
    }
    if (flag === false) break;
  }
  sum += flag ? 1 : 0;
}

function dfs(n, k) {
  if (k == n) {
    isSatisfy(n);
  }
  for (var next=0;next<n;next++) {
    var flag = isInArray(next, k, arr);
    if(!flag) {
      arr[k] = next;
      dfs(n, k+1);
    }
  }
}

dfs(8, 0);

console.log(sum); // 92