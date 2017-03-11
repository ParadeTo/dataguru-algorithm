/**
 * Created by ayou on 17/3/11.
 */


function topo(M) {
    var ret = []

    var degree = [];
    var vNum = M.length;

    // 初始化每个顶点的入度为0
    for (var i = 0; i < vNum; i++) {
        degree[i] = 0;
    }

    // 统计每个顶点的入度
    for (var i = 0; i < vNum; i++)
        for (var j = 0; j < M[i].length; j++)
            degree[M[i][j]]++;

    // 统计0入度的点的个数
    var degree0 = 0;
    for (var i = 0; i < vNum; i++)
        if (degree[i] === 0) degree0++;

    for (var k = 0; degree0 > 0; k++) {
        // 找一个入度为0的顶点
        var j = -1;
        for (var i = vNum - 1; i >= 0; i--)
            if (degree[i] == 0) {
                j = i;
                break;
            }

        // 取出此顶点
        ret[k] = j;
        degree[j] = -1;
        degree0--;

        // 取出该顶点的所有边并统计0度顶点数
        for (var i = 0; i < M[j].length; i++) {
            degree[M[j][i]]--;
            if (degree[M[j][i]] === 0) degree0++;
        }
    }
    return ret;
}

var V = 8;
var e = [
    [0,3],[1,3],[1,4],[2,4],[2,6],[3,4],[3,5],[3,6],[4,6],[5,7],[6,7]
];

var M = [];
for (var i = 0; i < V; i++) {
    M[i] = [];
}

// 边集合转为邻接表
for (var i = 0; i < e.length; i++) {
    M[e[i][0]].unshift(e[i][1]);
}

// 排序
console.log(topo(M));