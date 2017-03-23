/**
 * Created by ayou on 2017/3/23.
 */
var TrieTree = require('./TrieTree');
var Heap = require('./Heap');
var path = require('path');

var trie = new TrieTree();
trie.create(path.join(__dirname, './data.csv'));

var heap = new Heap(function(a, b) {
  if (a.num > b.num) {
    return 1;
  } else if (a.num < b.num) {
    return -1;
  } else {
    return 0;
  }
});

var ret;
var arr = trie.prefixSearch('a');
var ret = heap.topN(arr, 10);

console.log(ret);

var arr = trie.prefixSearch('ax');
if (arr.length > 0) {
  var ret = heap.topN(arr, 10);
}


console.log(ret);

// var arr = trie.prefixSearch('a');
// var ret = heap.topN(arr, 10);
//
// console.log(ret);