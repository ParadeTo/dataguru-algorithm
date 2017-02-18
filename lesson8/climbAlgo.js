function f1(x) {
    return x * Math.sin(16.2 * x) + x * x * Math.cos(-1.3 * x) + 0.05 * Math.exp( x / 71);
}

function f2(x) {
    if (x === 0) return Infinity;
    return Math.sin(12 * x) + x * Math.cos(0.1 * x) / 800 + 1 / x;
}

function climb(f, x, step, L, R) {
    while ((L < x && x < R) && (f(x) < f(x+step) || f(x) < f(x-step))) {
        if (f(x-step) > f(x+step)) {
            x -= step;
        } else {
            x += step;
        }
    }
    return x;
}

function multiClimb(f, L, R) {
    var max = -Infinity;
    var maxX = 0;
    // 每个5点新建一个起点
    for(var i = L; i <= R; i += 0.01) {
        var localMaxX = climb(f, i, 0.1, L, R);
        var localMax = f(localMaxX);
        if (max < localMax) {
            max = localMax;
            maxX = localMaxX;
        }
    }
    return [maxX, max];
}

console.log(multiClimb(f1, -1000, 1000)); // [ 995.6499999984777, 1053380.957351711 ]
console.log(multiClimb(f2, -1000, 1000)); // [ 0.009999999235500268, 100.11973234317159 ]
