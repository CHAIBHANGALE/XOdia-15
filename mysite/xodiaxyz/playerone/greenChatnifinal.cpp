#include<iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

char EMPTY = '0', LEAF_MY = '1', LEAF_OPP = '2', NODE_MY = '3', NODE_OPP = '4',
        FROZEN_LEAF_MY = '5', FROZEN_LEAF_OPP = '6';

int i1 = 99, j1 = 99, i2 = 99, j2 = 99, i3 = 99, j3 = 99;
char array[20][20][9];

//magic array
int magic[10000];
static int index = 0;

void set_defaults() {
    i1 = j1 = i2 = j2 = i3 = j3 = 99;
}


void print(int r, int c, int i2, int j2, int i3, int j3) {
    if (r >= 0 && r <= 19 && c >= 0 && c <= 19 && i2 >= 0 && i2 <= 19 && j2 >= 0
            && j2 <= 19 && i3 >= 0 && i3 <= 19 && j3 >= 0 && j3 <= 19
            && array[r][c][0] == LEAF_MY
            ) {
        cout << r << "," << c << "," << i2 << "," << j2 << "," << i3 << ","
                << j3;
        exit(0);
    }
    set_defaults();
}

//is_danger(source_x,source_y,dir,dest_x,dest_y)
bool is_danger1(int source_x, int source_y, int dir, int r, int c) {
    if (array[source_x][source_y][dir] == EMPTY) {
        return true;
    } else {
        return false;
    }
    return false;
}
//end

//is_danger(source_x,source_y,dir,dest_x,dest_y)
bool is_danger(int source_x, int source_y, int dir, int r, int c) {
    if (array[r][c][0] == EMPTY && array[source_x][source_y][dir] == EMPTY) {

        if (r < 19 && r > 0 && c < 19 && c > 0) {
            if (array[r - 1][c][0] != LEAF_OPP
                    && array[r - 1][c + 1][0] != LEAF_OPP
                    && array[r][c + 1][0] != LEAF_OPP
                    && array[r + 1][c + 1][0] != LEAF_OPP
                    && array[r + 1][c][0] != LEAF_OPP
                    && array[r + 1][c - 1][0] != LEAF_OPP
                    && array[r][c - 1][0] != LEAF_OPP
                    && array[r - 1][c - 1][0] != LEAF_OPP) {
                return true;
            }
        } else if (r == 0) {
            if (c == 0) {
                if (array[r][c + 1][0] != LEAF_OPP
                        && array[r + 1][c + 1][0] != LEAF_OPP
                        && array[r + 1][c][0] != LEAF_OPP) {
                    return true;
                }

            } else if (c == 19) {
                if (array[r + 1][c][0] != LEAF_OPP
                        && array[r + 1][c - 1][0] != LEAF_OPP
                        && array[r][c - 1][0] != LEAF_OPP) {
                    return true;
                }
            } else {
                if (array[r][c + 1][0] != LEAF_OPP
                        && array[r + 1][c + 1][0] != LEAF_OPP
                        && array[r + 1][c][0] != LEAF_OPP
                        && array[r + 1][c - 1][0] != LEAF_OPP
                        && array[r][c - 1][0] != LEAF_OPP) {
                    return true;
                }
            }

        } else if (r == 19) {
            if (c == 0) {
                if (array[r - 1][c][0] != LEAF_OPP
                        && array[r - 1][c + 1][0] != LEAF_OPP
                        && array[r][c + 1][0] != LEAF_OPP) {
                    return true;
                }
            } else if (c == 19) {
                if (array[r - 1][c][0] != LEAF_OPP
                        && array[r][c - 1][0] != LEAF_OPP
                        && array[r - 1][c - 1][0] != LEAF_OPP) {
                    return true;
                }
            } else {
                if (array[r - 1][c][0] != LEAF_OPP
                        && array[r - 1][c + 1][0] != LEAF_OPP
                        && array[r][c + 1][0] != LEAF_OPP
                        && array[r][c - 1][0] != LEAF_OPP
                        && array[r - 1][c - 1][0] != LEAF_OPP) {
                    return true;
                }
            }

        } else if (c == 0) {
            if (array[r - 1][c][0] != LEAF_OPP
                    && array[r - 1][c + 1][0] != LEAF_OPP
                    && array[r][c + 1][0] != LEAF_OPP
                    && array[r + 1][c + 1][0] != LEAF_OPP
                    && array[r + 1][c][0] != LEAF_OPP) {
                return true;
            }
        } else if (c == 19) {
            if (array[r - 1][c][0] != LEAF_OPP && 
                    array[r + 1][c][0] != LEAF_OPP
                    && array[r + 1][c - 1][0] != LEAF_OPP
                    && array[r][c - 1][0] != LEAF_OPP
                    && array[r - 1][c - 1][0] != LEAF_OPP) {
                return true;
            }
        }

    } else {
        return false;
    }
    return false;
}

