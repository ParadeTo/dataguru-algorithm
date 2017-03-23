/**
 * Created by ayou on 2017/3/23.
 */

/**
 * 小顶堆
 * @constructor
 */

function Heap(fn) {
  // 用数组来做堆的内部存储
  this.arr = [];
  // 当前堆的大小
  this.k = 0;
  // 比较函数
  this.fn = fn;
}

Heap.prototype.push = function (ele) {
  // 放到堆尾
  this.arr[this.k++] = ele;
  // 上行到合适位置
  var currentIndex = this.k - 1;
  var parentIndex = Math.floor((currentIndex - 1) / 2);
  while( parentIndex >= 0 && this.fn(this.arr[parentIndex], this.arr[currentIndex]) > 0) {
    var tmp = this.arr[currentIndex];
    this.arr[currentIndex] = this.arr[parentIndex];
    this.arr[parentIndex] = tmp;
    currentIndex = parentIndex;
    parentIndex = Math.floor((currentIndex - 1) / 2);
  }
}

Heap.prototype.pushFront = function (ele) {
  // 与堆顶元素比较，如果比堆顶大，就替换，并向下移动
  if (ele > this.arr[0]) {
    this.arr[0] = ele;
    this.upToDown(0);
  }
}

Heap.prototype.upToDown = function (index) {
  var currentIndex = index;
  while(currentIndex < this.k/2) {
    var lIndex = currentIndex * 2 + 1;
    var rIndex = currentIndex * 2 + 2;
    // 选取左右子树最小者
    var minIndex = 0;
    if (this.fn(this.arr[lIndex], this.arr[rIndex]) < 1) {
      minIndex = lIndex;
    } else {
      minIndex = rIndex;
    }
    // 交换父子
    if (this.fn(this.arr[currentIndex], this.arr[minIndex]) > 0) {
      var tmp = this.arr[currentIndex];
      this.arr[currentIndex] = this.arr[minIndex];
      this.arr[minIndex] = tmp;
      currentIndex = minIndex;
    } else {
      break;
    }
  }
}

Heap.prototype.clean = function() {
  this.k = 0;
  this.arr = [];
}

Heap.prototype.topN = function (arr, n) {
  var len = arr.length;

  this.clean();
  for (var i = 0; i < n && i < len; i++) {
    this.push(arr[i]);
  }

  for (; i < len; i++) {
    this.pushFront(arr[i])
  }
  return this.arr;
}


module.exports = Heap;

// 测试
// var heap = new Heap(compare);
//
// function compare(a, b) {
//   if (a > b) {
//     return 1;
//   } else if (a < b) {
//     return -1;
//   } else {
//     return 0;
//   }
// }
//
//
// console.log(heap.topN([11,2,3,4,5,6,7,8,9,10], 20)); // [ 4, 5, 6, 8, 10, 9, 7, 11 ]