/**
 * Created by ayou on 17/3/18.
 */

function TreeNode(ch) {
    this.children = [];
    this.ch = ch;
    this.flag = false; // 用于记录该字母是否是单词结尾的标志，此题中的单词为url
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
                if (i === str.length - 1) p.children[j].flag = true;
                p = p.children[j];
                break;
            }
        }
        if (j === pChildren.length) break;
    }
    for (; i < str.length; i++) {
        var newChild = new TreeNode(str[i]);
        if (i === str.length - 1) newChild.flag = true;
        p.children.push(newChild);
        p = newChild;
    }
};

TrieTree.prototype.search = function (str) {
    var p = this.root;
    var flag = false;
    for (var i = 0; i < str.length; i++) {
        pChildren = p.children;
        for (var j = 0; j < pChildren.length; j++) {
            if (pChildren[j].ch === str[i]) {
                if (pChildren[j].flag) flag = true;
                p = p.children[j];
                break;
            }
        }
        if (j === pChildren.length) break;
    }
    if (i === str.length && flag) return true;
    else return false;
};

var trieTree = new TrieTree();

// 读取B，建立字典
var fs = require('fs');
var contentB = fs.readFileSync('./B.csv','utf-8');
var linesB = contentB.split('\r\n');
for (var i = 0 ; i < linesB.length; i++) {
    trieTree.push(linesB[i]);
}

// 搜索A中的记录
var writeStream = fs.createWriteStream('./ans.csv');
var contentA = fs.readFileSync('./A.csv','utf-8');
var linesA = contentA.split('\r\n');
for (var i = 0 ; i < linesA.length; i++) {
    if(trieTree.search(linesA[i])) {
        writeStream.write(linesA[i]+','+'line:'+(i+1)+'\r\n', "utf-8");
    }
}
writeStream.end();