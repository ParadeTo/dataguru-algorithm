/**
 * Created by ayou on 2017/3/23.
 */
var fs = require('fs');

function randomString(len) {
  len = len || 32;
  var $chars = 'ABCDEFGHJKMNPQRSTWXYZabcdefhijkmnprstwxyz2345678';
  var maxPos = $chars.length;
  var pwd = '';
  for (i = 0; i < len; i++) {
    pwd += $chars.charAt(Math.floor(Math.random() * maxPos));
  }
  return pwd;
}


/**
 * 每一轮生成一个随机字符串，然后生成一系列[0,_l]的子串 _l < l
 * 每个子串输出_n次 _n < n
 * 每一轮输出不超过N条
 * @param N 每次生成的行数
 * @param n 字符串最大输出次数
 * @param l 字符串最大长度
 * @params t 轮数
 */
function genData(N, n, l, t) {
  var writeStream = fs.createWriteStream('./data.csv');
  function _gen(N, n, l) {
    var str = randomString(l);
    var i = 0;
    while (i < N) {
      var _l = Math.floor(Math.random() * l + 1);
      var _n = Math.floor(Math.random() * n + 1);
      var _str = str.substr(0, _l);
      for (var j = 0; j < _n; j++) {
        writeStream.write(_str + '\r\n', "utf-8");
      }
      i += _n;
    }
  }

  for (var i = 0; i < t; i++) {
    _gen(N, n, l);
  }
  writeStream.end();
  writeStream = null;
}


genData(1000, 100, 30, 50);

