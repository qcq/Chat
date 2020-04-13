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

    *The reason to upgrade of gcc, because gtest need a higher complier to compile*
    or may be just pass in c++14 in cmake command will be ok.

1. git clone https://github.com/google/googletest.git

2. cd googletest

3. mkdir build

4. cd build

5. cmake -DCMAKE_CXX_COMPILER="c++" -DCMAKE_CXX_FLAGS="-std=c++17 -stdlib=libc++" ../

6. make

7. sudo make install
