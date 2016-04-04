# boehmtest - Test Boehm GC

## REQUIREMENTS

* [clang](http://clang.llvm.org/)
* [cmake](https://cmake.org/)

### Ubuntu

 - [libgc-dev](http://packages.ubuntu.com/search?keywords=libgc-dev&searchon=names)

E.g. `sudo apt-get install clang cmake libgc-dev`

### Mac OS X, Windows

 - [Boehm GC](http://www.hpl.hp.com/personal/Hans_Boehm/gc/)

E.g. `brew install cmake boehmgc`

### Optional

* [cppcheck](http://cppcheck.sourceforge.net/)
* [splint](http://www.splint.org/)
* [vera++](https://bitbucket.org/verateam/vera/wiki/Home)
* [valgrind](http://valgrind.org/)
* [Python](https://www.python.org/) 2+ (for infer)

# EXAMPLE

```
$ cmake . && make

$ bin/boehmtest
Heap size = 131072
Heap size = 131072
Heap size = 131072
...
```
