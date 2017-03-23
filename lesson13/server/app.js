var express = require('express');
var cookieParser = require('cookie-parser');
var bodyParser = require('body-parser');
var swig = require('swig');
var path = require('path');
var app = express();

var TrieTree = require('../search/TrieTree');
var Heap = require('../search/Heap');

var trie = new TrieTree();
trie.create(path.join(__dirname, '../search/data.csv'));

var heap = new Heap(function(a, b) {
  if (a.num > b.num) {
    return 1;
  } else if (a.num < b.num) {
    return -1;
  } else {
    return 0;
  }
});


// view engine setup
// Disables caching in Swig.
swig.setDefaults({ cache: false });
app.engine('html', swig.renderFile);
app.set('views', path.join(__dirname, 'views'));
app.set('view engine', 'html');

app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: false }));
app.use(cookieParser());


// 路由配置
app.get('/', function(req, res, next) {
  res.render('index')
})

app.get('/api/search', function(req, res, next) {
  var str = req.query.search;
  var arr = trie.prefixSearch(str);
  var ret;
  if (arr.length > 0) {
    ret = heap.topN(arr, 10);
  } else {
    ret = [];
  }
  res.json({data: ret});
})

// catch 404 and forward to error handler
app.use(function(req, res, next) {
  var err = new Error('Not Found');
  err.status = 404;
  next(err);
});

// production error handler
// no stacktraces leaked to user
app.use(function(err, req, res, next) {
  res.status(err.status || 500);
  res.render('error', {
    message: err.message,
    error: {}
  });
});

// 启动服务
app.listen(3000, err => {
  console.log(err || '启动');
});
