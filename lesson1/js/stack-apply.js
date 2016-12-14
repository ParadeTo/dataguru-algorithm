/**
 * js版栈实现并应用
 */
function Stack() {
  this.dataStore = [];
  this.top = 0;
}

Stack.prototype.push = function (element) {
  this.dataStore[this.top++] = element;
};

Stack.prototype.pop = function () {
  return this.dataStore[--this.top];
};

Stack.prototype.peek = function () {
  return this.dataStore[this.top-1];
};

Stack.prototype.length = function () {
  return this.top;
};

Stack.prototype.clear = function () {
  this.top = 0;
};

/**
 * 中缀表达式转为后缀表达式
 */
function transMiddleToSuffix(exp) {
  var expSuffix = [];
  var s = new Stack();
  for (var i = 0, len=exp.length; i < len; i++) {
    switch (exp[i]) {
      case '(':
        s.push(exp[i]);
        break;
      case ')':
        while(s.peek() !== '(' && s.length() > 0){
          expSuffix.push(s.pop());
        }
        s.pop(); // 弹出(
        break;
      case '+':// 优先级最低，出栈直到遇到(
      case '-':
        while(s.length() > 0 && s.peek() !== '('){
          expSuffix.push(s.pop());
        }
        s.push(exp[i]);
        break;
      case '*':// 出栈直到遇到( * /
      case '/':
        while(s.length() > 0 && s.peek() !== '(' && (s.peek() === '*' || s.peek() === '/')) {
          expSuffix.push(s.pop());
        }
        s.push(exp[i]);
        break;
      default: // 默认是数字
        expSuffix.push(exp[i]);
        break;
    }
  }
  while(s.length() > 0) {
    expSuffix.push(s.pop());
  }

  return expSuffix;
}

/**
  利用后缀表达式求结果
 */
function compute(expSuffix) {
  var s = new Stack();
  for (var i = 0, len=expSuffix.length; i < len; i++) {
    switch (expSuffix[i]) {
      case '+':
        var right = s.pop();
        var left = s.pop();
        s.push(parseInt(left) + parseInt(right));
        break;
      case '-':
        var right = s.pop();
        var left = s.pop();
        s.push(left - right);
        break;
      case '*':
        var right = s.pop();
        var left = s.pop();
        s.push(left * right);
        break;
      case '/':
        var right = s.pop();
        var left = s.pop();
        s.push(left / right);
        break;
      default: // 默认是数字,进栈
        s.push(expSuffix[i]);
        break;
    }
    console.log(s.dataStore)
  }
  return s.pop();
}

var a = ['1','*','(','1','+','2','*','3',')'];
console.log(compute(transMiddleToSuffix(a)));
