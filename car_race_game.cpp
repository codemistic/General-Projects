#include <stdio.h> 
#include <conio.h> 
#include <process.h>
#include <graphics.h>
#include <dos.h>
#include <stdlib.h>
#include <time.h>

    class car {
        private:
            int x1, y1, x2, y2, col, col2, col3;
        public:
            car(): x1(200), y1(300), x2(270), y2(200), col(4) {}
        car(int a, int b, int c, int d, int e, int f, int g): x1(a), y1(b), x2(c), y2(d), col(e), col2(f), col3(g) {}
        void get(int a, int b, int c, int d, int e, int f, int g) {
            x1 = a;
            y1 = b;
            x2 = c;
            y2 = d;
            col = e;
            col2 = f;
            col3 = g;
            if (x1 <= 180) {
                sound(1000);
                x1 = 200;
                x2 = 270;
            }
            if (x2 >= 430) {
                sound(1000);
                x1 = 340;
                x2 = 410;
            }
        }
        void draw() {
            setcolor(col);
            setfillstyle(1, col);
            rectangle(x1, y1, x2, y2); //car body
            floodfill(x1 + 10, y2 + 10, col);
            setcolor(col2); //windows
            setfillstyle(2, col2);
            rectangle(x1 + 10, y1 - 70, x2 - 10, y2 + 10);
            floodfill(x1 + 15, y2 + 15, col2);
            rectangle(x1 + 10, y1 - 10, x2 - 10, y2 + 70);
            floodfill(x1 + 15, y1 - 15, col2);
            setcolor(col3); //wheels
            setfillstyle(1, col3);
            rectangle(x1 - 10, y2 + 5, x1, y2 + 20);
            floodfill(x1 - 4, y2 + 12, col3);
            rectangle(x2, y2 + 5, x2 + 10, y2 + 20);
            floodfill(x2 + 4, y2 + 12, col3);
            rectangle(x1 - 15 + 1, y1 - 25, x1, y1 - 5);
            floodfill(x1 - 10, y1 - 20, col3);
            rectangle(x2, y1 - 25, x2 + 15, y1 - 5);
            floodfill(x2 + 4, y1 - 20, col3);
        }
        void collide(int col) {
            setcolor(col);
            setfillstyle(1, col);
            line(x1 - 5, y2 - 3, x1, y2);
            line(x1 - 5, y2 - 5, x1, y2 - 5);
            line(x1 - 5, y2 - 3, x1 - 5, y2 - 5);
            line(x1, y2 - 5, x1 + 5, y2 - 3);
            line(x1 + 5, y2 - 3, x1 + 10, y2 - 15);
            line(x1 + 10, y2 - 15, x1 + 20, y2 - 3);
            line(x1 + 20, y2 - 3, x1 + 30, y2 - 10);
            line(x1 + 30, y2 - 10, x1 + 35, y2 - 3);
            line(x1 + 35, y2 - 3, x1 + 45, y2 - 12);
            line(x1 + 45, y2 - 12, x1 + 55, y2 - 3);
            line(x1 + 55, y2 - 3, x1 + 60, y2 - 10);
            line(x1 + 60, y2 - 10, x1 + 70, y2 - 3);
            line(x1 + 70, y2 - 3, x1 + 74, y2 - 8);
            line(x1 + 74, y2 - 8, x1 + 70, y2);
            line(x1, y2, x1 + 70, y2);
            floodfill(x1 + 30, y2 - 1, col);
            line(x1 - 5, y1 + 3, x1, y1);
            line(x1 - 5, y1 + 5, x1, y1 + 5);
            line(x1 - 5, y1 + 3, x1 - 5, y1 + 5);
            line(x1, y1 + 5, x1 + 5, y1 + 3);
            line(x1 + 5, y1 + 3, x1 + 10, y1 + 15);
            line(x1 + 10, y1 + 15, x1 + 20, y1 + 3);
            line(x1 + 20, y1 + 3, x1 + 30, y1 + 10);
            line(x1 + 30, y1 + 10, x1 + 35, y1 + 3);
            line(x1 + 35, y1 + 3, x1 + 45, y1 + 12);
            line(x1 + 45, y1 + 12, x1 + 55, y1 + 3);
            line(x1 + 55, y1 + 3, x1 + 60, y1 + 10);
            line(x1 + 60, y1 + 10, x1 + 70, y1 + 3);
            line(x1 + 70, y1 + 3, x1 + 74, y1 + 8);
            line(x1 + 74, y1 + 8, x1 + 70, y1);
            line(x1, y1, x1 + 70, y1);
            floodfill(x1 + 30, y1 + 1, col);
        }
    };