void kill_leaf(int r, int c) {
    set_defaults();
    int points = 0;
    if (r < 19 && r > 0 && c < 19 && c > 0) {
        if (is_danger1(r, c, 1, r - 1, c)) {
            i2 = r - 1;
            j2 = c;
            points++;
        }
        if (is_danger1(r, c, 2, r - 1, c + 1)) {
            i3 = r - 1;
            j3 = c + 1;
            points++;
        }
        if (points == 2) {
            //        print r c i2 j2 i3 j3;
            print(r, c, i2, j2, i3, j3);

        }
        if (is_danger1(r, c, 3, r, c + 1)) {
            if (i2 == 99) {
                i2 = r;
                j2 = c + 1;
                points++;
            } else if (i3 == 99) {
                i3 = r;
                j3 = c + 1;
                points++;
            }
        }
        if (points == 2) {
            //        print r c i2 j2 i3 j3;
            print(r, c, i2, j2, i3, j3);

        }
        if (is_danger1(r, c, 4, r + 1, c + 1)) {
            if (i2 == 99) {
                i2 = r + 1;
                j2 = c + 1;
                points++;
            } else if (i3 == 99) {
                i3 = r + 1;
                j3 = c + 1;
                points++;
            }
        }
        if (points == 2) {
            //        print r c i2 j2 i3 j3;
            print(r, c, i2, j2, i3, j3);

        }
        if (is_danger1(r, c, 5, r + 1, c)) {
            if (i2 == 99) {
                i2 = r + 1;
                j2 = c;
                points++;
            } else if (i3 == 99) {
                i3 = r + 1;
                j3 = c;
                points++;
            }
        }
        if (points == 2) {
            //        print r c i2 j2 i3 j3;
            print(r, c, i2, j2, i3, j3);

        }
        if (is_danger1(r, c, 6, r + 1, c - 1)) {
            if (i2 == 99) {
                i2 = r + 1;
                j2 = c - 1;
                points++;
            } else if (i3 == 99) {
                i3 = r + 1;
                j3 = c - 1;
                points++;
            }
        }
        if (points == 2) {
            //        print r c i2 j2 i3 j3;
            print(r, c, i2, j2, i3, j3);

        }
        if (is_danger1(r, c, 7, r, c - 1)) {
            if (i2 == 99) {
                i2 = r;
                j2 = c - 1;
                points++;
            } else if (i3 == 99) {
                i3 = r;
                j3 = c - 1;
                points++;
            }
        }
        if (points == 2) {
            //        print r c i2 j2 i3 j3;
            print(r, c, i2, j2, i3, j3);

        }
        if (is_danger1(r, c, 8, r - 1, c - 1)) {
            if (i2 == 99) {
                i2 = r - 1;
                j2 = c - 1;
                points++;
            } else if (i3 == 99) {
                i3 = r - 1;
                j3 = c - 1;
                points++;
            }
        }
        if (points == 2) {
            //        print r c i2 j2 i3 j3;
            print(r, c, i2, j2, i3, j3);

        }
    } else if (r == 0) {
        if (c == 0) {
            if (is_danger1(r, c, 3, r, c + 1)) {
                if (i2 == 99) {
                    i2 = r;
                    j2 = c + 1;
                    points++;
                } else if (i3 == 99) {
                    i3 = r;
                    j3 = c + 1;
                    points++;
                }
            }
            if (points == 2) {
                //        print r c i2 j2 i3 j3;
                print(r, c, i2, j2, i3, j3);

            }
            if (is_danger1(r, c, 4, r + 1, c + 1)) {
                if (i2 == 99) {
                    i2 = r + 1;
                    j2 = c + 1;
                    points++;
                } else if (i3 == 99) {
                    i3 = r + 1;
                    j3 = c + 1;
                    points++;
                }
            }
            if (points == 2) {
                //        print r c i2 j2 i3 j3;
                print(r, c, i2, j2, i3, j3);

            }
            if (is_danger1(r, c, 5, r + 1, c)) {
                if (i2 == 99) {
                    i2 = r + 1;
                    j2 = c;
                    points++;
                } else if (i3 == 99) {
                    i3 = r + 1;
                    j3 = c;
                    points++;
                }
            }
            if (points == 2) {
                //        print r c i2 j2 i3 j3;
                print(r, c, i2, j2, i3, j3);

            }

        } else if (c == 19) {
            if (is_danger1(r, c, 5, r + 1, c)) {
                if (i2 == 99) {
                    i2 = r + 1;
                    j2 = c;
                    points++;
                } else if (i3 == 99) {
                    i3 = r + 1;
                    j3 = c;
                    points++;
                }
            }
            if (points == 2) {
                //        print r c i2 j2 i3 j3;
                print(r, c, i2, j2, i3, j3);

            }
            if (is_danger1(r, c, 6, r + 1, c - 1)) {
                if (i2 == 99) {
                    i2 = r + 1;
                    j2 = c - 1;
                    points++;
                } else if (i3 == 99) {
                    i3 = r + 1;
                    j3 = c - 1;
                    points++;
                }
            }
            if (points == 2) {
                //        print r c i2 j2 i3 j3;
                print(r, c, i2, j2, i3, j3);

            }
            if (is_danger1(r, c, 7, r, c - 1)) {
                if (i2 == 99) {
                    i2 = r;
                    j2 = c - 1;
                    points++;
                } else if (i3 == 99) {
                    i3 = r;
                    j3 = c - 1;
                    points++;
                }
            }
            if (points == 2) {
                //        print r c i2 j2 i3 j3;
                print(r, c, i2, j2, i3, j3);

            }
        } else {
            if (is_danger1(r, c, 3, r, c + 1)) {
                if (i2 == 99) {
                    i2 = r;
                    j2 = c + 1;
                    points++;
                } else if (i3 == 99) {
                    i3 = r;
                    j3 = c + 1;
                    points++;
                }
            }
            if (points == 2) {
                //        print r c i2 j2 i3 j3;
                print(r, c, i2, j2, i3, j3);

            }
            if (is_danger1(r, c, 4, r + 1, c + 1)) {
                if (i2 == 99) {
                    i2 = r + 1;
                    j2 = c + 1;
                    points++;
                } else if (i3 == 99) {
                    i3 = r + 1;
                    j3 = c + 1;
                    points++;
                }
            }
            if (points == 2) {
                //        print r c i2 j2 i3 j3;
                print(r, c, i2, j2, i3, j3);

            }
            if (is_danger1(r, c, 5, r + 1, c)) {
                if (i2 == 99) {
                    i2 = r + 1;
                    j2 = c;
                    points++;
                } else if (i3 == 99) {
                    i3 = r + 1;
                    j3 = c;
                    points++;
                }
            }
            if (points == 2) {
                //        print r c i2 j2 i3 j3;
                print(r, c, i2, j2, i3, j3);

            }
            if (is_danger1(r, c, 6, r + 1, c - 1)) {
                if (i2 == 99) {
                    i2 = r + 1;
                    j2 = c - 1;
                    points++;
                } else if (i3 == 99) {
                    i3 = r + 1;
                    j3 = c - 1;
                    points++;
                }
            }
            if (points == 2) {
                //        print r c i2 j2 i3 j3;
                print(r, c, i2, j2, i3, j3);

            }
            if (is_danger1(r, c, 7, r, c - 1)) {
                if (i2 == 99) {
                    i2 = r;
                    j2 = c - 1;
                    points++;
                } else if (i3 == 99) {
                    i3 = r;
                    j3 = c - 1;
                    points++;
                }
            }
            if (points == 2) {
                //        print r c i2 j2 i3 j3;
                print(r, c, i2, j2, i3, j3);

            }
        }

    } else if (r == 19) {
        if (c == 0) {
            if (is_danger1(r, c, 1, r - 1, c)) {
                if (i2 == 99) {
                    i2 = r - 1;
                    j2 = c;
                    points++;
                } else if (i3 == 99) {
                    i3 = r - 1;
                    j3 = c;
                    points++;
                }
            }
            if (points == 2) {
                //        print r c i2 j2 i3 j3;
                print(r, c, i2, j2, i3, j3);

            }
            if (is_danger1(r, c, 2, r - 1, c + 1)) {
                if (i2 == 99) {
                    i2 = r - 1;
                    j2 = c + 1;
                    points++;
                } else if (i3 == 99) {
                    i3 = r - 1;
                    j3 = c + 1;
                    points++;
                }
            }
            if (points == 2) {
                //        print r c i2 j2 i3 j3;
                print(r, c, i2, j2, i3, j3);

            }
            if (is_danger1(r, c, 3, r, c + 1)) {
                if (i2 == 99) {
                    i2 = r;
                    j2 = c + 1;
                    points++;
                } else if (i3 == 99) {
                    i3 = r;
                    j3 = c + 1;
                    points++;
                }
            }
            if (points == 2) {
                //        print r c i2 j2 i3 j3;
                print(r, c, i2, j2, i3, j3);

            }
        } else if (c == 19) {
            if (is_danger1(r, c, 1, r - 1, c)) {
                if (i2 == 99) {
                    i2 = r - 1;
                    j2 = c;
                    points++;
                } else if (i3 == 99) {
                    i3 = r - 1;
                    j3 = c;
                    points++;
                }
            }
            if (points == 2) {
                //        print r c i2 j2 i3 j3;
                print(r, c, i2, j2, i3, j3);

            }
            if (is_danger1(r, c, 7, r, c - 1)) {
                if (i2 == 99) {
                    i2 = r;
                    j2 = c - 1;
                    points++;
                } else if (i3 == 99) {
                    i3 = r;
                    j3 = c - 1;
                    points++;
                }
            }
            if (points == 2) {
                //        print r c i2 j2 i3 j3;
                print(r, c, i2, j2, i3, j3);

            }
            if (is_danger1(r, c, 8, r - 1, c - 1)) {
                if (i2 == 99) {
                    i2 = r - 1;
                    j2 = c - 1;
                    points++;
                } else if (i3 == 99) {
                    i3 = r - 1;
                    j3 = c - 1;
                    points++;
                }
            }
            if (points == 2) {
                //        print r c i2 j2 i3 j3;
                print(r, c, i2, j2, i3, j3);

            }
        } else {
            if (is_danger1(r, c, 1, r - 1, c)) {
                if (i2 == 99) {
                    i2 = r - 1;
                    j2 = c;
                    points++;
                } else if (i3 == 99) {
                    i3 = r - 1;
                    j3 = c;
                    points++;
                }
            }
            if (points == 2) {
                //        print r c i2 j2 i3 j3;
                print(r, c, i2, j2, i3, j3);

            }
            if (is_danger1(r, c, 2, r - 1, c + 1)) {
                if (i2 == 99) {
                    i2 = r - 1;
                    j2 = c + 1;
                    points++;
                } else if (i3 == 99) {
                    i3 = r - 1;
                    j3 = c + 1;
                    points++;
                }
            }
            if (points == 2) {
                //        print r c i2 j2 i3 j3;
                print(r, c, i2, j2, i3, j3);

            }
            if (is_danger1(r, c, 3, r, c + 1)) {
                if (i2 == 99) {
                    i2 = r;
                    j2 = c + 1;
                    points++;
                } else if (i3 == 99) {
                    i3 = r;
                    j3 = c + 1;
                    points++;
                }
            }
            if (points == 2) {
                //        print r c i2 j2 i3 j3;
                print(r, c, i2, j2, i3, j3);

            }
            if (is_danger1(r, c, 7, r, c - 1)) {
                if (i2 == 99) {
                    i2 = r;
                    j2 = c - 1;
                    points++;
                } else if (i3 == 99) {
                    i3 = r;
                    j3 = c - 1;
                    points++;
                }
            }
            if (points == 2) {
                //        print r c i2 j2 i3 j3;
                print(r, c, i2, j2, i3, j3);

            }
            if (is_danger1(r, c, 8, r - 1, c - 1)) {
                if (i2 == 99) {
                    i2 = r - 1;
                    j2 = c - 1;
                    points++;
                } else if (i3 == 99) {
                    i3 = r - 1;
                    j3 = c - 1;
                    points++;
                }
            }
            if (points == 2) {
                //        print r c i2 j2 i3 j3;
                print(r, c, i2, j2, i3, j3);

            }
        }

    } else if (c == 0) {
        if (is_danger1(r, c, 1, r - 1, c)) {
            if (i2 == 99) {
                i2 = r - 1;
                j2 = c;
                points++;
            } else if (i3 == 99) {
                i3 = r - 1;
                j3 = c;
                points++;
            }
        }
        if (points == 2) {
            //        print r c i2 j2 i3 j3;
            print(r, c, i2, j2, i3, j3);

        }

        if (is_danger1(r, c, 2, r - 1, c + 1)) {
            if (i2 == 99) {
                i2 = r - 1;
                j2 = c + 1;
                points++;
            } else if (i3 == 99) {
                i3 = r - 1;
                j3 = c + 1;
                points++;
            }
        }
        if (points == 2) {
            //        print r c i2 j2 i3 j3;
            print(r, c, i2, j2, i3, j3);

        }
        if (is_danger1(r, c, 3, r, c + 1)) {
            if (i2 == 99) {
                i2 = r;
                j2 = c + 1;
                points++;
            } else if (i3 == 99) {
                i3 = r;
                j3 = c + 1;
                points++;
            }
        }
        if (points == 2) {
            //        print r c i2 j2 i3 j3;
            print(r, c, i2, j2, i3, j3);

        }
        if (is_danger1(r, c, 4, r + 1, c + 1)) {
            if (i2 == 99) {
                i2 = r + 1;
                j2 = c + 1;
                points++;
            } else if (i3 == 99) {
                i3 = r + 1;
                j3 = c + 1;
                points++;
            }
        }
        if (points == 2) {
            //        print r c i2 j2 i3 j3;
            print(r, c, i2, j2, i3, j3);

        }
        if (is_danger1(r, c, 5, r + 1, c)) {
            if (i2 == 99) {
                i2 = r + 1;
                j2 = c;
                points++;
            } else if (i3 == 99) {
                i3 = r + 1;
                j3 = c;
                points++;
            }
        }
        if (points == 2) {
            //        print r c i2 j2 i3 j3;
            print(r, c, i2, j2, i3, j3);

        }
    } else if (c == 19) {
        if (is_danger1(r, c, 1, r - 1, c)) {
            if (i2 == 99) {
                i2 = r - 1;
                j2 = c;
                points++;
            } else if (i3 == 99) {
                i3 = r - 1;
                j3 = c;
                points++;
            }
        }
        if (points == 2) {
            //        print r c i2 j2 i3 j3;
            print(r, c, i2, j2, i3, j3);

        }
        if (is_danger1(r, c, 5, r + 1, c)) {
            if (i2 == 99) {
                i2 = r + 1;
                j2 = c;
                points++;
            } else if (i3 == 99) {
                i3 = r + 1;
                j3 = c;
                points++;
            }
        }
        if (points == 2) {
            //        print r c i2 j2 i3 j3;
            print(r, c, i2, j2, i3, j3);

        }
        if (is_danger1(r, c, 6, r + 1, c - 1)) {
            if (i2 == 99) {
                i2 = r + 1;
                j2 = c - 1;
                points++;
            } else if (i3 == 99) {
                i3 = r + 1;
                j3 = c - 1;
                points++;
            }
        }
        if (points == 2) {
            //        print r c i2 j2 i3 j3;
            print(r, c, i2, j2, i3, j3);

        }
        if (is_danger1(r, c, 7, r, c - 1)) {
            if (i2 == 99) {
                i2 = r;
                j2 = c - 1;
                points++;
            } else if (i3 == 99) {
                i3 = r;
                j3 = c - 1;
                points++;
            }
        }
        if (points == 2) {
            //        print r c i2 j2 i3 j3;
            print(r, c, i2, j2, i3, j3);

        }
        if (is_danger1(r, c, 8, r - 1, c - 1)) {
            if (i2 == 99) {
                i2 = r - 1;
                j2 = c - 1;
                points++;
            } else if (i3 == 99) {
                i3 = r - 1;
                j3 = c - 1;
                points++;
            }
        }
        if (points == 2) {
            //        print r c i2 j2 i3 j3;
            print(r, c, i2, j2, i3, j3);

        }
    }
}

