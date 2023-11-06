BEGIN
    int n;
    double a[1000000];
    int count = 0;
    read(n);
    for i=1 to n do
        read(a[i]);
    double max = a[1];
    int count=1;
    for i=2 to n do {
        if (a[i]==max) then count++;
        if (a[i] > max) then {
            max = a[i];
            count = 1;
        }
    }
    printf("MAX: %.2lf\n", max);
    printf("Number of MAX: %d", count);
    return 0;
END