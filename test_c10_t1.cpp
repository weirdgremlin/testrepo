#include <fcntl.h>
#include <bits/stdc++.h>

using namespace std;

int check(int ret) {
    if (ret == -1) {
        throw system_error(errno, generic_category());
    }
    return ret;
}

class File {
private:
    char *name;
public:
    int fd;
    char data[10];

    // Class constructor
    File(char *filename) : name(filename), fd(open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644)) {}

    ~File() {
        close(fd);
    }

    // Move
    File(File &&f) : name(f.name), fd(f.fd) {
        swap(f);
    }

    File &operator=(File &&f) {
        File tmp(move(f));
        swap(tmp);
        return *this;
    }

    // Copy
    File(const File &f) {
        fd = dup(f.fd);
        name = f.name;
        for (size_t i = 0; i < 10; ++i) {
            data[i] = f.data[i];
        }
    }

    File &operator=(const File &f) {
        File tmp(f);
        swap(tmp);
        return *this;
    }

    //

    void swap(File &f) {
        std::swap(name, f.name);
        std::swap(data, f.data);
        std::swap(fd, f.fd);
    }

    // Functions to read/write data
    int fin(string msg) {
        return write(fd, msg.data(), msg.size());
    }

    int fout() {
        return read(fd, data, 10);
    }

    // Task 3
    off_t move_on(off_t bytes) {
        return lseek(fd, bytes, SEEK_SET);
    }
};

int main() {
    File f("myfile.txt");
/*    cout << check(f.fin("abc"));
    cout << check(f.fout());
    cout << f.data[5] << "\n";
    cout << f.fd << "\n";
    cout << check(f.move_on(2));
    f.fin("yy");
    File ff;
    cout << ff.fd << "\n";
    f = ff;
    cout << f.fd;
    File ff(move(f));
    ff = move(f);
    cout << ff.fd; */
    return 0;
}