void check_forward_growth(int r, int c) {
    // s s
    // a s
    // s s

    int points = 0;
    if (is_danger(r, c, 2, r - 1, c + 1)) {
        i2 = r - 1;
        j2 = c + 1;
        points++;
    }
    if (is_danger(r, c, 4, r + 1, c + 1)) {
        i3 = r + 1;
        j3 = c + 1;
        points++;
    }

    if (points == 2) {
        //        print r c i2 j2 i3 j3;
        print(r, c, i2, j2, i3, j3);

    }

    if (is_danger(r, c, 3, r, c + 1)) {
        if (i2 == 99) {
            i2 = r;
            j2 = c + 1;
            points++;
        } else if (i3 == 99) {
            i3 = r;
            j3 = c + 1;
            points++;
        }
    }
    if (points == 2) {
        //            print;
        print(r, c, i2, j2, i3, j3);

    }

    if (is_danger(r, c, 1, r - 1, c)) {
        if (i2 == 99) {
            i2 = r - 1;
            j2 = c;
            points++;
        } else if (i3 == 99) {
            i3 = r - 1;
            j3 = c;
            points++;
        }
    }
    if (points == 2) {
        //            print;
        print(r, c, i2, j2, i3, j3);

    }

    if (is_danger(r, c, 5, r + 1, c)) {
        if (i2 == 99) {
            i2 = r + 1;
            j2 = c;
            points++;
        } else if (i3 == 99) {
            i3 = r + 1;
            j3 = c;
            points++;
        }
    }
    if (points == 2) {
        //            print;
        print(r, c, i2, j2, i3, j3);

    }

    /////
    if (is_danger(r, c, 8, r - 1, c - 1)) {
        if (i2 == 99) {
            i2 = r - 1;
            j2 = c - 1;
            points++;
        } else if (i3 == 99) {
            i3 = r - 1;
            j3 = c - 1;
            points++;
        }
    }
    if (points == 2) {
        //            print;
        print(r, c, i2, j2, i3, j3);

    }

    if (is_danger(r, c, 6, r + 1, c - 1)) {
        if (i2 == 99) {
            i2 = r + 1;
            j2 = c - 1;
            points++;
        } else if (i3 == 99) {
            i3 = r + 1;
            j3 = c - 1;
            points++;
        }
    }
    if (points == 2) {
        //            print;
        print(r, c, i2, j2, i3, j3);

    }
    if (is_danger(r, c, 7, r, c - 1)) {
        if (i2 == 99) {
            i2 = r;
            j2 = c - 1;
            points++;
        } else if (i3 == 99) {
            i3 = r;
            j3 = c - 1;
            points++;
        }
    }
    if (points == 2) {
        //            print;
        print(r, c, i2, j2, i3, j3);

    }
    set_defaults();
}

