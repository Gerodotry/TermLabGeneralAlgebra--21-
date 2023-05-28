#include "algorithms/GroupElementOrder.h"

long long GroupElementOrder::run(Number a, Number modulo) {
    if (!modulo.isZero()) {
        a.toField(modulo);
    }
    long long max_iterations = 1000;
    long long order = findOrder(a, modulo, max_iterations);
    return order == max_iterations ? -1 : order;
}

long long GroupElementOrder::findOrder(Number &a, Number &modulo, long long max_iterations) {
    int order = 0;
    for (Number product = a; !product.isZero() && order < max_iterations; order++) {
        product = NumberMultiplication::run(product, a, modulo);
        product.toField(modulo);
    }
    return order;
}
