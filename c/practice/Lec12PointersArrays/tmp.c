//your code goes here
void convert_to_polar(int *coords, int N) {
    double dir, dist, tan, pi = 4.0 * atan(1);
    int x, y;
    for (int i = 0; i < N; i++) {
        x = *(coords + i*2 + 0);
        y = *(coords + i*2 + 1);
        if (x == 0 && y == 0) {
            printf("0.00 ");
            printf("0.00\n");
            break;
        }
        dist = sqrt(x*x + y*y);
        tan = (double) y / (double) x;
        dir = atan(tan) / pi * 180;
        if (x < 0)
            dir += 180;
        else if (x > 0 && y < 0)
            dir += 360;

        printf("%.2lf ", dir);
        printf("%.2lf\n", dist);
    }

}