void check_adj_leaf_opp(int r, int c) {    //add dir
    if (r < 19 && r > 0 && c < 19 && c > 0) {
        if (array[r - 1][c][0] == LEAF_OPP) {
            magic[index++] = r;
            magic[index++] = c;
            magic[index++] = r - 1;
            magic[index++] = c;
            magic[index++] = 1;
        } else if (array[r - 1][c + 1][0] == LEAF_OPP) {
            magic[index++] = r;
            magic[index++] = c;
            magic[index++] = r - 1;
            magic[index++] = c + 1;
            magic[index++] = 2;
        } else if (array[r][c + 1][0] == LEAF_OPP) {
            magic[index++] = r;
            magic[index++] = c;
            magic[index++] = r;
            magic[index++] = c + 1;
            magic[index++] = 3;
        } else if (array[r + 1][c + 1][0] == LEAF_OPP) {
            magic[index++] = r;
            magic[index++] = c;
            magic[index++] = r + 1;
            magic[index++] = c + 1;
            magic[index++] = 4;
        } else if (array[r + 1][c][0] == LEAF_OPP) {
            magic[index++] = r;
            magic[index++] = c;
            magic[index++] = r + 1;
            magic[index++] = c;
            magic[index++] = 5;
        } else if (array[r + 1][c - 1][0] == LEAF_OPP) {
            magic[index++] = r;
            magic[index++] = c;
            magic[index++] = r + 1;
            magic[index++] = c - 1;
            magic[index++] = 6;
        } else if (array[r][c - 1][0] == LEAF_OPP) {
            magic[index++] = r;
            magic[index++] = c;
            magic[index++] = r;
            magic[index++] = c - 1;
            magic[index++] = 7;
        } else if (array[r - 1][c - 1][0] == LEAF_OPP) {
            magic[index++] = r;
            magic[index++] = c;
            magic[index++] = r - 1;
            magic[index++] = c - 1;
            magic[index++] = 8;
        }
    } else if (r == 0) {
        if (c == 0) {
            if (array[r][c + 1][0] == LEAF_OPP) {
                magic[index++] = r;
                magic[index++] = c;
                magic[index++] = r;
                magic[index++] = c + 1;
                magic[index++] = 3;
            } else if (array[r + 1][c + 1][0] == LEAF_OPP) {
                magic[index++] = r;
                magic[index++] = c;
                magic[index++] = r + 1;
                magic[index++] = c + 1;
                magic[index++] = 4;
            } else if (array[r + 1][c][0] == LEAF_OPP) {
                magic[index++] = r;
                magic[index++] = c;
                magic[index++] = r + 1;
                magic[index++] = c;
                magic[index++] = 5;
            }

        } else if (c == 19) {
            if (array[r + 1][c][0] == LEAF_OPP) {
                magic[index++] = r;
                magic[index++] = c;
                magic[index++] = r + 1;
                magic[index++] = c;
                magic[index++] = 5;
            } else if (array[r + 1][c - 1][0] == LEAF_OPP) {
                magic[index++] = r;
                magic[index++] = c;
                magic[index++] = r + 1;
                magic[index++] = c - 1;
                magic[index++] = 6;
            } else if (array[r][c - 1][0] == LEAF_OPP) {
                magic[index++] = r;
                magic[index++] = c;
                magic[index++] = r;
                magic[index++] = c - 1;
                magic[index++] = 7;
            }
        } else {
            if (array[r][c + 1][0] == LEAF_OPP) {
                magic[index++] = r;
                magic[index++] = c;
                magic[index++] = r;
                magic[index++] = c + 1;
                magic[index++] = 3;
            } else if (array[r + 1][c + 1][0] == LEAF_OPP) {
                magic[index++] = r;
                magic[index++] = c;
                magic[index++] = r + 1;
                magic[index++] = c + 1;
                magic[index++] = 4;
            } else if (array[r + 1][c][0] == LEAF_OPP) {
                magic[index++] = r;
                magic[index++] = c;
                magic[index++] = r + 1;
                magic[index++] = c;
                magic[index++] = 5;
            } else if (array[r + 1][c - 1][0] == LEAF_OPP) {
                magic[index++] = r;
                magic[index++] = c;
                magic[index++] = r + 1;
                magic[index++] = c - 1;
                magic[index++] = 6;
            } else if (array[r][c - 1][0] == LEAF_OPP) {
                magic[index++] = r;
                magic[index++] = c;
                magic[index++] = r;
                magic[index++] = c - 1;
                magic[index++] = 7;
            }
        }

    } else if (r == 19) {
        if (c == 0) {
            if (array[r - 1][c][0] == LEAF_OPP) {
                magic[index++] = r;
                magic[index++] = c;
                magic[index++] = r - 1;
                magic[index++] = c;
                magic[index++] = 1;
            } else if (array[r - 1][c + 1][0] == LEAF_OPP) {
                magic[index++] = r;
                magic[index++] = c;
                magic[index++] = r - 1;
                magic[index++] = c + 1;
                magic[index++] = 2;
            } else if (array[r][c + 1][0] == LEAF_OPP) {
                magic[index++] = r;
                magic[index++] = c;
                magic[index++] = r;
                magic[index++] = c + 1;
                magic[index++] = 3;
            }
        } else if (c == 19) {
            if (array[r - 1][c][0] == LEAF_OPP) {
                magic[index++] = r;
                magic[index++] = c;
                magic[index++] = r - 1;
                magic[index++] = c;
                magic[index++] = 1;
            } else if (array[r][c - 1][0] == LEAF_OPP) {
                magic[index++] = r;
                magic[index++] = c;
                magic[index++] = r;
                magic[index++] = c - 1;
                magic[index++] = 7;
            } else if (array[r - 1][c - 1][0] == LEAF_OPP) {
                magic[index++] = r;
                magic[index++] = c;
                magic[index++] = r - 1;
                magic[index++] = c - 1;
                magic[index++] = 8;
            }
        } else {
            if (array[r - 1][c][0] == LEAF_OPP) {
                magic[index++] = r;
                magic[index++] = c;
                magic[index++] = r - 1;
                magic[index++] = c;
                magic[index++] = 1;
            } else if (array[r - 1][c + 1][0] == LEAF_OPP) {
                magic[index++] = r;
                magic[index++] = c;
                magic[index++] = r - 1;
                magic[index++] = c + 1;
                magic[index++] = 2;
            } else if (array[r][c + 1][0] == LEAF_OPP) {
                magic[index++] = r;
                magic[index++] = c;
                magic[index++] = r;
                magic[index++] = c + 1;
                magic[index++] = 3;
            } else if (array[r][c - 1][0] == LEAF_OPP) {
                magic[index++] = r;
                magic[index++] = c;
                magic[index++] = r;
                magic[index++] = c - 1;
                magic[index++] = 7;
            } else if (array[r - 1][c - 1][0] == LEAF_OPP) {
                magic[index++] = r;
                magic[index++] = c;
                magic[index++] = r - 1;
                magic[index++] = c - 1;
                magic[index++] = 8;
            }
        }

    } else if (c == 0) {
        if (array[r - 1][c][0] == LEAF_OPP) {
            magic[index++] = r;
            magic[index++] = c;
            magic[index++] = r - 1;
            magic[index++] = c;
            magic[index++] = 1;
        } else if (array[r - 1][c + 1][0] == LEAF_OPP) {
            magic[index++] = r;
            magic[index++] = c;
            magic[index++] = r - 1;
            magic[index++] = c + 1;
            magic[index++] = 2;
        } else if (array[r][c + 1][0] == LEAF_OPP) {
            magic[index++] = r;
            magic[index++] = c;
            magic[index++] = r;
            magic[index++] = c + 1;
            magic[index++] = 3;
        } else if (array[r + 1][c + 1][0] == LEAF_OPP) {
            magic[index++] = r;
            magic[index++] = c;
            magic[index++] = r + 1;
            magic[index++] = c + 1;
            magic[index++] = 4;
        } else if (array[r + 1][c][0] == LEAF_OPP) {
            magic[index++] = r;
            magic[index++] = c;
            magic[index++] = r + 1;
            magic[index++] = c;
            magic[index++] = 5;
        }
    } else if (c == 19) {
        if (array[r - 1][c][0] == LEAF_OPP) {
            magic[index++] = r;
            magic[index++] = c;
            magic[index++] = r - 1;
            magic[index++] = c;
            magic[index++] = 1;
        } else if (array[r + 1][c][0] == LEAF_OPP) {
            magic[index++] = r;
            magic[index++] = c;
            magic[index++] = r + 1;
            magic[index++] = c;
            magic[index++] = 5;
        } else if (array[r + 1][c - 1][0] == LEAF_OPP) {
            magic[index++] = r;
            magic[index++] = c;
            magic[index++] = r + 1;
            magic[index++] = c - 1;
            magic[index++] = 6;
        } else if (array[r][c - 1][0] == LEAF_OPP) {
            magic[index++] = r;
            magic[index++] = c;
            magic[index++] = r;
            magic[index++] = c - 1;
            magic[index++] = 7;
        } else if (array[r - 1][c - 1][0] == LEAF_OPP) {
            magic[index++] = r;
            magic[index++] = c;
            magic[index++] = r - 1;
            magic[index++] = c - 1;
            magic[index++] = 8;
        }
    }

}

