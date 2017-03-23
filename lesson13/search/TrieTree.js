/**
 * Created by ayou on 2017/3/23.
 */

function TreeNode(ch) {
  this.children = [];
  this.ch = ch;
  this.num = 0; // 词频
};

function TrieTree() {
  this.root = new TreeNode(null);
};

TrieTree.prototype.push = function (str) {
  var p = this.root;
  for (var i = 0; i < str.length; i++) {
    pChildren = p.children;
    for (var j = 0; j < pChildren.length; j++) {
      if (pChildren[j].ch === str[i]) {
        if (i === str.length - 1) p.children[j].num++;
        p = p.children[j];
        break;
      }
    }
    if (j === pChildren.length) break;
  }
  for (; i < str.length; i++) {
    var newChild = new TreeNode(str[i]);
    if (i === str.length - 1) newChild.num++;
    p.children.push(newChild);
    p = newChild;
  }
};

/**
 * 找到str最后一个字符的节点
 * @param str
 * @returns {*}
 */
TrieTree.prototype.search = function (str) {
  var p = this.root;
  var num = 0;
  for (var i = 0; i < str.length; i++) {
    pChildren = p.children;
    for (var j = 0; j < pChildren.length; j++) {
      if (pChildren[j].ch === str[i]) {
        p = p.children[j];
        break;
      }
    }
    if (j === pChildren.length) break;
  }
  if (i === str.length) return p;
  else return null;
};

TrieTree.prototype.prefixSearch = function (str) {
  var p = this.root;
  var res = [];

  var node = this.search(str);

  if (node === null) return [];

  if (node.num > 0) res.push({word: str, num: node.num});

  node.prefix = str;
  res = res.concat(this.bfs(node, str));
  return res;
}

TrieTree.prototype.bfs = function (p) {
  var res = [];
  var que = [];
  que.push(p);
  while (que.length > 0) {
    var node = que.shift();
    for (var i = 0; i < node.children.length; i++) {
      node.children[i].prefix = node.prefix + node.children[i].ch;
      if (node.children[i].num > 0) {
        // var word = '';
        // if (node === p) word = str + node.children[i].ch;
        // else word = str + node.ch + node.children[i].ch;
        res.push({word: node.children[i].prefix, num: node.children[i].num});
      }
      que.push(node.children[i]);
    }
  }
  return res;
}

TrieTree.prototype.create = function (filename) {
  var fs = require('fs');
  var content = fs.readFileSync(filename,'utf-8');
  var lines = content.split('\r\n');
  var len = lines.length;
  for (var i = 0 ; i < len; i++) {
    this.push(lines[i]);
  }
}

module.exports = TrieTree;


// 测试
// var trieTree = new TrieTree();
// trieTree.push('abcd');
// trieTree.push('abc');
// trieTree.push('ab');
// trieTree.push('abe');
// trieTree.push('abf');
// trieTree.push('abf');
// console.log(trieTree.prefixSearch('a'))
// console.log(trieTree.prefixSearch('ab'))
// console.log(trieTree.prefixSearch('abc'))