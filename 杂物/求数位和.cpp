int numsum(int n){
    int sum = 0, m;
    m = n;
    while (m != 0){
        n = m % 10;
        m = m / 10;
        sum += n;
    }
    return sum;
}