void make_a_move(int r, int c, int i2, int j2, int dir) {
    if (r < 19 && r > 0 && c < 19 && c > 0) {
        if (dir != 1 && is_danger(r, c, 1, r - 1, c)) {
            print(r, c, i2, j2, r - 1, c);
        } else if (dir != 2 && is_danger(r, c, 2, r - 1, c + 1)) {
            print(r, c, i2, j2, r - 1, c + 1);
        } else if (dir != 3 && is_danger(r, c, 3, r, c + 1)) {
            print(r, c, i2, j2, r, c + 1);
        } else if (dir != 4 && is_danger(r, c, 4, r + 1, c + 1)) {
            print(r, c, i2, j2, r + 1, c + 1);
        } else if (dir != 5 && is_danger(r, c, 5, r + 1, c)) {
            print(r, c, i2, j2, r + 1, c);
        } else if (dir != 6 && is_danger(r, c, 6, r + 1, c - 1)) {
            print(r, c, i2, j2, r + 1, c - 1);
        } else if (dir != 7 && is_danger(r, c, 7, r, c - 1)) {
            print(r, c, i2, j2, r, c - 1);
        } else if (dir != 8 && is_danger(r, c, 8, r - 1, c - 1)) {
            print(r, c, i2, j2, r - 1, c - 1);
        }
    } else if (r == 0) {
        if (c == 0) {
            if (dir != 3 && is_danger(r, c, 3, r, c + 1)) {
                print(r, c, i2, j2, r, c + 1);
            } else if (dir != 4 && is_danger(r, c, 4, r + 1, c + 1)) {
                print(r, c, i2, j2, r + 1, c + 1);
            } else if (dir != 5 && is_danger(r, c, 5, r + 1, c)) {
                print(r, c, i2, j2, r + 1, c);
            }
        } else if (c == 19) {
            if (dir != 5 && is_danger(r, c, 5, r + 1, c)) {
                print(r, c, i2, j2, r + 1, c);
            } else if (dir != 6 && is_danger(r, c, 6, r + 1, c - 1)) {
                print(r, c, i2, j2, r + 1, c - 1);
            } else if (dir != 7 && is_danger(r, c, 7, r, c - 1)) {
                print(r, c, i2, j2, r, c - 1);
            }
        } else {
            if (dir != 1 && is_danger(r, c, 1, r - 1, c)) {
                print(r, c, i2, j2, r - 1, c);
            } else if (dir != 2 && is_danger(r, c, 2, r - 1, c + 1)) {
                print(r, c, i2, j2, r - 1, c + 1);
            } else if (dir != 3 && is_danger(r, c, 3, r, c + 1)) {
                print(r, c, i2, j2, r, c + 1);
            } else if (dir != 4 && is_danger(r, c, 4, r + 1, c + 1)) {
                print(r, c, i2, j2, r + 1, c + 1);
            } else if (dir != 5 && is_danger(r, c, 5, r + 1, c)) {
                print(r, c, i2, j2, r + 1, c);
            }
        }

    } else if (r == 19) {
        if (c == 0) {
            if (dir != 1 && is_danger(r, c, 1, r - 1, c)) {
                print(r, c, i2, j2, r - 1, c);
            } else if (dir != 2 && is_danger(r, c, 2, r - 1, c + 1)) {
                print(r, c, i2, j2, r - 1, c + 1);
            } else if (dir != 3 && is_danger(r, c, 3, r, c + 1)) {
                print(r, c, i2, j2, r, c + 1);
            }
        } else if (c == 19) {
            if (dir != 1 && is_danger(r, c, 1, r - 1, c)) {
                print(r, c, i2, j2, r - 1, c);
            } else if (dir != 7 && is_danger(r, c, 7, r, c - 1)) {
                print(r, c, i2, j2, r, c - 1);
            } else if (dir != 8 && is_danger(r, c, 8, r - 1, c - 1)) {
                print(r, c, i2, j2, r - 1, c - 1);
            }
        } else {
            if (dir != 1 && is_danger(r, c, 1, r - 1, c)) {
                print(r, c, i2, j2, r - 1, c);
            } else if (dir != 2 && is_danger(r, c, 2, r - 1, c + 1)) {
                print(r, c, i2, j2, r - 1, c + 1);
            } else if (dir != 3 && is_danger(r, c, 3, r, c + 1)) {
                print(r, c, i2, j2, r, c + 1);
            } else if (dir != 7 && is_danger(r, c, 7, r, c - 1)) {
                print(r, c, i2, j2, r, c - 1);
            } else if (dir != 8 && is_danger(r, c, 8, r - 1, c - 1)) {
                print(r, c, i2, j2, r - 1, c - 1);
            }
        }

    } else if (c == 0) {
        if (dir != 1 && is_danger(r, c, 1, r - 1, c)) {
            print(r, c, i2, j2, r - 1, c);
        } else if (dir != 2 && is_danger(r, c, 2, r - 1, c + 1)) {
            print(r, c, i2, j2, r - 1, c + 1);
        } else if (dir != 3 && is_danger(r, c, 3, r, c + 1)) {
            print(r, c, i2, j2, r, c + 1);
        } else if (dir != 4 && is_danger(r, c, 4, r + 1, c + 1)) {
            print(r, c, i2, j2, r + 1, c + 1);
        } else if (dir != 5 && is_danger(r, c, 5, r + 1, c)) {
            print(r, c, i2, j2, r + 1, c);
        }
    } else if (c == 19) {
        if (dir != 1 && is_danger(r, c, 1, r - 1, c)) {
            print(r, c, i2, j2, r - 1, c);
        } else if (dir != 5 && is_danger(r, c, 5, r + 1, c)) {
            print(r, c, i2, j2, r + 1, c);
        } else if (dir != 6 && is_danger(r, c, 6, r + 1, c - 1)) {
            print(r, c, i2, j2, r + 1, c - 1);
        } else if (dir != 7 && is_danger(r, c, 7, r, c - 1)) {
            print(r, c, i2, j2, r, c - 1);
        } else if (dir != 8 && is_danger(r, c, 8, r - 1, c - 1)) {
            print(r, c, i2, j2, r - 1, c - 1);
        }
    }
}

