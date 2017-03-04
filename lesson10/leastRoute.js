/**
 * Created by ayou on 2017/3/1.
 */

function dijkstra(S, M) {
  let D = [];
  let vNum = M.length;
  let result = [], route = [];
  // 初始化
  for (let i = 0; i < vNum; i++) {
    if (i === 0) {
      result[i] = 0;
      route[i] = 0;
    } else {
      result[i] = Infinity;
      route[i] = 0;
    }
    D[i] = M[S][i];
  }
  // 添加剩余的点到T集合
  for (let i = 1; i < vNum; i++) {
    let sp = Infinity;
    let newPoint = -1;
    // 选择V-T中距离起点最近的点添加到V集合中，并记录其到起点的距离
    for (let j = 0; j < vNum; j++)
      if (result[j] === Infinity && D[j] < sp) {
        newPoint = j;
        sp = D[j];
      }
    result[newPoint] = sp;

    // 更新V-T集合中各点到起点的最短距离
    for (let j = 0; j < vNum; j++) {
      if (result[j] === Infinity && D[j] > sp + M[newPoint][j]) {
        D[j] = sp + M[newPoint][j];
        route[j] = newPoint;
      }
    }
  }
  return {result, route};
}

const M = [
    [0,1,4,Infinity,Infinity,Infinity],
    [1,0,1,5,Infinity,Infinity],
    [4,1,0,2,3,Infinity],
    [Infinity,5,2,0,Infinity,6],
    [Infinity,Infinity,3,Infinity,0,2],
    [Infinity,Infinity,Infinity,6,2,0],
]

const {result, route} = dijkstra(0, M);
console.log(result, route);
for (let i = 1, len = route.length; i < len; i++) {
  let path = i;
  let prevPoint = i;
  do {
    prevPoint = route[prevPoint];
    path = prevPoint + '->' + path;
  } while (prevPoint != 0);
  console.log(path, ' ', result[i]);
}



