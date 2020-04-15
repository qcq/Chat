# Items

## add the support of gtest in CMakeLists.txt

CentOs7 embeded with old version of gcc(4.8.x) which is too old to support c++17,
can only support cxx14. for because develop this project under MAC/Linux two platform
So, I need to consider the difference between them. did below things:

### upgrade the version of gcc

1. download the gcc(9.3.0), under link: http://ftp.tsukuba.wide.ad.jp/software/gcc/releases/gcc-9.3.0/gcc-9.3.0.tar.gz

2. tar zxvf gcc-9.3.0.tar.gz

3. cd gcc-9.3.0

4. mkdir build

5. ../configure  --prefix=/usr --disable-multilib
    in this step has no install needed package which non-exist.

6. make    *have to wait long times*

7. sudo make install

### compile gtest by own

    The reason to upgrade of gcc, because gtest need a higher complier to compile
    or may be just pass in c++14 in cmake command will be ok.
    may be under some platform can not found them, set PKG_CONFIG_PATH to /usr/lib64/pkgconfig

1. git clone https://github.com/google/googletest.git

2. cd googletest

3. mkdir build

4. cd build

5. cmake  -DCMAKE_CXX_FLAGS="-std=c++17" ..

6. make

7. sudo make install

8. also can set set(ENV{PKG_CONFIG_PATH} "/usr/local/lib64/pkgconfig:$ENV{PKG_CONFIG_PATH}")

    which set the pkg path to the gtest.pc file located.

## add basic server and client function

### first step just add non-ssl enabled c/s

    do not care others, let it be work first.
