/**
 * Created by ayou on 2017/3/1.
 */

function dijkstra(S, M) {
  let D = [];
  let vNum = M.length;
  let result = [], route = [];
  // 初始化
  for (let i = 0; i < vNum; i++) {
    result[i] = Infinity;
    D[i] = M[S][i];
    route[i] = S;
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
      if (result[j] == Infinity && D[j] > sp + M[newPoint][j]) {
        D[j] = sp + M[newPoint][j];
        route[j] = newPoint;
      }
    }
  }
  return {result, route};
}