//////////////////////////////////////////////////////////////////////////
class obstacle {
    private:
        int x, y, col;
    public:
        obstacle(): x(0), y(0), col(0) {}
    obstacle(int a, int b, int c): x(a), y(b), col(c) {}
    void get(int a, int b, int c) {
        x = a;
        y = b;
        col = c;
    }
    void draw() {
        setcolor(col);
        setfillstyle(1, col);
        circle(x, y, 20);
        floodfill(x, y, col);
    }
};
///////////////////////////////////////////////////////////////////////////
class timer {
    private:
        int sec, min, ms, flag;
    public:
        timer(): min(0), sec(0), ms(0), flag(0) {}
    timer(int a, int b, int c, int d): min(a), sec(b), ms(c), flag(d) {}
    void start() {
        min = sec = ms = flag = 0;
    }
    void get() {
        settextstyle(1, 0, 1);
        char * minn;
        if (min > 9) {
            int minnn = min / 10;
            if (minnn == 0)
                minn = "0";
            if (minnn == 1)
                minn = "1";
            if (minnn == 2)
                minn = "2";
            if (minnn == 3)
                minn = "3";
            if (minnn == 4)
                minn = "4";
            if (minnn == 5)
                minn = "5";
            if (minnn == 6)
                minn = "6";
            if (minnn == 7)
                minn = "7";
            if (minnn == 8)
                minn = "8";
            if (minnn == 9)
                minn = "9";
            setcolor(15);
            outtextxy(20, 100, minn);
            setcolor(0);
            outtextxy(20, 100, minn);
        }
        if (min > 9) {
            int minnn = min % 10;
            if (minnn == 0)
                minn = "0";
            if (minnn == 1)
                minn = "1";
            if (minnn == 2)
                minn = "2";
            if (minnn == 3)
                minn = "3";
            if (minnn == 4)
                minn = "4";
            if (minnn == 5)
                minn = "5";
            if (minnn == 6)
                minn = "6";
            if (minnn == 7)
                minn = "7";
            if (minnn == 8)
                minn = "8";
            if (minnn == 9)
                minn = "9";
            setcolor(15);
            outtextxy(30, 100, minn);
            setcolor(0);
            outtextxy(30, 100, minn);
        }
        if (min <= 9) {
            int minnn = min;
            if (minnn == 0)
                minn = "0";
            if (minnn == 1)
                minn = "1";
            if (minnn == 2)
                minn = "2";
            if (minnn == 3)
                minn = "3";
            if (minnn == 4)
                minn = "4";
            if (minnn == 5)
                minn = "5";
            if (minnn == 6)
                minn = "6";
            if (minnn == 7)
                minn = "7";
            if (minnn == 8)
                minn = "8";
            if (minnn == 9)
                minn = "9";
            setcolor(15);
            outtextxy(20, 100, minn);
            setcolor(0);
            outtextxy(20, 100, minn);
        }
        setcolor(15);
        outtextxy(40, 100, ":");
        if (sec > 9) {
            int minnn = sec / 10;
            if (minnn == 0)
                minn = "0";
            if (minnn == 1)
                minn = "1";
            if (minnn == 2)
                minn = "2";
            if (minnn == 3)
                minn = "3";
            if (minnn == 4)
                minn = "4";
            if (minnn == 5)
                minn = "5";
            if (minnn == 6)
                minn = "6";
            if (minnn == 7)
                minn = "7";
            if (minnn == 8)
                minn = "8";
            if (minnn == 9)
                minn = "9";
            setcolor(15);
            outtextxy(50, 100, minn);
            setcolor(0);
            outtextxy(50, 100, minn);
        }
        if (sec > 9) {
            int minnn = sec % 10;
            if (minnn == 0)
                minn = "0";
            if (minnn == 1)
                minn = "1";
            if (minnn == 2)
                minn = "2";
            if (minnn == 3)
                minn = "3";
            if (minnn == 4)
                minn = "4";
            if (minnn == 5)
                minn = "5";
            if (minnn == 6)
                minn = "6";
            if (minnn == 7)
                minn = "7";
            if (minnn == 8)
                minn = "8";
            if (minnn == 9)
                minn = "9";
            setcolor(15);
            outtextxy(60, 100, minn);
            setcolor(0);
            outtextxy(60, 100, minn);
        }
        if (sec <= 9) {
            int minnn = sec;
            if (minnn == 0)
                minn = "0";
            if (minnn == 1)
                minn = "1";
            if (minnn == 2)
                minn = "2";
            if (minnn == 3)
                minn = "3";
            if (minnn == 4)
                minn = "4";
            if (minnn == 5)
                minn = "5";
            if (minnn == 6)
                minn = "6";
            if (minnn == 7)
                minn = "7";
            if (minnn == 8)
                minn = "8";
            if (minnn == 9)
                minn = "9";
            setcolor(15);
            outtextxy(50, 100, minn);
            setcolor(0);
            outtextxy(50, 100, minn);
        }
        setcolor(15);
        outtextxy(70, 100, ":");
        if (ms > 9) {
            int minnn = ms / 10;
            if (minnn == 0)
                minn = "0";
            if (minnn == 1)
                minn = "1";
            if (minnn == 2)
                minn = "2";
            if (minnn == 3)
                minn = "3";
            if (minnn == 4)
                minn = "4";
            if (minnn == 5)
                minn = "5";
            if (minnn == 6)
                minn = "6";
            if (minnn == 7)
                minn = "7";
            if (minnn == 8)
                minn = "8";
            if (minnn == 9)
                minn = "9";
            setcolor(15);
            outtextxy(80, 100, minn);
            setcolor(0);
            outtextxy(80, 100, minn);
        }
        if (ms > 9) {
            int minnn = ms % 10;
            if (minnn == 0)
                minn = "0";
            if (minnn == 1)
                minn = "1";
            if (minnn == 2)
                minn = "2";
            if (minnn == 3)
                minn = "3";
            if (minnn == 4)
                minn = "4";
            if (minnn == 5)
                minn = "5";
            if (minnn == 6)
                minn = "6";
            if (minnn == 7)
                minn = "7";
            if (minnn == 8)
                minn = "8";
            if (minnn == 9)
                minn = "9";
            setcolor(15);
            outtextxy(90, 100, minn);
            setcolor(0);
            outtextxy(90, 100, minn);
        }
        if (ms <= 9) {
            int minnn = ms;
            if (minnn == 0)
                minn = "0";
            if (minnn == 1)
                minn = "1";
            if (minnn == 2)
                minn = "2";
            if (minnn == 3)
                minn = "3";
            if (minnn == 4)
                minn = "4";
            if (minnn == 5)
                minn = "5";
            if (minnn == 6)
                minn = "6";
            if (minnn == 7)
                minn = "7";
            if (minnn == 8)
                minn = "8";
            if (minnn == 9)
                minn = "9";
            setcolor(15);
            outtextxy(80, 100, minn);
            setcolor(0);
            outtextxy(80, 100, minn);
        }
    }
    void time() {
        ms++;
        if (ms == 100) {
            ms = 0;
            sec++;
        }
        if (sec == 60) {
            sec = 0;
            min++;
        }
    }
    int minutes() {
        return min;
    }
    void timego() {
        ms = 0;
        sec += 30;
        if (sec > 60) {
            sec = 0;
            min++;
        }
    }
};
void grass() {
    setcolor(10);
    setfillstyle(1, 10);
    rectangle(0, 0, 180, 400);
    floodfill(10, 100, 10);
    rectangle(430, 0, 600, 400);
    floodfill(480, 100, 10);
    setcolor(5);
    settextstyle(8, 0, 3);
    outtextxy(440, 50, "RACE CRAZE");
    setcolor(0);
    setfillstyle(1, 0);
    settextstyle(7, 0, 2);
    outtextxy(20, 60, "TIMER");
    rectangle(20, 100, 150, 130);
    floodfill(60, 120, 0);
    settextstyle(7, 0, 2);
    outtextxy(20, 260, "MILES");
    rectangle(20, 300, 150, 330);
    floodfill(60, 320, 0);
}
void track(int n, int coll) {
    setcolor(coll);
    setfillstyle(1, coll);
    rectangle(300, n, 310, 50 + n);
    floodfill(302, 10 + n, coll);
    rectangle(300, 100 + n, 310, 150 + n);
    floodfill(302, 110 + n, coll);
    rectangle(300, 200 + n, 310, 250 + n);
    floodfill(302, 210 + n, coll);
    rectangle(300, 300 + n, 310, 350 + n);
    floodfill(302, 310 + n, coll);
    rectangle(300, 400 + n, 310, 450 + n);
    floodfill(302, 410 + n, coll);
    rectangle(300, 500 + n, 310, 550 + n);
    floodfill(302, 510 + n, coll);
    rectangle(300, 600 + n, 310, 650 + n);
    floodfill(302, 610 + n, coll);
    rectangle(300, 700 + n, 310, 750 + n);
    floodfill(302, 710 + n, coll);
}
void main() {
    int driver=DETECT, mode;
    //driver = EGA;
    //mode = EGAHI;

    initgraph( &driver, &mode, "c:\\turboc3\\bgi");
    car c, c1;
    obstacle o;
    timer T;
    int i, j = 200, k = 200;
    int t = -200, flg = 0;
    time_t tt, ttt;
    c.get(k, j + 100, k + 70, j, 4, 3, 8);
    c.draw();
    grass();
    track(t, 15);
    randomize();
    int r = 0, r1, l = 50;
    int miles = 0, mil = 0;
    int stage = 10;
    getch();
    do {
        T.get();
        i = 0;
        if (kbhit())
            i = getch();
        T.time();
        char * minn;
        settextstyle(1, 0, 1);
        if (miles > 99) {
            int minnn = miles / 100;
            if (minnn == 0)
                minn = "0";
            if (minnn == 1)
                minn = "1";
            if (minnn == 2)
                minn = "2";
            if (minnn == 3)
                minn = "3";
            if (minnn == 4)
                minn = "4";
            if (minnn == 5)
                minn = "5";
            if (minnn == 6)
                minn = "6";
            if (minnn == 7)
                minn = "7";
            if (minnn == 8)
                minn = "8";
            if (minnn == 9)
                minn = "9";
            setcolor(15);
            outtextxy(30, 310, minn);
            setcolor(0);
            outtextxy(30, 310, minn);
        }
        if (miles > 99) {
            int minnn = miles % 100;
            if (minnn == 0)
                minn = "0";
            if (minnn == 1)
                minn = "1";
            if (minnn == 2)
                minn = "2";
            if (minnn == 3)
                minn = "3";
            if (minnn == 4)
                minn = "4";
            if (minnn == 5)
                minn = "5";
            if (minnn == 6)
                minn = "6";
            if (minnn == 7)
                minn = "7";
            if (minnn == 8)
                minn = "8";
            if (minnn == 9)
                minn = "9";
            setcolor(15);
            outtextxy(40, 310, minn);
            setcolor(0);
            outtextxy(40, 310, minn);
        }
        if (miles > 9) {
            int minnn = miles / 10;
            if (minnn == 0)
                minn = "0";
            if (minnn == 1)
                minn = "1";
            if (minnn == 2)
                minn = "2";
            if (minnn == 3)
                minn = "3";
            if (minnn == 4)
                minn = "4";
            if (minnn == 5)
                minn = "5";
            if (minnn == 6)
                minn = "6";
            if (minnn == 7)
                minn = "7";
            if (minnn == 8)
                minn = "8";
            if (minnn == 9)
                minn = "9";
            setcolor(15);
            outtextxy(40, 310, minn);
            setcolor(0);
            outtextxy(40, 310, minn);
        }
        if (miles > 9) {
            int minnn = miles % 10;
            if (minnn == 0)
                minn = "0";
            if (minnn == 1)
                minn = "1";
            if (minnn == 2)
                minn = "2";
            if (minnn == 3)
                minn = "3";
            if (minnn == 4)
                minn = "4";
            if (minnn == 5)
                minn = "5";
            if (minnn == 6)
                minn = "6";
            if (minnn == 7)
                minn = "7";
            if (minnn == 8)
                minn = "8";
            if (minnn == 9)
                minn = "9";
            setcolor(15);
            outtextxy(50, 310, minn);
            setcolor(0);
            outtextxy(50, 310, minn);
        }
        if (miles <= 9) {
            int minnn = miles;
            if (minnn == 0)
                minn = "0";
            if (minnn == 1)
                minn = "1";
            if (minnn == 2)
                minn = "2";
            if (minnn == 3)
                minn = "3";
            if (minnn == 4)
                minn = "4";
            if (minnn == 5)
                minn = "5";
            if (minnn == 6)
                minn = "6";
            if (minnn == 7)
                minn = "7";
            if (minnn == 8)
                minn = "8";
            if (minnn == 9)
                minn = "9";
            setcolor(15);
            outtextxy(40, 310, minn);
            setcolor(0);
            outtextxy(40, 310, minn);
        }
        if (flg == 0) {
            randomize();
            srand((unsigned) time( & ttt));
            r = rand() % 3;
            if (r == 2) {
                randomize();
                r1 = random(10) % 2;
                l = 100;
                //(r1==0)?o.get(230,l+stage,7):o.get(370,l+stage,7);
                //o.draw();

                (r1 == 0) ? c1.get(200, l + stage, 270, l + stage - 100, 5, 6, 7): c1.get(335, l + stage, 405, l + stage - 100, 5, 6, 7);
                c1.draw();
                flg = 2;
            }
        }
        sound(miles + 100);
        if (i == 75) {
            c.get(k, j + 100, k + 70, j, 0, 0, 0);
            c.draw();
            k = 200;
            c.get(k, j + 100, k + 70, j, 4, 3, 8);
            if (flg == 1) {
                c1.collide(14);
                c.collide(14);
                delay(500);
                c1.collide(0);
                c.collide(0);
                flg = 3;
                T.timego();
            }
            c.draw();
        }
        if (i == 155) {
            c.get(k, j + 100, k + 70, j, 0, 0, 0);
            c.draw();
            k = 200;
            c.get(k, j + 100, k + 70, j, 4, 3, 8);
            if (flg == 1) {
                c1.collide(14);
                c.collide(14);
                delay(500);
                c1.collide(0);
                c.collide(0);
                flg = 3;
                T.timego();
            }
            c.draw();
        }
        if (i == 77) {
            c.get(k, j + 100, k + 70, j, 0, 0, 0);
            c.draw();
            k = 335;
            c.get(k, j + 100, k + 70, j, 4, 3, 8);
            if (flg == 1) {
                c1.collide(14);
                c.collide(14);
                delay(500);
                c1.collide(0);
                c.collide(0);
                flg = 3;
                T.timego();
            }
            c.draw();
        }
        if (i == 157) {
            c.get(k, j + 100, k + 70, j, 0, 0, 0);
            c.draw();
            k = 335;
            c.get(k, j + 100, k + 70, j, 4, 3, 8);
            if (flg == 1) {
                c1.collide(14);
                c.collide(14);
                delay(500);
                c1.collide(0);
                c.collide(0);
                T.timego();
                flg = 3;
            }
            c.draw();
        }
        if (i == 72) {
            mil += 1;
            track(t, 0);
            (t > 70) ? t = -200: t += 5;
            track(t, 15);
            if ((l + stage) >= 200 && (l + stage) <= 300) {
                if (r1 == 0 && k == 200) {
                    flg = 1;
                    //(r1==0)?o.get(230,l+stage,0):o.get(370,l+stage,0);
                    //o.draw();

                    (r1 == 0) ? c1.get(200, l + stage, 270, l + stage - 100, 0, 0, 0): c1.get(335, l + stage, 405, l + stage - 100, 0, 0, 0);
                    c1.draw();
                } else if (r1 == 1 && k == 335) {
                    flg = 1;
                    //(r1==0)?o.get(230,l+stage,0):o.get(370,l+stage,0);
                    //o.draw();

                    (r1 == 0) ? c1.get(200, l + stage, 270, l + stage - 100, 0, 0, 0): c1.get(335, l + stage, 405, l + stage - 100, 0, 0, 0);
                    c1.draw();
                } else
                    flg = 2;
            }
            if (flg == 1) {
                c.collide(14);
                c1.collide(14);
                flg = 0;
                delay(1000);
                c.collide(0);
                c1.collide(0);
                c.get(k, j + 100, k + 70, j, 4, 3, 8);
                c.draw();
                T.timego();
            }
            if (flg == 2) {
                //(r1==0)?o.get(230,l+stage,0):o.get(370,l+stage,0);
                //o.draw();

                (r1 == 0) ? c1.get(200, l + stage, 270, l + stage - 100, 0, 0, 0): c1.get(335, l + stage, 405, l + stage - 100, 0, 0, 0);
                c1.draw();
                l = l + 5;
                //(r1==0)?o.get(230,l+stage,7):o.get(370,l+stage,7);
                //o.draw();

                (r1 == 0) ? c1.get(200, l + stage, 270, l + stage - 100, 5, 6, 7): c1.get(335, l + stage, 405, l + stage - 100, 5, 6, 7);
                c1.draw();
                if (l + stage > 300)
                    flg = 3;
            }
        }
        if (i == 152) {
            mil += 2;
            track(t, 0);
            (t > 70) ? t = -200: t += 20;
            track(t, 15);
            if (l + stage >= 200 && l + stage <= 300) {
                if (r1 == 0 && k == 200) {
                    flg = 1;
                    //(r1==0)?o.get(230,l+stage,0):o.get(370,l+stage,0);
                    //o.draw();

                    (r1 == 0) ? c1.get(200, l + stage, 270, l + stage - 100, 0, 0, 0): c1.get(335, l + stage, 405, l + stage - 100, 0, 0, 0);
                    c1.draw();
                } else if (r1 == 1 && k == 335) {
                    flg = 1;
                    //(r1==0)?o.get(230,l+stage,0):o.get(370,l+stage,0);
                    //o.draw();

                    (r1 == 0) ? c1.get(200, l + stage, 270, l + stage - 100, 0, 0, 0): c1.get(335, l + stage, 405, l + stage - 100, 0, 0, 0);
                    c1.draw();
                } else
                    flg = 2;
            }
            if (flg == 1) {
                c.collide(14);
                c1.collide(14);
                flg = 0;
                delay(1000);
                c.collide(0);
                c1.collide(0);
                c.get(k, j + 100, k + 70, j, 4, 3, 8);
                c.draw();
                T.timego();
            }
            if (flg == 2) {
                //(r1==0)?o.get(230,l+stage,0):o.get(370,l+stage,0);
                //o.draw();

                (r1 == 0) ? c1.get(200, l + stage, 270, l + stage - 100, 0, 0, 0): c1.get(335, l + stage, 405, l + stage - 100, 0, 0, 0);
                c1.draw();
                l += 10;
                //(r1==0)?o.get(230,l+stage,7):o.get(370,l+stage,7);
                //o.draw();

                (r1 == 0) ? c1.get(200, l + stage, 270, l + stage - 100, 5, 6, 7): c1.get(335, l + stage, 405, l + stage - 100, 5, 6, 7);
                c1.draw();
                if (l + stage > 300)
                    flg = 3;
            }
        }
        if (i == 80) {
            mil -= 1;
            track(t, 0);
            (t < -370) ? t = -200: t -= 5;
            track(t, 15);
            if (l + stage >= 200 && l + stage <= 300) {
                if (r1 == 0 && k == 200) {
                    flg = 1;
                    //(r1==0)?o.get(230,l+stage,0):o.get(370,l+stage,0);
                    //o.draw();

                    (r1 == 0) ? c1.get(200, l + stage, 270, l + stage - 100, 0, 0, 0): c1.get(335, l + stage, 405, l + stage - 100, 0, 0, 0);
                    c1.draw();
                } else if (r1 == 1 && k == 335) {
                    flg = 1;
                    //(r1==0)?o.get(230,l+stage,0):o.get(370,l+stage,0);
                    //o.draw();

                    (r1 == 0) ? c1.get(200, l + stage, 270, l + stage - 100, 0, 0, 0): c1.get(335, l + stage, 405, l + stage - 100, 0, 0, 0);
                    c1.draw();
                } else
                    flg = 2;
            }
            if (flg == 1) {
                c.collide(14);
                c1.collide(14);
                flg = 0;
                delay(1000);
                c.collide(0);
                c1.collide(0);
                c.draw();
                T.timego();
            }
            if (flg == 2) {
                //(r1==0)?o.get(230,l+stage,0):o.get(370,l+stage,0);
                //o.draw();

                (r1 == 0) ? c1.get(200, l + stage, 270, l + stage - 100, 0, 0, 0): c1.get(335, l + stage, 405, l + stage - 100, 0, 0, 0);
                c1.draw();
                l = l - 5;
                //(r1==0)?o.get(230,l+stage,7):o.get(370,l+stage,7);
                //o.draw();

                (r1 == 0) ? c1.get(200, l + stage, 270, l + stage - 100, 5, 6, 7): c1.get(335, l + stage, 405, l + stage - 100, 5, 6, 7);
                c1.draw();
                if (l + stage > 300)
                    flg = 3;
            }
        }
        if (i == 160) {
            mil -= 2;
            track(t, 0);
            (t < -370) ? t = -200: t -= 20;
            track(t, 15);
            if (l + stage >= 200 && l + stage <= 300) {
                if (r1 == 0 && k == 200) {
                    flg = 1;
                    //(r1==0)?o.get(230,l+stage,0):o.get(370,l+stage,0);
                    //o.draw();

                    (r1 == 0) ? c1.get(200, l + stage, 270, l + stage - 100, 0, 0, 0): c1.get(335, l + stage, 405, l + stage - 100, 0, 0, 0);
                    c1.draw();
                } else if (r1 == 1 && k == 335) {
                    flg = 1;
                    //(r1==0)?o.get(230,l+stage,0):o.get(370,l+stage,0);
                    //o.draw();

                    (r1 == 0) ? c1.get(200, l + stage, 270, l + stage - 100, 0, 0, 0): c1.get(335, l + stage, 405, l + stage - 100, 0, 0, 0);
                    c1.draw();
                } else
                    flg = 2;
            }
            if (flg == 1) {
                c.collide(14);
                c1.collide(14);
                flg = 0;
                delay(1000);
                c.collide(0);
                c1.collide(0);
                c.draw();
                T.timego();
            }
            if (flg == 2) {
                //(r1==0)?o.get(230,l+stage,0):o.get(370,l+stage,0);
                //o.draw();

                (r1 == 0) ? c1.get(200, l + stage, 270, l + stage - 100, 0, 0, 0): c1.get(335, l + stage, 405, l + stage - 100, 0, 0, 0);
                c1.draw();
                l = l - 10;
                //(r1==0)?o.get(230,l+stage,7):o.get(370,l+stage,7);
                //o.draw();

                (r1 == 0) ? c1.get(200, l + stage, 270, l + stage - 100, 5, 6, 7): c1.get(335, l + stage, 405, l + stage - 100, 5, 6, 7);
                c1.draw();
                if (l + stage > 300)
                    flg = 3;
            }
        }
        if (flg == 3) {

            (r1 == 0) ? c1.get(200, l + stage, 270, l + stage - 100, 0, 0, 0): c1.get(335, l + stage, 405, l + stage - 100, 0, 0, 0);
            c1.draw();
            flg = 0;
        }
        if (i == 32) {
            sound(2000);
            delay(200);
        }
        nosound();
        if (mil > 4) {
            miles += 1;
            mil = 0;
        }
        if (mil < -4) {
            miles -= 1;
            mil = 0;
        }
        if (miles >= 1000)
            break;
    } while (i != '\r');
    if (miles >= 1000) {
        sound(3000);
        clearviewport();
        settextstyle(8, 0, 1);
        int i = T.minutes();
        if (i < 8)
            outtextxy(50, 100, "CONGRATULATIONS! You have won the competetion");
        else
            outtextxy(50, 100, "SORRY! You fell out of time");
        delay(1000);
        getch();
        nosound();
    }
}