void analyse_magic_array() {
    int d1;
    int i = 0;
    while (i < index) {
        i1 = magic[i++];
        j1 = magic[i++];
        i2 = magic[i++];
        j2 = magic[i++];
        d1 = magic[i++];
        array[i2][j2][0] = EMPTY;
        make_a_move(i1, j1, i2, j2, d1);
    }
}

int main() {
    int i, j, k;
    char s[3600];
    cin >> s;
    for (i = 0; i < 20; i++)
        for (j = 0; j < 20; j++)
            for (k = 0; k < 9; k++)
                array[i][j][k] = s[i * 9 * 20 + j * 9 + k];

    /*
     Scan whether
     1. Grid is empty
     2. There is a move played by opponent
     in order to play the first move
     Note: Your code is always given the grid values according to player1.
     Your code should output just one move and then exit.
     */

    //For Instance:-
    bool first_move = true;
    for (int i = 0; i < 20; i++) {
        if (array[i][0][0] == EMPTY) {
            continue;
        } else {
            first_move = false;
            break;
        }
    }

    if (first_move) {
        cout << "9,0,9,1";
        exit(0);
    }

    int r1 = 99, c1 = 99, r2 = 99, c2 = 99, r3 = 99, c3 = 99;
    int point = 1;
    bool found_point = false;
    //Your code logic starts here

    //check if possible to kill leaf

    for (int column = 19; column >= 0; column--) {
        for (int row = 0; row < 20; row++) {
            if (array[row][column][0] == LEAF_MY) {
                check_adj_leaf_opp(row, column);
            }
        }
    }
    if (index) {
        analyse_magic_array();

    }

    //check if possible to kill leaf end

    int check[40] = { 0 };
    static int check_index = 0;

    //to move forward 1
    for (int column = 18; column >= 0; column--) {
        for (int row = 1; row < 19; row++) {
            if (array[row][column][0] == LEAF_MY) {
                check[check_index++] = row;
                check[check_index++] = column;
                if (point == 1) {
                    r1 = row;
                    point = 2;
                    found_point = true;
                    c1 = column;
                } else {
                    r2 = row;
                }
            }
        }
        if (found_point) {

            if (r2 != 99) {
                if (abs(r1 - 9) < abs(r2 - 9)) {
                    check_forward_growth(r1, c1);
                    check_forward_growth(r2, c1);
                } else {
                    check_forward_growth(r2, c1);
                    check_forward_growth(r1, c1);
                }
            } else {
                check_forward_growth(r1, c1);
            }
            point = 1;
            r1 = 99;
            c1 = 99;
            r2 = 99;
            found_point = false;
        }

        //try rest numbers
        for (int z = 0; z < check_index; z = z + 2) {
            check_forward_growth(check[z], check[z + 1]);
        }
        check_index = 0;
    }
    //to move forward end

    //make a move ...new or merge + kill
    for (int column = 0; column < 20; column++) {
        for (int row = 0; row < 20; row++) {
            if (array[row][column][0] == LEAF_MY) {
                kill_leaf(row, column);
            }
        }
    }
    //make a move ...new or merge end + kill
    
    

    int x[400];
                int y[400];
                int x1,y1,fx2=0,fy2=0,fx3=0,fy3=0,pos=0;

        int c=0;
        for(i=0;i<20;i++)
        {
            for(j=0;j<20;j++)
            {
                if(array[j][i][0]=='1')
                {
                    x[c]=i;
                    y[c]=j;
                    c++;
                }
            }
        }
        srand( time(0));

        pos=rand()%20;
        x1=x[pos];
        y1=y[pos];
        int to=0;
        do
        {
            for(to=1;to<9;to++)
            if((to==1 || to==0) && y[pos]!=0)
            {
                fx2=x[pos];
                fy2=y[pos]-1;
            }
            else if(to==2 && x[pos]!=19 && y[pos]!=0)
            {
                fx2=x[pos]+1;
                fy2=y[pos]-1;
            }
            else if(to==3 && y[pos]!=19)
            {
                fx2=x[pos]+1;
                fy2=y[pos];
            }
            else if(to==4 && y[pos]!=19 && x[pos]!=0)
            {
                fx2=x[pos]+1;
                fy2=y[pos]+1;
            }
            else if(to==5 && y[pos]!=19)
                {
                fx2=x[pos];
                fy2=y[pos]+1;
            }
            else if(to==6 && y[pos]!=19 && x[pos]!=0)
            {
                fx2=x[pos]-1;
                fy2=y[pos]+1;
            }
            else if(to==7 && x[pos]!=0)
            {
                fx2=x[pos]-1;
                fy2=y[pos];
            }
            else if(to==8 && x[pos]!=0 && y[pos]!=0)
            {
                fx2=x[pos]-1;
                fy2=y[pos]-1;
            }
            else
            {
                to=0;
            }
        }while(to==0 || array[y1][x1][to]=='1');
        int temp=to;
        do
        {
            for(to=1;to<9;to++)
            if((to==1 || to==0) && y[pos]!=0)
            {
                fx3=x[pos];
                fy3=y[pos]-1;
            }
            else if(to==2 && x[pos]!=19 && y[pos]!=0)
            {
                fx3=x[pos]+1;
                fy3=y[pos]-1;
            }
            else if(to==3 && y[pos]!=19)
            {
                fx3=x[pos]+1;
                fy3=y[pos];
            }
            else if(to==4 && y[pos]!=19 && x[pos]!=19)
            {
                fx3=x[pos]+1;
                fy3=y[pos]+1;
            }
            else if(to==5 && y[pos]!=19)
            {
                fx3=x[pos];
                fy3=y[pos]+1;
            }
            else if(to==6 && y[pos]!=19 && x[pos]!=0)
            {
                fx3=x[pos]-1;
                fy3=y[pos]+1;
            }
            else if(to==7 && x[pos]!=0)
            {
                fx3=x[pos]-1;
                fy3=y[pos];
            }
            else if(to==8 && x[pos]!=0 && y[pos]!=0)
            {
                fx3=x[pos]-1;
                fy3=y[pos]-1;
            }
            else
            {
                to=0;
            }
        }while(to==0 || array[y1][x1][to]=='1' || to==temp);
        cout<<y1<<","<<x1<<","<<fy2<<","<<fx2<<","<<fy3<<","<<fx3;



    return 0;
}