/**
 * Created by ayou on 17/3/18.
 */

var arr = [];
// 初始化数据
var fs = require('fs');
var content = fs.readFileSync('./log.txt','utf-8');
var lines = content.split('\r\n');
for (var i = 0 ; i < lines.length; i++) {
    var tmp = lines[i].split(' ');
    arr.push({
        ts: parseInt(tmp[0]),
        // 登录操作记为1，下线操作记做-1，则从最大子序列的末尾时间戳到下一个下线操作的时间戳之间为在线人数最多时间段
        val: parseInt(tmp[2]) === 0 ? 1 : -1
    });
}

function maxSubArr(arr) {
    var L, R;
    var i = 0, j = 0, n = arr.length;
    var sumIj = 0;
    var ans = -Infinity;
    while (j < n) {
        if (sumIj < 0) i = j, j = j + 1, sumIj = arr[i].val;
        else sumIj = sumIj + arr[j].val, j = j + 1;
        if (sumIj > ans) ans = sumIj, L = i, R = j - 1;

    }
    return {ans, L, R};
}



var res = maxSubArr(arr);
console.log(arr.slice(res.R-5, res.R+5));
console.log('最大在线人数为：',res.ans);
console.log('最大在线人数时期：',arr[res.R].ts, '-' ,arr[res.R+1].ts);