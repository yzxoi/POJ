from random import randint

def gen():
    ih = open("test", "w")
    oh = open("test.a", "w")
    c = 100
    ih.write(str(c)+'\n');
    for i in range(c):
        m, n, l = 10, 10, randint(1, 100)
        mm = [[False]*n for _ in range(m)]
        c1, c2 = [0]*m, [0]*n
        ih.write("%d %d %d\n" % (m, n, l))
        for j in range(m):
            k = randint(10, 99)/10.0
            c1[j]=k
            ih.write("%.1f " % k);
        ih.write("\n");
        for j in range(n):
            k = randint(10, 99)/10.0
            c2[j]=k
            ih.write("%.1f " % k);
        ih.write("\n");
        for j in range(l):
            a, b = randint(1, m), randint(1, n)
            mm[a-1][b-1] = True
            ih.write("%d %d\n" % (a, b))
        mr = -1;
        for m1 in range(1<<m):
            m2 = 0;
            r = 1.0 
            for j in range(m):
                if m1&(1<<j):
                    r *= c1[j]
                    continue;
                for k in range(n):
                    if mm[j][k]: m2 |= (1<<k)
            for j in range(n):
                if (m2&(1<<j)) or c2[j]<1: r*=c2[j]
            if mr<0 or mr>r: mr=r
        oh.write("%.4f\n" % mr)

    ih.close()
    oh.close()

gen()