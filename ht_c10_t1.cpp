#include <fcntl.h>
#include <bits/stdc++.h>

using namespace std;

template<class T>
inline T check(T ret) {
    if (ret == T(-1)) {
        throw std::system_error(errno, std::generic_category());
    }
    return ret;
}

class File {
// =========================================================== first
private:
    char *_filename = nullptr;
public:
    int fd;
    char buff[10];

    File(char *rhs) : _filename(rhs), fd(check(open(_filename, O_CREAT | O_WRONLY | O_TRUNC, 0644))) {
        auto nwritten = check(write(fd, _filename, sizeof(_filename)));
    }

//============================================================= second
    File &operator=(const File &rhs) {
        File tmp(rhs._filename);
        swap(tmp);
        return *this;
    }

    // обмен
    void swap(File &rhs) {
        std::swap(fd, rhs.fd);
        std::swap(_filename, rhs._filename);
    }

    File(File &&rhs) :
            _filename(rhs._filename), fd(rhs.fd) { // захватываем ресурсы
        rhs._filename = nullptr; // обнуляем исходные ресурсы
        rhs.fd = NULL;
    }

    File &operator=(File &&rhs) {
        File tmp(std::move(rhs));
        swap(tmp);
        return *this;
    }

    int fin(std::string msg) {
        return write(fd, msg.data(), msg.size());
    }

    int fout() {
        return read(fd, buff, 10);
    }

    off_t change_pos(off_t bytes) {
        return lseek(fd, bytes, SEEK_SET);
    }

    ~File() {
        close(fd);
    }
// =============================================================== third
    File(const File& rhs) {
        fd = dup(rhs.fd);
        _filename = rhs._filename;
        for (size_t i = 0; i < 10; ++i) {
            buff[i] = rhs.buff[i];
        }
    }
};

int main() {
    File f("myfile.txt");
    cout << check(f.fin("abc"));
    cout << check(f.fout());
    cout << f.buff[5] << "\n";
    /*
    std::cout << f.fd << "\n";
    std::cout << check(f.change_pos(2));
    f.f_write("yy");
    File ff;
    std::cout << ff.fd << "\n";
    f = ff;
    std::cout << f.fd;
    File ff(std::move(f));
    ff = std::move(f);
    std::cout << ff.fd;
     */
    return 0;
}
