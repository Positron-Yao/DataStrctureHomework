#include <iostream>
#include <stack>
using namespace std;

struct Box {
    int i, j;
    int dir;
    bool operator==(const Box& b) const {
        return (i == b.i && j == b.j);
    }
    bool operator!=(const Box& b) const {
        return !(*this == b);
    }
};

class Maze {
    private:
        int const row = 10, col = 10;
        int maze[10][10] = {
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
            {1, 0, 0, 1, 1, 0, 0, 1, 1, 1},
            {1, 1, 0, 1, 0, 1, 0, 0, 0, 1},
            {1, 1, 0, 0, 0, 0, 0, 1, 0, 1},
            {1, 0, 1, 1, 0, 1, 1, 1, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 1, 1, 0, 0, 1, 1, 1, 1, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 1, 0, 1, 1, 0, 1, 0, 0, 1},
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        };
        stack<Box> st;

    public:
        Maze() {}

        int get_maze(int r, int c) {
            return maze[r][c];
        }

        int get_maze(Box pos) {
            return maze[pos.i][pos.j];
        }

        void set_maze(int r, int c, int val) {
            maze[r][c] = val;
        }

        void set_maze(Box pos, int val) {
            maze[pos.i][pos.j] = val;
        }

        void show() {
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    switch (maze[i][j]) {
                        case 1:
                            cout << "# ";
                            break;
                        case 0:
                            cout << "  ";
                            break;
                        case -1:
                            cout << "· ";
                            break;
                    }
                }
                cout << endl;
            }
        }

        bool find_path(Box from, Box to) {
            if (get_maze(from) != 0 || get_maze(to) != 0) {
                // 判断起点和终点都是可行的
                return false;
            }
            set_maze(from, -1);
            Box pos = from, next = pos;
            st.push(pos);

            while (!st.empty()) {
                if (pos == to) {   // 找到路径
                    return true;
                }
                while (pos.dir < 4) {
                    switch (pos.dir) {
                        case 0:
                            next.i--;
                            break;
                        case 1:
                            next.j++;
                            break;
                        case 2:
                            next.i++;
                            break;
                        case 3:
                            next.j--;
                            break;
                    }
                    if (get_maze(next) == 0) {
                        set_maze(next, -1);
                        st.push(pos);
                        pos = next;
                        pos.dir = 0;
                        break;
                    } else {
                        next = pos;
                        pos.dir++;
                    }
                }
                if (pos.dir == 4) {
                    set_maze(pos, 0);
                    pos = st.top();
                    st.pop();
                }
            }
            return false;
        }
};

int main() {
    Maze m;
    if (m.find_path({1, 1}, {8, 8})) {
        cout << "找到路径!\n";
    } else {
        cout << "未找到路径\n";
    }
    m.show();
    return 0;
}

